#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
    int N, M;
    std::cin >> N >> M;
    
    std::vector<int> arr(N+1);
    for(int i=1; i<=N; ++i)
    {
        arr[i] = i;
    }

    int a, b;
    for(int i=0; i<M; ++i)
    {
        cin >> a >> b;
        std::reverse(arr.begin() + a, arr.begin() + b + 1);
    }

    for(int i=1; i<=N; ++i)
        std::cout << arr[i] << " ";
    
    return 0;
} // main