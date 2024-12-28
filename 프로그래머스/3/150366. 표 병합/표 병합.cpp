#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;
typedef std::string VT;

constexpr int MAX_N =  50 + 1;
constexpr int MAX_IDX = MAX_N * MAX_N;
vector<VT> result;
map<int, VT> indexMapper;

// UF
vector<int> parent;
int find(const int x)
{
    if(parent[x] < 0) return x;
    return parent[x] = find(parent[x]);
}

bool merge(const int a, const int b)
{
    int r1 = find(a);
    int r2 = find(b);

    if(r1 == r2) return false;

    // 두 셀 중 한 셀이 값을 가지고 있을 경우 병합된 셀은 그 값을 가지게 됩니다.
    // 두 셀 모두 값을 가지고 있을 경우 병합된 셀은 (r1, c1) 위치의 셀 값을 가지게 됩니다.
    VT v1 = indexMapper[r1];
    VT v2 = indexMapper[r2];

    VT value = "";
    if(!v1.empty() && !v2.empty())
        value = v1;
    else if(!v1.empty() && v2.empty())
        value = v1;
    else if(v1.empty() && !v2.empty())
        value = v2;

    if(parent[r1] < parent[r1])
    {
        parent[r2] += parent[r1];
        parent[r1] = r2;

        if(value.empty())
            indexMapper[r2].clear();
        else
            indexMapper[r2] = value;

    }
    else
    {
        parent[r1] += parent[r2];
        parent[r2] = r1;
        if(value.empty())
            indexMapper[r1].clear();
        else
            indexMapper[r1] = value;
    }

    return true;
}

// ---------------------------------------------------

void init()
{
    result.clear();
    indexMapper.clear();
    parent.resize(MAX_IDX, -1);
}

int getIndex(const int r, const int c)
{
    return (r-1)*50 + (c-1);
}

void update(const int r, const int c, const VT& value)
{
    int index = getIndex(r, c);
    int root = find(index);

    indexMapper[root] = value;
}

void update(const VT& before, const VT& after)
{
    for(auto& [index, value] : indexMapper)
    {
        if(value == before)
            value = after;
    }
}

void merge(const int r1, const int c1,
           const int r2, const int c2)
{
    int idx = getIndex(r1, c1);
    int idx2 = getIndex(r2, c2);

    merge(idx, idx2);
};

void unmerge(const int r, const int c)
{
    int idx = getIndex(r, c);
    int root = find(idx);
    VT value = indexMapper[root];

    // 자식 정리
    for(int i=0; i<MAX_IDX; ++i)
    {
        if(find(i) == root) // NOTE: 그냥 인덱스 말고 얘네의 부모를 다 찾아가야하는구나..
        {
            parent[i] = -1; // 초기화
            indexMapper[i].clear();
        }
    }

    // 부모 정리
    parent[root] = -1;
    indexMapper[root].clear();

    // 독립
    update(r, c, value);
};

std::string print(const int r, const int c)
{
    int index = getIndex(r, c);
    int root = find(index);

    if(indexMapper.find(root) == indexMapper.end() || indexMapper[root].empty())
        return "EMPTY";

    return (indexMapper[root] == "" ? "EMPTY" : indexMapper[root]); // 보충함
}

vector<string> split(const string& line)
{
    vector<string> out;
    string word;
    stringstream sstream(line);
    while(getline(sstream, word, ' '))
    {
        out.push_back(word);
    }

    return out;
}

void run(const string& cmd)
{
    auto words = split(cmd);

    if(words[0] == "UPDATE")
    {
        if(words.size() == 4)
        {
            update(stoi(words[1]), stoi(words[2]), words[3]);
        }
        else if(words.size() == 3)
        {
            update(words[1], words[2]);
        }
    }
    else if(words[0] == "MERGE")
        merge(stoi(words[1]), stoi(words[2]), stoi(words[3]), stoi(words[4]));
    else if(words[0] == "UNMERGE")
        unmerge(stoi(words[1]), stoi(words[2]));
    else if(words[0] == "PRINT")
        result.push_back(print(stoi(words[1]), stoi(words[2])));
}

vector<string> solution(vector<string> commands) {

    init();

    for(const auto& cmd : commands)
        run(cmd);

    return result;
}
