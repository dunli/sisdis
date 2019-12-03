#include "pruebastub.h"

pruebaStub::pruebaStub()
{
        MPI_Manager::Init();
        // en remoto se adapta al host
        this->comm = MPI_Manager::instanciate("rpc_pruebaclase");
}

pruebaStub::~pruebaStub()
{

    int op = EXT_EXIT;
    MPI_Send(&op,1,MPI_INT,0,0,*(this->comm));
}

void pruebaStub::holaMundo()
{
// enviar peticion de ejecucion holaMundo
   int op= EXT_HOLAMUNDO;
    MPI_Send(&op,1,MPI_INT,0,0,*(this->comm));

//sincronización --> recibo ack
    int ack = 0;
    MPI_Status status;
    MPI_Recv(&ack,1,MPI_INT,0,0,*(this->comm),&status);
    if(ack != 1)
        std::cout<<"Error Master HOLAMUNDO\n";
}

int pruebaStub::suma(int a, int b)
{
//enviar peticion de ejecucion suma
    int result = 0;
    int op = EXT_SUMA;
    MPI_Send(&op,1,MPI_INT,0,0,*(this->comm));


//enviar parametros
    MPI_Status status;
    int *params = new int[2];
    params[0] = a;
    params[1] = b;
    MPI_Send(params,2,MPI_INT,0,0,*(this->comm));

// esperar resultado
    MPI_Recv(&result,1,MPI_INT,0,0,*(this->comm),&status);

    delete[] params;

    return result;
}
