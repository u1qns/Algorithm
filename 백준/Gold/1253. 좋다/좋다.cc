#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> input;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, answer = 0;

    cin >> N;
    input.resize(N, 0);
    for(int i=0; i<N; ++i)
    {
        cin >> input[i];
    }

    sort(input.begin(), input.end());

    for(int i=0; i<N; ++i)
    {
        int start = 0;
        int end = N-1; // 음수가 있어서 전 범위 탐색
        int key = input[i];

        while(start < end)
        {
        	// 자기 자신은 제외
            if (start == i) start++;
            else if(end == i) end--;

			// 포인터 이동 후에도 조건 체크
            if(start >= end) continue;

            int cur = input[start] + input[end];
            if(key == cur)
            {
                ++answer;
                break;
            }

            if(key > cur) ++start;
            else  --end;
        }

    }

    cout << answer;
    return 0;
}