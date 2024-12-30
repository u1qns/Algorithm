#include <iostream>
#include <map>

using namespace std;

int main() 
{
    int inp;
    map<int, int> m;
    for(int i=0; i<10; ++i) 
    {
        cin >> inp;
        ++m[inp%42];
    }
    cout << m.size();
    
    return 0;
}
