#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
constexpr int MAX_N = 50 + 1;
int N, answer = 1e9;
vector<vector<int>> children;

// 내 자식 중 누굴 가는게 좋을까?
// -> 내 자식 트리의 리프가 깊은거 부터 가야함 근데 그냥 가보고 생각함녀 안될까? 시초 나는지 테스트
// 각 레벨 level, 자식 개수 sz
// 각 위치에서 예상되는 총 최소 개수가 level + sz이자나
// 걍 depth + max_sz 인데?
// solve(다음 노드 인덱스, 깊이, 계속 더한 사이즈 (자신을 포함)
bool cmp(const vector<int>& a, const vector<int>& b)
{
    return a.size() > b.size();
}

//void solve(const int idx, const int sum)
//{
    //cout << "visite : " << idx << "\n";
//    if(answer <= sum) return;
//
//    int sz = children[idx].size();
//    if(sz == 0)
//    {
//        answer = (answer < sum ? answer : sum);
//        return;
//    }

//    int next = children[idx][0]; // 자식 제일 많이 가진 부하한테 뉴스 전파
//    // 사실 이러면 안됨.. ㅎㅎ
//    for(const auto& i : children[idx])
//    {
//        if(children[next].size() > children[i].size())
//            next = i;
//    }

//
//    solve(next, sum + sz);
//}

int solve(const int idx)
{
    int sz = children[idx].size();
    if(sz == 0) return 0;

    vector<int> times;
    for (const auto& c : children[idx]) {
        times.push_back(solve(c));
    }

    sort(times.rbegin(), times.rend());

    int result = 0;
    for (int i = 0; i < sz; ++i)
        result = max(result, times[i] + i + 1);

    return result;
}

int main() {

    cin >> N;
    children.resize(N);
    int p;
    cin >> p;
    for(int i=1; i<N; ++i) {
        cin >> p;
        children[p].push_back(i);
    }
    //solve(0, 0);

    //cout << answer;
    cout << solve(0);
    return 0;
}