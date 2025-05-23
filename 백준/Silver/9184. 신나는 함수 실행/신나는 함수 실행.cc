
#include <iostream>

using namespace std;

int result[51][51][51] = {0, };
bool visited[51][51][51] = {false, };

int w(int a, int b, int c)
{
    if(a <= 0 || b <= 0 || c<=0)
        return 1;

    if(visited[a][b][c])
        return result[a][b][c];

    visited[a][b][c] = true;
    if(a > 20 || b > 20 || c > 20)
        return result[a][b][c] = w(20, 20, 20);

    if(a < b && b < c)
        return result[a][b][c] = w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c);

    return result[a][b][c] = w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1);
}

int main()
{
    int a, b, c;

    while(1)
    {
        cin >> a >> b >> c;
        if(a ==-1 && b == -1 && c == -1)
            break;

        printf("w(%d, %d, %d) = %d\n", a, b, c, w(a, b, c));
    }
    return 0;
}