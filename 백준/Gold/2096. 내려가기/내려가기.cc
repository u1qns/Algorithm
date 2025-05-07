#include <iostream>
#include <vector>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int N;
    std::cin >> N;

    int arr[3] = {0, };
    int max_dp[2][3] = {0, };
    int min_dp[2][3] = {0, };
    bool idx = true;

    for(int i=1; i<=N; ++i)
    {
        std::cin >> arr[0] >> arr[1] >> arr[2];

        max_dp[idx][0] = std::max(max_dp[!idx][0], max_dp[!idx][1]) + arr[0];
        min_dp[idx][0] = std::min(min_dp[!idx][0], min_dp[!idx][1]) +  arr[0];

        max_dp[idx][1] = std::max(std::max(max_dp[!idx][0], max_dp[!idx][1]), max_dp[!idx][2]) + arr[1];
        min_dp[idx][1] = std::min(std::min(min_dp[!idx][0], min_dp[!idx][1]), min_dp[!idx][2]) + arr[1];

        max_dp[idx][2] = std::max(max_dp[!idx][1], max_dp[!idx][2]) + arr[2];
        min_dp[idx][2] = std::min(min_dp[!idx][1], min_dp[!idx][2]) + arr[2];

        idx = !idx;
    }

    int max_score = 0, min_score = 1e9;
    for(int i=0; i<3; ++i)
    {
        max_score = std::max(max_score, max_dp[!idx][i]);
        min_score = std::min(min_score, min_dp[!idx][i]);
    }

    std::cout << max_score << " " << min_score;

    return 0;
}