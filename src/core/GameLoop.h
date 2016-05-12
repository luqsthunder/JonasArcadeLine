#ifndef JONASARCADEPROJECT_GAMELOOP_HH
#define JONASARCADEPROJECT_GAMELOOP_HH


class GameLoop
{
public:
  virtual ~GameLoop() = 0;

  void run();

protected:
  void initialize();
  virtual void loadContent() = 0;
  virtual void update() = 0;
  virtual void events(sf::Event& evts) = 0;
  virtual void draw(sf::Window& wnd);
};


#endif //JONASARCADEPROJECT_GAMELOOP_HH
