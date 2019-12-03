#ifndef REMOTEFILE_IMP_H
#define REMOTEFILE_IMP_H
#include "remotefile.h"
#include "mpi_manager.h"
#include "openmpi/mpi.h"

class remotefile_imp
{
    remotefile *rfile= nullptr;
    MPI_Comm *parent;

public:
    remotefile_imp();
    ~remotefile_imp();
    void run();

};

#endif // REMOTEFILE_IMP_H
