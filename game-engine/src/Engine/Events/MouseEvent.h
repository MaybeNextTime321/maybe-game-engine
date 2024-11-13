#pragma once

#include "Event.h"
#include <sstream>

namespace Maybe
{
    class MB_API MouseScrolledEvent : public Event
    {
      public:
        MouseScrolledEvent(int XOffset, int YOffset) : m_XOffset(XOffset), m_YOffset(YOffset)
        {
        }

        static EventType GetStaticType()
        {
            return EventType::MouseScrolled;
        }

        virtual EventType GetEventType() const override
        {
            return EventType::MouseScrolled;
        }

        EVENT_CLASS_GET_NAME(MouseScrolled)

        virtual int GetCategoryFlags() const override
        {
            return (int)EventType::MouseScrolled;
        }

        inline int GetXOffset() const
        {
            return m_XOffset;
        }

        inline int GetYOffset() const
        {
            return m_YOffset;
        }

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "Mouse Scrolled event (X: " << GetXOffset() << ", Y: " << GetYOffset() << " )";
            return ss.str();
        }

      private:
        int m_XOffset;
        int m_YOffset;
    };

    class MB_API MouseMovedEvent : public Event
    {
      public:
        MouseMovedEvent(int XPosition, int YPosition) : m_XPosition(XPosition), m_YPosition(YPosition)
        {
        }

        static EventType GetStaticType()
        {
            return EventType::MouseMoved;
        }

        virtual EventType GetEventType() const override
        {
            return EventType::MouseMoved;
        }

        EVENT_CLASS_GET_NAME(MouseMoved)

        virtual int GetCategoryFlags() const override
        {
            return (int)EventType::MouseMoved;
        }

        inline int GetX() const
        {
            return m_XPosition;
        }

        inline int GetY() const
        {
            return m_YPosition;
        }

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "Mouse Moved event (X: " << GetX() << ", Y: " << GetY() << " )";
            return ss.str();
        }

      private:
        int m_XPosition;
        int m_YPosition;
    };

    class MB_API MouseButtonEvent : public Event
    {
      public:
        static EventType GetStaticType()
        {
            return EventType::None;
        }

        virtual EventType GetEventType() const override
        {
            return EventType::None;
        }

        EVENT_CLASS_GET_NAME(None)

        virtual int GetCategoryFlags() const override
        {
            return (int)EventType::None;
        }

        inline int GetKey() const
        {
            return m_KeyCode;
        }

      protected:
        MouseButtonEvent(int KeyCode) : m_KeyCode(KeyCode)
        {
        }

        int m_KeyCode;
    };

    class MB_API MouseButtonPressedEvent : public MouseButtonEvent
    {
      public:
        static EventType GetStaticType()
        {
            return EventType::MouseButtonPressed;
        }

        virtual EventType GetEventType() const override
        {
            return EventType::MouseButtonPressed;
        }

        EVENT_CLASS_GET_NAME(MouseButtonPressed)

        virtual int GetCategoryFlags() const override
        {
            return (int)EventType::MouseButtonPressed;
        }

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "Mouse Button Pressend event (key " << GetKey() << " )";
            return ss.str();
        }

        MouseButtonPressedEvent(int KeyCode) : MouseButtonEvent(KeyCode)
        {
        }
    };

    class MB_API MouseButtonReleasedEvent : public MouseButtonEvent
    {
      public:
        static EventType GetStaticType()
        {
            return EventType::MouseButtonReleased;
        }

        virtual EventType GetEventType() const override
        {
            return EventType::MouseButtonReleased;
        }

        EVENT_CLASS_GET_NAME(MouseButtonReleased)

        virtual int GetCategoryFlags() const override
        {
            return (int)EventType::MouseButtonReleased;
        }

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "Mouse Button Released event (key " << GetKey() << " )";
            return ss.str();
        }

        MouseButtonReleasedEvent(int KeyCode) : MouseButtonEvent(KeyCode)
        {
        }
    };
} // namespace Maybe