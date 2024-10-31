#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int N, C, answer = 0;
    cin >> N >> C;

    vector<int> inp(N);
    for(int i=0; i<N; ++i)
        cin >> inp[i];
    sort(inp.begin(), inp.end());

    int left = 0;
    int right = inp[N-1]; // 최대 길이는 양 끝이니까
    while(left <= right) // N=1 대비해서 <가 아닌 <=
    {
        int mid = (left + right) / 2;
        
        int pre = inp[0]; // 첫 시작은 무조건 데려가
        int cnt = 1;

        for(int i=1; i<N; ++i)
        {
            // 근데 모든 거리가 같을 필요가 없는데 왜 이분 탐색?
            if(inp[i] - pre < mid) continue;
            ++cnt;
            pre = inp[i];
        }

        if(cnt >= C)
        {
            left = mid+1;
            answer = (answer > mid ? answer : mid);
            continue;
        }

        right = mid-1;
    }

    cout << answer;
    return 0;
}
