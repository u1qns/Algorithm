#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
typedef pair<int, int> pii;

constexpr int MAX_N = 40 + 1;
constexpr int MAX_M = 10 + 1;

int N, M, K, answer = 0;
int grid[MAX_N][MAX_N] = {false, };
int tmp_sticker[MAX_M][MAX_M] = {false, };


struct Sticker
{
    int r, c;
    int size = 0;
    int grid[MAX_M][MAX_M] = {0, };
} stickers[100];

bool isValid(const int x, const int y)
{
    if(x<0 || y<0 || x>=N || y>=M)
        return false;
    return true;
}

void show()
{
    for(int i=0; i<N; ++i)
    {
        for(int j=0; j<M; ++j)
        {
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }
}

bool try_attach(const pii& start, const Sticker& target)
{
    for(int i=0; i<target.r; ++i)
    {
        for(int j=0; j<target.c; ++j)
        {
            if(grid[i + start.first][j + start.second] && target.grid[i][j])
                return false;
        }
    }

    return true;
}

void painting(const pii& start, const Sticker& target)
{
    for(int i=0; i<target.r; ++i)
    {
        for(int j=0; j<target.c; ++j)
        {
            if(target.grid[i][j])
                grid[i + start.first][j + start.second] = 1;
        }
    }

}

bool attach(Sticker& target)
{
    for(int i=0; i<N; ++i)
    {
        for(int j=0; j<M; ++j)
        {
            if(!isValid(i + target.r - 1, j + target.c -1))
                break;

            if(try_attach(make_pair(i, j), target))
            {
                painting(make_pair(i, j), target);
                answer += target.size;
                return true;
            }
        }
    }

    return false;
}

void rotation90(Sticker& target)
{
    for(int i=0; i<target.r; ++i)
    {
        for(int j=0; j<target.c; ++j)
        {
            tmp_sticker[j][target.r - i - 1] = target.grid[i][j];
        }
    }

    std::swap(target.r, target.c);
    for(int i=0; i<target.r; ++i)
    {
        for(int j=0; j<target.c; ++j)
        {
            target.grid[i][j] = tmp_sticker[i][j];
        }
    }
}

void solve()
{
    for(auto& target : stickers)
    {
        for(int d=0; d<4; ++d)
        {
            if(attach(target))// t번째 스티커를 d방향으로 붙이려고 합니다
                break;

            if(d == 3) break;
            rotation90(target); // 안되면 돌려 - 한번 붙이고 말거라 그냥 덮어씀
        }
    }
}

int main()
{
    int r, c;
    cin >> N >> M >> K;
    for(int i=0; i<K; ++i)
    {
        cin >> r >> c;
        stickers[i].r = r;
        stickers[i].c = c;

        for(int j=0; j<r; ++j)
        {
            for(int k=0; k<c; ++k)
            {
                cin >> stickers[i].grid[j][k];
                if(stickers[i].grid[j][k])
                    stickers[i].size++;
            }
        }
    }

    solve();
    cout << answer;

    return 0;
}