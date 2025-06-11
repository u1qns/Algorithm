#include <iostream>
#include <queue>

using namespace std;
int dp[1001][31][2]; // t시간에 w번 움직인 결과 나는 line에 위치함

int main()
{
    int T, W, plum, answer = 0;

    cin >> T >> W;

    if(T == 1 && W == 1)
    {
        cout << 1;
        return 0;
    }
    for(int t=0; t<T; ++t) {
        cin >> plum;

        --plum;

        for (int w = 0; w <= W; ++w) {
            // 답 봄 --------
            if (t == 0) {
                if (w == 0) {
                    dp[t][w][0] = (plum == 0 ? 1 : 0);
                    dp[t][w][1] = 0;
                }
                else {
                    dp[t][w][0] = 0;
                    dp[t][w][1] = (plum == 1 ? 1 : 0);
                }
            }
            else {
                dp[t][w][0] = dp[t - 1][w][0]; // 일단 전의 상태 데려옴
                if (w > 0)
                    dp[t][w][0] = max(dp[t][w][0], dp[t - 1][w - 1][1]);
                // 현재 0로 오려면 이동하는게 나을까? + 현재 위치에 자두 있으면 주워!
                dp[t][w][0] += (plum == 0 ? 1 : 0);


                dp[t][w][1] = dp[t - 1][w][1];
                if (w > 0)
                    dp[t][w][1] = max(dp[t][w][1], dp[t - 1][w - 1][0]);
                dp[t][w][1] += (plum == 1 ? 1 : 0);


                int tmp = std::max(dp[t][w][0], dp[t][w][1]);
                answer = std::max(answer, tmp);
            }
        }
    }

        cout << answer;

        return 0;
    }