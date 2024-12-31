#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<long long> guitars;
int N, answer = 1e9;
long long tmp = 0; // 가장 많이 친 곡 수 

void dfs(const int depth, const int cnt, const long long mask)
{
    if (mask == tmp && answer > cnt)
    {
        answer = cnt;
    }
    else if(mask > tmp)
    {
        tmp = mask;
        answer = cnt;
    }

    if(depth == N)
        return;

    dfs(depth+1, cnt+1, (mask | guitars[depth]));
    dfs(depth+1, cnt, mask);
}

int main()
{
    string guitar, inp;
    int M;

    cin >> N >> M;

    guitars.resize(N);
    for(int i=0; i<N; ++i)
    {
        long long mask = 0b0;
        cin >> guitar >> inp;
        for(int j=0; j<M; ++j)
        {
            if(inp[j] == 'Y')
                mask|= (1LL << (M-1-j)); // LL는 있어야 한다..
        }
        guitars[i] = mask;
    }

    dfs(0, 0, 0);

    cout << (answer == 0 ? -1 : answer);

    return 0;
}
