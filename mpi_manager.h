#ifndef MPI_MANAGER_H
#define MPI_MANAGER_H
#include <vector>
#include "openmpi/mpi.h"

class MPI_Manager
{
    static bool init;
    // se almacenarán todos los comunicadores en este vector
    static std::vector<MPI_Comm*> comms;

public:
    MPI_Manager();
    static void Init();
    static void Finalize();
    static MPI_Comm* instanciate(char *processName);
};

#endif // MPI_MANAGER_H
