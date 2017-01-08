#ifndef SNAKELOGIC_H
#define SNAKELOGIC_H
#include "GameLogic.h"
#include "SnakeMovement.h"
#include <utility>

class SnakeLogic : public GameLogic, SnakeMovement
{
private:
	std::pair<size_t, size_t> m_ActiveCell;
	size_t m_Delay = 400;
	bool m_bIsGameOver = false;
private:
	void SetDefaultColorForCell(std::pair<size_t, size_t>);
	void GenerateSnake();
	void LocateFood();
	void IlluminateSnake();
	void LightActiveCell();
	size_t GetCellsInRow()const override;
	size_t GetCellsInColumn()const override;
	size_t GetTypeOfCell(size_t _col, size_t _row)const override;

	void GameOver() override;
	void InitializeFieldSizes()override;
	void ProcessingUP()override;
	void ProcessingDOWN()override;
	void ProcessingLEFT()override;
	void ProcessingRIGHT()override;
	void ProcessingESCAPE()override;
	void ProcessingSPACE()override;
	void ProcessingRETURN()override;
public:
	SnakeLogic(GameController* _GC);
	~SnakeLogic() = default;

	void Launch() override;
	void InitializeSetOfElement()override;
	void SetGameField()override;
	void SetToZero() override;
};

#endif SNAKELOGIC_H