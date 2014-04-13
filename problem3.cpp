#include <math.h>
#include <stdint.h>
#include <errno.h>
#include "euler.hpp"
#include <algorithm>
#include <iterator>
#include <iostream>

using namespace std;

// The prime factors of 13195 are 5, 7, 13 and 29.
// What is the largest prime factor of the number 600851475143;
int main(int argc, char **argv)
{
    const uint64_t n = 600851475143;
    const uint64_t bound = sqrt(n);
    auto p = euler::primes(bound);
    decltype(p) factors;
    for (auto i = p.cbegin(); i != p.cend(); ++i) {
        if ((n % (*i)) == 0) {
            factors.insert(*i);
        }
    }
    copy(factors.begin(),factors.end(),ostream_iterator<uint64_t>(cout," "));
    return 0;
}
