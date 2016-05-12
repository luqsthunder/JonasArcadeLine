#include "Background.h"

Background::Background(std::string path)
{
  _bkg.loadFromFile(path);
  _bkgShape.setSize({(float)_bkg.getSize().x, (float)_bkg.getSize().y});
  _bkgShape.setOrigin(_bkgShape.getSize() / 2.f);
  _bkgShape.setTexture(&_bkg, true);
  _bkgShape.setPosition(400, 300);
}

void
Background::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
  target.draw(_bkgShape, states);
}