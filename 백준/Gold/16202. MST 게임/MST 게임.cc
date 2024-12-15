#include <iostream>
#include <algorithm>
#include <queue>
#include <memory.h>
#include <vector>

using namespace std;

constexpr int MAX_N = 1000 + 1;
int N, M, K;

struct Info
{
    Info(int cost, int from, int to)
    :cost(cost), from(from), to(to) {};
    int from, to, cost;
};

struct cmp
{
    bool operator()(const Info& a, const Info& b)
    {
        return a.cost > b.cost;
    }
};
typedef priority_queue<Info, vector<Info>, cmp> PQ;

struct UF
{
    vector<int> root;
    UF(const int size)
    {
        root.resize(size, -1);
    }

    bool merge(const int x, const int y)
    {
        int r1 = find(x);
        int r2 = find(y);
        if(r1 == r2) return false;
        if(root[r1] > root[r2])
        {
            root[r2] += root[r1];
            root[r1] = r2;
        }
        else
        {
            root[r1] += root[r2];
            root[r2] = r1;
        }
        return true;
    }

    int find(const int x)
    {
        if(root[x] < 0) return x;
        return root[x] = find(root[x]);
    }
};

int getAnswer(PQ pq)
{
    int answer = 0;
    int cnt = 0;

    bool visited[MAX_N] = {false, };
    memset(visited, false, sizeof(visited));

    UF uf = UF(N+1);
    while(!pq.empty())
    {
        auto top = pq.top(); pq.pop();

        if(uf.merge(top.from, top.to))
        {
            answer += top.cost;
            if(++cnt == N-1)
                return answer;
        }
    }
    return 0;
}
int main()
{
    cin >> N >> M >> K;

    int a, b;
    PQ pq;
    for(int cost=1; cost<=M; ++cost)
    {
        cin >> a >> b;
        pq.push({cost, a, b});
    }

    for(int i=0; i<K; ++i)
    {
        cout << getAnswer(pq) << " ";
        pq.pop();
    }

    return 0;
}