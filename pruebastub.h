// interfaz de objetos remotos -> solo pertenece al cliente
#ifndef PRUEBASTUB_H
#define PRUEBASTUB_H

#define EXT_HOLAMUNDO 1
#define EXT_SUMA 2
#define EXT_EXIT 0

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <openmpi/mpi.h>
#include "mpi_manager.h"

class pruebaStub{

    MPI_Comm *comm;

public:
    pruebaStub();
    ~pruebaStub();
    void holaMundo();
    int suma(int a, int b);
};

#endif // PRUEBASTUB_H
