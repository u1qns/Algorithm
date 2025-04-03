#include <iostream>

using namespace std;

int main() 
{
    // N의 약수가 홀수개면 열려있음 -> 닫겨있다가 -> 열 닫 열 닫 열.. 반복
    // N까지의 제곱수를 구하자.. 왜냐면? 여기에 해당하는 애들은 다 열려있을거 아님? 그래서 ++answer
    
    int N, answer = 0;
    cin >> N;
    for(int i=1; i*i <=N; ++i)
        ++answer;
    cout << answer;
    return 0;
}
