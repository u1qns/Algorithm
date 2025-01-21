#include <iostream>
#include <vector>

using namespace std;

int T, score = 0;

int blue[4][6] = {0, };
int green[6][4] = {0, };
enum
{
    RED,
    BLUE,
    GREEN,
};

void gravityBlock(const int t, const int x, const int y, const int cnt)
{
    bool flag = false;

    if(t == 1)
    {
        for(int j=0; j<5; ++j)
        {
            if(blue[x][j+1] == 0) continue;

            flag = true;
            blue[x][j] = cnt;
            break;
        }
        if(!flag) blue[x][5] = cnt;

        flag = false;
        for(int i=0; i<5; ++i)
        {
            if(green[i+1][y] == 0) continue;

            green[i][y] = cnt;
            flag = true;
            break;
        }
        if(!flag) green[5][y] = cnt;
    }
    else if(t == 2) // 가로 1 x 2
    {
        flag = false;
        for(int j=0; j<5; ++j)
        {
            if(blue[x][j+1] == 0) continue;

            blue[x][j] = blue[x][j-1] = cnt;
            flag = true;
            break;
        }
        if(!flag) blue[x][5] = blue[x][4] = cnt;

        flag = false;
        for(int i=0; i<5; ++i)
        {
            // 밑으로 쭉 내려가는데 가로 두 칸 중 하나라도 블럭을 만나면 이 자리 위에 블럭이 얹혀져 있어야 한다.
            if(green[i+1][y] || green[i+1][y+1])
            {
                green[i][y] = green[i][y+1] = cnt;
                flag = true;
                break;
            }
        }
        if(!flag) green[5][y] = green[5][y+1] = cnt;
    }
    else if(t == 3) // 세로 2 x 1
    {
        flag = false;
        for(int j=0; j<5; ++j)
        {
            // 오른쪽으로 이동하는데 세로 두 칸 중 하나라도 블럭을 만나면 이 자리 위에 블럭이 얹혀져 있어야 한다.
            if(blue[x][j+1] || blue[x+1][j+1])
            {
                blue[x][j] = blue[x+1][j] = cnt;
                flag = true;
                break;
            }
        }
        if(!flag) blue[x][5] = blue[x+1][5] = cnt;

        flag = false;
        for(int i=0; i<5; ++i)
        {
            if(green[i+1][y] == 0) continue;

            green[i][y] = green[i-1][y]= cnt;
            flag = true;
            break;
        }
        if(!flag) green[5][y] = green[4][y] = cnt;
    }

}

void removeBottom(const int color, const int cnt)
{
    if(cnt == 0)
        return;

    if(color == BLUE)
    {
        for(int i=0; i<4; ++i)
        {
            for (int j=5; j>=cnt; --j)
            {
                blue[i][j] = blue[i][j-cnt];
                blue[i][j-cnt] = 0;
            }
        }
    }
    else if(color == GREEN)
    {
        for(int i=5; i>=cnt; --i)
        {
            for (int j=0; j<4; ++j)
            {
                green[i][j] = green[i-cnt][j];
                green[i-cnt][j] = 0;
            }
        }
    }
}

bool isCheck(const int len, const int color)
{
    if(color == BLUE)
    {
        for(int i=0; i<4; ++i)
        {
            if(blue[i][len] != 0)
                return true;
        }
    }
    else if(color == GREEN)
    {
        for(int j=0; j<4; ++j)
        {
            if(green[len][j] != 0)
                return true;
        }
    }

    return false;
}

bool isFull(const int len, const int color)
{
    if(color == BLUE)
    {
        for(int i=0; i<4; ++i)
        {
            if(blue[i][len] == 0)
                return false;
        }
    }
    else if(color == GREEN)
    {
        for(int j=0; j<4; ++j)
        {
            if(green[len][j] == 0)
                return false;
        }
    }

    return true;
}

void pull(const int len, const int color)
{
    if(color == BLUE)
    {
        for(int j=len; j>0; j--)
        {
            for(int i=0; i<4; ++i)
            {
                blue[i][j] = blue[i][j-1];
                blue[i][j-1] = 0;
            }
        }
    }
    else if(color == GREEN)
    {
        for(int i=len; i>0; --i)
        {
            for(int j=0; j<4; ++j)
            {
                green[i][j] = green[i-1][j];
                green[i-1][j] = 0;
            }
        }
    }
}

vector<int> getScore(const int color)
{
    vector<int> result;

    for(int len=2; len<6; ++len)
    {
        if(!isFull(len, color)) continue;

        result.push_back(len);
    }

    return result;
}

int getLightLine(const int color)
{
    int cnt = 0;

    for(int len=0; len<2; ++len)
    {
        if(isCheck(len, color))
            ++cnt;
    }

    return cnt;
}

void play(const int t, const int x, const int y, const int order)
{
    gravityBlock(t, x, y, order);

    // BLUE ----------
    auto result = getScore(BLUE);
    for(const auto& line : result)
        pull(line, BLUE);
    removeBottom(BLUE, getLightLine(BLUE));
    score += result.size();

    // GREEN ----------
    result = getScore(GREEN);
    for(const auto& line : result)
        pull(line, GREEN);
    removeBottom(GREEN, getLightLine(GREEN));
    score += result.size();

}

int getAnswer()
{
    int answer = 0;

    for(int i=0; i<4; ++i)
    {
        for(int j=0; j<6; ++j)
        {
            if(blue[i][j] != 0) ++answer;
            if(green[j][i] != 0) ++answer;
        }
    }

    return answer;
}

int main()
{
    int t, x, y;
    cin >> T;
    for(int i=1; i<=T; ++i)
    {
        cin >> t >> x >> y;
        play(t, x, y, i);
    }

    cout << score << "\n" << getAnswer();

    return 0;
}