#include "pruebaimpl.h"
#include "pruebastub.h"

pruebaImpl::pruebaImpl()
{
    MPI_Manager::Init();
    this->parent = new MPI_Comm[1];
    // comunicación con el master
    MPI_Comm_get_parent(this->parent);

    this->pclase = new pruebaClase();
}

void pruebaImpl::run(){
//bucle infinito que espere el tipo de operacion
   bool salir = false;

 while(!salir){

       int op = -1;
       MPI_Status status;

       MPI_Recv(&op,1,MPI_INT,0,0,*(this->parent),&status);


    //dependiendo de operacion -> recibo para metros -> ejecuto operacion -> envio resultado
    switch (op){

    case EXT_HOLAMUNDO: {

            pclase->holaMundo();
            int ack = 1;
            MPI_Send(&ack,1,MPI_INT,0,0,*(this->parent));

        }break;

    case EXT_SUMA:{

            int *params = new int[2];
            MPI_Recv(params,2,MPI_INT,0,0,*(this->parent),&status);
            int result = pclase->suma(params[0],params[1]);

            MPI_Send(&result,1,MPI_INT,0,0,*(this->parent));

            delete[] params;
        }break;

    case EXT_EXIT:{
            salir = true;
    }break;

    default:{
       std::cout<<"Error SLAVE operacion no encontrada\n";
       }break;

    }//fin switch

   }//fin bucle

}//fin function

pruebaImpl::~pruebaImpl(){

   MPI_Manager::Finalize();
    delete pclase;
   delete[] this->parent;
}
