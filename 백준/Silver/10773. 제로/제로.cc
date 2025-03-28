#include <iostream>
#include <stack>
using namespace std;

int main() 
{
    stack<int> stk;
    int K, inp, answer = 0;
    cin >> K;
    
    for(int i=0; i<K; ++i)
    {
        cin >> inp;
        if(inp!=0) stk.push(inp);
        else if(!stk.empty()) stk.pop();

    }
    
    while(!stk.empty())
    {
        answer += stk.top();
        stk.pop();
    }
    
    cout << answer;
    return 0;
}
