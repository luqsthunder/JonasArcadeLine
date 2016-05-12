#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <stdexcept>

#include "core/Ball.h"
#include "core/Background.h"

#include "pong/PongGame.h"

int main()
{
  GameLoop* game = new PongGame;
  game->run();
  delete game;

  return 0;
}
