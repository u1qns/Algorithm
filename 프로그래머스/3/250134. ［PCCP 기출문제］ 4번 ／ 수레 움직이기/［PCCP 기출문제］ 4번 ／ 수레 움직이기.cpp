#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
typedef pair<int, int> pii;

constexpr int MAX_N = 4 + 1;
constexpr int dx[] = {0, 1, 0, -1};
constexpr int dy[] = {1, 0, -1, 0};
enum
{
    EMPTY,
    RED,
    BLUE,
    DST_RED,
    DST_BLUE,
    BLOCK
};

int N, M, answer = 1e9;
pii red, blue;
bool visited[2][MAX_N][MAX_N] = {false, }; // RED, BLUE

bool isValid(int x, int y)
{
    if(x<0 || y<0 || x>=N || y>=M)
        return false;
    return true;
}


void dfs(const vector<vector<int>>& maze,
         const int _rx, const int _ry, const int _bx, const int _by,
         const int sum)
{
    bool rArrive = maze[_rx][_ry] == DST_RED;
    bool bArrive = maze[_bx][_by] == DST_BLUE;

    if(rArrive && bArrive)
    {
        answer = (answer < sum ? answer : sum);
        return;
    }

    int rx = _rx; int ry = _ry;
    int bx = _bx; int by = _by;

    for(int d=0; d<4; ++d)
    {
        if(!rArrive)
        {
            rx = _rx + dx[d];
            ry = _ry + dy[d];

            if (!isValid(rx, ry) || visited[0][rx][ry] || maze[rx][ry] == BLOCK) continue;
            visited[0][_rx][_ry] = true;
        }

        for(int bd=0; bd<4; ++bd)
        {
            if(!bArrive)
            {
                bx = _bx + dx[bd];
                by = _by + dy[bd];

                if (!isValid(bx, by) || visited[1][bx][by] || maze[bx][by] == BLOCK) continue;

            }

            if((bx == rx) && (ry == by)) continue; // 수레가 겹치잖아
            if(bx == _rx && by == _ry)
            {
                if(rx == _bx && ry == _by)
                    continue;
            }
            visited[1][_bx][_by] = true;
            dfs(maze, rx, ry, bx, by, sum + 1);

            if(bArrive) break;
            visited[1][bx][by] = false;
        }

        if(rArrive) break;
        visited[0][rx][ry] = false;
    }
}

int solution(std::vector<std::vector<int>> maze) {

    N = maze.size();
    M = maze[0].size();

    for(int i=0; i<N; ++i)
    {
        for(int j=0; j<M; ++j)
        {
            if(maze[i][j] == RED)
            {
                red = make_pair(i, j);
            }
            else if(maze[i][j] == BLUE)
            {
                blue = make_pair(i, j);
            }
        }
    }

    dfs(maze, red.first, red.second, blue.first, blue.second, 0);

    return (answer == 1e9 ? 0 : answer);
}

