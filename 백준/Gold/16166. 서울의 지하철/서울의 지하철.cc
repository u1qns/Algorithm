#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, dest;
int answer = 1e9;
vector<int> adj[11];
vector<int> start;
bool check[11];

void dfs(int x, int time)
{
    check[x] = true;
    for(int i=0; i<adj[x].size(); ++i)
    {
        if(adj[x][i] == dest)
        {
            answer = min(answer,time);
            check[x] = false;
            return;
        }

        for(int j=0; j<N; ++j)
        {
            if(j == x) continue;
            for(int k=0; k<adj[j].size(); ++j)
            {
                if(check[j] || adj[j][k] != adj[x][i]) continue;
                dfs(j, time+1);
            }
        }
    }
    check[x] = false;
}



int main() {

    // input
    cin >> N;
    int K, station;
    for(int i=0; i<N; i++)
    {
        cin >> K;
        for(int j=0; j<K; j++)
        {
            cin >> station;
            adj[i].push_back(station);

            if(station == 0)
                start.push_back(i);
        }
    }
    cin >> dest;

    for(int i=0; i<start.size(); ++i)
        dfs(start[i],0);

	cout << (answer == 1e9 ? -1 : answer);
    return 0;

}