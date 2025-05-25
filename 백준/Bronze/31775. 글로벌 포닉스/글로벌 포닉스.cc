#include <iostream>
#include <string>
using namespace std;

bool solve()
{
    string str;
    bool check[3] = {false, };
    for(int i=0; i<3; ++i)
    {
        cin >> str;
        if(str[0] == 'l') check[0] = true;
        else if(str[0] == 'k') check[1] = true;
        else if(str[0] == 'p') check[2] = true;
        else return false;
    }
    
    return check[0] && check[1] && check[2];
}

int main() 
{
    cout << (solve() ? "GLOBAL" : "PONIX");
    return 0;
}