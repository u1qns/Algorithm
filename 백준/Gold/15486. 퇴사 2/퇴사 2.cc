#include <iostream>
#include <algorithm>
using namespace std;

int N, answer = 0;
int T[1500001] = {0, };
int P[1500001] = {0, };
int DP[1500001] = {0, };
	
int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    
	std::cin >> N;
	for(int i=0; i<N; ++i)
		std::cin >> T[i] >> P[i];
		
	
	for(int day=0; day<=N; ++day)
	{
		answer = std::max(answer, DP[day]);
		if(T[day] + day <= N)
		{
			DP[day + T[day]] = std::max(answer + P[day], DP[day + T[day]]);
		}
	}
	std::cout << DP[N];
	return 0;
}