#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "remotefile_imp.h"

int main()
{
        remotefile_imp *rfile = new remotefile_imp();
        rfile->run();
        delete rfile;
}
