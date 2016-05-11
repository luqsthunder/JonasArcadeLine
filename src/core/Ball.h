#ifndef JONASARCADEPROJECT_BALL_H
#define JONASARCADEPROJECT_BALL_H

#include <epoxy/gl.h>
#include <epoxy/glx.h>

#include <cstdio>
#include <glm/glm.hpp>

class Ball
{
public:
  Ball(unsigned int radius, glm::vec2 position, size_t points = 30);
  ~Ball();

  void move(glm::vec2 offset);
  void position(glm::vec2 offset);

  void draw() const;


protected:
  glm::vec2 _pos;
  GLuint _vbo, _vao;
  GLfloat _radius;
  size_t _points;
};


#endif //JONASARCADEPROJECT_BALL_H
