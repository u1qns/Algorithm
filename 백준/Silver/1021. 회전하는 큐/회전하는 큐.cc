#include <iostream>
#include <deque>
using namespace std;

int main()
{
    deque<int> dq;
    int N, M, target, answer = 0;
    cin >> N >> M;

    for(int i=0; i<N; ++i)
        dq.push_back(i+1);

    for(int i=0; i<M; ++i)
    {
        cin >> target;

        if (target == dq.front())
        {
            dq.pop_front();
            continue;
        }

        auto idx = std::find(dq.begin(), dq.end(),target) - dq.begin();
        if(idx < dq.size() - idx)
        {
            for(int j=0; j<idx; ++j)
            {
                dq.push_back(dq.front());
                dq.pop_front();
            }
            answer += idx;
        }
        else
        {
            int offset = dq.size() - idx;
            for(int j=0; j<offset; ++j)
            {
                dq.push_front(dq.back());
                dq.pop_back();
            }
            answer += offset;
        }
        dq.pop_front();
    }

    cout << answer;

    return 0;
}