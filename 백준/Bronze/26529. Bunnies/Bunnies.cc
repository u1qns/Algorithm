#include <iostream>
using namespace std;
int N, fibo[46] = {1, };

int solve(const int x)
{
    if(x == 0 || x == 1) return 1;
    if(fibo[x] != 0) return fibo[x];
    return fibo[x] = solve(x-1) + solve(x-2);
}

int main()
{
    int T;
    cin >> T;

    while(T--)
    {
        cin >> N;
        cout << solve(N) << "\n";
    }

    return 0;
}