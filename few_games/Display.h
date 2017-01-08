#ifndef DISPLAY_H
#define DISPLAY_H
#include <Windows.h>
#include <string>
#include <map>
class GameController;

class Display
{
	const GameController* m_pGC;

	CHAR_INFO *m_ArrayForDisplay = nullptr;
	std::map<int, CHAR_INFO*> m_pTypesOfElement;

	HANDLE m_hStdOut;
	COORD m_size;
	COORD m_coord;
	SMALL_RECT m_sr;

	size_t m_sizeOfCell;
	size_t m_cellsInRow;
	size_t m_cellsInColumn;
	size_t m_gameFieldSize; // m_cellsInRow*m_cellsInColumn;
	size_t m_arraySize;		// m_gameFieldSize*m_sizeOfCell*m_sizeOfCell;
private:
	void HideCursor()const;
	void DrawGameElemnt(size_t _cellNumber, size_t _typeOfFigure);
public:
	Display(const GameController* _GC);
	~Display() = default;

	void Initializing();
	void CleanseYourself();
	void SetSizesOfField(size_t _sizeOfCell, size_t _cellsInRow, size_t _cellsInColumn);
	void GenerateArrayForDisplay();
	void InitializeDisplayField();
	void DisplayYourself();
	void AddTypeOfElement(size_t _number, CHAR_INFO*& _element);
};
#endif DISPLAY_H
