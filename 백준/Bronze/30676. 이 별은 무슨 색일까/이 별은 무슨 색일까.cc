#include <iostream>
#include <string>
using namespace std;
int a[7] = {620, 590, 570, 495, 450, 425, 380};
int b[7] = {781, 620, 590, 570, 495, 450, 425};
string ans[7] = {"Red", "Orange", "Yellow", "Green", "Blue", "Indigo", "Violet"};

int main() 
{
    int inp;
    cin >> inp;
    for(int i=0; i<7; ++i)
    {
        if(a[i] <= inp && inp < b[i])
        {
            cout << ans[i];
            break;
        }
    }
    
    return 0;
}