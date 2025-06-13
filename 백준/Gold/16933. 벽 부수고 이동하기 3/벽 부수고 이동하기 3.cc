#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX_N = 1000 + 1;
const int MAX_K = 10 + 1;

constexpr int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int N, M, K;
bool grid[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N][MAX_K][2] = {false, }; // k번 벽을 부숴 도착한 (x, y) 위치에 day 시간에 도착
// 1000 x 1000 x  10 x 2 = 10^3 x 10^3 X 10 X 2 = 10^7x 2 ...
struct Node
{
    int x, y, k;
    bool day;
};

int solve()
{
    // 예외 케이스
    if(N == 1 && M == 1)
        return 1;

    queue<Node> q;
    q.push({0, 0, 0, true});

    int distance = 0;
    visited[0][0][0][1] = true;

    while(!q.empty())
    {
        int qSize = q.size();
        ++distance;

        while(qSize--)
        {
            const auto [x, y, k, day] = q.front(); q.pop();

            if(x == N-1 && y == M-1)
                return distance;

            for(int d=0; d<4; ++d)
            {
                int nx = x + dir[d][0];
                int ny = y + dir[d][1];

                if(nx<0 || ny<0 || nx>=N || ny>=M) continue;

                if(grid[nx][ny])
                {
                    if(k >= K) continue;

                    if(day)
                    {
                        if(visited[nx][ny][k+1][!day]) continue;
                        q.push({nx, ny, k + 1, !day});
                        visited[nx][ny][k + 1][!day] = true;
                    }
                    else
                    {
                        // nx, ny가 아니라 제자리인 x, y
                        if(visited[x][y][k][!day]) continue;
                        q.push({x, y, k, !day});
                        visited[x][y][k][!day] = true;
                    }
                }
                else
                {
                    if(visited[nx][ny][k][!day]) continue;
                    q.push({nx, ny, k, !day});
                    visited[nx][ny][k][!day] = true;
                }
            }
        } // distance
    } // while

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