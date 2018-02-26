#include "prim_stuff.h"

int main(int argc, char** argv)
{
    int m = check_input(argc, argv);
    if (m == -1)
        return -1;
    unsigned n = m;
    print_prim_factors(n, false);
    return 0;
}
