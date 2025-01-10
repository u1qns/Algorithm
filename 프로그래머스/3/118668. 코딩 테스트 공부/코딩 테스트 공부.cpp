#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int N;

struct Node
{
    Node(int alp, int cop, int cost, int visited = 0)
    :alp(alp), cop(cop), cost(cost), visited (0) {};
    int visited;
    int alp, cop;
    int cost;
};

int solution(int alp, int cop, vector<vector<int>> problems) {
    int answer = 1e9;

    int max_alp = 0,max_cop= 0;
    for(const auto& p : problems)
    {
        max_alp = std::max(max_alp, p[0]);
        max_cop = std::max(max_cop, p[1]);
    }

    vector<vector<int>> visited;
    visited.resize(max_alp + 1, vector<int>(max_cop + 1));

    N = problems.size();
    problems.push_back({0, 0, 1, 0, 1}); // alp 공부
    problems.push_back({0, 0, 0, 1, 1}); // cop 공부

    queue<Node> q;
    q.push({alp, cop, 0}); // 초기 상태

    while(!q.empty())
    {
        Node now = q.front(); q.pop();
        for(int i=0; i<problems.size(); ++i)
        {
            auto& p = problems[i];
            int cost = p[4];
            int req_al = p[0]; int req_co = p[1];
            int rwd_al = p[2]; int rwd_co = p[3];

            if(req_al > now.alp || req_co > now.cop) continue;

            Node next = Node(now.alp + rwd_al, now.cop + rwd_co, now.cost + cost);
            next.alp = min(next.alp, max_alp);
            next.cop = min(next.cop, max_cop);

            if (visited[next.alp][next.cop] == 0
                || visited[next.alp][next.cop] > next.cost)
            {
                visited[next.alp][next.cop] = next.cost;
                q.push(next);
            }
        }
    }
    
    return visited[max_alp][max_cop];
}