#include <iostream>
#include <string>
using namespace std;
int answer[11] = {0, };

int main() 
{
    long long A, B, C;
    cin >> A >> B >> C;
    long long tmp = A*B;
    tmp *= C;
    
    string str = to_string(tmp);
    for(int i=0; i<str.size(); ++i)
    {
        if(str[i] == '0')
            answer[0]++;
        else
            answer[str[i]-'0']++;
    }
    
    for(int i=0; i<10; ++i)
    {
        cout << answer[i] << "\n";
    }
    return 0;
}
