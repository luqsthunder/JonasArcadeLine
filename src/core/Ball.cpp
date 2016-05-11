#include "Ball.h"
#include <iostream>

#include <cmath>
#include <vector>

Ball::Ball(unsigned int radius, glm::vec2 position, size_t points)
{
  glGenBuffers(1, &_vbo);
  glGenVertexArrays(1, &_vao);

  glBindVertexArray(_vao);
  glBindBuffer(GL_ARRAY_BUFFER, _vbo);

  std::vector<GLfloat> ballVertices, firstVertices, lastVertices;
  GLfloat domFunIt = -1.f;
  const GLfloat domParts = (std::abs(-1) + std::abs(1)) / ((GLfloat)points);
  // usando as equações y = sqrt(x(x - 1))
  // usando as equações y = -sqrt(x(x - 1))
  // para gerar o circulo
  position = glm::normalize(position);
  for(size_t x = 0; x < points / 2; ++x)
  {
    firstVertices.push_back(x);
    firstVertices.push_back(std::sqrt(-1 * std::pow(domFunIt, 2) - 1));

    lastVertices.push_back(domFunIt);
    lastVertices.push_back(-1* std::sqrt(-(std::pow(domFunIt, 2) - 1)));

    domFunIt += domParts;
  }
  ballVertices.insert(ballVertices.begin(), firstVertices.begin(),
                      firstVertices.end());
  ballVertices.insert(ballVertices.end(), lastVertices.begin(),
                      lastVertices.end());

  int cont = 0;
  for(const auto& it : ballVertices)
  {
    std::cout << it << (cont == 3 ? "," : "\n");
    cont = cont == 3 ? cont + 1 : 0;
  }

  /*glBufferData(GL_ARRAY_BUFFER,sizeof(GLfloat) * ballVertices.size(),
               &ballVertices[0], GL_STATIC_DRAW);
  glVertexArrayAttribPointer()*/
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
  //glDrawArrays(GL_TRIANGLE_STRIP,);
  glBindVertexArray(0);
}
