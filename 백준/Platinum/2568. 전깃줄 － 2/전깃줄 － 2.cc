#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<pair<int, int>> arr;      // (A, B)
vector<int> lis;                 // LIS 값 저장 (B 기준)
vector<int> pos;                 // lis에 들어간 arr의 인덱스
vector<int> pre;                // 추적용 - 이전 인덱스 저장
vector<bool> is_in_lis;          // 어떤 A가 LIS에 포함됐는지

int lower_bound(int left, int right, int target)
{
    while (left < right)
    {
        int mid = (left + right) / 2;
        if (lis[mid] < target)
            left = mid + 1;
        else
            right = mid;
    }
    return left;
}

void computeLIS()
{
    lis.push_back(arr[0].second);
    pos.push_back(0);
    pre.assign(N, -1);

    for (int i = 1; i < N; ++i)
    {
        int val = arr[i].second;

        if (val > lis.back())
        {
            pre[i] = pos.back();
            lis.push_back(val);
            pos.push_back(i);
        }
        else
        {
            int idx = lower_bound(0, lis.size(), val);
            lis[idx] = val;
            pos[idx] = i;
            pre[i] = (idx > 0 ? pos[idx - 1] : -1);
        }
    }

    // LIS 구성 요소 체크
    is_in_lis.assign(N, false);
    int cur = pos.back();
    while (cur != -1)
    {
        is_in_lis[cur] = true;
        cur = pre[cur];
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    arr.resize(N);
    for (int i = 0; i < N; ++i)
        cin >> arr[i].first >> arr[i].second;

    sort(arr.begin(), arr.end()); // A 기준 정렬
    computeLIS();

    // 출력
    cout << N - lis.size() << '\n'; // 제거해야 할 개수

    // 제거 대상 A값 출력
    for (int i = 0; i < N; ++i)
    {
        if (!is_in_lis[i])
            cout << arr[i].first << '\n';
    }

    return 0;
}