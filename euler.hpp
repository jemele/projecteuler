#ifndef _euler_hpp_
#define _euler_hpp_
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <vector>
#include <sstream>
#include <iostream>

namespace euler
{

// generate a set of primes from [2,n]
template <typename T>
std::set<T> primes(T n)
{
    std::set<T> p;
    std::vector<bool> sieve(n+1);
    for (auto i = 2; i <= n; ++i) {
        if (sieve[i]) {
            continue;
        }
        if (!sieve[i]) {
            p.insert(i);
            for (auto j = i; j <= n; j+=i) {
                sieve[j] = true;
            }
        }
    }
    return p;
}

// generate factors for n
template <typename T>
std::map<T,std::size_t> factors(T n, const std::set<T> & p)
{
    std::map<T,std::size_t> f;
    auto bound = std::sqrt(n) + 1;
    for (auto i = p.cbegin(); (i != p.cend()) || (*i > bound); ++i) {
        const auto prime = *i;
        std::size_t order = 0;
        for (auto d = n; (d % prime) == 0; d /= prime) {
            ++order;
        }
        if (order) {
            f[prime] = order;
        }
    }
    return f;
}

// returns true if the number is a palindrome
template <typename T>
bool palindrome(T n)
{
    std::ostringstream s;
    s << n;
    auto r = s.str();
    return std::equal(r.begin(), r.end(),
                      r.rbegin());
}

// return the nth triangle number
template <typename T>
T triangle(T n)
{
    return (n*(n+1))/2;
}

} // namespace euler
#endif //_euler_hpp_
