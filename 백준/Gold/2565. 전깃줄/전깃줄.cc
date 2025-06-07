#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

int main()
{
    int N, max = 0;
    int a, b;
    
    std::cin >> N;
    std::vector<std::pair<int, int>> A;
    std::vector<int> DP(N, 1);
    
    for (int i = 0; i<N; ++i)
    {
        std::cin  >> a >> b;
        A.push_back({a,b});
    }

    std::sort(A.begin(), A.end());
    
    for (int k=0; k<N; ++k)
    {
        for (int i=0; i<k; ++i)
        {
            if (A[i].second < A[k].second && DP[k] < DP[i] + 1)
            {
                DP[k]++;
            }
        }
        max = (max < DP[k] ? DP[k] : max);
    }
    
    std::cout << N-max;
    
    return 0;
}
