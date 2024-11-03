#include <iostream>
#include <queue>
#include <algorithm>
#include <memory.h>

const int MAX = 1000 + 1;

int N, M, V;
bool visited[MAX] = {false, };
bool graph[MAX][MAX];

void input()
{
    int v1, v2;
    for(int i=0; i<M; ++i)
    {
        std::cin >> v1 >> v2;
        graph[v1][v2] = graph[v2][v1] = true;
    }
}

void DFS(const int x)
{
    std::cout << x << ' ';

    for(int i=1; i<=N; ++i)
    {
        if(visited[i] || !graph[x][i])
            continue;

        visited[i] = true;
        DFS(i);
    }
}

void BFS()
{
    std::queue<int> q;

    memset(visited, false, sizeof(visited));
    visited[V] = true;
    q.push(V);

    while(!q.empty())
    {
        int x = q.front();
        q.pop();

        std::cout << x << ' ';

        for(int i=1; i<=N; ++i)
        {
            if(visited[i] || !graph[x][i])
                continue;
            q.push(i);
            visited[i] = true;
        }
    }
}

int main()
{
    std::cin >> N >> M >> V;

    input();

    memset(visited, false, sizeof(visited));
    visited[V] = true;
    DFS(V);

    std::cout << std::endl;

    BFS();

    return 0;
}