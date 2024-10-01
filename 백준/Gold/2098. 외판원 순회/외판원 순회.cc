#include <iostream>
using namespace std;
const int INF = 1e9;
const int MAX_N = 15 + 1;

int N;
int W[MAX_N][MAX_N] = {0, };
int dp[MAX_N][(1 << MAX_N) + 1] = {0, };

int tsp(int cur, int subset)
{
    if (subset == (1 << N) - 1)
        return (W[cur][0] == 0 ? INF : W[cur][0]);

    int& ret = dp[cur][subset];

    if (ret > 0) return ret;

    ret = INF;

    for (int next = 0; next < N; ++next)
    {
        if (!W[cur][next] || (subset & (1 << next))) continue;
        
        int tmp = W[cur][next] + tsp(next, subset | 1 << next);
        ret  = (ret < tmp ? ret : tmp);
    }
    
    return ret;
}

int main() {

    cin >> N;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            std::cin >> W[i][j];


    cout << tsp(0, 1);

	return 0;
}