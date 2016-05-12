#include "PongGame.h"

#include <iostream>

#include <SFML/Graphics.hpp>

PongGame::PongGame() : ball(26, {400, 300}) , wallLeft({15,300}, {30, 600}),
                       wallRight({800 - 15, 300}, {30, 600}),
                       wallUp({400, 15}, {800,30}),
                       wallDown({400, 600-15}, {800, 30}),
                       bkg("Content/SpaceBackground.jpg"),
                       left(sf::Vector2f{42, 300}, sf::Vector2f{20, 80}),
                       right(sf::Vector2f{800-42, 300}, sf::Vector2f{20, 80})
{
}

PongGame::~PongGame()
{}

void PongGame::initialize()
{
  solver.add(&ball);
  solver.add(&wallLeft);
  solver.add(&wallRight);
  solver.add(&wallUp);
  solver.add(&wallDown);
  solver.add(&left);
  solver.add(&right);
}

void PongGame::loadContent() { }

void PongGame::update()
{
  ball.update();
  solver.update();
}

void PongGame::events(sf::Event &evts)
{
  if(evts.type == sf::Event::Closed)
    exitGame = true;

  if(evts.type == sf::Event::KeyPressed)
  {
    switch (evts.key.code)
    {
      case sf::Keyboard::W:
        left.move(-2);
        break;
      case sf::Keyboard::S:
        left.move(2);
        break;

      case sf::Keyboard::Up:
        right.move(-2);
        break;
      case sf::Keyboard::Down:
        right.move(2);
        break;

      default:
        break;
    }
  }

}

void PongGame::draw(sf::RenderWindow &wnd)
{
  wnd.draw(bkg);
  wnd.draw(wallLeft);
  wnd.draw(wallRight);
  wnd.draw(wallUp);
  wnd.draw(wallDown);

  wnd.draw(left);
  wnd.draw(right);
  wnd.draw(ball);

}
