#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, X;
vector<int> arr;

int getAnswer(const int target)
{
    int answer = 0;
    std::sort(arr.begin(), arr.end());
    int right = N-1;
    int left = 0;
    
    while(left < right)
    {
        int mid = (arr[left] + arr[right]);
        
        if(mid == target)
        {
            ++answer;
            ++left;
            --right;
            continue;
        }
        
        if(mid > target)
            --right;
        else
            ++left;
    }
    
    return answer;
}


int main() 
{
    cin >> N;
    arr.resize(N);
    for(int i=0; i<N; ++i)
        cin >> arr[i];
    cin >> X;
    
    cout << getAnswer(X);
    return 0;
}
