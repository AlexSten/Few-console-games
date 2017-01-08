#include "CController.h"
#include "Display.h"

void CController::Controller()
{

	if (GetAsyncKeyState(VK_UP))
	{
		keybd_event(VK_UP, 0, KEYEVENTF_KEYUP, 0);
		ProcessingUP();
	}
	if (GetAsyncKeyState(VK_DOWN))
	{
		keybd_event(VK_DOWN, 0, KEYEVENTF_KEYUP, 0);
		ProcessingDOWN();
	}
	if (GetAsyncKeyState(VK_LEFT))
	{
		keybd_event(VK_LEFT, 0, KEYEVENTF_KEYUP, 0);
		ProcessingLEFT();
	}
	if (GetAsyncKeyState(VK_RIGHT))
	{
		keybd_event(VK_RIGHT, 0, KEYEVENTF_KEYUP, 0);
		ProcessingRIGHT();
	}
	if (GetAsyncKeyState(VK_ESCAPE))
	{
		keybd_event(VK_ESCAPE, 0, KEYEVENTF_KEYUP, 0);
		ProcessingESCAPE();
	}
	if (GetAsyncKeyState(VK_SPACE))
	{
		keybd_event(VK_SPACE, 0, KEYEVENTF_KEYUP, 0);
		ProcessingSPACE();
	}
	if (GetAsyncKeyState(VK_RETURN))
	{
		keybd_event(VK_RETURN, 0, KEYEVENTF_KEYUP, 0);
		ProcessingRETURN();
	}
}