#include "remotefile.h"
#include <stdio.h>
#include <stdlib.h>



remotefile::remotefile()
{

}


void remotefile::readfile(char *filename, char **buff, unsigned long int *buffleng){

    FILE* fin = fopen(filename, "r");
    if(fin ==NULL){

        *buff = NULL;
        *buffleng = 0;
    }

    else{
        unsigned long int flen = 0;
         //posicionarse al final del fichero
        fseek(fin,0,SEEK_END);
        //averiguar posicion
        flen = ftell(fin);
	
	flen+=1;
         *buff = new char[flen];
         // leer el contenido
         fread(*buff,1,flen-1,fin);

         *buffleng = flen;
         (*buff)[flen-1] ='\0';

         fclose(fin);
    }

}
