#include "GameLoop.h"

GameLoop::~GameLoop() { }

void GameLoop::run()
{
  exitGame = false;
  initialize();
  loadContent();

  sf::RenderWindow window({800, 600}, "Jonas Arcade Line", sf::Style::Close);
  window.setFramerateLimit(30);
  sf::Event event;
  window.setKeyRepeatEnabled(true);

  while(not exitGame)
  {
    while(window.pollEvent(event))
    {
      events(event);
    }
    update();

    window.clear();

    draw(window);

    window.display();
  }
}

void GameLoop::initialize() { }

void GameLoop::loadContent() { }

void GameLoop::update() { }

void GameLoop::events(sf::Event &evts) { }

void GameLoop::draw(sf::RenderWindow &wnd) { }
