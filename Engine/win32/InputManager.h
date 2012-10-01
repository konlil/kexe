/*
 * InputMananger.h
 * written by konlil
 *
 */

const UINT MaxKeyCount = 256;

enum MouseButtonType
{
	MouseButtonLeft,
	MouseButtonRight,
	MouseButtonCenter,
	MouseButtonCount
};

enum InputEventType
{
	InputEventMenu,
	InputEventToolbar0,
	InputEventCount
};

struct InputEvent
{
	InputEvent() {}
	InputEvent(InputEventType t, UINT id)
	{
		Type = t;
		Id = id;
	}
	InputEventType Type;
	UINT Id;
};

struct MouseState
{
	Vec2i Pos;
	int Wheel;
	bool Buttons[MouseButtonCount];
};


class InputManager
{
public:
	InputManager();
};
