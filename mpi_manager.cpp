#include "mpi_manager.h"

std::vector<MPI_Comm*> MPI_Manager::comms;
bool MPI_Manager::init = false;

MPI_Manager::MPI_Manager()
{

}

void MPI_Manager::Init()
{
    if(!MPI_Manager::init)
    {
        init = true;
        int argc = 0;
        char **argv=nullptr;
        MPI_Init(&argc, &argv);
        MPI_Manager::init = true;
    }
}

void MPI_Manager::Finalize()
{
    if(MPI_Manager::init)
    {
        MPI_Finalize();
        MPI_Manager::init = false;
    }
}

MPI_Comm* MPI_Manager::instanciate(char *processName)
{
    MPI_Comm *newComm = new MPI_Comm[1];
    MPI_Info info;
    MPI_Info_create(&info);
    
    // Caso 1: PRoceso es pruebaclase, se ejecutará en la maquina que contiene la implementación de pruebaclase.
    if(strcmp(processName,"rpc_pruebaclase") == 0)
    {
        MPI_Info_set(info, "host", "ip-172-31-43-51");
        //MPI_Info_set(info, "server1", "localhost");
printf("SERVER: 1\n");
    }
    // Caso 2: Proceso es remotefile, " " " "
    else if(strcmp(processName,"rpc_remotefile") == 0)
    {
        MPI_Info_set(info, "host", "ip-172-31-95-184");
printf("SERVER: 2\n");
        //MPI_Info_set(info, "server2", "localhost");
    }
    // crear un nuevo proceso en nuestra red -> crea una subred y se accede a ella con newComm
        MPI_Comm_spawn(processName,MPI_ARGV_NULL,1,info,0,MPI_COMM_SELF,newComm,MPI_ERRCODES_IGNORE);

        comms.push_back(newComm);

        return newComm;
}
