#ifndef TICTACTOE_AI_H
#define TICTACTOE_AI_H
#include "Random.h"

class TicTacToeAI : virtual public Random
{
protected:
	enum Colors {
		Grey = 1,
		White,
		Blue,
		Red,
		LRed,
		Green,
		LGreen
	};
	enum class Player
	{
		X,
		O
	};
	enum Lines
	{
		h1,
		h2,
		h3,
		v1,
		v2,
		v3,
		d1,
		d2,
		none
	};

	size_t* m_MiniGameField;
	Player m_eCurrentPlayer;
	size_t m_Step;
protected:
	virtual ~TicTacToeAI() = default;

	void AI();
	void AI_X();
	void AI_O();
	void AI_O_Cross();
	bool IsCrossO()const;
	virtual void MakeMove(size_t _cell) = 0;
	virtual size_t GetFreeCell()const = 0;
	virtual size_t GetSumOfCells(Lines _aimLine)const = 0;
	size_t FindFreeCorner();
	size_t FindFreeCornerOnTheLine(Lines _aimLine);
	Lines FindLineOnlyWithOwnSymbol_Cross();
	Lines CheckForRule1();
	Lines CheckForRule2();
	size_t FindNecessaryCell(Lines _aimLine);
};

#endif TICTACTOE_AI_H