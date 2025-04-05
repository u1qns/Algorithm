#include <iostream>
#include <unordered_set>
#include <vector>
#include <string>
using namespace std;

vector<string> split(const string& line, const string& token)
{
    vector<string> result;
    size_t start=0, pos;

    while((pos= line.find(token, start)) != line.npos)
    {
        result.push_back(line.substr(start, pos-start));
        start = pos + token.size();
    }
    result.push_back(line.substr(start, line.size() - start));
    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    unordered_set<string> set;
    string str;
    int N, M;
    cin >> N >> M;
    for(int i=0; i<N; ++i)
    {
        cin >> str;
        set.insert(str);
    }

    for(int i=0; i<M; ++i)
    {
        cin >> str;
        auto list = split(str, ",");
        for(const auto& word : list)
        {
            set.erase(word);
        }
        cout << set.size() << "\n";
    }
    return 0;
}