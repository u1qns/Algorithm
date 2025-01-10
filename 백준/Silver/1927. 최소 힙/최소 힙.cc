#include <iostream>
#include <queue>

using namespace std;


int main()
{
    std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    
    priority_queue<int> pq;

    int order, N = 0;
    cin >> N;
    for(int i=0; i<N; ++i)
    {
        cin >> order;

        if(order == 0)
        {
            if(pq.empty())
                cout << "0\n";
            else
            {
                cout << pq.top()*-1 << "\n";
                pq.pop();
            }
        }
        else
        {
            pq.push(order*-1);
        }
    }
    return 0;
}