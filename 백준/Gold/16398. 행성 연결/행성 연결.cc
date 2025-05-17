#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> parent;

struct Node
{
    int cost, from, to;
};

struct cmp
{
    bool operator()(const Node& a, const Node& b)
    {
        return a.cost > b.cost;
    }
};

int find(const int x)
{
    if(parent[x] < 0)
        return x;
    return parent[x] = find(parent[x]);
}

bool merge(const int a, const int b)
{
    int ra = find(a);
    int rb = find(b);

    if(ra == rb) return false;

    if(ra < rb)
    {
        parent[ra] += parent[rb];
        parent[rb] = ra;
    }
    else
    {
        parent[rb] += parent[ra];
        parent[ra] = rb;
    }

    return true;
}

int main()
{
    long long answer = 0L;
    int N;
    int count = 0, cost;

    priority_queue<Node, vector<Node>, cmp> pq;

    cin >> N;
    for(int i=0; i<N; ++i)
    {
        for(int j=0; j<N; ++j)
        {
            cin >> cost;
            pq.push({cost, i, j});
        }
    }

    parent.resize(N, -1);
    while(!pq.empty())
    {
        auto front = pq.top(); pq.pop();

        if(merge(front.from, front.to))
        {
            answer += front.cost;
            if(++count == N-1)
                break;
        }
    }

    std::cout << answer;

    return 0;
}