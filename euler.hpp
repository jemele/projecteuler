#ifndef _euler_hpp_
#define _euler_hpp_
#include <set>
#include <vector>

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

} // namespace euler
#endif //_euler_hpp_
