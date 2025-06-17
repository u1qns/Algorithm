#include <iostream>
#include <algorithm>
using namespace std;

int main() 
{
    int N, X, S, T;
    int answer = 0;
    cin >> N >> X;
    for(int i=0; i<N; ++i)
    {
        cin >> S >> T;
        
        if(X >= S+T)
        {
            answer = std::max(S, answer);
        }
        
    }
    
    cout << (answer == 0 ? -1 : answer);
     
    return 0;
}
