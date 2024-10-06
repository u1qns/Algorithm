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
	stack<int> st;

	for (int i=0; i<N; ++i)
	{
		cin >> arr[i];
		F[arr[i]]++;
	}

	for (int i=0; i<N; ++i)
	{
		while (!st.empty() && F[arr[st.top()]]< F[arr[i]])
		{
			ngf[st.top()] = arr[i];
			st.pop();
		}
		st.push(i);
	}

	for (int i=0; i<N; ++i)
		cout << ngf[i] << ' ';

	return 0;
}