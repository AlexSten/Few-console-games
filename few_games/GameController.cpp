#include "GameController.h"
#include <iostream>
#include "SnakeLogic.h"
#include "TicTacToeLogic.h"
#include "CompulsiveLogic.h"
// If you want to add a new game, you have to put changes into:
// header in Enumeration; CPP in GameController() ,ShowMenu(), operator++, operator--

GameController::GameController()
	: m_CDisplay(this)
{
	m_eCurrentGame = Games::Snake;
	m_MapOfLogics.insert(std::pair <Games, GameLogic*>(Games::Snake, new SnakeLogic(this)));
	m_MapOfLogics.insert(std::pair <Games, GameLogic*>(Games::TicTacToe, new TicTacToeLogic(this)));
	m_MapOfLogics.insert(std::pair <Games, GameLogic*>(Games::Compulsive, new CompulsiveLogic(this)));
}

void GameController::MainLoop()
{
	ShowMenu();
	while (!m_bExit)
	{
		Controller();
	}
}

void GameController::RefreshScreen()const
{
	m_CDisplay.InitializeDisplayField();
	m_CDisplay.DisplayYourself();
}

void GameController::SetCellOfGamefield(size_t _col, size_t _row, size_t _type)
{
	size_t numbOfCell = _col + _row*m_cellsInRow;
	m_GameField[numbOfCell] = _type;
}

size_t GameController::GetTypeOfCell(size_t _col, size_t _row)const
{
	return m_GameField[(_col + _row*m_cellsInRow)];
}

void GameController::SetSizes()
{
	m_sizeOfCell = m_MapOfLogics.at(m_eCurrentGame)->GetSizeOfCell();
	m_cellsInRow = m_MapOfLogics.at(m_eCurrentGame)->GetCellsInRow();
	m_cellsInColumn = m_MapOfLogics.at(m_eCurrentGame)->GetCellsInColumn();
	m_gameFieldSize = m_cellsInRow * m_cellsInColumn;
}

void GameController::GenerateArrayGameField()
{
	m_GameField = new size_t[m_gameFieldSize];
}

void GameController::LaunchGame()
{
	m_MapOfLogics.at(m_eCurrentGame)->Launch();
	Deinitialization();
}

void GameController::ShowMenu()const
{
	system("CLS");
	switch (m_eCurrentGame)
	{
	case Games::Snake:
		std::cout << "Snake";
		break;
	case Games::TicTacToe:
		std::cout << "TicTacToe";
		break;
	case Games::Compulsive:
		std::cout << "Compulsive";
		break;
	default:
		break;
	}
}

void GameController::Initialization()
{
	SetSizes();
	GenerateArrayGameField();
	m_MapOfLogics.at(m_eCurrentGame)->SetGameField();
	m_MapOfLogics.at(m_eCurrentGame)->InitializeSetOfElement();
	m_CDisplay.SetSizesOfField(m_sizeOfCell, m_cellsInRow, m_cellsInColumn);
	m_CDisplay.GenerateArrayForDisplay();
	m_CDisplay.Initializing();
	m_CDisplay.InitializeDisplayField();
}

void GameController::Deinitialization()
{
	delete[] m_GameField;
	m_CDisplay.CleanseYourself();
	m_MapOfLogics.at(m_eCurrentGame)->SetToZero();
}

void GameController::ProcessingUP()
{
	++m_eCurrentGame;
	ShowMenu();
}

void GameController::ProcessingDOWN()
{
	--m_eCurrentGame;
	ShowMenu();
}

void GameController::ProcessingLEFT()
{
	++m_eCurrentGame;
	ShowMenu();
}

void GameController::ProcessingRIGHT()
{
	--m_eCurrentGame;
	ShowMenu();
}

void GameController::ProcessingESCAPE()
{
	m_bExit = true;
}

void GameController::ProcessingSPACE()
{
	Initialization();
	system("CLS");
	LaunchGame();
	ShowMenu();
}

void GameController::ProcessingRETURN()
{
	ProcessingSPACE();
}


GameController::Games operator++(GameController::Games& _val)
{
	if (_val == GameController::Games::Compulsive)
		_val = GameController::Games::Snake;
	else
		_val = static_cast<GameController::Games>(static_cast<int>(_val) + 1);
	return _val;
}

GameController::Games operator--(GameController::Games& _val)
{
	if (_val == GameController::Games::Snake)
		_val = GameController::Games::Compulsive;
	else
		_val = static_cast<GameController::Games>(static_cast<int>(_val) - 1);
	return _val;
}