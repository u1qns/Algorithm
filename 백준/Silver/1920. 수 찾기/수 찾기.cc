#include <iostream>
#include <map>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    // 이분 탐색인거 아는데 트라이
    map<int, int> map;
    int n, m, inp; 
    
    cin>>n;
    for(int i=0; i<n; ++i)
    {
        cin >> inp;
        map[inp]++;
    }
    
    cin >> m;
    for(int i=0; i<m; ++i)
    {
        cin >> inp;
        cout << (map.find(inp) == map.end() ? 0 : 1) << "\n";
    }
    return 0;
}