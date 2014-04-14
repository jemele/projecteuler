#include <iostream>
#include <sstream>
using namespace std;

// returns true if the number is a palindrome.
// need the top bit set.
bool palindrome(int n)
{
    ostringstream s;
    s << n;
    auto r = s.str();
    return std::equal(r.begin(), r.end(),
                      r.rbegin());
}

// A palindromic number reads the same both ways.
// The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
// Find the largest palindrome made from the product of two 3-digit numbers.
int main(int, char**)
{
    int x,y,l = 0;
    for (auto i = 999; i >= 100; --i) {
        for (auto j = 999; j >= 100; --j) {
            const auto product = i*j;
            if (palindrome(product)) {
                if (product > l) {
                    x = i;
                    y = j;
                    l = product;
                    cout << i << ' ' << j << ' ' << product << endl;
                }
            }
        }
    }
    cout << x << ' ' << y << ' ' << l << endl;
    return 0;
}
