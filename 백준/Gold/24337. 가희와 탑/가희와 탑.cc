#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;


deque<int> getAnswer(const int N, const int a, const int b)
{
    deque<int> answer;

    if(N + 1 < a + b)
        return answer;
    
	for (int i=1; i<a; ++i)
		answer.push_back(i);

	answer.push_back(std::max(a, b));

	for (int i=b-1; i>0; --i)
		answer.push_back(i);

	int front = answer.front(); 
    answer.pop_front();

	int sz = answer.size();
	for (int i=1; i<N-sz; ++i)
		answer.push_front(1);

	answer.push_front(front);

    return answer;
}

int main()
{
	int N, a, b;
	cin >> N >> a >> b;

    auto answer = getAnswer(N, a, b);
    if(answer.empty())
        cout << -1;
    else
    {
   	    for (const auto& ans : answer)
  		    cout << ans << " ";
    }
    return 0;
} // main