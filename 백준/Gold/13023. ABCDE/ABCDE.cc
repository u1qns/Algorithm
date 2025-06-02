#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;
int N, M;
bool answer = false;

vector<vector<int>> list;
bool visited[2001] = {false, };

void dfs(int depth, int idx)
{
    if(depth == 4)
    {
        answer = true;
        return;
    }

    for(const int i : list[idx])
    {
        if(visited[i]) continue;
        visited[i] = true;
        dfs(depth + 1, i);
        if(answer) return;
        visited[i] = false;
    }

}
bool solve()
{
    for(int i=0; i<N; ++i)
    {
        memset(visited, false, sizeof(visited));
        visited[i] = true;
        dfs(0, i);
        if(answer) return true;
    }
    return false;
}
int main()
{
    int a, b;
    cin >> N >> M;

    list.resize(N);
    for(int i=0; i<M; ++i)
    {
        cin >> a >> b;
        list[a].push_back(b);
        list[b].push_back(a);
    }

    cout << solve();

    return 0;
}