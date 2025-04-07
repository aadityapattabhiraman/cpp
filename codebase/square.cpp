#include "square.h"

int get_square_sides()
{
    return 4;
}

int get_square_perimeter(int side_length)
{
    return side_length * get_square_sides();
}
