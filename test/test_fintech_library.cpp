#include <gtest/gtest.h>
#include <fintech_library.h>
#include <cmath>

TEST(EuropeanOptionTest, BlackScholesCall) {
    double price = PriceEuropeanOption(Call, BS, 2, 8, 0.30, 0.02, 100, 105);
    price = std::round(price * 100.0) / 100.0;
    EXPECT_DOUBLE_EQ(price, 16.44);
}

TEST(EuropeanOptionTest, BinomialPut) {
    double price = PriceEuropeanOption(Put, Binomial, 2, 8, 0.30, 0.02, 100, 105);
    price = std::round(price * 100.0) / 100.0;
    EXPECT_DOUBLE_EQ(price, 17.35);
}

TEST(ImpliedVolatilityTest, BlackScholesCall) {
    double impliedVol = CalculateBSImpliedVolatility(
        30.95, Call, 0.5, 0.0427, 210, 227.5);
    impliedVol = std::round(impliedVol * 100.0) / 100.0;
    EXPECT_DOUBLE_EQ(impliedVol, 0.29);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
