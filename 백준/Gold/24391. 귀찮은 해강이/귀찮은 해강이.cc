#include <iostream>
#include <vector>

// 유니온 파인드
using namespace std;
struct UF
{
    vector<int> root;
    UF(const int size)
    {
        root.resize(size+1, -1);
    }

    bool merge(const int x, const int y)
    {
        int rx = find(x);
        int ry = find(y);
        if(rx == ry)
            return false;

        if(root[rx] > root[ry])
        {
            root[ry] += root[rx];
            root[rx] = ry;
        }
        else
        {
            root[rx] += root[ry];
            root[ry] = rx;
        }
        return true;
    }

    int find(const int x)
    {
        if(root[x] < 0) return x;
        return root[x] = find(root[x]);
    }
};
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    int N, M, answer = 0;

    cin >> N >> M;
    UF uf = UF(N);

    int a, b;
    for(int i=0; i<M; ++i)
    {
        cin >> a >> b;
        uf.merge(a, b);
    }

    int now, next;
    cin >> now;
    for(int j=1; j<N; ++j)
    {
        cin >> next;
        if(uf.find(now) != uf.find(next))
            ++answer;
        now = next;
    }
    cout << answer;

    return 0;
}