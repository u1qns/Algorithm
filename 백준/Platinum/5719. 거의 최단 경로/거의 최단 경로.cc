#include <iostream>
#include <algorithm>
#include <queue>
#include <memory.h>
using namespace std;
typedef pair<int, int> pii;

constexpr int MAX_N = 500 + 1;
int N, M, S, D;

struct Node
{
    int idx, cost, parent;
};

struct cmp
{
    bool operator()(const Node& a, const Node& b)
    {
        return a.cost > b.cost;
    }
};

vector<vector<pii>> info; // info[from] = { {from, cost}, ... }};
vector<vector<int>> parents; // 각 노드의 부모 저장
vector<vector<int>> all_paths; // 여러 경로들 저장
vector<int> path; // S->D 단일경로
bool removedPair[MAX_N][MAX_N] = {false, };

void eraseShorestPath(const int idx)
{
    path.push_back(idx);

    if(idx == S)
    {
        removedPair[S][idx] = true;
        all_paths.push_back(path);
    }
    else
    {
        for(int p : parents[idx])
        {
            if(removedPair[p][idx]) continue;
            removedPair[p][idx] = true;
            eraseShorestPath(p);
        }
    }

    path.pop_back();
}

void init()
{
    info.clear();
    info.resize(N);

    parents.clear();
    parents.resize(N);

    all_paths.clear();
    memset(removedPair, false, sizeof(removedPair));

    int from, to, cost;
    for (int i = 0; i < M; ++i)
    {
        cin >> from >> to >> cost;
        info[from].push_back({to, cost});
    }
}


int findShortestPath(bool second)
{
    vector<int> dp(N, 1e9);
    dp[S] = 0;

    priority_queue<Node, vector<Node>, cmp> pq;
    pq.push({S, 0, -1});

    while(!pq.empty())
    {
        auto [from, sum_cost, parent] = pq.top();
        pq.pop();

        if(sum_cost < dp[from]) continue;

        for(const auto& [idx, cost] : info[from])
        {
            int next_cost = cost + sum_cost;
            if(dp[idx] < next_cost) continue;

            // 최단 경로 제외
            if(second && removedPair[from][idx]) continue;

            // 모든 최단 경로 구할 때만 동일 비용인 새로운 루트 고려해줌
            if(!second && dp[idx] == next_cost)
            {
                parents[idx].push_back(from);
                //pq.push({idx, next_cost, from}); // 동일 비용이라는 것은 이미 방문했다는 것이므로 제외
            }
            else if(dp[idx] > next_cost)
            {
                parents[idx].clear();
                parents[idx].push_back(from);

                dp[idx] = next_cost;
                pq.push({idx, next_cost, from});
            }
        }
    }

    return (dp[D] == 1e9 ? -1 : dp[D]);
}


int solve()
{
    init();

    if(findShortestPath(false) == -1) return -1;

    eraseShorestPath(D);

    return findShortestPath(true);
}


int main()
{
    while(1)
    {
        cin >> N >> M;

        if(N == 0 && M == 0) break;

        cin >> S >> D;
        cout << solve() << "\n";
    }

    return 0;
}