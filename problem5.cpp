#include "euler.hpp"
#include <algorithm>
#include <iterator>
#include <iostream>

using namespace std;

// 2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
// What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
int main(int, char**)
{
    auto p = euler::primes(20);
    decltype(euler::factors(1,p)) o;
    for (auto i = 2; i <= 20; ++i) {
        auto f = euler::factors(i,p);
        for (auto j = f.cbegin(); j != f.cend(); ++j) {
            o[j->first] = max(o[j->first],j->second);
        }
    }
    int k = 1;
    for (auto i = o.cbegin(); i != o.cend(); ++i) {
        int n = i->first;
        for (auto j = i->second; j > 1; --j) {
            n *= i->first;
        }
        k *= n;
    }
    cout << k << endl;
    return 0;
}
