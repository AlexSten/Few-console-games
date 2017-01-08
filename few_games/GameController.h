#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H
#include <map>
#include "Display.h"
#include "CController.h"
class GameLogic;

class GameController :public CController
{
private:
	enum class Games {
		Snake,
		TicTacToe,
		Compulsive
	};
	Games m_eCurrentGame;
	bool m_bExit = false;

	size_t m_sizeOfCell;
	size_t m_cellsInRow;
	size_t m_cellsInColumn;
	size_t m_gameFieldSize;

	std::map<Games, GameLogic*> m_MapOfLogics;

	virtual void ProcessingUP()override;
	virtual void ProcessingDOWN()override;
	virtual void ProcessingLEFT()override;
	virtual void ProcessingRIGHT()override;
	virtual void ProcessingESCAPE()override;
	virtual void ProcessingSPACE()override;
	virtual void ProcessingRETURN()override;
public:
	size_t* m_GameField = nullptr;

	mutable Display m_CDisplay;
public:
	GameController();
	~GameController() = default;

	void MainLoop();
	void RefreshScreen()const;
	void SetCellOfGamefield(size_t _col, size_t _row, size_t _type);
	size_t GetTypeOfCell(size_t _col, size_t _row)const;
private:
	void SetSizes();
	void GenerateArrayGameField();
	void LaunchGame();
	void ShowMenu()const;
	void Initialization();
	void Deinitialization();

	friend Games operator++(Games& _val);
	friend Games operator--(Games& _val);
};

#endif GAMECONTROLLER_H