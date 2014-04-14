#include "euler.hpp"
#include <iostream>
#include <iterator>

using namespace std;

int main(int, char**)
{
    auto p = euler::primes(1000);
    for (auto i = 10000; i < 13000; ++i) {
        auto t = euler::triangle(i);
        auto f = euler::factors(t,p);
        auto d = 1;
        for (auto j = f.cbegin(); j != f.cend(); ++j) {
            d *= (j->second + 1);
        }
        if (d >= 500) {
            cout << i << ',' << t << ',' << d << endl;
            break;
        }
    }
    return 0;
}
