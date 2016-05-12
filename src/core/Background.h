#ifndef JONASARCADEPROJECT_BACKGROUND_H
#define JONASARCADEPROJECT_BACKGROUND_H

#include <SFML/Graphics.hpp>

#include <string>

class Background : public sf::Drawable
{
public:
  Background(std::string path);

protected:
  void draw(sf::RenderTarget& target, sf::RenderStates states) const;
  sf::RectangleShape _bkgShape;
  sf::Texture _bkg;
};


#endif //JONASARCADEPROJECT_BACKGROUND_H
