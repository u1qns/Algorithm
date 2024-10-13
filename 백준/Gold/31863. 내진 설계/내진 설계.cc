#include <iostream>
#include <queue>
using namespace std;
typedef pair<int, int> pii;

const int MAX_N = 1000 + 1;
const int dx[4] = {0, 1, -1, 0};
const int dy[4] = {1, 0, 0, -1};

int N, M;

bool isValid(const int x, const int y)
{
    if(x<0 || y<0 || x>=N || y>=M)
        return false;
    return true;
}


int main()
{
    char grid[MAX_N][MAX_N];
    queue<pii> q;

    int broken, total;
    broken = total = 0;

    cin >> N >> M;
    for(int i=0; i<N; ++i)
    {
        for(int j=0; j<M; ++j)
        {
            cin >> grid[i][j];

            if(grid[i][j] == '@')
                q.push({i, j});
            else if(grid[i][j] == '*' || grid[i][j] == '#')
                total++;
        }
    }

    bool start = true;
    int range = 2;

    while(!q.empty())
    {
        pii front = q.front(); q.pop();
        for (int d = 0; d < 4; ++d)
        {
            for (int len = 1; len <=range; ++len)
            {
                int x = front.first + (dx[d] * len);
                int y = front.second + (dy[d] * len);

                if (!isValid(x, y) || grid[x][y] == '|') break;

                if (grid[x][y] == '*')
                {
                    grid[x][y] = '.';
                    q.push({x, y});
                    ++broken;
                    continue;
                }

                if (grid[x][y] == '#')
                {
                    grid[x][y] = '*';
                    continue;
                }
            }
        }

        if(start)
        {
            start = false;
            range = 1;
        }
    }


    cout << broken << " " << total - broken;
    return 0;
}