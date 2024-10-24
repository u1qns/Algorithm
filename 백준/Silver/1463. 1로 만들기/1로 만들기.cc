#include <iostream>
#include <queue>

using namespace std;
bool visited[1000001] = {false, };
queue<int> q;

bool isX(const int num, const int x)
{
    if(x == num)
        return true;

    if(num >= 1000001 || visited[num])
        return false;

    visited[num] = true;
    q.push(num);
    return false;
}

int bfs(const int x)
{
    int answer = 0;
    if(x == 1)
        return 0;

    q.push(1);
    while(!q.empty())
    {
        int qSize = q.size();
        ++answer;
        while(qSize--)
        {
            int now = q.front(); q.pop();
            if(isX(now*2, x))
                return answer;
            if(isX(now*3, x))
                return answer;
            if(isX(now+1, x))
                return answer;
        }
    }
    return x-1;
}

int main()
{
    int X;
    cin >> X;
    cout << bfs(X);

    return 0;
}