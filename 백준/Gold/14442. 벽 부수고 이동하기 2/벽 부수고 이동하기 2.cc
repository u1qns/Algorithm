#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX_N = 1000 + 1;
const int MAX_K = 10 + 1;

constexpr int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int N, M, K;
bool grid[MAX_N][MAX_N];
int visited[MAX_N][MAX_N][MAX_K]; // cost 저장

struct Node
{
    int x, y, k;
};

int solve()
{
    // 예외 케이스
    if(N == 1 && M == 1)
        return 1;

    queue<Node> q;
    q.push({0, 0, 0});

    visited[0][0][0] = 1;

    while(!q.empty())
    {
        auto front = q.front(); q.pop();

        if(front.x == N-1 && front.y == M-1)
            return visited[front.x][front.y][front.k];


        for(int d=0; d<4; ++d)
        {
            int x = front.x + dir[d][0];
            int y = front.y + dir[d][1];
            int k = front.k;
            int cost = visited[front.x][front.y][k];

            if(x<0 || y<0 || x>=N || y>=M) continue;

            if(grid[x][y])
            {
                if(k+1 > K || visited[x][y][k+1]) continue;
                q.push({x, y, k + 1});
                visited[x][y][k+1] = cost + 1;
            }
            else
            {
                if(visited[x][y][k]) continue;
                q.push({x, y, k});
                visited[x][y][k] = cost + 1;
            }
        }

    }

    return -1;
}

int main()
{
    char ch;
    cin >> N >> M >> K;
    for(int i=0; i<N; ++i)
    {
        for(int j=0; j<M; ++j)
        {
            cin >> ch;
            grid[i][j] = (ch == '0' ? 0 : 1);
        }
    }

    cout << solve();

    return 0;
}