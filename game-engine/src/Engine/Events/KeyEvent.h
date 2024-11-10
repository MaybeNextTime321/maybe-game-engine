#pragma once

#include "Event.h"
#include <sstream>

namespace Maybe
{
	class MB_API KeyEvent : public Event
	{
	public:
		KeyEvent(int KeyCode) : m_KeyCode(KeyCode) {}
		
		static EventType GetStaticType() { return EventType::None; }
		virtual EventType GetEventType() const override { return EventType::None; }
		EVENT_CLASS_GET_NAME(None)
		virtual int GetCategoryFlags() const override { return (int)EventCategory::EventCategoryKeyboard; }
	
		inline int GetKeyCode()const { return m_KeyCode; }

	protected:
		int m_KeyCode;
	};

	class MB_API KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(int KeyCode, int RepeatCount): KeyEvent(KeyCode), m_RepeatCount(RepeatCount){}
		

		static EventType GetStaticType() { return EventType::KeyPressed; }
		virtual EventType GetEventType() const override { return EventType::KeyPressed; }
		EVENT_CLASS_GET_NAME(EventType::KeyPressed)
		virtual int GetCategoryFlags() const override { return (int)EventCategory::EventCategoryKeyboard; }

		
		inline int GetRepeatCount()const { return m_RepeatCount; }
		
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "Key pressed event " << m_KeyCode << " (" << m_RepeatCount << " repeats)";

			return ss.str();
		}

	private:
		int m_RepeatCount;
	};

	class MB_API KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(int KeyCode) : KeyEvent(KeyCode){}

		static EventType GetStaticType() { return EventType::KeyReleased; }
		virtual EventType GetEventType() const override { return EventType::KeyReleased; }
		EVENT_CLASS_GET_NAME(KeyReleased)
		virtual int GetCategoryFlags() const override { return (int)EventType::KeyReleased; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "Key release event " << m_KeyCode;

			return ss.str();
		}

	};
}