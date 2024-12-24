#include <iostream>
using namespace std;

int k, l = 1, r = 0, result = 0;
char s[300001], st;
bool flag;

int main()
{
	cin >> k >> s;

	l = 1;
	st = s[0];
	flag = false;
	for (int i = 1; i < k; i++)
	{
		if (st == s[i])
		{
			if (!flag) l++;
			else r++;
		}
		else {
			st = s[i];
			flag = !flag;
			if (r == 0) r = 1;
			else
			{
				result = max(result, min(l, r) * 2);
				l = r;
				r = 1;
				flag = !flag;
			}
		}
	}
	result = max(result, min(l, r) * 2);
	cout << result;
	return 0;
}