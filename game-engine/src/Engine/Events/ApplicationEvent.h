#pragma once

#include "Event.h"
#include <sstream>

namespace Maybe
{

    class MB_API WindowResizeEvent : public Event
    {

      public:
        WindowResizeEvent(int Width, int Height) : m_Width(Width), m_Height(Height)
        {
        }

        static EventType GetStaticType()
        {
            return EventType::WindowResize;
        }

        virtual EventType GetEventType() const override
        {
            return EventType::WindowResize;
        }

        EVENT_CLASS_GET_NAME(WindowResize)

        virtual int GetCategoryFlags() const override
        {
            return (int)EventType::WindowResize;
        }

        inline int GetWidth() const
        {
            return m_Width;
        }

        inline int GetHeight() const
        {
            return m_Height;
        }

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "Widndow resize Event (Width: " << GetWidth() << ", Height: " << GetHeight() << " )";
            return ss.str();
        }

      private:
        int m_Width;
        int m_Height;
    };

    class MB_API WindowCloseEvent : public Event
    {
      public:
        WindowCloseEvent()
        {
        }

        static EventType GetStaticType()
        {
            return EventType::WindowClose;
        }

        virtual EventType GetEventType() const override
        {
            return EventType::WindowClose;
        }

        EVENT_CLASS_GET_NAME(WindowClose)

        virtual int GetCategoryFlags() const override
        {
            return (int)EventType::WindowClose;
        }
    };

    class MB_API AppTickEvent : public Event
    {
      public:
        AppTickEvent()
        {
        }

        static EventType GetStaticType()
        {
            return EventType::AppTick;
        }

        virtual EventType GetEventType() const override
        {
            return EventType::AppTick;
        }

        EVENT_CLASS_GET_NAME(AppTick)

        virtual int GetCategoryFlags() const override
        {
            return (int)EventType::AppTick;
        }
    };

    class MB_API AppUpdateEvent : public Event
    {
      public:
        AppUpdateEvent()
        {
        }

        static EventType GetStaticType()
        {
            return EventType::AppUpdate;
        }

        virtual EventType GetEventType() const override
        {
            return EventType::AppUpdate;
        }

        EVENT_CLASS_GET_NAME(AppUpdate)

        virtual int GetCategoryFlags() const override
        {
            return (int)EventType::AppUpdate;
        }
    };

    class MB_API AppRenderEvent : public Event
    {
      public:
        AppRenderEvent()
        {
        }

        static EventType GetStaticType()
        {
            return EventType::AppRender;
        }

        virtual EventType GetEventType() const override
        {
            return EventType::AppRender;
        }

        EVENT_CLASS_GET_NAME(AppRender)

        virtual int GetCategoryFlags() const override
        {
            return (int)EventType::AppRender;
        }
    };

} // namespace Maybe