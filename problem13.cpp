#include <iostream>
#include <iterator>
#include <string>
#include <sstream>
using namespace std;
int main(int, char**)
{
    uint64_t a = 0;
    string line;
    while (getline(cin,line)) {
        auto i = atol(line.substr(0,11).c_str());
        a += i;
        cout << i << ',' << a << endl;
    }
    ostringstream s;
    s << a;
    string result = s.str();
    result = result.substr(0,10);
    cout << a << '(' << result << ')' << endl;
    return 0;
}
