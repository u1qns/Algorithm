#include <iostream>
using namespace std;
int dp[31][31] = {0, };

int comb(const int n, const int r)
{     
        if (r < 0 || r > n) // r이 n보다 크거나 음수일 경우
        return 0;
    if (r == 0 || r == n) // r이 0이거나 n과 같을 경우
        return 1;
          
    if(dp[n][r] != 0)
        return dp[n][r];
        
    return dp[n][r] = comb(n-1, r-1) + comb(n-1, r);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T, N, M;
    for(int i=0; i<31; ++i)
        dp[i][0] = dp[i][i] = 1; // 초기값 세팅
    
    cin >> T;
    while(T--)
    {
        cin >> N >> M;
        cout << comb(M, N) << "\n"; // 여길 주의!
    }
}