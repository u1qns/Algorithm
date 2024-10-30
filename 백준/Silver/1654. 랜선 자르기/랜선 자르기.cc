#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int K, N;
    cin >> K >> N;

    vector<long long> line(K);
    for(int i=0; i<K; ++i)
    {
        cin >> line[i];
    }
    sort(line.begin(), line.end());

    long long answer = 0;
    long long left = 0, right = line[K-1];
    while(left <= right)
    {
        int cnt = 0;
        long long mid = (left + right) / 2;
        if(mid == 0) mid = 1;

        for(int i=0; i<K; ++i)
        {
            cnt += line[i] / mid;
        }

        if(cnt >= N)
        {
            left = mid + 1;
            answer = mid;
        }
        else if(cnt < N)
        {
            right = mid -1;
        }
    }
    
    cout << answer;
    return 0;
}