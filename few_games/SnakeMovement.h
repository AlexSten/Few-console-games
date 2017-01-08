#ifndef SNAKEMOVEMENT_H
#define SNAKEMOVEMENT_H
#include <deque>

class SnakeMovement
{
protected:
	enum Direction
	{
		top,
		right,
		down,
		left
	};
	enum Colors {
		White = 1,
		Grey,
		LGreen,
		LRed,
		LBlue,
		Green
	};
	Direction m_Direction;
	std::deque<std::pair<size_t, size_t>> m_SnakeArray;
protected:
	void Movement();
	void InitializeCoorForMovementUp(size_t& _x, size_t& _y);
	void InitializeCoorForMovementRight(size_t& _x, size_t& _y);
	void InitializeCoorForMovementDown(size_t& _x, size_t& _y);
	void InitializeCoorForMovementLeft(size_t& _x, size_t& _y);

	virtual size_t GetTypeOfCell(size_t _col, size_t _row)const = 0;
	virtual void GameOver() = 0;
	virtual void SetDefaultColorForCell(std::pair<size_t, size_t>) = 0;
	virtual void LocateFood() = 0;
	virtual void LightActiveCell() = 0;
	virtual size_t GetCellsInRow()const = 0;
	virtual size_t GetCellsInColumn()const = 0;
public:
	virtual ~SnakeMovement() = default;
};

#endif SNAKEMOVEMENT_H