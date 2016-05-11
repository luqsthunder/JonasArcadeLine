#include "Ball.h"
#include <iostream>

#include <cmath>
#include <vector>

#include <glm/gtc/constants.hpp>

Ball::Ball(unsigned int radius, glm::vec2 position, size_t points) :
  _radius(radius), _pos(position), _points(points)
{
  glGenBuffers(1, &_vbo);
  glGenVertexArrays(1, &_vao);

  glBindVertexArray(_vao);
  glBindBuffer(GL_ARRAY_BUFFER, _vbo);

  std::vector<GLfloat> ballVertices;
  GLfloat domFunIt = -1.f;
  const GLfloat domParts = (std::abs(-1) + std::abs(1)) / ((GLfloat)points);
  // usando as equações y = sqrt(x(x - 1))
  // usando as equações y = -sqrt(x(x - 1))
  // para gerar o circulo
  position = glm::normalize(position);
  ballVertices.push_back(0.f);
  ballVertices.push_back(0.f);
  for(int ii = 0; ii < points; ii++)
  {
    float theta = 2.0f * 3.1415926f * float(ii) / float(points);//get the
    // current angle

    float x = 1 * std::cos(theta);//calculate the x component
    float y = 1 * std::sin(theta);//calculate the y component

    ballVertices.push_back(x);
    ballVertices.push_back(y);
  }

  /*int cont = 0;
  for(const auto& it : ballVertices)
  {
    std::cout << it << ((cont == 1) ? "\n" : " , ");
    cont = cont == 1 ? 0 : cont + 1;
  }*/

  glBufferData(GL_ARRAY_BUFFER,sizeof(GLfloat) * ballVertices.size(),
               &ballVertices[0], GL_STATIC_DRAW);
  glVertexAttribPointer(0,2 * sizeof(GLfloat), GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(0);
  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glBindVertexArray(0);
}



Ball::~Ball()
{
  glDeleteBuffers(1, &_vbo);
  glDeleteVertexArrays(1, &_vao);
}


void
Ball::draw() const
{
  glBindVertexArray(_vao);
  glDrawArrays(GL_TRIANGLE_FAN, 0, _points);
  glBindVertexArray(0);
}
