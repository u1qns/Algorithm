#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;

struct cmp
{
    bool operator()(const pii& a, const pii& b) const
    {
        return a.first > b.first;
    }
};

int main()
{
    // 이 새끼 그리디 아님?.. 하.. 그리디구나..

    int N, L, answer = 0;
    cin >> N >> L;

    priority_queue<pii, vector<pii>, cmp> pq;
    int start, end, now;
    for(int i=0; i<N; ++i)
    {
        cin >> start >> end;
        pq.push({start, end});
    }

    // 첨에 널판지 시작하는데부터 깔아.
    now = 0;
    while(!pq.empty())
    {
        now = (now > pq.top().first ? now : pq.top().first);
        while(now < pq.top().second)
        {
            now += L;
            ++answer;
        }
        pq.pop();
    }

    cout << answer;

    return 0;
}
