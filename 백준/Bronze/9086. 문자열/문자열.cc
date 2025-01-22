#include <iostream>
#include <string>
using namespace std;

int main() 
{
    std::string inp;
    int T;
    cin >> T;
    while(T--)
    {
        cin >> inp;
        cout << inp.front() << inp.back() <<"\n";
    }
    return 0;
}
