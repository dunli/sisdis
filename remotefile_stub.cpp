#include "remotefile_stub.h"

remotefile_stub::remotefile_stub()
{
    MPI_Manager::Init();
    // en remoto se adapta al host
    this->comm = MPI_Manager::instanciate("rpc_remotefile");
}

remotefile_stub::~remotefile_stub()
{

    int op = EXT_EXIT;
    MPI_Send(&op,1,MPI_INT,0,0,*(this->comm));
}



void remotefile_stub::readfile(char *filename, char **buff, unsigned long int *buffleng)
{
        std::cout<<"filename in stub: "<<filename<<std::endl;
        *buff = NULL;
        *buffleng = 0;
    // enviar tipo de operacion
        MPI_Status status;
        int op = EXT_READFILE;
        MPI_Send(&op,1,MPI_INT,0,0,*(this->comm));
    // enviar parametros
        unsigned long int filenameleng = strlen(filename)+1;
        MPI_Send(&filenameleng, 1, MPI_LONG, 0, 0, *(this->comm));
        MPI_Send(filename, (int)filenameleng, MPI_CHAR, 0, 0, *(this->comm));

    // esperar resultado
        //recibir tamaño
        MPI_Recv(buffleng, 1, MPI_LONG, 0, 0, *(this->comm), &status);
        // reservar buffer
        *buff = new char[*buffleng];
        // recibir buffer
        MPI_Recv(*buff, *buffleng, MPI_CHAR,0,0, *(this->comm), &status);
}
