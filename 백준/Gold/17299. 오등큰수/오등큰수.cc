#include <iostream>
#include <vector>
#include <stack>
using namespace std;
const int MAX = 1000000 + 1;

int main()
{
	int N;
	cin >> N;

	vector<int> arr(N + 1);
	vector<int> ngf(N + 1, -1);
	vector<int> F(MAX, 0);
	stack<int> stk;

	for (int i=0; i<N; ++i)
	{
		cin >> arr[i];
		F[arr[i]]++;
	}

	for (int i=0; i<N; ++i)
	{
		int now = arr[i];

		while (!stk.empty())
		{
			int idx = stk.top();
			int top = arr[idx];

			if(F[top] >=  F[now]) break;

			ngf[idx] = arr[i];
			stk.pop();
		}
		stk.push(i);
	}

	for (int i=0; i<N; ++i)
		cout << ngf[i] << ' ';

	return 0;
}