#include "ShockSolver.h"

ShockSolver::ShockSolver()
{ }

void ShockSolver::update()
{
  for( auto it1: objs)
  {
    for( auto it2 : objs)
    {
      if(it1 != it2)
        it1->checkChock(*it2);
    }
  }
}

void ShockSolver::add(IShock *add)
{
  objs.push_back({add, [](IShock*){}});
}
