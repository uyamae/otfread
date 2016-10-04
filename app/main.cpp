#include "otfread.h"

int main(int,char**)
{
    char data[8] = {0,1,2,3,4,5,6,7};
    otfread::read(data, sizeof data);
}


