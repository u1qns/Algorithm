#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int  main()
{
    int N, A, B;

    cin >> N >> B >> A;

    vector<int> costs(N, 0);
    int cost = 0;

    for(int i=0; i<N; ++i) {
        cin >> costs[i];
    }

    sort(costs.begin(), costs.end());

    int left = 0, right = 0;

    // 먼저 반값으로 물건 구매
    while(right<A && cost<B) {
        cost += (costs[right++] / 2);
    }

    if(cost > B) {
        cout << right-1;
        return 0;
    }

    //  현재 A 물건까지 반값으로 샀고 예산 남았음
    while(right<N && cost<B) {
        cost += (costs[right++]/2); //비싼걸 싸게 사야하고
        cost += (costs[left++]/2); // 싼걸 정가로 사야함
    }

    if(cost > B) right--;
    cout << right;

    return 0;
}