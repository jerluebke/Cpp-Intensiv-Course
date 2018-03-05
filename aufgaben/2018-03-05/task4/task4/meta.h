#pragma once

// Berechnung nur mit den Faktoren n und k
template <const int n, const int k>
class FallendeFaktorielle_2
{
    public:
        static const int val = FallendeFaktorielle_2<n-1, k-1>::val * n;
};

template <const int n>
class FallendeFaktorielle_2<n, 0>
{
    public:
        static const int val = 1;
};


// Fakultaetsfunktion
template <const int n>
class Fakultaet
{
    public:
        static const int val = Fakultaet<n-1>::val * n;
};

template <>
class Fakultaet<1>
{
    public:
        static const int val = 1;
};

// Berechnung mit der Fakultaetsfunktion
template <const int n, const int k>
class FallendeFaktorielle_1
{
    public:
        static const int val = (Fakultaet<n>::val) / (Fakultaet<n-k>::val);
};
