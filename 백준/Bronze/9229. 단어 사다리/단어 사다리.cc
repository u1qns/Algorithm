#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool solve(const vector<string>& words)
{
    int sz = words.size();
    int len = words[0].size();

    for(int i=1; i<sz; ++i)
    {
        if(words[i].size() != len)
            return false;

        const string& pre = words[i-1];
        const string& now = words[i];
        int cnt = 0;
        for(int j=0; j<len; ++j)
        {
            if(pre[j] != now[j])
            {
                if(cnt ++ > 1)
                    return false;
            }
        }

        if(cnt != 1)
            return false;
    }



    return true;
}

int main()
{
    vector<string> words;
    string inp;

    while(1)
    {
        cin >> inp;
        if(inp == "#")
        {
            if(words.empty()) break;
            cout << (solve(words) ? "Correct\n" : "Incorrect\n");
            words.clear();
        }
        else
        {
            words.push_back(inp);
        }
    }

    return 0;
}
