#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <stdexcept>

#include "core/Ball.h"
#include "core/Background.h"

#include "pong/PongLoop.h"

int main()
{
  GameLoop* game = new PongLoop;
  game->run();
  delete game;

  return 0;
}
