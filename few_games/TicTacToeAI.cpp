#include "TicTacToeAI.h"
#define EMPTY 0
#define XCELL 5		// prime numbers
#define YCELL 7


void TicTacToeAI::AI()
{
	if (m_MiniGameField[4] == EMPTY)
	{
		MakeMove(4);
		return;
	}
	Lines aimLine;
	aimLine = CheckForRule1();
	if (aimLine != none)
	{
		MakeMove(FindNecessaryCell(CheckForRule1()));
		return;
	}
	aimLine = CheckForRule2();
	if (aimLine != none)
	{
		MakeMove(FindNecessaryCell(CheckForRule2()));
		return;
	}
	(m_eCurrentPlayer == Player::X) ? (AI_X()) : (AI_O());
}

void TicTacToeAI::AI_X()
{
	if (m_Step == 2)
		MakeMove(FindFreeCorner());
	else if (m_Step == 4)
		MakeMove(FindFreeCornerOnTheLine(FindLineOnlyWithOwnSymbol_Cross()));
	else
		MakeMove(GetFreeCell());
}

void TicTacToeAI::AI_O()
{
	if (IsCrossO())
		AI_O_Cross();
	else
		MakeMove(GetFreeCell());
}

void TicTacToeAI::AI_O_Cross()
{
	if (m_Step == 3)
		MakeMove(FindFreeCorner());
}

bool TicTacToeAI::IsCrossO()const
{
	bool answer = false;
	if (m_MiniGameField[4] == 7)
		if (GetSumOfCells(h2) == 17) //2X+O
			answer = true;
		else if (GetSumOfCells(v2) == 17) //2X+O
			answer = true;
	return answer;
}

size_t TicTacToeAI::FindFreeCorner()
{
	size_t rightCorner = 10;
	while (rightCorner > 9)
	{
		switch (GetRandom(1, 4))
		{
		case 1:
			if (m_MiniGameField[0] == EMPTY)
				rightCorner = 0;
			break;
		case 2:
			if (m_MiniGameField[2] == EMPTY)
				rightCorner = 2;
			break;
		case 3:
			if (m_MiniGameField[6] == EMPTY)
				rightCorner = 6;
			break;
		case 4:
			if (m_MiniGameField[8] == EMPTY)
				rightCorner = 8;
			break;
		default:
			break;
		}
	}
	return rightCorner;
}

size_t TicTacToeAI::FindFreeCornerOnTheLine(Lines _aimLine)
{
	size_t necessaryCell;
	switch (_aimLine)
	{
	case TicTacToeAI::h1:
		if (m_MiniGameField[0] == EMPTY)
			necessaryCell = 0;
		if (m_MiniGameField[2] == EMPTY)
			necessaryCell = 2;
		break;
	case TicTacToeAI::h3:
		if (m_MiniGameField[6] == EMPTY)
			necessaryCell = 6;
		if (m_MiniGameField[8] == EMPTY)
			necessaryCell = 8;
		break;
	case TicTacToeAI::v1:
		if (m_MiniGameField[0] == EMPTY)
			necessaryCell = 0;
		if (m_MiniGameField[6] == EMPTY)
			necessaryCell = 6;
		break;
	case TicTacToeAI::v3:
		if (m_MiniGameField[2] == EMPTY)
			necessaryCell = 2;
		if (m_MiniGameField[8] == EMPTY)
			necessaryCell = 8;
		break;
	default:
		break;
	}
	return necessaryCell;
}

TicTacToeAI::Lines TicTacToeAI::FindLineOnlyWithOwnSymbol_Cross()
{
	Lines line = none;
	size_t sum = 0;
	sum = GetSumOfCells(h1);
	if ((m_eCurrentPlayer == Player::X) ? (sum == XCELL) : (sum == YCELL))
		line = h1;
	sum = GetSumOfCells(h3);
	if ((m_eCurrentPlayer == Player::X) ? (sum == XCELL) : (sum == YCELL))
		line = h3;
	sum = GetSumOfCells(v1);
	if ((m_eCurrentPlayer == Player::X) ? (sum == XCELL) : (sum == YCELL))
		line = v1;
	sum = GetSumOfCells(h3);
	if ((m_eCurrentPlayer == Player::X) ? (sum == XCELL) : (sum == YCELL))
		line = v3;
	return line;
}

TicTacToeAI::Lines TicTacToeAI::CheckForRule1()
{
	Lines line = none;
	size_t sum = 0;
	sum = GetSumOfCells(h1);
	if ((m_eCurrentPlayer == Player::X) ? (sum == (2 * XCELL)) : (sum == (2 * YCELL)))
		line = h1;
	sum = GetSumOfCells(h2);
	if ((m_eCurrentPlayer == Player::X) ? (sum == (2 * XCELL)) : (sum == (2 * YCELL)))
		line = h2;
	sum = GetSumOfCells(h3);
	if ((m_eCurrentPlayer == Player::X) ? (sum == (2 * XCELL)) : (sum == (2 * YCELL)))
		line = h3;
	sum = GetSumOfCells(v1);
	if ((m_eCurrentPlayer == Player::X) ? (sum == (2 * XCELL)) : (sum == (2 * YCELL)))
		line = v1;
	sum = GetSumOfCells(v2);
	if ((m_eCurrentPlayer == Player::X) ? (sum == (2 * XCELL)) : (sum == (2 * YCELL)))
		line = v2;
	sum = GetSumOfCells(v3);
	if ((m_eCurrentPlayer == Player::X) ? (sum == (2 * XCELL)) : (sum == (2 * YCELL)))
		line = v3;
	sum = GetSumOfCells(d1);
	if ((m_eCurrentPlayer == Player::X) ? (sum == (2 * XCELL)) : (sum == (2 * YCELL)))
		line = d1;
	sum = GetSumOfCells(d2);
	if ((m_eCurrentPlayer == Player::X) ? (sum == (2 * XCELL)) : (sum == (2 * YCELL)))
		line = d2;
	return line;
}

TicTacToeAI::Lines TicTacToeAI::CheckForRule2()
{
	Lines line = none;
	size_t sum = 0;
	sum = GetSumOfCells(h1);
	if ((m_eCurrentPlayer == Player::O) ? (sum == (2 * XCELL)) : (sum == (2 * YCELL)))
		line = h1;
	sum = GetSumOfCells(h2);
	if ((m_eCurrentPlayer == Player::O) ? (sum == (2 * XCELL)) : (sum == (2 * YCELL)))
		line = h2;
	sum = GetSumOfCells(h3);
	if ((m_eCurrentPlayer == Player::O) ? (sum == (2 * XCELL)) : (sum == (2 * YCELL)))
		line = h3;
	sum = GetSumOfCells(v1);
	if ((m_eCurrentPlayer == Player::O) ? (sum == (2 * XCELL)) : (sum == (2 * YCELL)))
		line = v1;
	sum = GetSumOfCells(v2);
	if ((m_eCurrentPlayer == Player::O) ? (sum == (2 * XCELL)) : (sum == (2 * YCELL)))
		line = v2;
	sum = GetSumOfCells(v3);
	if ((m_eCurrentPlayer == Player::O) ? (sum == (2 * XCELL)) : (sum == (2 * YCELL)))
		line = v3;
	sum = GetSumOfCells(d1);
	if ((m_eCurrentPlayer == Player::O) ? (sum == (2 * XCELL)) : (sum == (2 * YCELL)))
		line = d1;
	sum = GetSumOfCells(d2);
	if ((m_eCurrentPlayer == Player::O) ? (sum == (2 * XCELL)) : (sum == (2 * YCELL)))
		line = d2;
	return line;
}

size_t TicTacToeAI::FindNecessaryCell(Lines _aimLine)
{
	size_t necessaryCell;
	switch (_aimLine)
	{
	case TicTacToeAI::h1:
		if (m_MiniGameField[0] == EMPTY)
			necessaryCell = 0;
		if (m_MiniGameField[1] == EMPTY)
			necessaryCell = 1;
		if (m_MiniGameField[2] == EMPTY)
			necessaryCell = 2;
		break;
	case TicTacToeAI::h2:
		if (m_MiniGameField[3] == EMPTY)
			necessaryCell = 3;
		if (m_MiniGameField[4] == EMPTY)
			necessaryCell = 4;
		if (m_MiniGameField[5] == EMPTY)
			necessaryCell = 5;
		break;
	case TicTacToeAI::h3:
		if (m_MiniGameField[6] == EMPTY)
			necessaryCell = 6;
		if (m_MiniGameField[7] == EMPTY)
			necessaryCell = 7;
		if (m_MiniGameField[8] == EMPTY)
			necessaryCell = 8;
		break;
	case TicTacToeAI::v1:
		if (m_MiniGameField[0] == EMPTY)
			necessaryCell = 0;
		if (m_MiniGameField[3] == EMPTY)
			necessaryCell = 3;
		if (m_MiniGameField[6] == EMPTY)
			necessaryCell = 6;
		break;
	case TicTacToeAI::v2:
		if (m_MiniGameField[1] == EMPTY)
			necessaryCell = 1;
		if (m_MiniGameField[4] == EMPTY)
			necessaryCell = 4;
		if (m_MiniGameField[7] == EMPTY)
			necessaryCell = 7;
		break;
	case TicTacToeAI::v3:
		if (m_MiniGameField[2] == EMPTY)
			necessaryCell = 2;
		if (m_MiniGameField[5] == EMPTY)
			necessaryCell = 5;
		if (m_MiniGameField[8] == EMPTY)
			necessaryCell = 8;
		break;
	case TicTacToeAI::d1:
		if (m_MiniGameField[0] == EMPTY)
			necessaryCell = 0;
		if (m_MiniGameField[4] == EMPTY)
			necessaryCell = 4;
		if (m_MiniGameField[8] == EMPTY)
			necessaryCell = 8;
		break;
	case TicTacToeAI::d2:
		if (m_MiniGameField[2] == EMPTY)
			necessaryCell = 2;
		if (m_MiniGameField[4] == EMPTY)
			necessaryCell = 4;
		if (m_MiniGameField[6] == EMPTY)
			necessaryCell = 6;
		break;
	default:
		break;
	}
	return necessaryCell;
}