#include <iostream>
#include <bitset>
#include <algorithm>
#include <queue>
using namespace std;
typedef pair<int, int> pii;
constexpr int MAX_N  = 50 + 1;

// 서북동남
constexpr int dx[4] = {0, -1, 0, 1};
constexpr int dy[4] = {-1, 0, 1, 0};
// 2234 성곽 4시 진짜 시작 ㅠ

int N, M;
int maxRoomSize = 0;
std::bitset<4> grid[MAX_N][MAX_N];
int roomIndex[MAX_N][MAX_N] = {0, };

bool isValid(const int x, const int y)
{
    if(x<0 || y<0 || x>=N || y>=M)
        return false;
    return true;
}

vector<vector<pii>> totalRoom;

vector<pii> solve(const int r, const int c, const int idx)
{
    vector<pii> rooms;
    rooms.push_back({r, c});

    queue<pii> q;
    q.push({r, c});

    vector<int> adj;
    roomIndex[r][c] = idx;

    while(!q.empty())
    {
        auto front = q.front(); q.pop();
        for(int d=0; d<4; ++d)
        {
            bool isWall = grid[front.first][front.second][d];
            if(isWall) continue;

            // 2진수였을 때 d 자리 수가 1이면 벽이 있어서 못감
            int x = front.first + dx[d];
            int y = front.second + dy[d];

            if(!isValid(x, y) || roomIndex[x][y])
                continue;

            q.push({x, y});
            rooms.push_back({x, y});
            roomIndex[x][y] = idx;
        }
    }

    return rooms;
}

int getCrushedRoomSize()
{
    int crushedRoomSize = 0;
    for(int i=0; i<N; ++i)
    {
        for(int j=0; j<M; ++j)
        {
            int nowIndex = roomIndex[i][j] - 1;
            int nowSize = totalRoom[nowIndex].size();

            for(int d=2; d<4; ++d)
            {
                int x = i + dx[d];
                int y = j + dy[d];

                if(!isValid(x, y) || roomIndex[i][j] == roomIndex[x][y]) continue;

                int targetIndex = roomIndex[x][y] - 1;
                int targetSize = totalRoom[targetIndex].size();

                if(crushedRoomSize < nowSize + targetSize)
                    crushedRoomSize = nowSize + targetSize;
            }
        }
    }

    return crushedRoomSize;
}

int main()
{
    cin >> M >> N;
    for(int i=0; i<N; ++i)
    {
        for(int j=0; j<M; ++j)
        {
            int inp; cin >> inp;
            grid[i][j] = inp;
        }
    }

    for(int i=0; i<N; ++i)
    {
        for(int j=0; j<M; ++j)
        {
            if(roomIndex[i][j]) continue;

            auto room = solve(i, j, totalRoom.size() + 1);
            totalRoom.push_back(room);
            if(room.size() > maxRoomSize)
                maxRoomSize = room.size();
        }
    }

    cout << totalRoom.size() << "\n" << maxRoomSize << "\n" << getCrushedRoomSize() << "\n";

    return 0;
}