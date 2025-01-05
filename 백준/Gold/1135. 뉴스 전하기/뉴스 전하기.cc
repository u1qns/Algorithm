#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> children;
int solve(const int idx)
{
    int sz = children[idx].size();
    if(sz == 0) return 0;

    int result = 0;
    vector<int> results;
    for (const auto& c : children[idx])
        results.push_back(solve(c));

    std::sort(results.rbegin(), results.rend());

    for (int order = 0; order < sz; ++order) 
        result = max(result, results[order] + order + 1);

    return result;
}

int main() {

    int N, inp;
    cin >> N >> inp;
    
    children.resize(N);
    for(int i=1; i<N; ++i) {
        cin >> inp;
        children[inp].push_back(i);
    }

    cout << solve(0);
    return 0;
}