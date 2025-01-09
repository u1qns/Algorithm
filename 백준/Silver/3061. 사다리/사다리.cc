#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;


int main()
{
    int T, N;
    vector<int> inp;

    cin >> T;
    while(T--)
    {
        cin >> N;
        inp.resize(N);
        for(int i=0; i<N; ++i)
        {
            cin >> inp[i];
        }

        int cnt = 0;
        for(int j=0; j<N; ++j)
        {
            for (int i = 0; i < N-1; ++i)
            {
                if (inp[i] > inp[i+1])
                {
                    swap(inp[i], inp[i+1]);
                    ++cnt;
                }
            }
        }
        cout << cnt << "\n";
    }

    return 0;
}
