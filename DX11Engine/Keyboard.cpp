#include "Keyboard.h"

Keyboard::Keyboard()
{
	for (int i = 0; i < 256; i++)
		m_keyStates[i] = false; //Initialize all key states to off (false)
}

bool Keyboard::KeyIsPressed(const unsigned char keycode)
{
	return m_keyStates[keycode];
}

bool Keyboard::KeyBufferIsEmpty()
{
	return m_keyBuffer.empty();
}

bool Keyboard::CharBufferIsEmpty()
{
	return m_charBuffer.empty();
}

KeyboardEvent Keyboard::ReadKey()
{
	if (m_keyBuffer.empty()) //If no keys to be read?
	{
		return KeyboardEvent(); //return empty keyboard event
	}
	else
	{
		KeyboardEvent e = m_keyBuffer.front(); //Get first Keyboard Event from queue
		m_keyBuffer.pop(); //Remove first item from queue
		return e; //Returns keyboard event
	}
}

unsigned char Keyboard::ReadChar()
{
	if (m_charBuffer.empty()) //If no keys to be read?
	{
		return 0u; //return 0 (NULL char)
	}
	else
	{
		unsigned char e = m_charBuffer.front(); //Get first char from queue
		m_charBuffer.pop(); //Remove first char from queue
		return e; //Returns char
	}
}

void Keyboard::OnKeyPressed(const unsigned char key)
{
	m_keyStates[key] = true;
	m_keyBuffer.push(KeyboardEvent(KeyboardEvent::EventType::Press, key));
}

void Keyboard::OnKeyReleased(const unsigned char key)
{
	m_keyStates[key] = false;
	m_keyBuffer.push(KeyboardEvent(KeyboardEvent::EventType::Release, key));
}

void Keyboard::OnChar(const unsigned char key)
{
	m_charBuffer.push(key);
}

void Keyboard::EnableAutoRepeatKeys()
{
	m_autoRepeatKeys = true;
}

void Keyboard::DisableAutoRepeatKeys()
{
	m_autoRepeatKeys = false;
}

void Keyboard::EnableAutoRepeatChars()
{
	m_autoRepeatChars = true;
}

void Keyboard::DisableAutoRepeatChars()
{
	m_autoRepeatChars = false;
}

bool Keyboard::IsKeysAutoRepeat()
{
	return m_autoRepeatKeys;
}

bool Keyboard::IsCharsAutoRepeat()
{
	return m_autoRepeatChars;
}