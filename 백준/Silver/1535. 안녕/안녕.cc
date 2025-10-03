#include <iostream>
using namespace std;

int N;
int dp[101], W[21], V[21];
int  main()
{

    cin >> N;
    for(int i=0; i<N; ++i) {
        cin >> W[i];
    }
    for(int i=0; i<N; ++i) {
        cin >> V[i];
    }

    for(int i=0; i<N; ++i) {
        for(int j=100; j>0; --j) {
            if(j > W[i])
                dp[j] = std::max(dp[j], dp[j-W[i]] + V[i]);
        }
    }

    cout << dp[100];

    return 0;
}