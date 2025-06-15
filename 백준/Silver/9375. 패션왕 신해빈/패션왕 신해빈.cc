#include <iostream>
#include <map>
#include <string>
using namespace std;

int main(){

    int T; cin >> T;
    while(T--)
    {
        int N, answer = 1; // 곱하기 때문에 일단 1 추가해줌 
        map<string,int> m;
        cin >> N;
        
        string a, b;
        for(int i=0; i<N; ++i)
        {
            cin >> a >> b;
            m[b]++;
        }

        for(auto iter=m.begin(); iter!=m.end(); ++iter)
            answer *= (iter->second+1);

        cout << answer-1 <<"\n";
    }

    return 0;
}