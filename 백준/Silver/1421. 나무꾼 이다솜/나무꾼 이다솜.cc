#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int N, C, W;
vector<int> tree;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> C >> W;

    long long inp = 0;
    long long max_num = 0;
    long long answer = 0;

    for (int i = 0; i < N; i++)
    {
        cin >> inp;
        tree.push_back(inp);
        max_num = std::max(max_num, inp);
    }


    for (int i = 1; i <= max_num; i++)
    {
        long long result = 0;

        for (int j = 0; j < N; j++)
        {
            if (i == tree[j])
            {
                result += i * W;
            }
            else if (i < tree[j])
            {
                int t = (tree[j] % i == 0 ? -1 : 0);
                if (((tree[j] / i) + t) * C < (i * W) * (tree[j] / i))
                {
                    result -= ((tree[j] / i) + t) * C;
                    result += (i * W) * (tree[j] / i);
                }
            }
        }

        answer = (answer > result ? answer : result);
    }

    cout << answer;

    return 0;
}