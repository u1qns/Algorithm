#include <iostream>
#include <string>
using namespace std;

int main()
{
    int one[15] = {'A','a', 'b', 'D', 'd', 'e', 'g', 'O', 'o', 'P', 'p', 'Q', 'q', 'R', '@'};
    string line;
    int answer = 0;
    bool flag = false;

    getline(cin, line);

    for(char ch : line)
    {
        flag = false;
        for(int i=0; i<15; ++i)
        {
            if(one[i] != ch) continue;
            ++answer;
            flag = true;
            break;
        }

        if(flag) continue;
        if(ch == 'B') answer += 2;
    }

    cout << answer;
    return 0;
}
