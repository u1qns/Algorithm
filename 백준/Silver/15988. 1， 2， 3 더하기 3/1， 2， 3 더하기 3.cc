#include <iostream>
#include <vector>
using namespace std;
const int MOD = 1000000009;
int main() 
{
    int T, N;
    vector<long long> dp(1000001, 0);
    dp[0] = dp[1] = 1; dp[2] = 2; dp[3] = 4;
    
    cin >> T;
    while(T--)
    {
        cin >> N;
        if(dp[N] != 0)
        {
            cout << dp[N] << "\n";
            continue;
        }
        
        for(int i=4; i<=N; ++i)
        {
            if(dp[i] !=0) continue;
            dp[i] = (dp[i-1] + dp[i-2]) % MOD;
            dp[i] = (dp[i] + dp[i-3]) % MOD;
        }
        cout << dp[N] << "\n";
    }
    return 0;
}
