#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;
constexpr int MAX_N = 50000+2;

int N, M; //node, edge
//int adj[MAX_N][MAX_N] = {0, };
vector<vector<pii>> adj;
int main() 
{
    int A, B, C;
    cin >> N >> M;
    
    adj.resize(N+2);
    for(int i=0; i<M; ++i)
    {
        cin >> A >> B >> C;
        //adj[A][B] = adj[B][A] = C;
        adj[A].push_back({C, B});
        adj[B].push_back({C, A});        
    }
    
    priority_queue<pii, vector<pii>, std::greater<>> pq;
    pq.push({0, 1});
    
    //vector<vector<int>> dp(N+1, vector<int>(N+1, 1e9));
    vector<int> dp(N+2, 1e9);
    dp[1] = 0;
    while(!pq.empty())
    {
        auto top = pq.top(); pq.pop();
        if(top.first > dp[top.second]) continue;
        
        for(const auto& next : adj[top.second])
        {
            int next_cost = next.first + dp[top.second];
            int next_node = next.second;
            
            if(dp[next_node] > next_cost)
            {
                dp[next_node] = next_cost;
                pq.push({next_cost, next_node});
            }
        }
    }
    cout << dp[N];
    return 0;
}
