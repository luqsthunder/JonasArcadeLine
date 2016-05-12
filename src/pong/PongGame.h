#ifndef JONASARCADEPROJECT_PONGGAME_H
#define JONASARCADEPROJECT_PONGGAME_H

#include "core/GameLoop.h"
#include "WallPong.h"
#include "BallPong.h"
#include "core/Background.h"
#include "PaddlePong.h"
#include "core/ShockSolver.h"

class PongGame : public GameLoop
{
public:
  PongGame();
  virtual ~PongGame();

protected:
  virtual void initialize();
  virtual void loadContent();
  virtual void update();
  virtual void events(sf::Event& evts);
  virtual void draw(sf::RenderWindow& wnd);

  BallPong ball;
  WallPong wallLeft,wallRight, wallUp, wallDown;
  PaddlePong left, right;
  Background bkg;

  ShockSolver solver;
};


#endif //JONASARCADEPROJECT_PONGGAME_H
