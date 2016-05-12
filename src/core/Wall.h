#ifndef __JONAS_ARCADE_WALL_HH__
#define __JONAS_ARCADE_WALL_HH__

#include <SFML/Graphics.hpp>

#include "IShock.h"

class Wall: public sf::Drawable, public IShock
{
public:
  Wall(sf::Vector2f position, sf::Vector2f size);

  /// \brief seta posição
  void position(sf::Vector2f position);

  /// \biref retorna a posição
  const sf::Vector2f position() const;

  sf::FloatRect bounds() const;

  virtual void tellMe(IShock& other);
protected:
  void draw(sf::RenderTarget& target, sf::RenderStates state) const;

  sf::RectangleShape _shape;
};

#endif
