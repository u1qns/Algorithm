#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;

int N;
deque<int> pass;

vector<int> solve(deque<pii>&& wait)
{
    vector<int> result;

    for (int i = 1; i < 2 * N; ++i)
    {

        if (i % 2 == 1)
        {
            if(pass.empty())
                return {-1};

            result.push_back(pass.front());
            pass.pop_front();
        }
        else
        {
            if (wait.empty())
                return {-1};

            auto& now = wait.front();
            result.push_back(now.first);
            now.second--;

            if (now.second == 0)
            {
                pass.push_back(now.first);
                wait.pop_front();
            }
        }
    }

    return result;
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
 
    int S;
    vector<pii> fail;

    cin >> N;
    for (int i = 1; i <= N; ++i)
    {
        cin >> S;
        if (S == 0)
            pass.push_back(i);
        else
            fail.push_back({i, S});
    }

    std::sort(fail.begin(), fail.end(), [](const pii& a, const pii& b) {
        return a.second < b.second;
    });

    vector<int> answer = solve(deque<pii>(make_move_iterator(fail.begin()), make_move_iterator(fail.end())));

    for (const int ans : answer)
        cout << ans << "\n";

    return 0;
}