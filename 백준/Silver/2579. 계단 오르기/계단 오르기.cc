#include <iostream>
#include <cmath>
using namespace std;

int dp[301][2] = {0, };
int score[301] = {0, };

int main()
{
    int N;
    cin >> N;
    for(int i=1; i<=N; ++i)
        cin >> score[i];

    dp[1][1] = score[1];
    for(int i=2; i<=N; ++i)
    {
        dp[i][0] = max(dp[i-1][1], dp[i-2][0] + score[i-1]);
        dp[i][1] = max(score[i-1] + dp[i-2][0], dp[i-2][1]) + score[i];
        //printf("%d %d\n", dp[i][0], dp[i][0]);
    }

    cout << dp[N][1];
    return 0;
}
