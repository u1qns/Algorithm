#include <iostream>
#include <queue>

using namespace std;
int N;
deque<pair<int, int>> dq;

int main()
{
    int tmp = 0;
    cin >> N;
    for(int i=1; i<=N; ++i)
    {
        cin >> tmp;
        dq.push_back({i, tmp});
    }

    while(!dq.empty())
    {
        pair<int, int> front = dq.front();
        dq.pop_front();

        cout << front.first << " ";

        if(dq.empty()) break;

        if(front.second > 0)
        {
            for(int i=0; i<front.second-1; ++i)
            {
                dq.push_back(dq.front());
                dq.pop_front();
            }
        }
        else
        {
            for(int i=0; i<front.second*-1; ++i)
            {
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }
    }
    return 0;
}
