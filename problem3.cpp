#include "euler.hpp"
#include <math.h>
#include <algorithm>
#include <stdint.h>
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
    auto f = euler::factors(n,p);
    copy(f.begin(),f.end(),ostream_iterator<uint64_t>(cout," "));
    return 0;
}
