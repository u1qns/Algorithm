#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;

std::vector<int> sortedTimes;

int lower_bound(const int target)
{
    int left = 0, right = sortedTimes.size()-1;
    while (left < right)
    {
        int mid = (right + left) / 2;

        if (sortedTimes[mid] < target)
            left = mid + 1;
        else
            right = mid;
    }
    return left;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;

    int answer[3] = {0, -1, 0};

    vector<pii> timetable(N);
    vector<int> prefix;

    for (int i = 0; i < N; ++i)
    {
        int from, to;
        cin >> from >> to;
        timetable[i] = {from, to};
        sortedTimes.push_back(from);
        sortedTimes.push_back(to);
    }

    sort(sortedTimes.begin(), sortedTimes.end());
    sortedTimes.erase(unique(sortedTimes.begin(), sortedTimes.end()), sortedTimes.end());
    prefix.resize(sortedTimes.size(), 0);

    for (const auto& [left, right] : timetable)
    {
        int start = lower_bound(left);
        int end = lower_bound(right);

        prefix[start]++;
        prefix[end]--;
    }

    int prefixSum = 0;
    for(int i=0; i<prefix.size(); ++i)
    {
        prefixSum += prefix[i];
        if(answer[0] < prefixSum)
        {
            answer[0] = prefixSum;
            answer[1] = i;
            answer[2] = i;
        }

        if(answer[0] == prefixSum && i-1 == answer[2])
        {
            answer[2] = i;
        }
    }

    cout << answer[0] << "\n" << sortedTimes[answer[1]] << " " << sortedTimes[answer[2] + 1] << "\n";

    return 0;
}