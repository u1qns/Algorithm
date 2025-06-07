#include <iostream>
#include <vector>

int main()
{
    int N, max = 0;
    std::cin >> N;
    std::vector<int> A(N);
    std::vector<int> DP(N, 1);
    
    for (int i = 0; i<N; ++i)
        std::cin >> A[i];

    for (int k=0; k<N; ++k)
    {
        for (int i=0; i<k; ++i)
        {
            if (A[i] < A[k] && DP[k] < DP[i] + 1)
            {
                DP[k]++;
            }
        }
        max = (max < DP[k] ? DP[k] : max);
    }
    
    std::cout << N-max;
    
    return 0;
}
