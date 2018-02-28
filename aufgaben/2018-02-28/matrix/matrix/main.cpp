#include <iostream>
#include <vector>
#include "matrix.h"


int main()
{
    matrix A(2, 3, 1, 4, "A");
    double b_data[2][2] = {{0, 1}, {1, 0}};
    matrix B(b_data, "B");
    matrix C(5, 2, 1, 5, "C");
    double d_data[2][2] = {{2, 1}, {5, 3}};
    matrix D(d_data, "D");

    std::vector<matrix> matrices = {A, B, C, D};

    for (matrix m: matrices)
    {
        m.printMatrix();
        matrix m_pow_2 = m.pow(2);
        matrix m_pow_1001 = m.pow(1001);
        m_pow_2.printMatrix();
        m_pow_1001.printMatrix();
        matrix m_inv = m.invert();
        m_inv.printMatrix();
        double det_m = m.determinant();
        std::cout << "Determinante von " << m.getName() << ": " << det_m << std::endl;
        std::cout << "\n" << std::endl;
    }
    std::cout << "\n" << std::endl;

    matrix E = A + B;
    E.setName("A+B");
    matrix F = C * D;
    F.setName("C*D");
    matrix G = B * 23.41;
    G.setName("B*23.41");
    matrix H = D * .21;
    H.setName("D*.21");
    std::vector<matrix> newMatrices = {E, F, G, H};
    for (matrix m: newMatrices)
        m.printMatrix();

    matrix K = C;
    matrix L = A;
    std::cout << "K == C?  " << (K == C) << std::endl;
    std::cout << "L == A?  " << (L == A) << std::endl;

    std::cout << "\n" << std::endl;
    A.printMatrix();
    C.printMatrix();
    A += C;
    std::cout << "A+=C" << std::endl;
    A.printMatrix();
    D.printMatrix();
    B.printMatrix();
    D *= B;
    std::cout << "D*=B" << std::endl;
    D.printMatrix();
    C.printMatrix();
    C -= D;
    std::cout << "C-=D" << std::endl;
    C.printMatrix();
    B.printMatrix();
    B *= 6.237;
    std::cout << "B*=6.237" << std::endl;
    B.printMatrix();

}
