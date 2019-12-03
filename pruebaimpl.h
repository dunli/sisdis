#ifndef PRUEBAIMPL_H
#define PRUEBAIMPL_H
#include "pruebaclase.h"
#include "openmpi/mpi.h"

class pruebaImpl
{
    pruebaClase *pclase=0x00;
    MPI_Comm *parent;

public:
    pruebaImpl();
    ~pruebaImpl();
    void run();
};

#endif // PRUEBAIMPL_H
