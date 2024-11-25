#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;
typedef pair<int, int> pii;
const int MAX_N = 50 + 1;
const int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

bool visited[MAX_N][MAX_N] = {false, };
int w, h, grid[MAX_N][MAX_N] = {0, };

void solve(const int startX, const int startY)
{
    queue<pii> q;
    q.push({startX, startY});

    while(!q.empty())
    {
        int qSize = q.size();
        while(qSize--)
        {
            auto top = q.front(); q.pop();

            for(int d=0; d<8; ++d)
            {
                int x = top.first + dx[d];
                int y = top.second + dy[d];

                if(x<0 || y<0 || x>=h || y>=w)
                    continue;
                if(visited[x][y] || grid[x][y] == 0)
                    continue;

                q.push({x, y});
                visited[x][y] = true;
            }
        }
    }
}

int getAnswer()
{
    //input
    int answer = 0;
    memset(visited, false, sizeof(visited));

    cin >> w >> h;

    if(w==0 && h == 0)
        return -1;

    for(int i=0; i<h; ++i)
    {
        for(int j=0; j<w; ++j)
        {
            cin >> grid[i][j];
        }
    }

    //find
    for(int i=0; i<h; ++i)
    {
        for(int j=0; j<w; ++j)
        {
            if(!visited[i][j] && grid[i][j] == 1)
            {
                solve(i, j);
                ++answer;
            }
        }
    }

    return answer;
}

int main()
{
    while(1)
    {
        int answer = getAnswer();
        if(answer == -1) break;
        cout << answer << "\n";
    }

    return 0;
}