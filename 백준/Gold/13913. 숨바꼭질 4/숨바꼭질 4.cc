#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int MAX_N = 100000 + 1;
const int op[2] = {+1,-1};

int N, K, route[MAX_N] = {0, };
bool visited[MAX_N] = {false, };

bool isValid(const int x)
{
    if(x < 0 || x >= MAX_N)
        return false;
    return true;
}

vector<int> solve()
{
    queue<int> q;
    q.push(N);

    vector<int> answer;
    visited[N] = true;

    while(!q.empty())
    {
        int now = q.front(); q.pop();

        for(int d=0; d<3; ++d)
        {
            int next = (d == 2 ? now * 2 : now + op[d]);

            if(!isValid(next) || visited[next])
                continue;

            route[next] = now;
            if(next == K)
            {
                answer.push_back(K);
                while(route[next] != N)
                {
                    answer.push_back(route[next]);
                    next = route[next];
                }

                return answer;
            }

            visited[next] = true;
            q.push(next);
        }
    }

    return answer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;
    if(N==K)
        cout << "0\n" << K;
    else
    {
        auto answer = solve();
        cout << answer.size() << "\n";
        cout << N << " ";
        for(auto iter=answer.rbegin(); iter!=answer.rend(); ++iter)
        {
            cout << *iter << " ";
        }
    }

    return 0;
}
