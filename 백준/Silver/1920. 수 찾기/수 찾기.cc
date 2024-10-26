#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> arr;

bool binarySearch(const int target)
{
    int left = 0;
    int right = N-1;
    
    while(left <= right)
    {
        int mid = (right + left) / 2;
        
        if(arr[mid] == target) 
            return true;

        if(arr[mid] > target) 
            right = mid-1;
        else 
            left = mid+1;
    }

    return false;
}

int main()
{
    // 시간 초과 (4%)라서 넣음 
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int inp;
    
    cin >> N;
    arr.resize(N);

    for(int i=0; i<N; ++i) 
        cin >> arr[i];
    sort(arr.begin(), arr.end());
    
    cin >> M;
    for(int i=0; i<M; ++i)
    {
        cin >> inp;
        cout << binarySearch(inp) << "\n";
    }
    
    return 0;
}