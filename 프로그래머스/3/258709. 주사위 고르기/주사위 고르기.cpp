#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;
constexpr int MAX_N = 10;

int N, maxWin = 0;
vector<int> winner;
bool visited[MAX_N] = {false, };

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

void play(const vector<vector<int>>& input)
{
    // A, B 주사위 정의
    vector<int> A, B;
    int szA = 0, szB = 0;
    for(int i=0; i<N; ++i)
    {
        if(visited[i])
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
    for(int i=0; i<sumA.size(); ++i)
    {
        for(int j=0; j<sumB.size(); ++j)
        {
            //cout << "*" <<  sumA[i] << "\t" << sumB[j] << "\n";
            if(sumA[i] > sumB[j]) ++win;
        }
    }

    // check()
    if(maxWin < win)
    {
        maxWin = win;
        winner = A;
    }

}

void pickDices(const int cnt, const int idx, const vector<vector<int>>& input)
{
    if(cnt == 0)
    {
        play(input);
        return;
    }

    for(int i=idx; i<N; ++i)
    {
        visited[i] = true;
        pickDices(cnt-1, i+1, input);
        visited[i] = false;
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

// int main()
// {
//     std::vector<std::vector<std::vector<int>>> allData = {
//             {
//                     {1, 2, 3, 4, 5, 6},
//                     {3, 3, 3, 3, 4, 4},
//                     {1, 3, 3, 4, 4, 4},
//                     {1, 1, 4, 4, 5, 5}
//             },
//             {
//                     {1, 2, 3, 4, 5, 6},
//                     {2, 2, 4, 4, 6, 6}
//             },
//             {
//                     {40, 41, 42, 43, 44, 45},
//                     {43, 43, 42, 42, 41, 41},
//                     {1, 1, 80, 80, 80, 80},
//                     {70, 70, 1, 1, 70, 70}
//             }
//     };

//     for(const auto& input : allData)
//     {
//         //init
//         maxWin = 0;
//         memset(visited, false, sizeof(visited));
//         winner.clear();

//         auto answer = solution(input);
//         for (const auto &i: answer)
//             cout << i << ", ";
//         cout <<"\n--------------- \n";
//     }
//     return 0;
// }
