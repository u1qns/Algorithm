#include <iostream>

using namespace std;

int main() 
{
    int tmp, answer=0, r, c;
    for(int i=0; i<9; ++i)
    {
        for(int j=0; j<9; ++j)
        {
            cin >> tmp;
            if(answer <= tmp)
            {
                answer = tmp;
                r = i+1;
                c = j+1;
            }
        }
    }
    
    cout << answer <<"\n" << r << " " << c;
    return 0;
}
