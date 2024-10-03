#include <iostream>
using namespace std;
 
const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {1, -1, 0, 0};
const int MAX = 250 + 1;

int R, C;
bool visited[MAX][MAX] = {false, };
char grid[MAX][MAX] = {false, };

int sheep, total_sheep = 0;
int wolf, total_wolf = 0;

bool isValid(const int x, const int y)
{
    if(x<0 || y<0 || x>=R || y>=C)
        return false;
    return true;
}

void solve(const int x, const int y)
{
    if(grid[x][y] == 'o') sheep++;
    else if(grid[x][y] == 'v') wolf++;
 
    for(int d = 0; d<4; ++d)
    {
        int nx = x + dx[d];
        int ny = y + dy[d];
        
        if(!isValid(nx, ny) || visited[nx][ny] || grid[nx][ny] == '#') continue;
        
        visited[nx][ny] = true;
        solve(nx, ny);
    }
 
}
 
int main()
{
    cin >> R >> C;
    for(int i=0; i<R;++i)
    {
        for(int j=0; j<C;++j)
        {
            cin >> grid[i][j];
        }
    }
 
    for(int i=0; i<R; ++i)
    {
        for(int j=0; j<C; ++j)
        {
            if(visited[i][j] || grid[i][j] == '#') continue;
            
            visited[i][j] = true;
            wolf = sheep = 0;
            solve(i, j);

            if(sheep > wolf)
                total_sheep += sheep;
            else
                total_wolf += wolf;
        }
    }
    
    cout << total_sheep << " " << total_wolf;
    return 0;
}