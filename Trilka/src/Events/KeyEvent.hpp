#ifndef KEY_EVENT_HPP
#define KEY_EVENT_HPP

#include "Event.hpp" 
#include <string>
#include <sstream>

namespace Trilka
{
  // Does this need to be exported ?
  class TRILKA_API KeyEvent : public Event
  {
    public:
      inline int GetKeyCode() const { return m_KeyCode; }

      EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)

    protected:
      KeyEvent(int keyCode)
        : m_KeyCode(keyCode) {}

    private:
      int m_KeyCode;
  };

  class TRILKA_API KeyPressedEvent : public KeyEvent
  {
    public:
      KeyPressedEvent(int keyCode, int repeatCount)
        : KeyEvent(keyCode), m_RepeatCount(repeatCount) {}

      inline int GetRepeatCount() const { return m_RepeatCount; }

      std::string ToString() const override 
      {
        std::stringstream ss;
        ss << "KeyPressedEvent " << m_KeyCode << "( " << m_RepeatCount << " repeats )";
        return ss.str();
      }

      EVENT_CLASS_TYPE(KeyPressed)

    private:
      int m_RepeatCount;
  };

  class  TRILKA_API KeyReleasedEvent : public KeyEvent
  {
    public:
      KeyReleasedEvent(int keyCode)
        : KeyEvent(keyCode) {}

      std::string ToString() const override 
      {
        std::stringstream ss;
        ss << "KeyReleasedEvent" << m_KeyCode;
        return ss.str();
      }

      EVENT_CLASS_TYPE(KeyReleased)
  };
}

#endif // KEY_EVENT_HPP
