#include "SnakeLogic.h"
#include "GameController.h"
#include <time.h>


SnakeLogic::SnakeLogic(GameController* _GC) : GameLogic(_GC)
{
	InitializeFieldSizes();
	GenerateSnake();
}

void SnakeLogic::InitializeSetOfElement()
{
	CHAR_INFO* element = new CHAR_INFO[m_sizeOfCell*m_sizeOfCell];
	for (auto i = 0u; i < m_sizeOfCell*m_sizeOfCell; ++i)
	{
		element[i].Attributes = BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY;
		element[i].Char.UnicodeChar = ' ';
	}
	m_pCGC->m_CDisplay.AddTypeOfElement(White, element);

	element = new CHAR_INFO[m_sizeOfCell*m_sizeOfCell];
	for (auto i = 0u; i < m_sizeOfCell*m_sizeOfCell; ++i)
	{
		element[i].Attributes = BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED;
		element[i].Char.UnicodeChar = ' ';
	}
	m_pCGC->m_CDisplay.AddTypeOfElement(Grey, element);

	element = new CHAR_INFO[m_sizeOfCell*m_sizeOfCell];
	for (auto i = 0u; i < m_sizeOfCell*m_sizeOfCell; ++i)
	{
		element[i].Attributes = BACKGROUND_GREEN | BACKGROUND_INTENSITY;
		element[i].Char.UnicodeChar = ' ';
	}
	m_pCGC->m_CDisplay.AddTypeOfElement(LGreen, element);

	element = new CHAR_INFO[m_sizeOfCell*m_sizeOfCell];
	for (auto i = 0u; i < m_sizeOfCell*m_sizeOfCell; ++i)
	{
		element[i].Attributes = BACKGROUND_RED | BACKGROUND_INTENSITY;
		element[i].Char.UnicodeChar = ' ';
	}
	m_pCGC->m_CDisplay.AddTypeOfElement(LRed, element);

	element = new CHAR_INFO[m_sizeOfCell*m_sizeOfCell];
	for (auto i = 0u; i < m_sizeOfCell*m_sizeOfCell; ++i)
	{
		element[i].Attributes = BACKGROUND_BLUE | BACKGROUND_INTENSITY;
		element[i].Char.UnicodeChar = ' ';
	}
	m_pCGC->m_CDisplay.AddTypeOfElement(LBlue, element);

	element = new CHAR_INFO[m_sizeOfCell*m_sizeOfCell];
	for (auto i = 0u; i < m_sizeOfCell*m_sizeOfCell; ++i)
	{
		element[i].Attributes = BACKGROUND_GREEN;
		element[i].Char.UnicodeChar = ' ';
	}
	m_pCGC->m_CDisplay.AddTypeOfElement(Green, element);
}

void SnakeLogic::SetGameField()
{
	bool flagNewLine = false;
	if (m_cellsInRow % 2 != 0)
		for (auto numberOfCell = 0u; numberOfCell < m_gameFieldSize; ++numberOfCell)
			(numberOfCell % 2 == 0) ? (m_pCGC->m_GameField[numberOfCell] = White) : (m_pCGC->m_GameField[numberOfCell] = Grey);
	else
	{
		for (auto numberOfCell = 0u; numberOfCell < m_gameFieldSize; ++numberOfCell)
		{
			if (numberOfCell%m_cellsInRow == 0)
				flagNewLine = !flagNewLine;
			if (flagNewLine)
				(numberOfCell % 2 == 0) ? (m_pCGC->m_GameField[numberOfCell] = White) : (m_pCGC->m_GameField[numberOfCell] = Grey);
			else
				(numberOfCell % 2 != 0) ? (m_pCGC->m_GameField[numberOfCell] = White) : (m_pCGC->m_GameField[numberOfCell] = Grey);
		}
	}	
}

void SnakeLogic::LightActiveCell()
{
	m_pCGC->SetCellOfGamefield(m_SnakeArray.back().first, m_SnakeArray.back().second, LGreen);
}

void SnakeLogic::InitializeFieldSizes()
{
	m_sizeOfCell = 2;
	m_cellsInRow = 13;
	m_cellsInColumn = 9;
	m_gameFieldSize = m_cellsInRow*m_cellsInColumn;
}

void SnakeLogic::SetDefaultColorForCell(std::pair<size_t, size_t> _cell)
{
	size_t numberOfCell = _cell.first + _cell.second*m_cellsInRow;
	if(m_cellsInRow % 2 != 0)
		(numberOfCell % 2 == 0) ? (m_pCGC->m_GameField[numberOfCell] = White) : (m_pCGC->m_GameField[numberOfCell] = Grey);
	else
	{
		if (_cell.second % 2 == 0)
			(numberOfCell % 2 == 0) ? (m_pCGC->m_GameField[numberOfCell] = White) : (m_pCGC->m_GameField[numberOfCell] = Grey);
		else
			(numberOfCell % 2 != 0) ? (m_pCGC->m_GameField[numberOfCell] = White) : (m_pCGC->m_GameField[numberOfCell] = Grey);
	}
}

void SnakeLogic::GenerateSnake()
{
	size_t cellOfHead_x = m_cellsInRow / 2;
	size_t cellOfHead_y = m_cellsInColumn / 2;
	m_SnakeArray.push_back(std::pair<size_t, size_t>(cellOfHead_x, cellOfHead_y));
	m_SnakeArray.push_back(std::pair<size_t, size_t>(++cellOfHead_x, cellOfHead_y));
	m_SnakeArray.push_back(std::pair<size_t, size_t>(++cellOfHead_x, cellOfHead_y));
	m_SnakeArray.push_back(std::pair<size_t, size_t>(++cellOfHead_x, cellOfHead_y));
}

void SnakeLogic::LocateFood()
{
	size_t x, y;
	std::deque <std::pair<size_t, size_t>>::const_iterator element;

	do
	{
		x = GetRandom(0, m_cellsInRow - 1);
		y = GetRandom(0, m_cellsInColumn - 1);
		element = find(m_SnakeArray.cbegin(), m_SnakeArray.cend(), std::pair<size_t, size_t>(x, y));
	} while (element != m_SnakeArray.end());

	m_pCGC->SetCellOfGamefield(x, y, LBlue);
}

size_t SnakeLogic::GetCellsInRow()const
{
	return m_cellsInRow;
}

size_t SnakeLogic::GetCellsInColumn()const
{
	return m_cellsInColumn;
}

size_t SnakeLogic::GetTypeOfCell(size_t _col, size_t _row)const
{
	return m_pCGC->GetTypeOfCell(_col, _row);
}

void SnakeLogic::GameOver()
{
	for (auto x : m_SnakeArray)
		m_pCGC->SetCellOfGamefield(x.first, x.second, LRed);
	m_pCGC->RefreshScreen();

	while (!m_bIsGameOver && !m_bExit)
		Controller();
}

void SnakeLogic::Launch()
{
	clock_t start = clock();
	IlluminateSnake();
	LocateFood();
	while (!m_bExit)
	{
		clock_t deltaTime = clock() - start;

		Controller();

		if (deltaTime > m_Delay)	//Attention
		{
			Movement();

			if (!m_bIsGameOver)
				m_pCGC->RefreshScreen();
			else
			{
				SetToZero();
				m_pCGC->RefreshScreen();
			}
			start = clock();
		}
	}
}

void SnakeLogic::SetToZero()
{
	m_SnakeArray.clear();
	SetGameField();
	GenerateSnake();
	IlluminateSnake();
	LocateFood();
	m_bIsGameOver = false;
	m_Direction = top;
	m_bExit = false;
}

void SnakeLogic::IlluminateSnake()
{
	for (auto x : m_SnakeArray)
		m_pCGC->SetCellOfGamefield(x.first, x.second, LGreen);
}

void SnakeLogic::ProcessingUP()
{
	if (m_Direction != down)
		m_Direction = top;
}

void SnakeLogic::ProcessingDOWN()
{
	if (m_Direction != top)
		m_Direction = down;
}

void SnakeLogic::ProcessingLEFT()
{
	if (m_Direction != right)
		m_Direction = left;
}

void SnakeLogic::ProcessingRIGHT()
{
	if (m_Direction != left)
		m_Direction = right;
}

void SnakeLogic::ProcessingESCAPE()
{
	m_bExit = true;
}

void SnakeLogic::ProcessingSPACE()
{
	m_bIsGameOver = true;
}

void SnakeLogic::ProcessingRETURN()
{
	m_bIsGameOver = true;
}