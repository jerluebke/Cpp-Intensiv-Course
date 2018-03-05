#include "statistik.h"
#include <iostream>
#include <cstdlib>

int main()
{
    const int I[] = { 5, -5, 2, 6, -4, 8 };
    const double D[] = { 5.5, -5.3, 2.7, 6.9, -4.1, 8.2 };
    statistik<int> S;
    statistik<double> T;

    std::cout << "Integer:\n";
    for (int i : I)
    {
        S.nextValue(i);
        std::cout << "Minumum: " << S.get_min() << "\n";
        std::cout << "Maximum: " << S.get_max() << "\n";
        std::cout << "Mittelwert: " << S.calc_mean() << "\n";
        std::cout << "Varianz-Schätzung: " << S.calc_sampleVariance() << "\n\n";
    }
    std::cout << "\n";
    std::cout << "Double:\n";
    or (double d : D)
    {
        T.nextValue(d);
        std::cout << "Minumum: " << T.get_min() << "\n";
        std::cout << "Maximum: " << T.get_max() << "\n";
        std::cout << "Mittelwert: " << T.calc_mean() << "\n";
        std::cout << "Varianz-Tchätzung: " << T.calc_sampleVariance() << "\n\n";
    }

	system("pause");

	return 0;
}


