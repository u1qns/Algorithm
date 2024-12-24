#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;
constexpr int MAX_N = 10;

int N, maxWin = 0;
vector<int> winner;
unordered_set<int> visited;
int picked = 0b0;


void roll(const int depth, const int sum,
          const vector<int>& dice, vector<int>& result,
          const vector<vector<int>>& input)
{
    if(depth == dice.size())
    {
        result.push_back(sum);
        return;
    }

    for(int i=0; i<6; ++i)
    {
        int idx = dice[depth]; // 고른 주사위가 input의 몇번째 주사위인지 가지고 잇음
        roll(depth+1, sum + input[idx][i], dice , result, input);
    }
}

bool getAnswer(const vector<int>& dice, const int winCnt)
{
    if(maxWin < winCnt)
    {
        maxWin = winCnt;
        winner = dice;
        return true;
    }
    return false;
}

void play(const vector<vector<int>>& input)
{
    visited.insert(picked);
    int unmask = (1 << N) - 1;
    visited.insert(picked ^ unmask);

    // A, B 주사위 정의
    vector<int> A, B;
    for(int i=0; i<N; ++i)
    {
        if(picked & (1 << i))
            A.push_back(i);
        else
            B.push_back(i);
    }

    // debug
//    for(const auto& i : A)
//        cout << i << " ";
//    cout << " | ";
//    for(const auto& i : B)
//        cout << i << " ";
//    cout << "\n";

    // roll() 각 가지고 있는 N/2개의 주사위로 6면 조합마다 합 만들어
    vector<int> sumA, sumB;
    roll(0, 0, A, sumA, input);
    roll(0, 0, B, sumB, input);

    // fight() : 지금 주사위 A, B 이렇게 골라놓으면 A가 win 만큼 이기는구나!
    int win = 0;
    int lose = 0;
    for(int i=0; i<sumA.size(); ++i)
    {
        for(int j=0; j<sumB.size(); ++j)
        {
            if(sumA[i] > sumB[j]) ++win;
            else if(sumA[i] < sumB[j]) ++lose;
        }
    }
    
    if(win > lose)
        getAnswer(A, win);
    else
        getAnswer(B, lose);

}


void pickDices(const int cnt, const int idx, const vector<vector<int>>& input)
{
    if(cnt == 0)
    {
        if(visited.find(picked) == visited.end())
            play(input);
        return;
    }

    for(int i=idx; i<N; ++i)
    {
        picked |= (1 << i);
        pickDices(cnt-1, i+1, input);
        picked &= ~(1 << i);
    }
}

vector<int> solution(vector<vector<int>> dice) {
    vector<int> answer;
    N = dice.size();

    //start
    pickDices(N/2, 0, dice);

    //getAnswer
    sort(winner.begin(), winner.end());
    for(auto& i : winner)
    {
        answer.push_back(i+1);
    }
    return answer;
}
