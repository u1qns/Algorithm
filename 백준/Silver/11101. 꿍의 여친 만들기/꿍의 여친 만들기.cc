#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<string> split(const string& inp, const string& token)
{
    vector<string> result; //쪼개진 문자열을 저장할 벡터
    size_t offset = 0, pos; //현재 탐색 위치(시작점), token이 발견된 위치

    while((pos=inp.find(token, offset)) != inp.npos)
    {
        result.push_back(inp.substr(offset, pos-offset));
        offset = pos + token.size();
    }

    result.push_back(inp.substr(offset, inp.size() - offset));
    return result;
}

int getAnswer()
{
    int answer = 1e9;
    string input;
    int totalSkill = 0;
    map<string, int> skill2Idx; // skill to index
    map<int, int> Idx2Cost;

    cin >> input;

    auto infos = split(input,",");
    for(const auto& str : infos)
    {
        size_t offset = 0, pos;

        while((pos=str.find(":", offset)) != str.npos)
        {
            string skill = str.substr(offset, pos-offset);
            offset = pos + 1;
//            cout << skill << "\t" << str.substr(offset, str.size()) << "\n";
            skill2Idx[skill] = ++totalSkill;
            Idx2Cost[totalSkill] = stoi(str.substr(offset, str.size()));
        }
    }

    // condition
    cin >> input;
    auto conditions = split(input, "|");

    for(const auto& skills : conditions)
    {
        auto skill = split(skills, "&");
        int cost = 0;
        for(const auto& s : skill)
        {
            int idx = skill2Idx[s];
            cost = std::max(cost, Idx2Cost[idx]);
        }
        answer = std::min(cost, answer);
    }

    return answer;
}

int main()
{
    int T; cin >> T;
    while(T--)
    {
        cout << getAnswer() << "\n";
    }
    return 0;
}
