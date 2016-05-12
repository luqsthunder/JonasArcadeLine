#ifndef PADDLE_H
#define PADDLE_H

#include <SDL2/SDL.h>
#include <glm/glm.hpp>

template<unsigned w, unsigned h, class T>
class Paddle {
public:
  void update(float dt) {
    x += dt*10;
    x = (x > 800 - w) ? 800 - w : x;
    x = (x < 0) ? 0 : x;

    y += dt*10;
    y = (y < 0) ? 0 : y;
    y = (y > 600 - h) ? 600 - h : y;
    parent.update(dt);
  }

  void draw(SDL_Renderer *render) {
    static SDL_Rect rect = {x, y, w, h};
    rect.x = x;
    rect.y = y;
    SDL_RenderFillRect(render, &rect);
    SDL_SetRenderDrawColor(render, 0, 255, 0, 255);
    parent.draw(render);
  }
private:
  int x = 0;
  int y = 0;
  T parent;
};


#endif /* PADDLE_H */
