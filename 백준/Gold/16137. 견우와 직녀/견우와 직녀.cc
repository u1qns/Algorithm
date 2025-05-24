#include <iostream>
#include <queue>
using namespace std;

constexpr int MAX_N = 10 + 1;
constexpr int dx[4] = {1, -1, 0, 0};
constexpr int dy[4] = {0, 0, -1, 1};

int N, M;
int grid[MAX_N][MAX_N];
int visited[2][MAX_N][MAX_N];

enum
{
    BLOCK = -1,
    CLIFF = 0,
    GROUND = 1,
};
struct Node
{
    int x, y;
    bool built = false, last = false;
};

bool isValid(const int x, const int y)
{
    if(x<0 || y<0 || x>=N || y>=N)
        return false;
    return true;
}

void check_cliff()
{
    // 절벽이 교차로라 오작교를 설치 못하는 구역인지 확인하는 함수
    // 설치 못 하면 절대 지나갈 수 없는 곳이니 -1로 표기
    for(int i=0; i<N; ++i)
    {
        for(int j=0; j<N; ++j)
        {
            if(grid[i][j] != CLIFF) continue;

            int r=0, c=0;
            for(int d=0; d<2; ++d)
                if(isValid(i+dx[d], j+dy[d]) && grid[i+dx[d]][j+dy[d]] != 1)
                    ++r;

            for(int d=2; d<4; ++d)
                if(isValid(i+dx[d], j+dy[d]) && grid[i+dx[d]][j+dy[d]] != 1)
                    ++c;

            if(r>=1 && c>=1) grid[i][j] = BLOCK;
        }
    }
}

void bfs()
{
    queue<Node> q;
    q.push({0, 0, false, false});
    visited[0][0][0] = 0;

    while(!q.empty())
    {
        const auto [nowX, nowY, built, last] = q.front();
        q.pop();

        for(int d=0; d<4; ++d)
        {
            int x = nowX + dx[d];
            int y = nowY + dy[d];

            if(!isValid(x, y) || grid[x][y] == BLOCK) continue;

            if(grid[x][y] == CLIFF)
            {
                if(built || last) continue;

                // 절벽인데 지어서 갈거고, M 주기를 기다림
                int time = 0;
                if((visited[built][nowX][nowY] + 1) % M !=0) // 안 맞아 떨어지면 M주기 될만큼 기다림
                    time = M - (visited[built][nowX][nowY] + 1) % M;

                time += visited[built][nowX][nowY] + 1;
                if(time >= visited[1][x][y]) continue;
                visited[1][x][y] = time;
                q.push({x, y, true, true});
            }
            else if(grid[x][y] == GROUND)
            {
                int tmp = visited[built][nowX][nowY] + 1;

                if(tmp >= visited[built][x][y]) continue;
                visited[built][x][y] = tmp;
                q.push({x, y, built, false});
            }
            else if(grid[x][y] > GROUND) // 주기를 기다리는 오작교
            {
                if(last) continue;

                int time = 0;
                if((visited[built][nowX][nowY] + 1) % grid[x][y] !=0) // 안 맞아 떨어지면 주기 될만큼 기다림
                    time = grid[x][y] - (visited[built][nowX][nowY] + 1) % grid[x][y];

                time += visited[built][nowX][nowY] + 1;
                if(time >= visited[built][x][y]) continue;
                visited[built][x][y] = time;
                q.push({x, y, built, true});
            }
        }
    }
}

int main()
{
    cin >> N >> M;
    for(int i=0; i<N; ++i)
    {
        for(int j=0; j<N; ++j)
        {
            cin >> grid[i][j];
            visited[0][i][j] = visited[1][i][j] = 1e9;
        }
    }

    check_cliff();
    bfs();
    cout << std::min(visited[0][N-1][N-1], visited[1][N-1][N-1]);

    return 0;
};