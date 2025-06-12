#include <iostream>
using namespace std;
int dp[15][15] = {0, };
int K, N;
int solve(const int f, const int r)
{
    if(dp[f][r] != 0) return dp[f][r];
    if(f == 0) return r;
    if(r == 0) return 0;

    return dp[f][r] = solve(f-1, r) + solve(f, r-1);
}

int main()
{
    int T;
    cin >> T;

    while(T--)
    {
        int K, N;
        cin >> K >> N;

        cout << solve(K, N) << "\n";
    }

    return 0;
}