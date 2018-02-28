#include <string>

#ifndef MATRIX_H
#define MATRIX_H

// TODO:
// operator*= for int

class matrix
{
    private:
        std::string m_name;
        double m_data[2][2];


    public:
        matrix();
        matrix(double aa, double ab, double ba, double bb,
                std::string name="Matrix");
        matrix(double data[2][2],
                std::string name="Matrix");
        matrix(double* data[2][2],
                std::string name="Matrix");
        // ~matrix();

        void setValue(int a, int b, double value);
        double getValue(int a, int b) const;
        void setName(std::string name);
        std::string getName() const;

        void printMatrix() const;
        matrix copy() const;
        matrix pow(int p) const;
        matrix invert() const;
        double determinant() const;
        double det() const;

        matrix operator=(matrix mat);
        matrix operator=(double data[2][2]);
        void operator=(std::string name);
        bool operator==(matrix & mat) const;

        matrix operator+(matrix & mat) const;
        matrix operator-(matrix & mat) const;
        matrix operator*(matrix & mat) const;
        matrix operator*(const double & lambda) const;

        void operator+=(matrix & mat);
        void operator-=(matrix & mat);
        void operator*=(matrix & mat);
        void operator*=(const double & lambda);

};

#endif
