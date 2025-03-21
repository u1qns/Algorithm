#include <iostream>
using namespace std;

constexpr int MAX_N = 1000 + 1;

int N, M, grid[MAX_N][MAX_N];
int dp[3][MAX_N][MAX_N]; // 진짜 dp, ->, <-

int main()
{
    cin >> N >> M;
    for(int i=0; i<N; ++i)
    {
        for(int j=0; j<M; ++j)
        {
            cin >> grid[i][j];
        }
    };

    //  첫행을 -> 로 진행하면서 누적합
    dp[0][0][0] = grid[0][0];
    for(int i=1; i<M; ++i)
    {
        dp[0][0][i] = dp[0][0][i-1] + grid[0][i];
    }

    // (N, M)으로 가기 위해 위에서 부터 아래로 내려가가ㅔㅆ음
    for(int i=1; i<N; ++i)
    {
        // -> 로 가면서 왼쪽이랑 위에꺼랑 비교
        dp[1][i][0] = dp[0][i-1][0] + grid[i][0];
        for(int j=1; j<M; ++j)
        {
            dp[1][i][j] = std::max(dp[1][i][j-1], dp[0][i-1][j]) + grid[i][j];
        }

        // <-로 가면서 오른쪽이랑 위랑 비교
        // 맨 오른쪽에 있는건 위에 있는 값을 그대로 가져오면 됨
        dp[2][i][M-1] = dp[0][i-1][M-1] + grid[i][M-1];
        for(int j=M-2; j>=0; --j)
        {
            dp[2][i][j] = std::max(dp[2][i][j+1], dp[0][i-1][j]) + grid[i][j];
        }

        for(int j=0; j<M; ++j)
        {
            dp[0][i][j] = std::max(dp[1][i][j], dp[2][i][j]);
        }
    }

    cout << dp[0][N-1][M-1];

    return 0;
}