#include <iostream>
#include <stack>
using namespace std;
stack<int> stk;
int arr[9];
bool answer = false;

void dfs(const int depth, const int idx, const int sum)
{
    if(depth > 7 ||sum > 100 || answer)
        return;

    if(sum == 100 && depth == 7)
    {
        answer = true;
        while(!stk.empty())
        {
            cout << stk.top() << "\n";
            stk.pop();
        }
        return;
    }

    for(int i=idx; i<9; ++i)
    {
        stk.push(arr[i]);
        dfs(depth+1, i+1, sum + arr[i]);
        if(answer) return;
        stk.pop();
    }
}
int main()
{
    for(int i=0; i<9; ++i)
        cin >> arr[i];

    dfs(0, 0, 0);

    return 0;
}
