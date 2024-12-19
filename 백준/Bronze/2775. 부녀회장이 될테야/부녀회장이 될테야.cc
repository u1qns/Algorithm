#include <iostream>

using namespace std;

int dp[15][15] = {0, };

int main()
{
    int T, k, n;


    for(int j=1; j<15; ++j)
        dp[0][j] = j;

    for(int i=1; i<15; ++i)
    {
        for(int k=1; k<15; ++k)
        {
            for (int j = 1; j <= k; ++j) {
                dp[i][k] += dp[i - 1][j];
            }
        }
    }


    cin >> T;
    while(T--)
    {
        cin >> k >> n;
        cout << dp[k][n] << "\n";
    }

    return 0;
}
