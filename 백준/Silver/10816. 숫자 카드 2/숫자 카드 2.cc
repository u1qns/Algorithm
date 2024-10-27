#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> cards;

int lower_bound(const int target)
{
    int left = 0, right = cards.size();
    while (left < right)
    {
        int mid = (left + right) / 2;
        if (cards[mid] < target)
            left = mid + 1;
        else
            right = mid;
    }
    return left; 
}

int upper_bound(const int target)
{
    int left = 0, right = cards.size();
    while (left < right)
    {
        int mid = (left + right) / 2;
        if (cards[mid] <= target)
            left = mid + 1;
        else
            right = mid;
    }
    return left;
}

int main()
{
    ios::sync_with_stdio(NULL);
    cin.tie(0);
  
    int N, M, input;

    cin >> N;
    cards.resize(N);
    for (int i = 0; i < N; ++i)
        cin >> cards[i];

    sort(cards.begin(), cards.end());

    cin >> M;
    while (M--)
    {
        cin >> input;
        cout << upper_bound(input) - lower_bound(input) << " ";
    }

    return 0;
}