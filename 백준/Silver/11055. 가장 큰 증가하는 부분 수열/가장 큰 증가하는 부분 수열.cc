#include <iostream>
#include <algorithm>

using namespace std;
constexpr int MAX_N = 1000 + 1;

int main()
{
    int N, answer = 0;
    int arr[MAX_N], dp[MAX_N] = {0, };

    cin >> N;

    for (int k=0; k<N; ++k)
    {
        cin >> arr[k];

        int max = 0;
        for (int i=0; i<k; ++i)
        {
            if (arr[i] < arr[k] && dp[i] > max)
                max = dp[i];
        }
        
        answer = std::max(answer, dp[k] = max + arr[k]);
    }
    
    cout << answer;
    
    return 0;
}