#include <iostream>

using namespace std;

int main() 
{
    int a, b, c;
    a = b = c = -1;
    while(true)
    {
        cin >> a >> b >> c;
        
        if(a == 0 && a == b && b == c && a == c)
            break;
        
        if(a >= b +c || b >= a+c || c >=a + b)
            cout << "Invalid\n";
        else if(a == b && b == c && c == a)
            cout<<"Equilateral\n";
        else if(a == b || b == c || c == a)
            cout << "Isosceles\n";
        else if(a != b && b != c && c!=a)
            cout << "Scalene\n";

    }
    
    return 0;
}
