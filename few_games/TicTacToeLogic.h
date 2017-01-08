#ifndef TICTACTOE_LOGIC_H
#define TICTACTOE_LOGIC_H
#include "GameLogic.h"
#include "TicTacToeAI.h"
#include <map>

class TicTacToeLogic : public GameLogic, public TicTacToeAI
{
private:
	std::map<Lines, size_t> m_mLines;
	size_t m_MiniGameFieldSize;
	size_t m_ActiveCell;
	size_t m_Step;

	size_t m_GridCellSize;
	size_t m_SeparatorSize;
private:
	bool IsGameOver();
	void DrawX();
	void DrawY();
	void LightUpACtiveCell();
	void LightDownACtiveCell();
	void MakeMove(size_t _cell) override;
	size_t GetFreeCell()const override;
	size_t GetSumOfCells(Lines _aimLine)const override;

	void GameOver()override;
	void InitializeFieldSizes()override;
	void ProcessingUP()override;
	void ProcessingDOWN()override;
	void ProcessingLEFT()override;
	void ProcessingRIGHT()override;
	void ProcessingESCAPE()override;
	void ProcessingSPACE()override;
	void ProcessingRETURN()override;
public:
	TicTacToeLogic(GameController* _GC);
	~TicTacToeLogic() = default;

	void InitializeSetOfElement()override;
	void SetGameField()override;
	void Launch()override;
	void SetToZero()override;
};

#endif TICTACTOE_LOGIC_H