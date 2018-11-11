/*******************************************************************************
GPU OPTIMIZED MONTE CARLO (GOMC) 2.31
Copyright (C) 2018  GOMC Group
A copy of the GNU General Public License can be found in the COPYRIGHT.txt
along with this program, also can be found at <http://www.gnu.org/licenses/>.
********************************************************************************/
#ifndef SIMULATION_H
#define SIMULATION_H

//Member vars
#include "CPUSide.h"
#include "System.h"
#include "StaticVals.h"
#include "BasicTypes.h"
#include <dirent.h>

class Simulation
{
public:
  explicit Simulation(char const*const configFileName);
  ~Simulation();

  void RunSimulation(void);

#ifndef NDEBUG
  void RunningCheck(const uint step);
#endif

private:
  StaticVals * staticValues;
  System * system;
  CPUSide * cpu;
  ulong totalSteps;
  ReplicaExchangeParameters replExParams;
  DIR* replica_directory = NULL;
  std::stringstream directory_stream;
  std::string directory_name;
  std::stringstream path_stream;
  std::string path_string;
  
};

#endif /*SIMULATION_H*/