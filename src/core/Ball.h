#ifndef JONASARCADEPROJECT_BALL_H
#define JONASARCADEPROJECT_BALL_H

#include <cstdio>
#include <SFML/System.hpp>
#include <SFML/Graphics/CircleShape.hpp>

#include "IShock.h"

class Ball : public sf::Drawable, public IShock
{
public:
  Ball(unsigned int radius, sf::Vector2f pos, size_t points = 30);

  virtual void update();

  void position(sf::Vector2f pos);
  const sf::Vector2f position() const;

  void move(sf::Vector2f offset);

  virtual void tellMe(IShock& other);
  sf::FloatRect bounds() const;
protected:
  void draw(sf::RenderTarget& target, sf::RenderStates state) const;

  sf::CircleShape _circle;
};


#endif //JONASARCADEPROJECT_BALL_H
