#ifndef JONASARCADEPROJECT_SHOCKSOLVER_H
#define JONASARCADEPROJECT_SHOCKSOLVER_H

#include <vector>
#include <memory>

#include "core/IShock.h"

class ShockSolver
{
public:
  ShockSolver();

  void update();
  void add(IShock* add);
protected:
  std::vector<std::shared_ptr<IShock>> objs;
};


#endif //JONASARCADEPROJECT_SHOCKSOLVER_H
