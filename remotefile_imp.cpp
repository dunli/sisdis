#include "remotefile_imp.h"
#include "remotefile_stub.h"



remotefile_imp::remotefile_imp(){

    MPI_Manager::Init();
    this->parent = new MPI_Comm[1];
    // comunicación con el master
    MPI_Comm_get_parent(this->parent);

    this->rfile = new remotefile();
}

void remotefile_imp::run(){
//bucle infinito que espere el tipo de operacion
   bool salir = false;

 while(!salir){

       int op = -1;
       MPI_Status status;

       MPI_Recv(&op,1,MPI_INT,0,0,*(this->parent),&status);


    //dependiendo de operacion -> recibo para metros -> ejecuto operacion -> envio resultado
    switch (op){

    case EXT_READFILE:{

        //recibir tamaño del nombre del archivo
            unsigned long int filenameLen = 0;
            MPI_Recv(&filenameLen, 1, MPI_LONG, 0, 0, *(this->parent), &status);

            char *filename = new char[filenameLen];
        // recibir el archivo
            MPI_Recv(filename, filenameLen, MPI_CHAR, 0,0, *(this->parent), &status);
            char *buff = NULL;
            unsigned long int bufflen = 0;
            rfile->readfile(filename, &buff, &bufflen);

       // enviar buffer
            MPI_Send(&bufflen, 1, MPI_LONG, 0, 0, *(this->parent));
            MPI_Send(buff, bufflen, MPI_CHAR, 0, 0, *(this->parent));

            delete[] filename;
            delete[] buff;

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

remotefile_imp::~remotefile_imp(){

   MPI_Manager::Finalize();
    delete rfile;
   delete[] this->parent;
}
