#include <iostream>
#include <queue>
using namespace std;

constexpr int MAX_N = 100 + 1;
constexpr int dir[6][3] = {
        {-1, 0, 0},
        {1, 0, 0},
        {0, -1, 0},
        {0, 1, 0},
        {0, 0, -1},
        {0, 0, 1}
};
int H, N, M, tomato = 0;
int box[MAX_N][MAX_N][MAX_N];
bool visited[MAX_N][MAX_N][MAX_N] = {false, };

struct Node
{
    int h, x, y;
};
queue<Node> q;

bool isValid(const int z, const int x, const int y)
{
    if(z<0 || z>=H || x<0 || x>=N || y<0 || y>=M)
        return false;
    return true;
}

int bfs()
{
    if(tomato == 0)
        return 0;

    int answer = 0;

    while(!q.empty())
    {
        int qSize = q.size();
        ++answer;

        while(qSize--)
        {
            auto [nowH, nowX, nowY] = q.front();
            q.pop();

            for(int d=0; d<6; ++d)
            {
                int x = nowX + dir[d][0];
                int y = nowY + dir[d][1];
                int z = nowH + dir[d][2];

                if (!isValid(z, x, y) || visited[z][x][y] || box[z][x][y] != 0)
                    continue;

                --tomato; // 안 익은 토마토 숫자 감소
                visited[z][x][y] = true;
                q.push({z, x, y});
            }
        }
    }
    return (tomato == 0 ? answer-1 : -1);
}
int main()
{
    cin >> M >> N >> H;

    for(int i=0; i<H; ++i)
    {
        for(int j=0; j<N; ++j)
        {
            for(int k=0; k<M; ++k)
            {
                cin >> box[i][j][k];
                if(box[i][j][k] == 1)
                {
                    visited[i][j][k] = true;
                    q.push({i, j, k});
                }
                else if(box[i][j][k] == 0)
                {
                    tomato++;
                }
            }
        }
    }



    int answer = bfs();
    cout << answer;
    return 0;
}