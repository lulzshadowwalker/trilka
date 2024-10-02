#ifndef APPLICATION_EVENT_HPP
#define APPLICATION_EVENT_HPP

#include "Event.hpp"
#include <string>
#include <sstream>

namespace Trilka {
  class TRILKA_API WindowResizeEvent : public Event
  {
    public:
      WindowResizeEvent(unsigned int width, unsigned int height)
        : m_Width(width), m_Height(height) {} 

      inline int GetWidth() { return m_Width; }
      inline int GetHeight() { return m_Height; }

      inline std::string ToString() const override 
      {
        std::stringstream ss;
        ss << "WindowResizeEvent: " << m_Width << ", " << m_Height;
        return ss.str();
      }

    EVENT_CLASS_TYPE(WindowResize)
    EVENT_CLASS_CATEGORY(EventCategoryApplication)

    private:
      unsigned int m_Width;
      unsigned int m_Height;
  };

  class TRILKA_API WindowCloseEvent : public Event
  {
    public:
      WindowCloseEvent() {};

      EVENT_CLASS_TYPE(WindowClose)
      EVENT_CLASS_CATEGORY(EventCategoryApplication)
  };

  class TRILKA_API AppTickEvent : public Event
  {
    public:
      AppTickEvent() {}

      EVENT_CLASS_TYPE(AppTick)
      EVENT_CLASS_CATEGORY(EventCategoryApplication)
  };

  class TRILKA_API AppUpdateEvent : public Event
  {
    public:
      AppUpdateEvent() {}


      EVENT_CLASS_TYPE(AppUpdate)
      EVENT_CLASS_CATEGORY(EventCategoryApplication)
  };

  class TRILKA_API AppRenderEvent : public Event 
  {
    public:
      AppRenderEvent() {}

      EVENT_CLASS_TYPE(AppRender)
      EVENT_CLASS_CATEGORY(EventCategoryApplication)
  };
}

#endif // APPLICATION_EVENT_HPP
