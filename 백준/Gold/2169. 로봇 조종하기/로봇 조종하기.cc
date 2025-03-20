#include <iostream>
#include <algorithm>
using namespace std;

constexpr int MAX_N = 1000 + 1;
constexpr int DIR_SIZE = 3;
constexpr int dx[DIR_SIZE] = { 1, 0, 0};
constexpr int dy[DIR_SIZE] = { 0, -1, 1};
constexpr int INF = 1e9;

int N, M, grid[MAX_N][MAX_N], dp[MAX_N][MAX_N][DIR_SIZE] = {0, };
bool visited[MAX_N][MAX_N] = {false, };

bool isValid(const int x, const int y)
{
    if(x<0 || y<0 || x>=N || y>=M)
        return false;
    return true;
}

int solve(const int x, const int y, const int dir)
{
    if(x==N-1 && y==M-1) return grid[x][y]; // 더 이상 진행할 수 없기 때문에 아래 로직 타지 않음
    if(dp[x][y][dir] != -INF) return dp[x][y][dir]; // 이미 최적이기 때문에 연산하지 않아도 됨

    // 현재 위치에서 갈 수 있는 곳으로 1칸 전진한 값을 찾음
    for(int d=0; d<DIR_SIZE; ++d)
    {
        int nx = x + dx[d];
        int ny = y + dy[d];

        if(!isValid(nx, ny) || visited[nx][ny]) continue;

        visited[nx][ny] = true;
        // 현재 위치의 최대 가중치와 다음으로 이동했을 때의 값을 찾아 갱신
        dp[x][y][dir] = std::max(dp[x][y][dir], solve(nx, ny, d) + grid[x][y]);
        visited[nx][ny] = false;
    }

    return dp[x][y][dir];
}

int main()
{
    cin >> N >> M;
    for(int i=0; i<N; ++i)
    {
        for(int j=0; j<M; ++j)
        {
            cin >> grid[i][j];

            dp[i][j][0] = dp[i][j][1] = dp[i][j][2] = -INF; // 최대 합을 구해야하니까 최소로 설정
        }
    };

    visited[0][0] = true; // 시작점 재방문 방지
    cout << solve(0, 0, 0);
    
    return 0;
}