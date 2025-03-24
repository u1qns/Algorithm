#include <iostream>
#include <string>
using namespace std;
int answer[11] = {0, };

int main() 
{
    long long A, B, C;
    cin >> A >> B >> C;
    long long tmp = A*B;
    tmp *= C;
    // 1234 -> tmp / 10 = 123... -> tmp%10 = 4..
    while(tmp !=0)
	{
   		int q = tmp/10;
   		int r = tmp%10;
   		answer[r]++;
   		tmp = q;
	} 
	
    for(int i=0; i<10; ++i)
    {
        cout << answer[i] << "\n";
    }
    return 0;
}
