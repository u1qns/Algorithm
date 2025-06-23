#include <iostream>
#include <algorithm>

using namespace std;
constexpr int MAX_N = 100000 + 1;
int N, M;
int arr[MAX_N] = {0, };

// target초 일때 수용 가능한 인원을 출력해보자
long long solve(const long long t)
{
    long long total = 0;
    for(int i=0; i<N; ++i)
    {
       total += t / arr[i];
       if(total > M) return total; // 32퍼틀 수정
    }
    return total;
}

long long binary_search()
{
    long long left = 0;
    long long right = 1e18; // 최대로 잡음
    long long answer = 1e18;

    while(left <= right)
    {
        long long mid = (left + right) / 2;
        long long cnt = solve(mid);

        //printf("%d초 일 때 %d명 통과 가능함 \n", mid, cnt);
        if(M > cnt)
        {
            left = mid + 1;
        }
        else
        {
            answer = std::min(answer, mid);
            right = mid - 1;
        }
    }

    return answer;
}


int main()
{
    cin >> N >> M;
    for(int i=0; i<N; ++i)
    {
        cin >> arr[i];
    }

    cout << binary_search();

    return 0;
}