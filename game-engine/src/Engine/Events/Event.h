#pragma once

#include "Core.h"
#include "mbpch.h"

enum class EventType
{
    None = 0,
    WindowClose,
    WindowResize,
    WindowLoseFocus,
    WindowMoved,
    AppTick,
    AppUpdate,
    AppRender,
    KeyPressed,
    KeyReleased,
    MouseButtonPressed,
    MouseButtonReleased,
    MouseMoved,
    MouseScrolled
};

enum class EventCategory
{
    None = 0,
    EventCategoryApplication = BIT(0),
    EventCategoryInput = BIT(1),
    EventCategoryKeyboard = BIT(2),
    EventCategoryMouse = BIT(3),
    EventCategoryMouseButton = BIT(4)
};

#define EVENT_CLASS_GET_NAME(EnumValue)                                                                                \
    virtual const char *GetName() const override                                                                       \
    {                                                                                                                  \
        return #EnumValue;                                                                                             \
    }

class MB_API Event
{
    friend class EventManager;

  public:
    static EventType GetStaticType()
    {
        return EventType::None;
    }

    virtual EventType GetEventType() const = 0;
    virtual const char *GetName() const = 0;
    virtual int GetCategoryFlags() const = 0;

    virtual std::string ToString() const
    {
        return GetName();
    }

    virtual ~Event(){};

    inline bool IsInCategory(EventCategory category)
    {
        return (GetCategoryFlags() & (int)category);
    }

  protected:
    bool m_Handled = false;
};

class MB_API EventManager
{
    template <typename T> using EventFn = std::function<bool(T &)>;

  public:
    EventManager(Event &event) : m_Event(event)
    {
    }

    template <typename T> bool Manage(EventFn<T> func)
    {
        if (m_Event.GetEventType() == T::GetStaticType())
        {
            /*
            1. func(*(T*)&m_Event) -> func(*(T*) Event* m_Event)
            2. func(*(T*) Event* m_Event) -> func(*(T* m_Event))
            3. func(*(T* m_Event)) -> func(T& m_Event)
            */
            m_Event.m_Handled = func(*(T *)&m_Event);
        }
    }

  private:
    Event &m_Event;
};