#include <iostream>
#include "matrix.h"


double identity[2][2] = {{1, 0},
                         {0, 1}};
const matrix IDENTITY(identity, "IDENTITY");

//////////////////////
//  Constructors    //
//////////////////////

matrix::matrix(){}

matrix::matrix(double aa, double ab, double ba, double bb,
        std::string name)
{
    m_name = name;
    double data[2][2] = {{aa, ab},
                             {ba, bb}};
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            m_data[i][j] = data[i][j];
}

matrix::matrix(double data[2][2], std::string name)
{
    m_name = name;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            m_data[i][j] = data[i][j];
}

matrix::matrix(double* data[2][2], std::string name)
{
    m_name = name;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            m_data[i][j] = *data[i][j];
}


//////////////////////////
//  Getter and Setter   //
//////////////////////////

void matrix::setValue(int a, int b, double value)
{
    m_data[a][b] = value;
}

double matrix::getValue(int a, int b) const
{
    return m_data[a][b];
}

void matrix::setName(std::string name)
{
    m_name = name;
}

std::string matrix::getName() const
{
    return this->m_name;
}


//////////////////////////
//  Public Methods      //
//////////////////////////

void matrix::printMatrix() const
{
    std::cout << m_name << " = ";
    for (int i = 0; i < 2; i++)
    {
        std::cout << "\t(";
        for (double val: m_data[i])
            std::cout << " " << val << " ";
        std::cout << ")\n";
    }
    std::cout << std::endl;
}

matrix matrix::copy() const
{
    matrix copy;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            copy.setValue(i, j, this->getValue(i, j));
    return copy;
}

matrix matrix::pow(int p) const
{
    if (p == 0)
        return IDENTITY;

    matrix resultMatrix;

    if (p < 0)
    {
        resultMatrix = this->invert();
        p = -p;
    }
    else
        resultMatrix = this->copy();

    matrix thisCopy = this->copy();
    resultMatrix.setName(this->m_name + "^" + std::to_string(p));
    if (p == 1)
        return resultMatrix;
    for (int i = 0; i < p; i++)
        resultMatrix *= thisCopy;
    return resultMatrix;
}

matrix matrix::invert() const
{
    double invData[2][2] = {{this->m_data[1][1], - this->m_data[0][1]},
                            {- this->m_data[1][0], this->m_data[0][0]}};
    matrix inverse(invData, this->m_name + "^-1");
    return inverse;
}

double matrix::det() const
{
    const double result = determinant();
    return result;
}

double matrix::determinant() const
{
    const double result = m_data[0][0] * m_data[1][1]
                        - m_data[0][1] * m_data[1][0];
    return result;
}


//////////////////
//  Operators   //
//////////////////

matrix matrix::operator=(matrix mat)
{
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            this->setValue(i, j, mat.getValue(i, j));
    return *this;
}

matrix matrix::operator=(double data[2][2])
{
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            this->setValue(i, j, data[i][j]);
    return *this;

}

void matrix::operator=(std::string name)
{
    setName(name);
}

bool matrix::operator==(matrix & mat) const
{
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            if (m_data[i][j] != mat.getValue(i, j))
                return false;
    return true;
}

matrix matrix::operator+(matrix & mat) const
{
    double result[2][2];
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            result[i][j] = this->m_data[i][j] + mat.getValue(i, j);
    matrix resultMatrix = matrix(result, "Result+");
    return resultMatrix;
}

matrix matrix::operator-(matrix & mat) const
{
    double result[2][2];
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            result[i][j] = this->m_data[i][j] - mat.getValue(i, j);
    matrix resultMatrix = matrix(result, "Result-");
    return resultMatrix;
}

matrix matrix::operator*(matrix & mat) const
{
    double result[2][2];
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            result[i][j] = this->m_data[i][j] * mat.getValue(i, j);
    matrix resultMatrix = matrix(result, "Result*");
    return resultMatrix;
}

matrix matrix::operator*(const double & lambda) const
{
    double result[2][2];
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            result[i][j] = this->m_data[i][j] * lambda;
    matrix resultMatrix = matrix(result, "Matrix*"+std::to_string(lambda));
    return resultMatrix;
}

void matrix::operator+=(matrix & mat)
{
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            this->m_data[i][j] += mat.getValue(i, j);
}

void matrix::operator-=(matrix & mat)
{
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            this->m_data[i][j] -= mat.getValue(i, j);
}

void matrix::operator*=(matrix & mat)
{
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            this->m_data[i][j] *= mat.getValue(i, j);
}

void matrix::operator*=(const double & lambda)
{
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            this->m_data[i][j] *= lambda;
}
