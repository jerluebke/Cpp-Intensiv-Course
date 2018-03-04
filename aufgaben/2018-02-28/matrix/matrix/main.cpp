#include <iostream>
#include <vector>
#include "matrix.h"


int main()
{
    // matrix A(2, 3, 1, 4, "A");
    // double b_data[2][2] = {{0, 1}, {1, 0}};
    // matrix B(b_data, "B");
    // matrix C(5, 2, 1, 5, "C");
    // double d_data[2][2] = {{2, 1}, {5, 3}};
    // matrix D(d_data, "D");
    // 
    // std::vector<matrix> matrices = {A, B, C, D};
    // 
    // for (matrix m: matrices)
    // {
    //     m.printMatrix();
    //     matrix m_pow_2 = m.pow(2);
    //     matrix m_pow_1001 = m.pow(1001);
    //     m_pow_2.printMatrix();
    //     m_pow_1001.printMatrix();
    //     matrix m_inv = m.invert();
    //     m_inv.printMatrix();
    //     double det_m = m.determinant();
    //     std::cout << "Determinante von " << m.getName() << ": " << det_m << std::endl;
    //     std::cout << "\n" << std::endl;
    // }
    // std::cout << "\n" << std::endl;
    // 
    // matrix E = A + B;
    // E.setName("A+B");
    // matrix F = C * D;
    // F.setName("C*D");
    // matrix G = B * 23.41;
    // G.setName("B*23.41");
    // matrix H = D * .21;
    // H.setName("D*.21");
    // std::vector<matrix> newMatrices = {E, F, G, H};
    // for (matrix m: newMatrices)
    //     m.printMatrix();
    // 
    // matrix K = C;
    // matrix L = A;
    // std::cout << "K == C?  " << (K == C) << std::endl;
    // std::cout << "L == A?  " << (L == A) << std::endl;
    // 
    // std::cout << "\n" << std::endl;
    // A.printMatrix();
    // C.printMatrix();
    // A += C;
    // std::cout << "A+=C" << std::endl;
    // A.printMatrix();
    // D.printMatrix();
    // B.printMatrix();
    // D *= B;
    // std::cout << "D*=B" << std::endl;
    // D.printMatrix();
    // C.printMatrix();
    // C -= D;
    // std::cout << "C-=D" << std::endl;
    // C.printMatrix();
    // B.printMatrix();
    // B *= 6.237;
    // std::cout << "B*=6.237" << std::endl;
    // B.printMatrix();
    // 
    // 
    // 


    matrix a(-1, 1, 2, 3);
    matrix b(5, -8, 13, -21);
    int exp = 7;
    a.printMatrix();
    b.printMatrix();
    matrix a_p_b = a + b;
    a_p_b.setName("a+b");
    a_p_b.printMatrix();
    matrix a_minus_b = a - b;
    a_minus_b.setName("a-b");
    a_minus_b.printMatrix();
    matrix a_mul_b = a*b;
    a_mul_b.setName("a*b");
    a_mul_b.printMatrix();
    matrix a_mul_2 = a*2;
    a_mul_2.printMatrix();
    matrix c = a;
    c.printMatrix();
    std::cout << "\n a+=b: \n";
    c+=b;
    c.printMatrix();
    matrix d = a;
    d.printMatrix();
    std::cout << "\n a*=b: \n";
    d.printMatrix();
    std::cout << "a==a?" << (a==a) << "\n";
    std::cout << "a==b?" << (a==b) << "\n";
    matrix a_inv = a.invert();
    a_inv.setName("a^-1");
    a_inv.printMatrix();
    matrix b_inv = b.invert();
    b_inv.printMatrix();
    matrix a_e7 = a.pow(exp);
    a_e7.setName("a^7");
    a_e7.printMatrix();
    double det_a = d.det();
    std::cout << "det a = " << det_a << "\n";
    double det_b = b.det();
    std::cout << "det b = " << det_b << "\n";


    matrix E2(1, 0, 0, 1);
    E2.setName("E2");
    E2.printMatrix();
    matrix a_mul_e = a*E2;
    a_mul_e.printMatrix();

}
