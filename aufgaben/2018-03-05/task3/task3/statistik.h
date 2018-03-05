#pragma once

template<typename T>
class statistik
{
public:
    statistik<T>() :
        m_first(true),
        m_min(0), m_max(0), m_numberOfValues(0),
        m_sumOfValues(0), m_squareSumOfValues(0)
    {}

    void nextValue(const T value)
    {
        m_numberOfValues++;
        m_sumOfValues += value;
        m_squareSumOfValues += value * value;
        if (m_first)
        {
            m_min = value;
            m_max = value;
            m_first = false;
            return;
        }
        if (value < m_min)
            m_min = value;
        if (value > m_max)
            m_max = value;
    }

    const T get_min() { return m_min; }
    const T get_max() { return m_max; }
    const T calc_mean() { return (m_sumOfValues / m_numberOfValues); }
    const T calc_sampleVariance()
    {
        const T mean = calc_mean();
        return (calc_squaredMean() - mean * mean);
    }

private:
    bool m_first;
    T m_min;
    T m_max;
    T m_numberOfValues;
    T m_sumOfValues;
    T m_squareSumOfValues;

    const T calc_squaredMean() { return (m_squareSumOfValues / m_numberOfValues); }

};
