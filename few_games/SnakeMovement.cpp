#include "SnakeMovement.h"


void SnakeMovement::Movement()
{
	size_t x;
	size_t y;
	switch (m_Direction)
	{
	case top:
		InitializeCoorForMovementUp(x, y);
		break;
	case right:
		InitializeCoorForMovementRight(x, y);
		break;
	case down:
		InitializeCoorForMovementDown(x, y);
		break;
	case left:
		InitializeCoorForMovementLeft(x, y);
		break;
	default:
		break;
	}
	if (GetTypeOfCell(x, y) == LGreen)
	{
		GameOver();
		return;
	}

	if (GetTypeOfCell(x, y) != LBlue)
	{
		SetDefaultColorForCell(m_SnakeArray.front());
		m_SnakeArray.pop_front();
		m_SnakeArray.push_back(std::pair<size_t, size_t>(x, y));
		LightActiveCell();
	}
	else
	{
		m_SnakeArray.push_back(std::pair<size_t, size_t>(x, y));
		LightActiveCell();
		LocateFood();
	}
}

void SnakeMovement::InitializeCoorForMovementUp(size_t& _x, size_t& _y)
{
	_x = m_SnakeArray.back().first;
	if (m_SnakeArray.back().second > 0)
		_y = m_SnakeArray.back().second - 1;
	else
		_y = GetCellsInColumn() - 1;
}

void SnakeMovement::InitializeCoorForMovementRight(size_t& _x, size_t& _y)
{
	_y = m_SnakeArray.back().second;

	if (m_SnakeArray.back().first < (GetCellsInRow() - 1))
		_x = m_SnakeArray.back().first + 1;
	else
		_x = 0;
}

void SnakeMovement::InitializeCoorForMovementDown(size_t& _x, size_t& _y)
{
	_x = m_SnakeArray.back().first;
	if (m_SnakeArray.back().second < (GetCellsInColumn() - 1))
		_y = m_SnakeArray.back().second + 1;
	else
		_y = 0;
}

void SnakeMovement::InitializeCoorForMovementLeft(size_t& _x, size_t& _y)
{
	_y = m_SnakeArray.back().second;

	if (m_SnakeArray.back().first > 0)
		_x = m_SnakeArray.back().first - 1;
	else
		_x = (GetCellsInRow() - 1);
}