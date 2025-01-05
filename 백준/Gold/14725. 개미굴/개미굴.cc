#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


struct Node
{
    string value;
    vector<Node*> next;

    Node* insert(string value)
    {
        for (const auto& node: next)
        {
            if(node->value == value)
                return node;
        }

        Node* newNode = new Node();
        newNode->value = value;
        this->next.push_back(newNode);
        return newNode;
    }
};

struct cmp
{
    bool operator()(const Node* a, const Node* b)
    {
        return a->value < b->value;
    }
};
void dfs(Node* node, const int depth)
{
    if(!node->value.empty())
    {
        for (int i = 1; i <depth; ++i)
            cout << "--";
        cout << node->value << '\n';
    }

    sort(node->next.begin(), node->next.end(), cmp());
    for(const auto& iter : node->next)
    {
        dfs(iter, depth+1);
    }
}

int main()
{
    int N, K;
    string value;
    Node* root = new Node();

    cin >> N;
    for(int i=0; i<N; ++i)
    {
        cin >> K;
        Node* cur = root;
        for(int j=0; j<K; ++j)
        {
            cin >> value;
            cur = cur->insert(value);
        }
    }

    dfs(root, 0);

    return 0;
}
