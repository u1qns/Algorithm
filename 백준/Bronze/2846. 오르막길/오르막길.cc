#include <iostream>
#include <algorithm>

using namespace std;

int arr[1001] = {0, };

int main()
{
    int N, answer = 0;
    cin >> N;
    for(int i=0; i<N; ++i)
    {
        cin >> arr[i];
    }

    for(int i=0; i<N; ++i)
    {
        int tmp = arr[i];
        for(int j=i+1; j<N; ++j)
        {
            if(tmp < arr[j])
            {
                answer = std::max(answer, arr[j] - arr[i]);
                tmp = arr[j];
            }
            else
                break;
        }
    }

    cout << answer;
    return 0;
}
