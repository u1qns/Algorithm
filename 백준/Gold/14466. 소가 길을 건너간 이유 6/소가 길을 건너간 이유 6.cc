#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <memory.h>

using namespace std;
constexpr int MAX_N = 100 + 1;
constexpr int MAX_K = MAX_N * MAX_N;
constexpr int dx[4] = {-1, 1, 0, 0};
constexpr int dy[4] = {0, 0, -1, 1};

typedef pair<int, int> pii;
int N, K, R;
int grid[MAX_N][MAX_N] = {0, };
bool visited[MAX_N][MAX_N] = {false, };
bool match[MAX_K][MAX_K] = {false, };
vector<pii> roads[MAX_N][MAX_N];
vector<pii> cows;


bool isValid(const int x, const int y)
{
    if(x<=0 || y<=0 || x > N || y > N)
        return false;
    return true;
}
bool isValid(const pii& pos, const int d)
{
    int x = pos.first + dx[d];
    int y = pos.second + dy[d];

    if(!isValid(x, y))
        return false;

    for(const auto& [nx, ny] : roads[pos.first][pos.second])
    {
        // 너가 가려고 하는 곳은 길이 있어
        if(x == nx && y == ny)
            return false;
    }
    return true;
}

void solve(const int idx)
{
    //printf("-------\n");
    queue<pii> q;
    q.push(cows[idx]);

    memset(visited, false, sizeof(visited));
    visited[cows[idx].first][cows[idx].second] = true;

    while(!q.empty())
    {
        auto front = q.front(); q.pop();
        //printf("front: %d, %d\n", front.first, front.second);
        for(int d=0; d<4; ++d)
        {
            int x = front.first + dx[d];
            int y = front.second + dy[d];

            if(!isValid(front, d) || visited[x][y]) continue;


            int cow = grid[x][y];
            if(cow > 0) // 여기 소가 있다!
                match[idx][cow] = match[cow][idx] = true;

            visited[x][y] = true;
            q.push({x, y});
        }
    }

}

int getAnswer()
{
    int answer = 0;
    for(int i=1; i<=K; ++i)
    {
        for(int j=i+1; j<=K; ++j)
        {
            if(!match[i][j])
                ++answer;
        }
    }
    return answer;
}
int main()
{
    cin >> N >> K >> R;

    int x, y, xx, yy;
    for(int i=0; i<R; ++i)
    {
        cin >> x >> y >> xx >> yy;
        roads[x][y].push_back({xx, yy});
        roads[xx][yy].push_back({x, y});
    }

    cows.resize(K+2);
    for(int i=1; i<=K; ++i)
    {
        cin >> x >> y;
        grid[x][y] = i; // 목초지 위치에 소가 있는지 바로 알 수 있도록
        cows[i] = make_pair(x, y);
    }

    for(int i=1; i<=K; ++i)
    {
        solve(i);
    }
//
//    for(int i=1; i<=N; ++i)
//    {
//        for(int j=1; j<=N; ++j) {
//            cout << match[i][j] << " ";
//        }
//        cout << "\n";
//    }

    cout << getAnswer();

    return 0;
}