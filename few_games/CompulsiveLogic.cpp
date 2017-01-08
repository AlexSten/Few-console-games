#include "CompulsiveLogic.h"
#include <iostream>
#include"GameController.h"



CompulsiveLogic::CompulsiveLogic(GameController* _GC) : GameLogic(_GC)
{
	InitializeFieldSizes();
	m_eChoosenColor = Red;
	m_StartCell = m_gameFieldSize / 2;	// middle
}


void CompulsiveLogic::InitializeSetOfElement()
{
	CHAR_INFO* element = new CHAR_INFO[m_sizeOfCell*m_sizeOfCell];
	for (auto i = 0u; i < m_sizeOfCell*m_sizeOfCell; ++i)
	{
		element[i].Attributes = 0;
		element[i].Char.UnicodeChar = ' ';
	}
	m_pCGC->m_CDisplay.AddTypeOfElement(Black, element);

	element = new CHAR_INFO[m_sizeOfCell*m_sizeOfCell];
	for (auto i = 0u; i < m_sizeOfCell*m_sizeOfCell; ++i)
	{
		element[i].Attributes = BACKGROUND_RED;
		element[i].Char.UnicodeChar = ' ';
	}
	m_pCGC->m_CDisplay.AddTypeOfElement(Red, element);

	element = new CHAR_INFO[m_sizeOfCell*m_sizeOfCell];
	for (auto i = 0u; i < m_sizeOfCell*m_sizeOfCell; ++i)
	{
		element[i].Attributes = BACKGROUND_GREEN;
		element[i].Char.UnicodeChar = ' ';
	}
	m_pCGC->m_CDisplay.AddTypeOfElement(Green, element);

	element = new CHAR_INFO[m_sizeOfCell*m_sizeOfCell];
	for (auto i = 0u; i < m_sizeOfCell*m_sizeOfCell; ++i)
	{
		element[i].Attributes = BACKGROUND_BLUE;
		element[i].Char.UnicodeChar = ' ';
	}
	m_pCGC->m_CDisplay.AddTypeOfElement(Blue, element);

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
		element[i].Attributes = BACKGROUND_GREEN | BACKGROUND_INTENSITY;
		element[i].Char.UnicodeChar = ' ';
	}
	m_pCGC->m_CDisplay.AddTypeOfElement(LGreen, element);

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
		element[i].Attributes = BACKGROUND_RED | BACKGROUND_GREEN;
		element[i].Char.UnicodeChar = ' ';
	}
	m_pCGC->m_CDisplay.AddTypeOfElement(Brown, element);

	element = new CHAR_INFO[m_sizeOfCell*m_sizeOfCell];
	for (auto i = 0u; i < m_sizeOfCell*m_sizeOfCell; ++i)
	{
		element[i].Attributes = BACKGROUND_RED | BACKGROUND_BLUE;
		element[i].Char.UnicodeChar = ' ';
	}
	m_pCGC->m_CDisplay.AddTypeOfElement(Magenta, element);

	element = new CHAR_INFO[m_sizeOfCell*m_sizeOfCell];
	for (auto i = 0u; i < m_sizeOfCell*m_sizeOfCell; ++i)
	{
		element[i].Attributes = BACKGROUND_GREEN | BACKGROUND_BLUE;
		element[i].Char.UnicodeChar = ' ';
	}
	m_pCGC->m_CDisplay.AddTypeOfElement(Cyan, element);

	element = new CHAR_INFO[m_sizeOfCell*m_sizeOfCell];
	for (auto i = 0u; i < m_sizeOfCell*m_sizeOfCell; ++i)
	{
		element[i].Attributes = BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_INTENSITY;
		element[i].Char.UnicodeChar = ' ';
	}
	m_pCGC->m_CDisplay.AddTypeOfElement(Yellow, element);

	element = new CHAR_INFO[m_sizeOfCell*m_sizeOfCell];
	for (auto i = 0u; i < m_sizeOfCell*m_sizeOfCell; ++i)
	{
		element[i].Attributes = BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_INTENSITY;
		element[i].Char.UnicodeChar = ' ';
	}
	m_pCGC->m_CDisplay.AddTypeOfElement(LMagenta, element);

	element = new CHAR_INFO[m_sizeOfCell*m_sizeOfCell];
	for (auto i = 0u; i < m_sizeOfCell*m_sizeOfCell; ++i)
	{
		element[i].Attributes = BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY;
		element[i].Char.UnicodeChar = ' ';
	}
	m_pCGC->m_CDisplay.AddTypeOfElement(LCyan, element);

	element = new CHAR_INFO[m_sizeOfCell*m_sizeOfCell];
	for (auto i = 0u; i < m_sizeOfCell*m_sizeOfCell; ++i)
	{
		element[i].Attributes = 0;
		element[i].Char.UnicodeChar = 'X';
	}
	m_pCGC->m_CDisplay.AddTypeOfElement(100 + Black, element);

	element = new CHAR_INFO[m_sizeOfCell*m_sizeOfCell];
	for (auto i = 0u; i < m_sizeOfCell*m_sizeOfCell; ++i)
	{
		element[i].Attributes = BACKGROUND_RED;
		element[i].Char.UnicodeChar = 'X';
	}
	m_pCGC->m_CDisplay.AddTypeOfElement(100 + Red, element);

	element = new CHAR_INFO[m_sizeOfCell*m_sizeOfCell];
	for (auto i = 0u; i < m_sizeOfCell*m_sizeOfCell; ++i)
	{
		element[i].Attributes = BACKGROUND_GREEN;
		element[i].Char.UnicodeChar = 'X';
	}
	m_pCGC->m_CDisplay.AddTypeOfElement(100 + Green, element);

	element = new CHAR_INFO[m_sizeOfCell*m_sizeOfCell];
	for (auto i = 0u; i < m_sizeOfCell*m_sizeOfCell; ++i)
	{
		element[i].Attributes = BACKGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY;
		element[i].Char.UnicodeChar = 'X';
	}
	m_pCGC->m_CDisplay.AddTypeOfElement(100 + Blue, element);

	element = new CHAR_INFO[m_sizeOfCell*m_sizeOfCell];
	for (auto i = 0u; i < m_sizeOfCell*m_sizeOfCell; ++i)
	{
		element[i].Attributes = BACKGROUND_RED | BACKGROUND_INTENSITY;
		element[i].Char.UnicodeChar = 'X';
	}
	m_pCGC->m_CDisplay.AddTypeOfElement(100 + LRed, element);

	element = new CHAR_INFO[m_sizeOfCell*m_sizeOfCell];
	for (auto i = 0u; i < m_sizeOfCell*m_sizeOfCell; ++i)
	{
		element[i].Attributes = BACKGROUND_GREEN | BACKGROUND_INTENSITY;
		element[i].Char.UnicodeChar = 'X';
	}
	m_pCGC->m_CDisplay.AddTypeOfElement(100 + LGreen, element);

	element = new CHAR_INFO[m_sizeOfCell*m_sizeOfCell];
	for (auto i = 0u; i < m_sizeOfCell*m_sizeOfCell; ++i)
	{
		element[i].Attributes = BACKGROUND_BLUE | BACKGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY;
		element[i].Char.UnicodeChar = 'X';
	}
	m_pCGC->m_CDisplay.AddTypeOfElement(100 + LBlue, element);

	element = new CHAR_INFO[m_sizeOfCell*m_sizeOfCell];
	for (auto i = 0u; i < m_sizeOfCell*m_sizeOfCell; ++i)
	{
		element[i].Attributes = BACKGROUND_RED | BACKGROUND_GREEN;
		element[i].Char.UnicodeChar = 'X';
	}
	m_pCGC->m_CDisplay.AddTypeOfElement(100 + Brown, element);

	element = new CHAR_INFO[m_sizeOfCell*m_sizeOfCell];
	for (auto i = 0u; i < m_sizeOfCell*m_sizeOfCell; ++i)
	{
		element[i].Attributes = BACKGROUND_RED | BACKGROUND_BLUE;
		element[i].Char.UnicodeChar = 'X';
	}
	m_pCGC->m_CDisplay.AddTypeOfElement(100 + Magenta, element);

	element = new CHAR_INFO[m_sizeOfCell*m_sizeOfCell];
	for (auto i = 0u; i < m_sizeOfCell*m_sizeOfCell; ++i)
	{
		element[i].Attributes = BACKGROUND_GREEN | BACKGROUND_BLUE;
		element[i].Char.UnicodeChar = 'X';
	}
	m_pCGC->m_CDisplay.AddTypeOfElement(100 + Cyan, element);

	element = new CHAR_INFO[m_sizeOfCell*m_sizeOfCell];
	for (auto i = 0u; i < m_sizeOfCell*m_sizeOfCell; ++i)
	{
		element[i].Attributes = BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_INTENSITY;
		element[i].Char.UnicodeChar = 'X';
	}
	m_pCGC->m_CDisplay.AddTypeOfElement(100 + Yellow, element);

	element = new CHAR_INFO[m_sizeOfCell*m_sizeOfCell];
	for (auto i = 0u; i < m_sizeOfCell*m_sizeOfCell; ++i)
	{
		element[i].Attributes = BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_INTENSITY;
		element[i].Char.UnicodeChar = 'X';
	}
	m_pCGC->m_CDisplay.AddTypeOfElement(100 + LMagenta, element);

	element = new CHAR_INFO[m_sizeOfCell*m_sizeOfCell];
	for (auto i = 0u; i < m_sizeOfCell*m_sizeOfCell; ++i)
	{
		element[i].Attributes = BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY;
		element[i].Char.UnicodeChar = 'X';
	}
	m_pCGC->m_CDisplay.AddTypeOfElement(100 + LCyan, element);
}

void CompulsiveLogic::InitializeFieldSizes()
{
	m_sizeOfCell = 2;
	m_cellsInRow = 13;
	m_cellsInColumn = 9;
	m_gameFieldSize = m_cellsInRow*m_cellsInColumn;
	m_BorderSize = 2;
	m_BorderShift = m_BorderSize*m_cellsInRow;
}

void CompulsiveLogic::Launch()
{
	m_pCGC->RefreshScreen();
	while (m_bExit == false)
		if (!IsGameOver())
			Controller();
		else
			GameOver();
}

void CompulsiveLogic::GameOver()
{
	m_bExit = true;
	if (m_Won)
	{
		system("CLS");
		std::cout << "Congratulations, you won!" << std::endl;
		system("pause");
	}
}

void CompulsiveLogic::ProcessingUP()
{
	++m_eChoosenColor;
	SetChoosenColor();
	m_pCGC->RefreshScreen();
}

void CompulsiveLogic::ProcessingDOWN()
{
	--m_eChoosenColor;
	SetChoosenColor();
	m_pCGC->RefreshScreen();
}

void CompulsiveLogic::ProcessingLEFT()
{
	--m_eChoosenColor;
	SetChoosenColor();
	m_pCGC->RefreshScreen();
}

void CompulsiveLogic::ProcessingRIGHT()
{
	++m_eChoosenColor;
	SetChoosenColor();
	m_pCGC->RefreshScreen();
}

void CompulsiveLogic::ProcessingESCAPE()
{
	m_bExit = true;
}

void CompulsiveLogic::ProcessingSPACE()
{
	ChangeCellColor(m_StartCell);
	m_eCurrentColor = m_eChoosenColor;
	m_pCGC->RefreshScreen();
}

void CompulsiveLogic::ProcessingRETURN()
{
	ChangeCellColor(m_StartCell);
	m_eCurrentColor = m_eChoosenColor;
	m_pCGC->RefreshScreen();
}

void CompulsiveLogic::SetToZero()
{
	m_bExit = false;
}

void CompulsiveLogic::SetGameField()
{

	unsigned int header = m_cellsInRow * m_sizeOfCell;
	for (auto i = 0u; i < header; ++i)
		m_pCGC->m_GameField[i] = Black;

	SetChoosenColor();

	for (auto numberOfCell = header; numberOfCell < m_gameFieldSize; ++numberOfCell)
	{
		auto i = GetRandom(1, 12);
		m_pCGC->m_GameField[numberOfCell] = i;
	}

	m_pCGC->m_GameField[m_StartCell] = m_pCGC->m_GameField[m_StartCell] + 100;

	m_eCurrentColor = static_cast<CompulsiveLogic::Colors>(m_pCGC->m_GameField[m_StartCell] - 100);
}

void CompulsiveLogic::SetChoosenColor()
{
	unsigned int cell = m_cellsInRow / 2;
	if (m_cellsInRow % 2 == 0)
	{
		m_pCGC->m_GameField[cell] = m_eChoosenColor;
		m_pCGC->m_GameField[cell + 1] = m_eChoosenColor;
	}
	else
	{
		m_pCGC->m_GameField[cell] = m_eChoosenColor;
		m_pCGC->m_GameField[cell + 1] = m_eChoosenColor;
		m_pCGC->m_GameField[cell - 1] = m_eChoosenColor;
	}
}

void CompulsiveLogic::ChangeCellColor(size_t _cell)
{
	if ((IsHaveCurrentColor(_cell)) && (m_eChoosenColor != m_eCurrentColor))
	{

		if (m_pCGC->m_GameField[_cell] > 100)		// with 'X' and not Black
			m_pCGC->m_GameField[_cell] = (size_t)m_eChoosenColor + 100;
		else
			m_pCGC->m_GameField[_cell] = (size_t)m_eChoosenColor;

		if (_cell > m_cellsInRow)						// checking of the upper cell
			ChangeCellColor(_cell - m_cellsInRow);
		if (_cell < (m_gameFieldSize - m_cellsInRow))	// checking of the bottom cell
			ChangeCellColor(_cell + m_cellsInRow);
		if ((_cell + 1) % m_cellsInRow != 0)			// checking of the right cell
			ChangeCellColor(_cell + 1);
		if ((_cell) % m_cellsInRow != 0)			// checking of the left cell
			ChangeCellColor(_cell - 1);
	}
}

bool CompulsiveLogic::IsHaveCurrentColor(size_t _cell)
{
	bool returnValue = false;
	if (m_pCGC->m_GameField[_cell] > 100)		// with 'X' and not Black
	{
		if (m_pCGC->m_GameField[_cell] == (m_eCurrentColor + 100))
			returnValue = true;
	}
	else
	{
		Colors clr = static_cast<Colors>(m_pCGC->m_GameField[_cell]);
		if (m_pCGC->m_GameField[_cell] == m_eCurrentColor)
			returnValue = true;
	}
	return returnValue;
}

bool CompulsiveLogic::IsGameOver()
{
	for (auto cell = m_BorderShift; cell < (m_gameFieldSize - 1); ++cell)			// (m_gameFieldSize - 1) because (cell + 1)
		if ((m_pCGC->m_GameField[cell] != m_pCGC->m_GameField[cell + 1])
			&& ((m_pCGC->m_GameField[cell] + 100) != m_pCGC->m_GameField[cell + 1])	// for comparing with the start cell
			&& (m_pCGC->m_GameField[cell] != (m_pCGC->m_GameField[cell + 1] + 100)))// for comparing with the start cell
		{
			m_Won = true;
			return false;
		}
	return true;
}

CompulsiveLogic::Colors operator++(CompulsiveLogic::Colors& _clr)
{
	if (_clr == CompulsiveLogic::Colors::LCyan)
		_clr = CompulsiveLogic::Colors::Red;			// the first color will be Red not Black
	else
		_clr = static_cast<CompulsiveLogic::Colors>(static_cast<int>(_clr) + 1);
	return _clr;
}
CompulsiveLogic::Colors operator--(CompulsiveLogic::Colors& _clr)
{
	if (_clr == CompulsiveLogic::Colors::Red)			// the first color will be Red not Black
		_clr = CompulsiveLogic::Colors::LCyan;
	else
		_clr = static_cast<CompulsiveLogic::Colors>(static_cast<int>(_clr) - 1);
	return _clr;
}