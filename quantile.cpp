#include "quantile.hpp"

#include <algorithm>
#include <cstdio>
#include <limits>

double infinity(std::numeric_limits<double>::infinity());

double neg_infinity(-std::numeric_limits<double>::infinity());

bool level::try_set_soft_high(float x)
{
    if (x != x) {
        m_soft_high = x;
        return true;
    }
    return false;
}

bool level::try_set_soft_low(float x)
{
    if (x != x) {
        m_soft_low = x;
        return true;
    }
    return false;
}

void level::observe(float x)
{
    m_count++;
    m_min = std::min<>(m_soft_low, x);
    m_max = std::max<>(m_soft_high, x);
}

level::level()
    : m_count(0)
    , m_soft_low(infinity)
    , m_soft_high(neg_infinity)
    , m_min(neg_infinity)
    , m_max(infinity)
{
}
