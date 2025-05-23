#include <iostream>
#include <queue>
using namespace std;

constexpr int MAX_N = 50 + 1;
constexpr int dx[4] = {0, 0, 1, -1};
constexpr int dy[4] = {1, -1, 0, 0};

int N, M, grid[MAX_N][MAX_N];
int maxDistance = 0, answer = 0;

void bfs(int _x, int _y)
{
    int distance = 0;

    queue<pair<int, int>> q;
    q.push({_x, _y});

    bool visited[MAX_N][MAX_N] = {false, };
    visited[_x][_y] = true;

    while(!q.empty())
    {
        int qSize = q.size();
        ++distance;

        while(qSize--)
        {
            auto front = q.front();
            q.pop();

            int tmp = grid[_x][_y] + grid[front.first][front.second ];
            if (distance > maxDistance)
            {
                maxDistance = distance;
                answer = tmp;
            } else if (distance == maxDistance) {
                answer = max(answer, tmp);
            }

            for(int d=0; d<4; ++d)
            {
                int x = front.first + dx[d];
                int y = front.second + dy[d];

                if(x<0 || y< 0 || x>=N || y>=M
                    || grid[x][y] == 0 || visited[x][y])
                    continue;

                visited[x][y] = true;
                q.push({x, y});
            }
        }
    }

}

int main()
{
    cin >> N >> M;
    for(int i=0; i<N; ++i)
    {
        for(int j=0; j<M; ++j)
        {
            cin >> grid[i][j];
        }
    }

    for(int i=0; i<N; ++i)
    {
        for(int j=0; j<M; ++j)
        {
            if(grid[i][j] == 0) continue;
            bfs(i, j);
        }
    }

    cout << answer;


    return 0;
};