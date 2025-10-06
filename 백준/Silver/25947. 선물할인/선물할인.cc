#include <iostream>
#include <algorithm>
#include <vector>

std::vector<int> p;
int n, b, a;


int solve()
{
    int start = 0, end = 0; // end가 answer
    long long sum = 0;
    
    // a개 만큼 할인 받기
    for(; end<a; ++end)
    {
        sum += (p[end]/2);
        
        // a개만큼 할인받아도 예산 넘으면 출력 후 종료
        if(sum > b)
        {
            return end;
        }
    }
    
    for(; end<n; ++end)
    {
        // 예산을 안 넘으면 포인터로 사용하는 start는 반값 할인됐던거 다시 원가로 사고
        // 다음 선물 end번째를 반값으로 구매 -> 할인 최대 개수 a개 유지
        sum = sum + p[start]/2;
        sum = sum + p[end]/2;
        ++start;
        
        if(sum > b) // 예산 넘으면 종료
        {
            return end;
        }
    }
    
    return end;
}

int main()
{
    std::cin >> n >> b >> a;
    
    p.resize(n);

    for(int i=0; i<n; ++i)
        std::cin >> p[i];
    
    std::sort(p.begin(), p.end());
    
    std::cout << solve();

    return 0;
}
