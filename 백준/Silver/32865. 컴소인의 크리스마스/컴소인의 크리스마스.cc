#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;

vector<int> solve(int n, deque<int>& ready, deque<pii>& pending)
{
    vector<int> result;

    for (int t = 1; t < 2 * n; ++t)
    {
        if (t % 2 == 1)
        {
            if (ready.empty())
                return {-1};

            result.push_back(ready.front());
            ready.pop_front();
        }
        else
        {
            if (pending.empty())
                return {-1};

            auto& cur = pending.front();
            result.push_back(cur.first);
            cur.second--;

            if (cur.second == 0)
            {
                ready.push_back(cur.first);
                pending.pop_front();
            }
        }
    }

    return result;
}

int main()
{
    int N, S;
    deque<int> right;
    vector<pii> wrong;


    cin >> N;
    for (int i = 1; i <= N; ++i)
    {
        cin >> S;
        if (S == 0)
            right.push_back(i);
        else
            wrong.push_back({i, S});
    }

    sort(wrong.begin(), wrong.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    });

    deque<pair<int, int>> tmp(wrong.begin(), wrong.end());

    vector<int> result = solve(N, right, tmp);
    if (result.size() == 1 && result[0] == -1)
    {
        cout << -1 << "\n";
    }
    else
    {
        for (int x : result)
            cout << x << "\n";
    }

    return 0;
}
