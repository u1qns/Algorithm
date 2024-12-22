#include <iostream>

using namespace std;

int main()
{
    int dog[2][3] = {0, };
    int dest[3] = {0, };

    for(int i=0; i<2; ++i)
    {
        for(int j=0; j<2; ++j)
        {
            cin >> dog[i][j];
            dog[i][2] += dog[i][j];
        }
    }

    for(int i=0; i<3; ++i)
        cin >> dest[i];

    for(const auto& time : dest)
    {
        int answer = 0;
        for(int d=0; d<2; ++d)
        {
            int range = time % dog[d][2];
            if(range <= dog[d][0] && range != 0)
                ++answer;
        }

        cout << answer <<"\n";
    }

    return 0;
}