#include "meta.h"
// #include "../../../common_repo/aufgaben/util.h"
#include <iostream>

int main()
{
    // const int n = static_cast<const int>(arg_to_int(argv[1]));
    // const int k = static_cast<const int>(arg_to_int(argv[2]));

    const int n = 5;
    const int k = 4;

    std::cout << "Teil 1:\n";
    std::cout << "Fallende Faktorielle von " << n << " und " << k << ": ";
    std::cout << FallendeFaktorielle_1<n, k>::val << std::endl;

    std::cout << "\nTeil 2:\n";
    std::cout << "Fallende Faktorielle von " << n << " und " << k << ": ";
    std::cout << FallendeFaktorielle_2<n, k>::val << std::endl;
    return 0;
}
