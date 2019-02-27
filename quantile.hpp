// quantile.hpp

#include <memory>

class level {
private:
    int m_count;
    float m_soft_low;
    float m_soft_high;
    float m_min;
    float m_max;

public:
    level();

    bool try_set_soft_low(float x);
    bool try_set_soft_high(float x);

    void observe(float x);
};

class interval_tree {
private:
    int m_count_under;
    // null when there is no left child
    std::unique_ptr<interval_tree> m_left;
    std::unique_ptr<interval_tree> m_right;

public:
    interval_tree();
};
