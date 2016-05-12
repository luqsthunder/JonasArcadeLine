#include "ShockSolver.h"

ShockSolver::ShockSolver()
{ }

void ShockSolver::update()
{
  for(size_t i = 0; i < objs.size(); ++i)
  {
    for(size_t ii = i + 1; ii < objs.size(); ++ii)
    {
      objs[i]->checkChock(*objs[ii]);
    }
  }
}

void ShockSolver::add(IShock *add)
{
  objs.push_back({add, [](IShock*){}});
}
