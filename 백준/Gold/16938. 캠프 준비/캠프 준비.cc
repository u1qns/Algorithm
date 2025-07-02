#include <iostream>

using namespace std;

int N, L, R, X;
int answer = 0;
int A[16];

void solve(int cnt, int idx, int sum, int easy, int hard)
{
    if(cnt >= 2 && sum >= L && sum <= R && (hard - easy) >= X)
    {
        ++answer;
    }

    for(int i=idx; i<N; ++i)
    {
        int e = (A[i] < easy ? A[i] : easy);
        int h = (A[i] > hard ? A[i] : hard);
        solve(cnt+1, i+1, sum + A[i], e, h);
    }
}


int main()
{
    cin >> N >> L >> R >> X;

    for(int i=0; i<N; ++i)
    {
        cin >> A[i];
    }

    solve(0, 0, 0, 1e9, 0);

    cout << answer;

    return 0;
}