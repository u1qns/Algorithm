#include <iostream>
#include <vector>
#include <queue>
using namespace std;

constexpr int MAX_N = 2222 + 1;
constexpr int INF = 1e9;
constexpr int dx[2] = {1, 0};
constexpr int dy[2] = {0, 1};

struct Node
{
    Node(int _cost, int _x, int _y)
            :cost(_cost), x(_x), y(_y){};

    int cost, x, y;
};

struct cmp
{
    bool operator()(const Node& a, const Node& b)
    {
        return a.cost > b.cost;
    }
};
int N, grid[MAX_N][MAX_N] = {0, };
int dp[MAX_N][MAX_N];

bool isValid(const int x, const int y)
{
    if(x<0 || y<0 || x>=N || y>=N)
        return false;
    return true;
}

int getAnswer()
{
    priority_queue<Node, vector<Node>, cmp> pq;
    pq.push({0, 0, 0});

    dp[0][0] = 0;

    while(!pq.empty())
    {
        Node top = pq.top(); pq.pop();
        if(dp[top.x][top.y] < top.cost) continue;

        for(int d=0; d<2; ++d)
        {
            int x = top.x + dx[d];
            int y = top.y + dy[d];

            if(!isValid(x, y)) continue;

            int cost = grid[x][y] - grid[top.x][top.y] + 1;
            if(cost <= 0) cost = 0;

            int next_cost = cost + top.cost;
            if(next_cost >= dp[x][y]) continue;
            dp[x][y] = next_cost;

            pq.push({next_cost, x, y});
        }
    }

    return dp[N-1][N-1];
}

int main()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

    cin >> N;
    for(int i=0; i<N; ++i)
    {
        for(int j=0; j<N; ++j)
        {
            cin >> grid[i][j];
            dp[i][j] = INF;
        }
    }

    cout << getAnswer();

    return 0;
}
