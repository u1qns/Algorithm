#include <iostream>
#include <string>
using namespace std;

int solve(const std::string& L, const std::string& R)
{
    if (L.size() != R.size())
        return 0;

    int answer = 0;
    for (int i = 0; i < L.size(); ++i)
    {
        if (L[i] != R[i])
            return answer;
        
        if (L[i] == R[i] && L[i] == '8')
            ++answer;
    }
    
    return answer;
}

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
    std::string L, R;
	cin >> L >> R;
    cout << solve(L, R);
	return 0;
}