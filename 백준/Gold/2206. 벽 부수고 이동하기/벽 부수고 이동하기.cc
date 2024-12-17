#include <iostream>
#include <queue>
#include <algorithm>

typedef std::pair<int, int> pii;

const int MAX_N = 1000 + 1;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

int N, M, answer = 0;
int map[MAX_N][MAX_N] = {0, };
int visited[2][MAX_N][MAX_N] = {0, };

struct Info
{
    Info() = default;
    Info(const int _x, const int _y, const int _type)
    :x(_x), y(_y), type(_type){};

    int x, y, type;
};

bool isValid(const int x, const int y)
{
    if(x<0 || y<0 || x>=N || y>=M)
        return false;
    return true;
}

int solve()
{
    Info front;
    int x, y, type, time = 1;

    if(N-1 == 0 && M -1 ==0)
        return time;
    std::queue<Info> q;
    q.push({0, 0, 0});

    visited[0][0][0] = 1;

    while(!q.empty())
    {
        int qSize = q.size();
        ++time;
        while(qSize--)
        {
            front = q.front(); q.pop();
            type = front.type;

            for(int d=0; d<4; ++d)
            {
                x = front.x + dx[d];
                y = front.y + dy[d];

                if(!isValid(x, y) || visited[type][x][y]) continue;


                if(x == N-1 && y == M-1)
                {
                    return time;
                }

                if(type == 0 && map[x][y])
                {
                    if(visited[1][x][y])  continue;
                    visited[1][x][y] = time;
                    q.push({x, y, true});

                } else if(map[x][y] == 0)
                {
                    visited[type][x][y] = time;
                    q.push({x, y, type});
                }
            }
        }
    }

    return -1;
}

int main()
{
    std::cin >> N >> M;
    char ch;
    for(int i=0; i<N; ++i)
    {
        for(int j=0; j<M; ++j)
        {
            std::cin >> ch;
            map[i][j] = (ch == '1' ? 1 : 0);
        }
    }

    answer = solve();

    std::cout << answer;
    return 0;
}