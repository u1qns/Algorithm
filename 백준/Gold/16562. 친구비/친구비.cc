#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

constexpr int MAX_N = 10000 + 1;

int N, M, K, cost[MAX_N];
vector<int> root;

int find(const int x)
{
    if(root[x] < 0) return x;
    return root[x] = find(root[x]);
}

bool merge(const int a, const int b)
{
    int r1 = find(a);
    int r2 = find(b);

    if(r1 == r2) return false;

    if(cost[r1] > cost[r2]) // r2가 최소금액이기 때문에 그룹의 리더가 된다
    {
        root[r2] += root[r1]; // 개수 갱신 - 그냥 의미 없는 깊이 조정임
        root[r1] = r2; // r1의 리더는 r2다
    }
    else
    {
        root[r1] += root[r2];
        root[r2] = r1;
    }
    return true;
}

int main()
{
    int answer = 0;

    cin >> N >> M >> K;
    root.resize(N+1, -1);

    for(int i=1; i<=N; ++i)
        cin >> cost[i];

    int v, w;
    for(int i=0; i<M; ++i)
    {
        cin >> v >> w;

        merge(v, w);
    }

    for(int i=1; i<=N; ++i)
    {
        int parent = find(i);
        if(parent == i)
            answer += cost[i];
    }


    if(answer > K)
        cout << "Oh no";
    else
        cout << answer;

    return 0;
}