#pragma once

#include <Windows.h>
#include <Xinput.h> // include the Xinput API
#pragma comment( lib, "xinput" ) // Link in the xinput.lib static library

class Vector2;

enum class XboxButton
{
	DUP,
	DDOWN,
	DLEFT,
	DRIGHT,
	A,
	B,
	X,
	Y,
	LB,
	RB,
	LT,
	RT,
	START,
	BACK,
	HOME,
	numXboxButtons
};


class XInputController
{
public:
	XInputController();
	XInputController(int controllerNumber);
	void Update(float deltaTime);
	bool IsPressed(XboxButton button);
	bool JustPressed(XboxButton button);
	bool IsConnected();
	int GetControllerNumber();
	Vector2 GetLeftStickPosition();
	Vector2 GetRightStickPosition();
	unsigned char GetLeftTrigger();
	unsigned char GetRightTrigger();
	void Vibrate(int leftMotorVibration, int rightMotorVibration);
	void VibrateForSeconds(float seconds, int leftMotorVibration, int rightMotorVibration);

	static const int MAX_CONTROLLERS = 4;

	static const int MAX_VIBRATE = 65535;
	static const int LARGE_VIBRATE = 48000;
	static const int MEDIUM_VIBRATE = 32000;
	static const int LOW_VIBRATE = 16000;
	static const int EXTREMELY_LOW_VIBRATE = 8000;
	static const int NO_VIBRATE = 0;

private:

	static const int INVALID_CONTROLLER_NUMBER = -1;

	bool IsPressed(XINPUT_STATE &state, XboxButton button);
	Vector2 CalculateNormalizedStickPosition(float x, float y);
	XINPUT_STATE m_state;
	XINPUT_STATE m_previousState;
	int m_controllerNumber;
	bool m_isConnected;
	float m_secondsToVibrate;
};