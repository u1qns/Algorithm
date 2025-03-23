#include <iostream>
#include <string>
using namespace std;

int main() 
{
    bool ascending = false;
    bool descending = false;
    int da[8]; cin >> da[0];
    for(int i=1; i<8; ++i)
    {
        cin >> da[i];
        if(da[i] - da[i-1] > 0)
            ascending = true;
        else if(da[i] - da[i-1] < 0)
            descending = true;
    }
    
    if(ascending && descending)
        cout << "mixed";
    else if(ascending)
        cout << "ascending";
    else
        cout << "descending";
    
    return 0;
}
