#include <cassert>
#include <cmath>
#include <iostream>
#include <string>

#include <fintech_library.h>

using namespace std;


int main() {
    const double calculatedPrice01 = std::round(
        PriceEuropeanOption(
            /*type=*/Call,
            /*method=*/BS,
            /*expiry_time=*/ 2,
            /*period_number=*/ 8,
            /*volatility=*/ 0.30,
            /*continuous_rf_rate=*/ 0.02,
            /*initial_share_price=*/ 100,
            /*strike_price=*/ 105
        ) * 100.0) / 100;
    assert(calculatedPrice01 == 16.44);
    cout << "The calculated price for a Call with the BS method is: " << calculatedPrice01 << endl;

    const double calculatedPrice02 = std::round(
        PriceEuropeanOption(
            /*type=*/Put,
            /*method=*/Binomial,
            /*expiry_time=*/ 2,
            /*period_number=*/ 8,
            /*volatility=*/ 0.30,
            /*continuous_rf_rate=*/ 0.02,
            /*initial_share_price=*/ 100,
            /*strike_price=*/ 105
        ) * 100.0) / 100;
    assert(calculatedPrice02 == 17.35);
    cout << "The calculated price for a Put with the Binomial method is: " << calculatedPrice02 << endl;
    
    const double market_price = 30.95;
    const double impliedVolatiliy = std::round(
        CalculateBSImpliedVolatility(
            /*option_market_price=*/market_price,
            /*type=*/Call,
            /*expiry_time=*/ 0.5,
            /*continuous_rf_rate=*/ 0.0427,
            /*strike_price=*/ 210,
            /*initial_share_price=*/ 227.5
        ) * 100.0) / 100;
    assert(impliedVolatiliy == 0.29);
    cout << "The implied volatily for a Call with market price " << market_price << " is: " << impliedVolatiliy << endl;

    return 0;
}
