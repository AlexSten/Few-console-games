#ifndef GAMELOGIC_H
#define GAMELOGIC_H
#include "CController.h"
#include "Random.h"
class GameController;

class GameLogic :public CController, virtual public Random
{
protected:
	size_t m_sizeOfCell;
	size_t m_cellsInRow;
	size_t m_cellsInColumn;
	size_t m_gameFieldSize;

	bool m_bExit = false;

	GameController* m_pCGC;
protected:
	virtual void InitializeFieldSizes() = 0;
	virtual void GameOver() = 0;
public:
	GameLogic(GameController* _GC);
	virtual ~GameLogic() = default;

	virtual void Launch() = 0;
	virtual void InitializeSetOfElement() = 0;
	virtual void SetGameField() = 0;
	virtual void SetToZero() = 0;

	size_t GetSizeOfCell()const;
	size_t GetCellsInRow()const;
	size_t GetCellsInColumn()const;
};

#endif GAMELOGIC_H