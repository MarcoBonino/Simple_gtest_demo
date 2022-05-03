//  Created by Marco Bonino on 22/10/2021.

#include <gtest/gtest.h>

int power(int base, int exp)
{
    int result = 1;
    for (; exp > 0; --exp)
        result = result * base;
    return result;
}

int powerFastImpl(int base, int exp)
{
    if (exp == 0)
        return 1;
    else if (exp == 1)
        return base;
    
    bool exp_odd = (exp % 2) == 1;
    int exp_half = exp / 2;
    int tmp = powerFastImpl(base, exp_half);
    int result = tmp * tmp;
    
    if (exp_odd)
        result = result * base;
    
    return result;
}

TEST(Power, linearImpl)
{
    ASSERT_EQ(power(3, 3), 27);
    ASSERT_EQ(power(2, 4), 16);
    ASSERT_EQ(power(2, 6), 64);
    ASSERT_EQ(power(20, 2), 400);
    ASSERT_EQ(power(20, 0), 1);
}

TEST(Power, lognImpl)
{
    ASSERT_EQ(powerFastImpl(3, 3), 27);
    ASSERT_EQ(powerFastImpl(2, 4), 16);
    ASSERT_EQ(powerFastImpl(2, 6), 64);
    ASSERT_EQ(powerFastImpl(20, 2), 400);
    ASSERT_EQ(powerFastImpl(20, 0), 1);
}

TEST(Power, cmpImpl)
{
    ASSERT_EQ(power(2, 30), powerFastImpl(2, 30));
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
