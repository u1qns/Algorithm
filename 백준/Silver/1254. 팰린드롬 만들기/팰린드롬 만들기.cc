#include <iostream>
#include <string>
#include <algorithm>
 
using namespace std;
 
// 펠린드롬인지 확인하는 함수
bool check(string re)
{
    string origin = re;
    reverse(re.begin(), re.end());
 
    return origin == re;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
 
    // reverse 할 것이므로 re라는 이름으로 받는다.
    string re;
    cin >> re;
 
    // re를 복사하여 origin에 저장
    string origin = re;
    // reverse를 이용하여 원래의 re는 뒤집는다.
    reverse(re.begin(), re.end());
 
 
    // 0번째 글자까지 체크
    int idx = 0;
    while (idx < origin.length())
    {
        // 원본을 저장해 놓고
        string temp = origin;
        // 뒤집은 글자를 temp에 더해준다.
 
        // qwerty의 경우
        // 1회차 -> qwerty
        // 2회차 -> qwertyq
        // 3회차 -> qwertywq
        // 4회차 -> qwertyewq 와 같이 만들어주는 것
        for (int i = re.length() - idx; i < re.length(); i++)
        {
            temp += re[i];
        }
 
        // 만들어진 단어가 펠린드롬인지 체크한다.
        if (check(temp))
        {
            cout << temp.length();
            break;
        }
        idx++;
    }
 
    return 0;
}
