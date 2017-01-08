#include "Display.h"
#include <iostream>
#include "GameController.h"


Display::Display(const GameController* _GC) : m_pGC(_GC)
{
	m_hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	HideCursor();
}


void Display::Initializing()
{
	m_coord.X = 0;
	m_coord.Y = 0;
	m_size.X = (short)(m_cellsInRow*m_sizeOfCell);
	m_size.Y = (short)(m_cellsInColumn*m_sizeOfCell);
	m_sr.Left = 0;
	m_sr.Top = 1;
	m_sr.Right = (short)(m_cellsInRow*m_sizeOfCell);
	m_sr.Bottom = (short)(m_cellsInColumn*m_sizeOfCell);
}

void Display::CleanseYourself()
{
	delete[] m_ArrayForDisplay;
	for (auto x : m_pTypesOfElement)
		delete[] x.second;
	m_pTypesOfElement.clear();
}

void Display::SetSizesOfField(size_t _sizeOfCell, size_t _cellsInRow, size_t _cellsInColumn)
{
	m_sizeOfCell = _sizeOfCell;
	m_cellsInRow = _cellsInRow;
	m_cellsInColumn = _cellsInColumn;
	m_gameFieldSize = m_cellsInRow*m_cellsInColumn;
	m_arraySize = m_gameFieldSize*m_sizeOfCell*m_sizeOfCell;
}

void Display::GenerateArrayForDisplay()
{
	m_ArrayForDisplay = new CHAR_INFO[m_arraySize];
}

void Display::InitializeDisplayField()
{
	for (auto i = 0u; i < m_gameFieldSize; ++i)
		DrawGameElemnt(i, m_pGC->m_GameField[i]);
}

void Display::DisplayYourself()
{
	WriteConsoleOutput(
		m_hStdOut,
		m_ArrayForDisplay,
		m_size,
		m_coord,
		&m_sr);
}

void Display::AddTypeOfElement(size_t _number, CHAR_INFO*& _element)
{
	m_pTypesOfElement.insert(std::pair<int, CHAR_INFO*>(_number, _element));
}

void Display::HideCursor()const
{
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(m_hStdOut, &structCursorInfo);
	structCursorInfo.bVisible = false;
	SetConsoleCursorInfo(m_hStdOut, &structCursorInfo);
}

void Display::DrawGameElemnt(size_t _cellNumber, size_t _typeOfFigure)
{
	size_t i = 0;
	for (auto y = 0u; y < m_sizeOfCell; ++y)
		for (auto x = 0u; x < m_sizeOfCell; ++x)
		{
			size_t rowOfCell = _cellNumber / m_cellsInRow;
			size_t columnOfCell = _cellNumber % m_cellsInRow;
			size_t position = rowOfCell*m_sizeOfCell*m_sizeOfCell*m_cellsInRow + columnOfCell*m_sizeOfCell;

			size_t fg = position + x + y*m_sizeOfCell*m_cellsInRow;
			m_ArrayForDisplay[fg] = m_pTypesOfElement.at(_typeOfFigure)[i];
			++i;
		}
}