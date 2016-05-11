#include <epoxy/gl.h>
#include <epoxy/glx.h>

#include <iostream>

#include <SDL2/SDL.h>

#include <stdexcept>

#include "core/Ball.h"

int main()
{
  if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
    throw std::runtime_error("cant init sdl");

  SDL_Window* window = SDL_CreateWindow("jonas arcade", SDL_WINDOWPOS_CENTERED,
                                        SDL_WINDOWPOS_CENTERED, 800, 600,
                                        SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);

  SDL_Renderer *render = SDL_CreateRenderer(window, -1,
                                            SDL_RENDERER_ACCELERATED |
                                            SDL_RENDERER_PRESENTVSYNC);

  Ball ball{2, {2, 1}};

  bool gameRunning = true;
  SDL_Event event;
  while(gameRunning)
  {
    while(SDL_PollEvent(&event))
    {
      if((event.type == SDL_QUIT) ||
         (event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_ESCAPE))
        gameRunning = false;
    }
    SDL_RenderClear(render);

    SDL_RenderPresent(render);
  }

  return 0;
}
