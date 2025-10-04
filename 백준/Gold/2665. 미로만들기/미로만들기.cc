#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;
constexpr int dx[4] = {0, 0, -1, 1};
constexpr int dy[4] = {-1, 1, 0, 0};
constexpr int MAX_N = 50 + 1;

int N, grid[MAX_N][MAX_N];
int visited[MAX_N][MAX_N] = {0, };

int  main()
{
    cin >> N;

    char ch;
    for(int i=0; i<N; ++i) {
        for(int j=0; j<N; ++j) {
            cin >> ch;
            visited[i][j] = 1e9;
            grid[i][j] = ch - '0';
        }
    }

    visited[0][0] = 0;

    deque<pair<int, int>> q;
    q.push_front({0, 0});
    while(!q.empty()) {
        int qSize = q.size();
        while(qSize--) {
            auto front = q.front(); q.pop_front();
            int cost = visited[front.first][front.second];

            if(cost >= visited[N-1][N-1])
                continue;

            for(int d=0; d<4; ++d) {
                int x = front.first + dx[d];
                int y = front.second + dy[d];

                if(x<0 || y<0  || x>=N || y>=N) continue;

                int next_cost = cost + (grid[x][y] == 0);
                if(next_cost >= visited[x][y]) continue;

                visited[x][y] = next_cost;

                if(grid[x][y] == 0)
                    q.push_back({x, y});
                else
                    q.push_front({x, y});

            }
        }
    }

    cout << visited[N-1][N-1];

    return 0;
}