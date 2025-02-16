#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

const int RADIX = 60;
const int MAX_TIME = 100 * RADIX * RADIX;
long long prefix[MAX_TIME + 1] = {0L, };

vector<string> split(const std::string& inp, const string& token)
{
    vector<string> result;
    size_t offset = 0, pos;

    while((pos=inp.find(token, offset)) != inp.npos)
    {
        result.push_back(inp.substr(offset, pos-offset));
        offset = pos + token.size();
    }

    result.push_back(inp.substr(offset, inp.size() - offset));
    return result;
}

int convert(const string& str_time)
{
    int result = 0;
    auto time = split(str_time, ":");

    if(time.size() != 3)
        return -1;

    result += std::stoi(time[0]) * RADIX * RADIX;
    result += std::stoi(time[1]) * RADIX;
    result += std::stoi(time[2]);

    return result;
}

string convert(int time)
{
    int h = time / (RADIX * RADIX);
    time %= (RADIX * RADIX);

    int m = time / RADIX;

    char buffer[10];
    sprintf(buffer, "%02d:%02d:%02d", h, m, time % RADIX);
    return std::string(buffer);
}

string solution(string play_time, string adv_time, vector<string> logs)
{
    string answer = "00:00:00";
    int total_time = convert(play_time);
    int ad_time = convert(adv_time);

    for (const auto &str: logs) {
        auto range = split(str, "-");

        int from = convert(range[0]);
        int to = convert(range[1]);

        prefix[from]++;
        prefix[to]--;
    }

    for (int i = 1; i <= total_time; ++i)
    {
        prefix[i] += prefix[i - 1];
    }

    for (int i = 1; i <= total_time; ++i) // 여기!!
    {
        prefix[i] += prefix[i - 1];
    }

    long long max_view = prefix[ad_time - 1];
    for(int now = ad_time; now <= total_time; ++now)
    {
        long long view = prefix[now] - (now - ad_time >= 0 ? prefix[now - ad_time] : 0);

        if(max_view < view)
        {
            max_view = view;
            answer = convert(now - ad_time  +1);
        }
    }

    return answer;
}
