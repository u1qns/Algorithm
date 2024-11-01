#include <iostream>
#include <string>
using namespace std;
constexpr int MAX = 4000 + 1;

int LCS[MAX][MAX] = {0, };

int main() 
{    
    string str1, str2;
    cin >> str1 >>str2;
    
    int answer = 0;
    int N = str1.size();
    int M = str2.size();

    for(int i=1; i<=N; ++i)
    {
        for(int j=1; j<=M; ++j)
        {
            if (str1[i - 1] == str2[j - 1])
                LCS[i][j] = LCS[i - 1][j - 1] + 1;
            if (LCS[i][j] > answer) answer = LCS[i][j];
        }
    }

    cout << answer;
    
    return 0;
}