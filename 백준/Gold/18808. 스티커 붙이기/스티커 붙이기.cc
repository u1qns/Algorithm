#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
typedef pair<int, int> pii;

constexpr int MAX_N = 40 + 1;
constexpr int MAX_M = 10 + 1;
constexpr int dx[] = {};
constexpr int dy[] = {};

int N, M, K, answer = 0;
int grid[MAX_N][MAX_N] = {false, };
struct Sticker
{
    int r, c;
    int size = 0;
    vector<vector<int>> grid;
    Sticker()
    {
        grid.resize(MAX_M, vector<int>(MAX_N, 0));
    }

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
            // 노트북에 스티커가 붙여져 있는데 나도 붙여야할때..
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

bool attach(const int idx)
{
    const Sticker& target = stickers[idx];
    for(int i=0; i<N; ++i)
    {
        for(int j=0; j<M; ++j)
        {
            if(!isValid(i + target.r - 1, j + target.c -1)) continue;

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

void rotation90(const int sticker_idx)
{
    auto& org = stickers[sticker_idx];
    vector<vector<int>> result(MAX_M, vector<int>(MAX_M, 0));

    for(int i=0; i<org.r; ++i)
    {
        for(int j=0; j<org.c; ++j)
        {
            result[j][org.r - i - 1] = org.grid[i][j];
        }
    }

    std::swap(org.r, org.c);
    for(int i=0; i<org.r; ++i)
    {
        for(int j=0; j<org.c; ++j)
        {
            stickers[sticker_idx].grid[i][j] = result[i][j];
        }
    }
}

void solve()
{
    for(int t=0; t<K; ++t)
    {
        for(int d=0; d<4; ++d)
        {
            if(attach(t))// t번째 스티커를 d방향으로 붙이려고 합니다
                break;
            rotation90(t); // 안되면 돌려 - 한번 붙이고 말거라 그냥 덮어씀
        }
//        cout << "@grid status\n";
//        show();

    }
}

void test()
{
    cout << "rotation 90 test\n";
    for(int i=0; i<K; ++i)
    {
        auto& target = stickers[i];
        rotation90(i);
        for(int i=0; i<target.r; ++i)
        {
            for(int j=0; j<target.c; ++j)
                cout << target.grid[i][j] << " ";
            cout << "\n";
        }
        cout << "\n=========================\n";
    }
    cout << "\n";
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