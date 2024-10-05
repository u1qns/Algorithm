#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int, int> pii;

const int MAX_N = 50 + 1;
const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};

int N, M;

struct Node
{
    int trash, around;
    int x, y;
};

struct cmp
{
    bool operator()(const Node& a, const Node& b) const
    {
        if(a.trash >= b.trash) return a.around > b.around;
        return a.trash > b.trash;
    }
};

bool isValid(const int x, const int y)
{
    if(x<0 || y<0 || x>=N || y>=M)
        return false;
    return true;
}

int main()
{
    pii S, F;
    char grid[MAX_N][MAX_N];

    queue<pii> trash;
    priority_queue<pii> pq;

    cin >> N >> M;

    vector<vector<pii>> dp(N+1, vector<pii>(M+1, {1e9, 1e9}));

    for(int i=0; i<N; ++i)
    {
        for(int j=0; j<M; ++j)
        {
            cin >> grid[i][j];
            if(grid[i][j] == 'F') F = make_pair(i, j);
            else if(grid[i][j] == 'S') S = make_pair(i, j);
            else if(grid[i][j] == 'g') trash.push({i, j});
        }
    }

    // 주변 위치 표시 #
    while(!trash.empty())
    {
        pii front = trash.front();
        trash.pop();

        for(int d=0; d<4; ++d)
        {
            int x = front.first + dx[d];
            int y = front.second + dy[d];

            if(!isValid(x, y) || grid[x][y] != '.') continue;

            grid[x][y] = '#';
        }
    }

    // 출발
    pq.push(S);
    dp[S.first][S.second] = {0, 0};
    while(!pq.empty())
    {
        pii top = pq.top();
        int nowX = top.first;
        int nowY = top.second;
        pq.pop();

        for(int d=0; d<4; ++d)
        {
            int x = top.first + dx[d];
            int y = top.second + dy[d];

            if(!isValid(x, y)) continue;

            int next_trash = dp[nowX][nowY].first + (grid[x][y] == 'g' ? 1 : 0 );
            int next_around = dp[nowX][nowY].second + (grid[x][y] == '#' ? 1 : 0);
            if(dp[x][y].first > next_trash ||
                (dp[x][y].first == next_trash && dp[x][y].second > next_around))
            {
                dp[x][y] = make_pair(next_trash, next_around);
                pq.push({x, y});
            }
        }
    }

    cout << (dp[F.first][F.second].first == 1e9 ? 0 : dp[F.first][F.second].first)
    << " " << (dp[F.first][F.second].second == 1e9 ? 0 : dp[F.first][F.second].second);


    return 0;
}