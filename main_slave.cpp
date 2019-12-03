#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include "pruebaimpl.h"

int main(int argc, char **argv)
{
    pruebaImpl *pimpl = new pruebaImpl();
    pimpl->run();

    delete pimpl;
    return 0;

}
