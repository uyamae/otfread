#include "otfread.h"
#include <iostream>

int main(int argc,char ** argv)
{
    if (argc < 2) {
        std::cout << "usage: " << std::endl;
        std::cout << "otfread otfname.otf" << std::endl;
        return 1;
    }

    otfread::readfile(argv[1]);


    //char data[8] = {0,1,2,3,4,5,6,7};
    //otfread::read(data, sizeof data);
}


