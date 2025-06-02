#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;
int N, M;
bool answer = false;

vector<vector<int>> list;
bool visited[2001] = {false, };

bool dfs(int depth, int idx)
{
    if(depth == 4)
    {
        return true;
    }

    for(const int i : list[idx])
    {
        if(visited[i]) continue;
        visited[i] = true;
        if(dfs(depth + 1, i)) return true;
        visited[i] = false;
    }
    return false; // 까먹어서 추가
}
bool solve()
{
    for(int i=0; i<N; ++i)
    {
        memset(visited, false, sizeof(visited));
        visited[i] = true;
        if(dfs(0, i)) return true;
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