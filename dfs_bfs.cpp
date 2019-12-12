#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

void helper(vector<vector<int> >& graph, vector<bool>& visited, int index)
{
    visited[index] = 1;
    cout << index << " ";
    for (int i = 0; i < graph[index].size(); i++)
    {
        if (!visited[i] && 1 == graph[index][i])
        {
            helper(graph, visited, i);
        }
    }
}

void dfs(vector<vector<int> >& graph)
{
    vector<bool> visited(graph.size(), 0);
    helper(graph, visited, 0);
}

// 非递归形式
void dfs_2(vector<vector<int> >& graph)
{
    vector<int> visited(graph.size(), 0);
    stack<int> st;
    st.push(0);
    cout << 0 << " ";
    visited[0] = 1;

    bool shoudPop = false;
    while(!st.empty())
    {
        int top = st.top();
        shoudPop = true;

        for (int i = 0; i < graph[top].size(); i++)
        {
            if (!visited[i] && 1 == graph[top][i])
            {
                st.push(i);
                visited[i] = 1;
                shoudPop = false;
                cout << i << " ";
                break;
            }
        }

        if (shoudPop)
        {
            st.pop();
        }
    }
}

void bfs(vector<vector<int> >& graph)
{
    vector<bool> visited(graph.size(), 0);
    queue<int> qu;
    qu.push(0);
    visited[0] = 1;

    while (!qu.empty())
    {
        int front = qu.front();
        cout << front << " " << endl;
        qu.pop();
        for (int i = 0; i < graph[front].size(); i++)
        {
            if (!visited[i] && graph[front][i] == 1)
            {
                qu.push(i);
                visited[i] = 1;
            }
        }
    }
    
}

int main(int argc, char** argv)
{
    vector<vector<int> > graph{
        // bfs
        // { 0, 1, 1, 0, 0 },
        // { 0, 0, 1, 1, 0 },
        // { 0, 1, 1, 1, 0 },
        // { 1, 0, 0, 0, 0 },
        // { 0, 0, 1, 1, 0 }

        // dfs
        { 0, 1, 1, 0, 0 },
        { 0, 0, 1, 0, 1 },
        { 0, 0, 1, 0, 0 },
        { 1, 1, 0, 0, 1 },
        { 0, 0, 1, 0, 0 }
    };
    bfs(graph);
    cout << endl;
    dfs(graph);
    cout << endl;
    dfs_2(graph);
    return 0;
}