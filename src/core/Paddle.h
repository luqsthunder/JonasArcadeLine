#ifndef JONASARCADEPROJECT_PADDLE_H
#define JONASARCADEPROJECT_PADDLE_H

#include <epoxy/gl.h>
#include <epoxy/glx.h>

#include <glm/glm.hpp>

class Paddle
{
public:
  enum class Orientation : bool
  {
    Vertical = false,
    Horizontal = true
  };

  Paddle(Orientation orient, glm::vec2 position);


  /// \brief move o paddle seguindo sua orientação;
  /// \param x positivo direita(vertical) ou baixo(horizontal), negativo
  ///          sequentemente esquerda e cima (vertical, horizontal)
  void move(GLfloat x);

  /// \brief seta posição
  void position(glm::vec2 position);
};


#endif //JONASARCADEPROJECT_PADDLE_H
