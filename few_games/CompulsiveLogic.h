#ifndef COMPULSIVELOGIC_H
#define COMPULSIVELOGIC_H
#include "GameLogic.h"

class CompulsiveLogic : public GameLogic
{
private:
	enum Colors {
		Black,
		Red,
		Green,
		Blue,
		LRed,
		LGreen,
		LBlue,
		Brown,
		Magenta,
		Cyan,
		Yellow,
		LMagenta,
		LCyan
	};
	bool m_Won = false;
	size_t m_BorderSize;
	size_t m_BorderShift;
	Colors m_eCurrentColor;
	Colors m_eChoosenColor;
	size_t m_StartCell;
private:
	void GameOver()override;
	void InitializeFieldSizes()override;
	void ProcessingUP()override;
	void ProcessingDOWN()override;
	void ProcessingLEFT()override;
	void ProcessingRIGHT()override;
	void ProcessingESCAPE()override;
	void ProcessingSPACE()override;
	void ProcessingRETURN()override;

	void SetChoosenColor();
	void ChangeCellColor(size_t _cell);
	bool IsHaveCurrentColor(size_t _cell);
	bool IsGameOver();
public:
	CompulsiveLogic(GameController* _GC);
	~CompulsiveLogic() = default;

	void Launch() override;
	void InitializeSetOfElement()override;
	void SetGameField()override;
	void SetToZero() override;

	friend Colors operator++(Colors& _clr);
	friend Colors operator--(Colors& _clr);
};

#endif COMPULSIVELOGIC_H