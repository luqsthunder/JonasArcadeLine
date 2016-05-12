#ifndef JONASARCADEPROJECT_PADDLE_H
#define JONASARCADEPROJECT_PADDLE_H

#include <SFML/Graphics.hpp>

#include "core/IShock.h"

/// \brief Classe para paddles como do pong ou brick game
/// so lembrando que a origem do paddle é o meio nao o primeiro vertice
class Paddle : public sf::Drawable, public IShock
{
public:
  Paddle(sf::Vector2f position, sf::Vector2f size);


  /// \brief move o paddle seguindo sua orientação;
  /// \param x positivo direita(vertical) ou baixo(horizontal), negativo
  ///          sequentemente esquerda e cima (vertical, horizontal)
  void move(float x);

  /// \brief seta posição
  void position(sf::Vector2f position);
  const sf::Vector2f position() const;

  sf::FloatRect bounds() const;

  virtual void tellMe(IShock& other);

protected:
  void draw(sf::RenderTarget& target, sf::RenderStates state) const;

  sf::RectangleShape _shape;
  bool _horizontal;
};


#endif //JONASARCADEPROJECT_PADDLE_H
