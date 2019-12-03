#ifndef REMOTEFILE_STUB_H
#define REMOTEFILE_STUB_H

#define EXT_READFILE 1
#define EXT_EXIT 0

#include "mpi_manager.h"
#include <string.h>

class remotefile_stub
{
     MPI_Comm *comm;
public:

    remotefile_stub();
    ~remotefile_stub();

    void readfile(char*, char**, unsigned long int*);

};

#endif // REMOTEFILE_STUB_H
