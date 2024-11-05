#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, int> pii;
char grid[601][601];
const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};
bool visited[601][601] = {false, };

int main()
{
    int N, M, answer = 0;
    pii start;
    cin >> N >> M;

    for(int i=0; i<N; ++i)
    {
        for(int j=0; j<M; ++j)
        {
            cin >> grid[i][j];
            if(grid[i][j] == 'I')
                start = make_pair(i, j);
        }
    }

    queue<pii> q;
    q.push(start);
    visited[start.first][start.second] = true;
    while(!q.empty())
    {
        int nowX = q.front().first;
        int nowY = q.front().second;
        q.pop();
        for(int d=0; d<4; ++d)
        {
            int x = nowX + dx[d];
            int y = nowY + dy[d];

            if(x<0 || y<0 || x>=N || y>=M) continue;
            if(visited[x][y] || grid[x][y] == 'X') continue;

            if(grid[x][y] == 'P')
                ++answer;
            visited[x][y] = true;
            q.push({x, y});
        }
    }
    if(answer == 0)
        cout << "TT";
    else
        cout << answer;

    return 0;
}
