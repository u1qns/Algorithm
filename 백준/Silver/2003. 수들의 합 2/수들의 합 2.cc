#include <iostream>
#include <vector>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int N, M, inp, answer = 0;

    cin >> N >> M;

    vector<int> prefixSum(N+1, 0);
    for(int i=1; i<=N; ++i)
    {
        cin >> inp;
        prefixSum[i] += prefixSum[i-1] + inp;

        for(int j=i-1;j>=0; --j)
        {
            if(prefixSum[j] < prefixSum[i] - M)
                break;

            if(prefixSum[i] - prefixSum[j] == M)
            {
                ++answer;
            }
        }
    }

    cout << answer;
    return 0;
}
