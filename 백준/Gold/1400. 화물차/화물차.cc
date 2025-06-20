#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;

constexpr int MAX_N = 20 + 1;
constexpr int MAX_K = 9 + 1;

//북남 서동
constexpr int dx[4] = {-1, 1, 0, 0};
constexpr int dy[4] = {0, 0, -1, 1};

int N, M, K;
char grid[MAX_N][MAX_N];

struct Crossroad
{
    int a, b;
    bool startVertical;
};

vector<Crossroad> cr(MAX_K);
pii start;

bool isValid(const int x, const int y)
{
    if(x<0 || y<0 || x>=N || y>=M)
        return false;
    return true;
}

bool isPass(const char ch, const int time, const bool isVertical)
{
    if(ch == '#')
        return true;

    int idx = ch - '0';

    auto [a, b, startVertical] = cr[idx]; //A 동서 - B 남북

    int cycle = a + b;
    int rest = (time - 1) % cycle;

    if (startVertical)
    {
        return (rest < a ? isVertical : !isVertical);
    }
    else
    {
        return (rest < b ? !isVertical : isVertical);
    }
}

int solve()
{
    int time = 0;

    queue<pair<int, int>> q;
    q.push(start);

    bool visited[MAX_N][MAX_N] = {false, };
    visited[start.first][start.second] = true;

    while(!q.empty())
    {
        int qSize = q.size();
        ++time;
        while(qSize--)
        {
            auto [nx, ny] = q.front(); q.pop();
            for(int d=0; d<4; ++d)
            {
                int x = nx + dx[d];
                int y = ny + dy[d];

                if(!isValid(x, y) || visited[x][y] || grid[x][y] == '.') continue;

                if(grid[x][y] == 'B')
                    return time;

                bool passed = isPass(grid[x][y], time, !(d < 2));
                if(passed)
                {
                    q.push({x, y});
                    visited[x][y] = true;
                }
                else
                {
                    q.push({nx, ny});
                }
            }
        }
    }

    return -1;
}

int main()
{
    while(true)
    {
        cin >> N >> M;

        if(N == 0 && M == 0)
            break;

        K = -1;
        for (int i=0; i<N; ++i)
        {
            for (int j=0; j<M; ++j)
            {
                cin >> grid[i][j];

                switch (grid[i][j])
                {
                    case 'A': {
                        start = make_pair(i, j);
                        break;
                    }

                    case '#': case '.': case 'B':
                        break;

                    default:
                    {
                        int idx = grid[i][j] - '0';
                        if (K < idx)
                            K = idx;
                        break;
                    }
                }
            }
        }

        if(K != -1)
        {
            int idx, a, b;
            char isVertical;
            for (int i=0; i<=K; ++i)
            {
                cin >> idx >> isVertical >> a >> b;
                cr[idx] = {a, b, (isVertical == '-')};
            }
        }

        int answer = solve();
        if(answer == -1)
            cout << "impossible" << "\n";
        else
            cout << answer << "\n";
    } // T

    return 0;
}