#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() 
{

    int G;
    cin >> G;

    vector<int> result;

    int left = 1, right = 2;

    while (left < right)
    {
        long long tmp = (long long)right * right - (long long)left * left;

        if (tmp <= G) 
        {
            if(tmp == G)
            {
                result.push_back(right);
            }
            right++;

        }
        else left++;
    }

    if (result.empty())
        cout << -1;
    else
    {
        for (const int val : result)
            cout << val << "\n";
    }

    return 0;
}