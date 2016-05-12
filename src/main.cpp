#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <stdexcept>

#include "Ball.h"
#include "Background.h"

int main()
{
  sf::RenderWindow window({800, 600}, "Jonas Arcade Line", sf::Style::Close);
  sf::Event event;

  Ball ball{5, {400, 300}};
  Background background{"Content/SpaceBackground.jpg"};

  while(window.isOpen())
  {
    while(window.pollEvent(event))
    {
      if(event.type == sf::Event::Closed or
        (event.type == sf::Event::KeyReleased and event.key.code ==
                                                  sf::Keyboard::Escape))
        window.close();
    }
    window.clear();

    window.draw(background);
    window.draw(ball);

    window.display();
  }

  return 0;
}
