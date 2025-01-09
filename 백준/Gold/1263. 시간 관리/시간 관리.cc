#include <iostream>
#include <queue>

using namespace std;
typedef pair<int, int> pii;

int main()
{
    int N, T, S;
    int end = 0, answer = 0;
    priority_queue<pii> pq;

    cin >> N;
    for(int i=0; i<N; ++i)
    {
        cin >> T >> S;
        pq.push({S, T});
    }

    end = pq.top().first;
    while(!pq.empty())
    {
        int time = pq.top().second;
        int deadline = pq.top().first;

        pq.pop();
        if(end > deadline)
            end = deadline;
        end -= time;
    }


    cout << (end < 0 ? -1 : end);
    return 0;
}