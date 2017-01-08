#include "TicTacToeLogic.h"
#include "GameController.h"
#define EMPTY 0
#define XCELL 5		// prime numbers
#define YCELL 7


TicTacToeLogic::TicTacToeLogic(GameController* _GC) : GameLogic(_GC)
{
	InitializeFieldSizes();
}

void TicTacToeLogic::InitializeFieldSizes()
{
	m_GridCellSize = 5;
	m_SeparatorSize = 1;
	m_sizeOfCell = 1;
	m_cellsInRow = m_GridCellSize * 3 + m_SeparatorSize * 2;
	m_cellsInColumn = m_GridCellSize * 3 + m_SeparatorSize * 2;
	m_gameFieldSize = m_cellsInColumn*m_cellsInColumn;
	m_MiniGameFieldSize = 9;
	m_ActiveCell = 1;
	m_eCurrentPlayer = Player::X;
	m_Step = 0;
	m_MiniGameField = new size_t[m_MiniGameFieldSize];
	for (size_t i = 0; i < m_MiniGameFieldSize; ++i)
		m_MiniGameField[i] = EMPTY;
}

void TicTacToeLogic::SetGameField()
{
	for (size_t numberOfCell = 0u; numberOfCell < m_gameFieldSize; ++numberOfCell)
		m_pCGC->m_GameField[numberOfCell] = Grey;

	size_t firstLine = m_GridCellSize;
	size_t secondLine = m_GridCellSize * 2 + m_SeparatorSize;
	for (size_t i = 0; i < m_cellsInColumn; ++i)
	{
		m_pCGC->SetCellOfGamefield(firstLine, i, Blue);
		m_pCGC->SetCellOfGamefield(secondLine, i, Blue);
		m_pCGC->SetCellOfGamefield(i, firstLine, Blue);
		m_pCGC->SetCellOfGamefield(i, secondLine, Blue);
	}
}

void TicTacToeLogic::InitializeSetOfElement()
{
	CHAR_INFO* element = new CHAR_INFO[1];
	element[0].Attributes = BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED;
	element[0].Char.UnicodeChar = ' ';
	m_pCGC->m_CDisplay.AddTypeOfElement(Grey, element);

	element = new CHAR_INFO[1];
	element[0].Attributes = BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY;
	element[0].Char.UnicodeChar = ' ';
	m_pCGC->m_CDisplay.AddTypeOfElement(White, element);

	element = new CHAR_INFO[1];
	element[0].Attributes = BACKGROUND_BLUE;
	element[0].Char.UnicodeChar = ' ';
	m_pCGC->m_CDisplay.AddTypeOfElement(Blue, element);

	element = new CHAR_INFO[1];
	element[0].Attributes = BACKGROUND_RED;
	element[0].Char.UnicodeChar = ' ';
	m_pCGC->m_CDisplay.AddTypeOfElement(Red, element);

	element = new CHAR_INFO[1];
	element[0].Attributes = BACKGROUND_RED | BACKGROUND_INTENSITY;
	element[0].Char.UnicodeChar = ' ';
	m_pCGC->m_CDisplay.AddTypeOfElement(LRed, element);

	element = new CHAR_INFO[1];
	element[0].Attributes = BACKGROUND_GREEN;
	element[0].Char.UnicodeChar = ' ';
	m_pCGC->m_CDisplay.AddTypeOfElement(Green, element);

	element = new CHAR_INFO[1];
	element[0].Attributes = BACKGROUND_GREEN | BACKGROUND_INTENSITY;
	element[0].Char.UnicodeChar = ' ';
	m_pCGC->m_CDisplay.AddTypeOfElement(LGreen, element);
}

void TicTacToeLogic::LightUpACtiveCell()
{
	size_t horizontalShift = (m_ActiveCell % 3) * (m_GridCellSize + m_SeparatorSize);
	size_t verticalShift = (m_ActiveCell / 3) * (m_GridCellSize + m_SeparatorSize);
	for (size_t x = 0; x < m_GridCellSize; ++x)		//cell size
		for (size_t y = 0; y < m_GridCellSize; ++y)
		{
			size_t type = m_pCGC->GetTypeOfCell(x + horizontalShift, y + verticalShift);
			m_pCGC->SetCellOfGamefield(x + horizontalShift, y + verticalShift, type + 1);
		}

}

void TicTacToeLogic::LightDownACtiveCell()
{
	size_t horizontalShift = (m_ActiveCell % 3) * (m_GridCellSize + m_SeparatorSize);
	size_t verticalShift = (m_ActiveCell / 3) * (m_GridCellSize + m_SeparatorSize);
	for (size_t x = 0; x < m_GridCellSize; ++x)
		for (size_t y = 0; y < m_GridCellSize; ++y)
		{
			size_t type = m_pCGC->GetTypeOfCell(x + horizontalShift, y + verticalShift);
			m_pCGC->SetCellOfGamefield(x + horizontalShift, y + verticalShift, type - 1);
		}
}

void TicTacToeLogic::DrawX()
{
	m_MiniGameField[m_ActiveCell] = 5;
	size_t horizontalShift = (m_ActiveCell % 3) * (m_GridCellSize + m_SeparatorSize);
	size_t verticalShift = (m_ActiveCell / 3) * (m_GridCellSize + m_SeparatorSize);
	for (auto i = 0; i < m_GridCellSize; ++i)
	{
		m_pCGC->SetCellOfGamefield(i + horizontalShift, i + verticalShift, LRed);
		m_pCGC->SetCellOfGamefield(i + horizontalShift, (4 - i) + verticalShift, LRed);
	}
}

void TicTacToeLogic::DrawY()
{
	m_MiniGameField[m_ActiveCell] = 7;
	size_t horizontalShift = (m_ActiveCell % 3) * (m_GridCellSize + m_SeparatorSize);
	size_t verticalShift = (m_ActiveCell / 3) * (m_GridCellSize + m_SeparatorSize);
	for (auto i = 1; i < 4; ++i)
	{
		m_pCGC->SetCellOfGamefield(i + horizontalShift, 1 + verticalShift, LGreen);
		m_pCGC->SetCellOfGamefield(i + horizontalShift, 3 + verticalShift, LGreen);
	}
	m_pCGC->SetCellOfGamefield(1 + horizontalShift, 2 + verticalShift, LGreen);
	m_pCGC->SetCellOfGamefield(3 + horizontalShift, 2 + verticalShift, LGreen);
}

void TicTacToeLogic::MakeMove(size_t _cell)
{
	LightDownACtiveCell();
	m_ActiveCell = _cell;
	LightUpACtiveCell();
	(m_eCurrentPlayer == Player::X) ? (m_MiniGameField[_cell] = XCELL) : (m_MiniGameField[_cell] = YCELL);
	++m_Step;
	(m_eCurrentPlayer == Player::X) ? (DrawX()) : (DrawY());
	m_pCGC->RefreshScreen();
	(m_eCurrentPlayer == Player::X) ? (m_eCurrentPlayer = Player::O) : (m_eCurrentPlayer = Player::X);
}

void TicTacToeLogic::Launch()
{
	LightUpACtiveCell();
	m_pCGC->RefreshScreen();
	while (!m_bExit)
	{
		if (m_eCurrentPlayer == Player::X)
			Controller();
		else
			AI();
		if (IsGameOver() || (m_Step == 9))
			GameOver();
	}
}

void TicTacToeLogic::GameOver()
{
	m_bExit = true;
}

bool TicTacToeLogic::IsGameOver()
{
	bool IsGameOVer = false;

	size_t sum = 0;
	sum = GetSumOfCells(h1);
	if ((m_eCurrentPlayer == Player::O) ? (sum == (3 * XCELL)) : (sum == (3 * YCELL)))
		IsGameOVer = true;
	sum = GetSumOfCells(h2);
	if ((m_eCurrentPlayer == Player::O) ? (sum == (3 * XCELL)) : (sum == (3 * YCELL)))
		IsGameOVer = true;
	sum = GetSumOfCells(h3);
	if ((m_eCurrentPlayer == Player::O) ? (sum == (3 * XCELL)) : (sum == (3 * YCELL)))
		IsGameOVer = true;
	sum = GetSumOfCells(v1);
	if ((m_eCurrentPlayer == Player::O) ? (sum == (3 * XCELL)) : (sum == (3 * YCELL)))
		IsGameOVer = true;
	sum = GetSumOfCells(v2);
	if ((m_eCurrentPlayer == Player::O) ? (sum == (3 * XCELL)) : (sum == (3 * YCELL)))
		IsGameOVer = true;
	sum = GetSumOfCells(v3);
	if ((m_eCurrentPlayer == Player::O) ? (sum == (3 * XCELL)) : (sum == (3 * YCELL)))
		IsGameOVer = true;
	sum = GetSumOfCells(d1);
	if ((m_eCurrentPlayer == Player::O) ? (sum == (3 * XCELL)) : (sum == (3 * YCELL)))
		IsGameOVer = true;
	sum = GetSumOfCells(d2);
	if ((m_eCurrentPlayer == Player::O) ? (sum == (3 * XCELL)) : (sum == (3 * YCELL)))
		IsGameOVer = true;
	return IsGameOVer;
}

size_t TicTacToeLogic::GetFreeCell()const
{
	for (size_t i = 0; i < 9; ++i)
		if (m_MiniGameField[i] == EMPTY)
			return i;
}

size_t TicTacToeLogic::GetSumOfCells(Lines _aimLine)const
{
	size_t sum = 0;
	switch (_aimLine)
	{
	case h1:
		sum = m_MiniGameField[0] + m_MiniGameField[1] + m_MiniGameField[2];
		break;
	case h2:
		sum = m_MiniGameField[3] + m_MiniGameField[4] + m_MiniGameField[5];
		break;
	case h3:
		sum = m_MiniGameField[6] + m_MiniGameField[7] + m_MiniGameField[8];
		break;
	case v1:
		sum = m_MiniGameField[0] + m_MiniGameField[3] + m_MiniGameField[6];
		break;
	case v2:
		sum = m_MiniGameField[1] + m_MiniGameField[4] + m_MiniGameField[7];
		break;
	case v3:
		sum = m_MiniGameField[2] + m_MiniGameField[5] + m_MiniGameField[8];
		break;
	case d1:
		sum = m_MiniGameField[0] + m_MiniGameField[4] + m_MiniGameField[8];
		break;
	case d2:
		sum = m_MiniGameField[2] + m_MiniGameField[4] + m_MiniGameField[6];
		break;
	default:
		break;
	}
	return sum;
}

void TicTacToeLogic::SetToZero()
{
	m_ActiveCell = 1;
	m_Step = 0;
	m_eCurrentPlayer = Player::X;
	m_bExit = false;
	for (size_t i = 0; i < m_MiniGameFieldSize; ++i)
		m_MiniGameField[i] = EMPTY;
}

void TicTacToeLogic::ProcessingUP()
{
	LightDownACtiveCell();
	if (m_ActiveCell > 2)
		m_ActiveCell -= 3;
	else
		m_ActiveCell += 6;
	LightUpACtiveCell();
	m_pCGC->RefreshScreen();
}

void TicTacToeLogic::ProcessingDOWN()
{
	LightDownACtiveCell();
	if (m_ActiveCell < 6)
		m_ActiveCell += 3;
	else
		m_ActiveCell -= 6;
	LightUpACtiveCell();
	m_pCGC->RefreshScreen();
}

void TicTacToeLogic::ProcessingLEFT()
{
	LightDownACtiveCell();
	if (m_ActiveCell % 3 != 0)
		--m_ActiveCell;
	else
		m_ActiveCell += 2;
	LightUpACtiveCell();
	m_pCGC->RefreshScreen();
}

void TicTacToeLogic::ProcessingRIGHT()
{
	LightDownACtiveCell();
	if ((m_ActiveCell + 1) % 3 != 0)
		++m_ActiveCell;
	else
		m_ActiveCell -= 2;
	LightUpACtiveCell();
	m_pCGC->RefreshScreen();
}

void TicTacToeLogic::ProcessingESCAPE()
{
	m_bExit = true;
}

void TicTacToeLogic::ProcessingSPACE()
{
	if (m_MiniGameField[m_ActiveCell] == EMPTY)
	{
		keybd_event(VK_SPACE, 0, KEYEVENTF_KEYUP, 0);
		++m_Step;
		(m_eCurrentPlayer == Player::X) ? (DrawX()) : (DrawY());
		m_pCGC->RefreshScreen();
		(m_eCurrentPlayer == Player::X) ? (m_eCurrentPlayer = Player::O) : (m_eCurrentPlayer = Player::X);
	}
}

void TicTacToeLogic::ProcessingRETURN()
{
	ProcessingSPACE();
}