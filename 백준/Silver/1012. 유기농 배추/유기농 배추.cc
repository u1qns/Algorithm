#include <iostream>
#include <queue>
#include <memory.h>

const int MAX = 1000 + 1;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

int N, M, answer = 0;
bool visited[MAX][MAX] = {false, };
bool map[MAX][MAX];

bool isValid(const int x, const int y)
{
    if(x<0 || x>=N || y<0 || y>=M)
        return false;
    return true;
}

void BFS(const int r, const int c)
{
    std::queue<std::pair<int, int> > q; 
    q.push(std::make_pair(r, c));
    visited[r][c] = true;

    while(!q.empty())
    {
        int nowX = q.front().first;
        int nowY = q.front().second;
        q.pop();

        for(int d=0; d<4; ++d)
        {
            int x = nowX + dx[d];
            int y = nowY + dy[d];

            if(isValid(x, y) && map[x][y])
            {
                visited[x][y] = true;
                map[x][y] = false;
                q.push(std::make_pair(x, y));
            }
        }
    }
    ++answer;
}

int getAnswer()
{
    answer = 0;

    for(int i=0; i<N; ++i)
    {
        for(int j=0; j<M; ++j)
        {
            if(map[i][j])
                BFS(i, j);
        }
    }

    return answer;
}

int main()
{
    int T;
    
    std::cin >> T;
    while(T--)
    {
        memset(map, false, sizeof(map));
        memset(visited, false, sizeof(visited));
        
        int x, y, K;
        std::cin >> N >> M >> K;
        for(int i=0; i<K; ++i)
        {
            std::cin >> x >> y;
            map[x][y] = true;
        }

        std::cout << getAnswer() << '\n';
    }
    return 0;
}