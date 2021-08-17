#include "DrawingController.h"

int main(int argc, char *argv[])
{
    CDrawingController Drawings;

    if (argc == 2)
    {
        Drawings.run(argv[1]);
    }
    else
    {
        Drawings.run();
    }
    return 0;
}
