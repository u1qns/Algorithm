#include <iostream>
#include <vector>
#include <queue>
using namespace std;

constexpr int MAX_N = 100 + 1;
constexpr int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int N, M;
char grid[MAX_N][MAX_N];
int visited[MAX_N][MAX_N];

bool isValid(const int x, const int y)
{
    if(x<0 || y<0 || x>=N || y>=M)
        return false;
    return true;
}

struct Node
{
    int x, y, k;
};

struct cmp
{
    bool operator()(Node& a, Node& b)
    {
        return a.k > b.k;
    }
};

int solve()
{
    priority_queue<Node, vector<Node>, cmp> pq;
    pq.push({0, 0, 0});

    visited[0][0] = 0;

    while(!pq.empty())
    {
        const auto [x, y, k] = pq.top(); pq.pop();

        if(visited[x][y] < k) continue; // 이미 벽을 덜 부수고 지나간 적 있어요

        for(int d=0; d<4; ++d)
        {
            int nx = x + dir[d][0];
            int ny = y + dir[d][1];

            if(!isValid(nx, ny)) continue;
            
            if(grid[nx][ny])
            {
                int next_cost = k + 1;
                if(visited[nx][ny] > next_cost)
                {
                    visited[nx][ny] = next_cost;
                    pq.push({nx, ny, next_cost});
                }
            }
            else
            {
                int next_cost = k;
                if(visited[nx][ny] > next_cost)
                {
                    visited[nx][ny] = next_cost;
                    pq.push({nx, ny, next_cost});
                }
            }
        }
    }
    return visited[N-1][M-1];
}

int main()
{
    char ch;
    cin >> M >> N;
    for(int i=0; i<N; ++i)
    {
        for(int j=0; j<M; ++j)
        {
            cin >> ch;
            grid[i][j]= (ch == '0' ? 0 : 1);
            visited[i][j] = 1e9;
        }
    }

    cout << solve();

    return 0;
}