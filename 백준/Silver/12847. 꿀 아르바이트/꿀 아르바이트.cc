#include <iostream>
#include <algorithm>
using namespace std;

constexpr int MAX_N = 100000 + 1;
long long prefix[MAX_N + 1] = {0, };

int main()
{
    int N, M, inp;
    long long answer = 0;
    cin >> N >> M;
    for(int i=0; i<N; ++i)
    {
        cin >> inp;
        prefix[i+1] = prefix[i] + inp;
    }

    for(int i=0; i<=N-M; ++i)
    {
        answer = std::max(answer, prefix[i + M] - prefix[i]);
    }

    cout << answer;

    return 0;
}