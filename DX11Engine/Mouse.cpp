#include "Mouse.h"

void Mouse::OnLeftPressed(int x, int y)
{
	m_leftIsDown = true;
	MouseEvent me(MouseEvent::EventType::LPress, x, y);
	m_eventBuffer.push(me);
}

void Mouse::OnLeftReleased(int x, int y)
{
	m_leftIsDown = false;
	m_eventBuffer.push(MouseEvent(MouseEvent::EventType::LRelease, x, y));
}

void Mouse::OnRightPressed(int x, int y)
{
	m_rightIsDown = true;
	m_eventBuffer.push(MouseEvent(MouseEvent::EventType::RPress, x, y));
}

void Mouse::OnRightReleased(int x, int y)
{
	m_rightIsDown = false;
	m_eventBuffer.push(MouseEvent(MouseEvent::EventType::RRelease, x, y));
}

void Mouse::OnMiddlePressed(int x, int y)
{
	m_mbuttonDown = true;
	m_eventBuffer.push(MouseEvent(MouseEvent::EventType::MPress, x, y));
}

void Mouse::OnMiddleReleased(int x, int y)
{
	m_mbuttonDown = false;
	m_eventBuffer.push(MouseEvent(MouseEvent::EventType::MRelease, x, y));
}

void Mouse::OnWheelUp(int x, int y)
{
	m_eventBuffer.push(MouseEvent(MouseEvent::EventType::WheelUp, x, y));
}

void Mouse::OnWheelDown(int x, int y)
{
	m_eventBuffer.push(MouseEvent(MouseEvent::EventType::WheelDown, x, y));
}

void Mouse::OnMouseMove(int x, int y)
{
	m_x = x;
	m_y = y;
	m_eventBuffer.push(MouseEvent(MouseEvent::EventType::Move, x, y));
}

void Mouse::OnMouseMoveRaw(int x, int y)
{
	m_eventBuffer.push(MouseEvent(MouseEvent::EventType::RAW_MOVE, x, y));
}

bool Mouse::IsLeftDown()
{
	return m_leftIsDown;
}

bool Mouse::IsMiddleDown()
{
	return m_mbuttonDown;
}

bool Mouse::IsRightDown()
{
	return m_rightIsDown;
}

int Mouse::GetPosX()
{
	return m_x;
}

int Mouse::GetPosY()
{
	return m_y;
}

MousePoint Mouse::GetPos()
{
	return{ m_x, m_y };
}

bool Mouse::EventBufferIsEmpty()
{
	return m_eventBuffer.empty();
}

MouseEvent Mouse::ReadEvent()
{
	if (m_eventBuffer.empty())
	{
		return MouseEvent();
	}
	else
	{
		MouseEvent e = m_eventBuffer.front(); //Get first event from buffer
		m_eventBuffer.pop(); //Remove first event from buffer
		return e;
	}
}