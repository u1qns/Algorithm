#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

constexpr int MAX_N = 101;
constexpr int dx[4] = {-1, 1, 0, 0};
constexpr int dy[4] = {0, 0, -1, 1};

int N, M, T;
int grid[MAX_N][MAX_N];

bool isValid(const int x, const int y)
{
    if(x<0 || y<0 || x>=N || y>=M)
        return false;
    return true;
}

int solve()
{
    int answer = 1e9;
    int tmp = 1e9;
    int distance = 0;

    queue<pair<int, int>> q;
    bool visited[MAX_N][MAX_N] = {false,};
    q.push({0, 0});
    visited[0][0] = true;

    while(!q.empty())
    {
        int qSize = q.size();

        if(distance > T)
            break;

        while(qSize--)
        {
            auto [nx, ny] = q.front();
            q.pop();

            if(nx == N-1 && ny == M-1)
                answer = min(answer, distance);

            if(grid[nx][ny] == 2)
                tmp = distance + (N - 1 - nx) + (M - 1 - ny);

            for(int d=0; d<4; ++d)
            {
                int x = nx + dx[d];
                int y = ny + dy[d];

                if(!isValid(x, y) || visited[x][y]) continue;
                if(grid[x][y] == 1) continue;

                visited[x][y] = true;
                q.push({x, y});
            }
        }

        distance++;
    }

    int result = min(answer, tmp);
    return result <= T ? result : 1e9;
}

int main()
{
    cin >> N >> M >> T;
    for(int i=0; i<N; ++i)
        for(int j=0; j<M; ++j)
            cin >> grid[i][j];

    int answer = solve();
    if(answer == 1e9)
        cout << "Fail";
    else
        cout << answer;

    return 0;
}
