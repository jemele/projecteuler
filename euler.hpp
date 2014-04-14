#ifndef _euler_hpp_
#define _euler_hpp_
#include <algorithm>
#include <set>
#include <vector>
#include <sstream>

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
            for (auto j = i; j < n; j+=i) {
                sieve[j] = true;
            }
        }
    }
    return p;
}

// generate factors for n
template <typename T>
std::set<T> factors(T n, const std::set<T> & p)
{
    std::set<T> f;
    for (auto i = p.cbegin(); i != p.cend(); ++i) {
        if ((n % (*i)) == 0) {
            f.insert(*i);
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


} // namespace euler
#endif //_euler_hpp_
