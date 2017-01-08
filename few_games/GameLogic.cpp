#include "GameLogic.h"
#include "GameController.h"


GameLogic::GameLogic(GameController* _GC) : m_pCGC(_GC)
{
}

size_t GameLogic::GetSizeOfCell()const
{
	return m_sizeOfCell;
}

size_t GameLogic::GetCellsInRow()const
{
	return m_cellsInRow;
}

size_t GameLogic::GetCellsInColumn()const
{
	return m_cellsInColumn;
}