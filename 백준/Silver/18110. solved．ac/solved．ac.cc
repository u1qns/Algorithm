#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    int N = 0;
    cin >> N;
    if(N == 0)
    {
        cout << 0;
        return 0;
    }
    double sum = 0;
    int cnt = round(N * 0.15);
    //cout << "절사평균 수 : " << cnt;

    vector<int> grade(N,0);
    for(int i=0; i<N; ++i)
    {
        cin >> grade[i];
    }
    sort(grade.begin(), grade.end());

    for(int i=cnt; i<N-cnt; ++i){
        sum += grade[i];
    }

    cout << round(sum/(N-cnt*2));

    return 0;
}
