#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int MAX = 1000000 + 1;
bool visited[MAX] = {false, };
int parent[MAX]; // 부모 노드를 저장하기 위한 배열

bool getAnswer(const int x)
{
    queue<int> q;
    q.push(1);
    visited[1] = true;
    parent[1] = -1; // 시작 노드의 부모는 없음

    int answer = 0;

    while (!q.empty())
    {
        int qSize = q.size();
        while (qSize--)
        {
            int e = q.front();
            q.pop();

            // 목표값에 도달했을 때
            if (x == e)
            {
                cout << answer<< "\n";

                vector<int> route;
                for (int node = x; node != -1; node = parent[node])
                {
                    cout << node << " ";
                }

                return true;
            }
            
            int result = e * 3;
            if (result < MAX && !visited[result])
            {
                visited[result] = true;
                parent[result] = e; // 부모 노드 설정
                q.push(result);
            }

            result = e * 2;
            if (result < MAX && !visited[result])
            {
                visited[result] = true;
                parent[result] = e; // 부모 노드 설정
                q.push(result);
            }

            result = e + 1;
            if (result < MAX && !visited[result])
            {
                visited[result] = true;
                parent[result] = e; // 부모 노드 설정
                q.push(result);
            }


        }
        answer++;
    }

    return false;
}

int main()
{
    int x;
    cin >> x;

    if(x == 1)
        cout << "0\n1";
    else
        getAnswer(x);

    return 0;
}