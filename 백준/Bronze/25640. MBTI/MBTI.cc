#include <iostream>
#include <string>
using namespace std;

int main() 
{
    int answer = 0, N;
    string jinho, inp;
    cin >> jinho;
    cin >> N;
    for(int i=0; i<N; ++i)
    {
        cin >> inp;
        if(jinho == inp)
            ++answer;
    }
    cout << answer;
    return 0;
}
