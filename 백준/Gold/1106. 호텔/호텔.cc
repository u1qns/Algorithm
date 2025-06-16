#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int C, N, answer = 1e9;
    int cost, value;
    cin >> C >> N;
    vector<int> dp(C+101, 1e9);
    dp[0] = 0;

    for(int i=0; i<N; ++i)
    {
        cin >> cost >> value; // cost원 들이면 인구수 value 만큼 얻을 수 있다
        dp[value] = std::min(dp[value], cost);

        // 인구수 증가
        for(int j=value; j<=C+100; ++j)
        {
            dp[j] = std::min(dp[j], dp[j - value] + cost);
        }

    }

    for (int i = C; i <= C + 100; ++i) {
        answer = min(answer, dp[i]);
    }


    cout << answer;
    return 0;
}