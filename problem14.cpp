#include <stdint.h>
#include <iostream>
using namespace std;

size_t hit = 0;
size_t miss = 0;
size_t lut[10000000];
size_t collatz(uint64_t n, size_t c = 0)
{
    if (n == 1) {
        return c+1;
    }
    if ((n < sizeof(lut)/sizeof(*lut)) && lut[n]) {
        ++hit;
        return c+lut[n];
    }
    ++miss;
    return collatz((n & 1) ? ((3*n)+1) : n/2, c+1);
}

int main(int, char**)
{
    size_t max_c = 0;
    uint64_t max_i = 0;
    for (auto i = 1; i < 1000000; ++i) {
        lut[i] = collatz(i);
        if (max_c < lut[i]) {
            max_c = lut[i];
            max_i = i;
        }
    }
    cout << "hit: " << hit << endl;
    cout << "miss: " << miss << endl;
    cout << "ratio: " << (hit*100)/miss << endl;
    cout << max_i << ':' << max_c << endl;
    return 0;
}
