#ifndef JONASARCADEPROJECT_ISHOCK_H
#define JONASARCADEPROJECT_ISHOCK_H

#include <SFML/Graphics.hpp>

#include <functional>

class IShock
{
public:
  virtual sf::FloatRect bounds() const = 0;

  void checkChock(IShock& other);

  virtual void tellMe(IShock& other) = 0;
};

#endif //JONASARCADEPROJECT_ISHOCK_H
