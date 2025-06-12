#include <iostream>
using namespace std;
int dp[15][15] = {0, };

int main()
{
    int T;
    cin >> T;

    while(T--)
    {
        int K, N;
        cin >> K >> N;

        for(int i=1; i<=N; ++i)
            dp[0][i] = i;

        for(int i=1; i<=K; ++i)
        {
            for(int j=1; j<=N; ++j)
            {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        cout << dp[K][N] << "\n";
    }

    return 0;
}