#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

class TreeNode
{
public:
    TreeNode() = default;
    TreeNode(int data){this->data = data;}
public:
    int data;
    TreeNode* left;
    TreeNode* right;
};

TreeNode* createTree(vector<char>& nums, int index)
{
    if (index >= nums.size() || '#' == nums[index])
    {
        return nullptr;
    }

    TreeNode* root = new TreeNode();
    root->data = nums[index];

    root->left = createTree(nums, index * 2 + 1);
    root->right = createTree(nums, index * 2 + 2);

    return root;
}

void preOrder_1(TreeNode* root) // abcdef
{
    if (nullptr == root)
    {
        return;
    }

    cout << (char)root->data << " ";
    preOrder_1(root->left);
    preOrder_1(root->right);
}

// 非递归
void preOrder_2(TreeNode* root)
{
    if (nullptr == root)
    {
        return;
    }

    stack<TreeNode*> st;
    st.push(root);

    while (!st.empty())
    {
        TreeNode* temp = st.top();
        cout << (char)temp->data << " ";
        st.pop();

        if (temp->right)
        {
            st.push(temp->right);
        }

        if (temp->left)
        {
            st.push(temp->left);
        }
        
    }
    
}


void inOrder_1(TreeNode* root)  // B D A E C F
{
    if (nullptr == root)
    {
        return;
    }

    inOrder_1(root->left);
    cout  << (char)root->data << " ";
    inOrder_1(root->right);
}

void inOrder_2(TreeNode* root)
{
    if (nullptr == root)
    {
        return;
    }

    stack<TreeNode*> st;
    TreeNode* cur = root;

    while(cur || !st.empty())
    {
        while (cur)
        {
            st.push(cur);
            cur = cur->left;
        }

        TreeNode* temp = st.top();
        cout << (char)temp->data << " ";
        st.pop();

        if (temp->right)
        {
            cur = temp->right;
        }
        
    }
}

void postOrder_1(TreeNode* root)    // D B E F C A
{
    if (nullptr == root)
    {
        return;
    }

    postOrder_1(root->left);
    postOrder_1(root->right);
    cout << (char)root->data << " ";
}

void postOrder_2(TreeNode* root)
{
    if (nullptr == root)
    {
        return;
    }

    stack<TreeNode* >st;
    TreeNode* cur = root;
    TreeNode* pre = nullptr;

    while (cur || !st.empty())
    {
        while (cur)
        {
            st.push(cur);
            cur = cur->left;
        }

        TreeNode* temp = st.top();
        // 什么时候弹出，什么时候打印
        if (nullptr == temp->right || temp->right == pre)
        {
            cout << (char)temp->data << " ";
            st.pop();
            pre = temp;
        }
        else
        {
            cur = temp->right;
        }
        
        
    }
    
}

void levelOrder(TreeNode* root) // A B C D E F
{
    if (nullptr == root)
    {
        return;
    }

    queue<TreeNode*> qu;
    qu.push(root);

    while (!qu.empty())
    {
        TreeNode* node = qu.front();
        cout << (char)node->data << " ";
        qu.pop();

        // left
        if (nullptr != node->left)
        {
            qu.push(node->left);
        }
        // right
        if (nullptr != node->right)
        {
            qu.push(node->right);
        }
    }
    
}

void dfs_1(TreeNode* root)  // A B D C E F
{
    if (nullptr == root)
    {
        return;
    }

    cout << (char)root->data << " ";
    dfs_1(root->left);
    dfs_1(root->right);
}

TreeNode* rebuildFromPreIn_helper(vector<char>& pre, int prestart, int preend, 
    vector<char>& in, int instart, int inend)
{
    if (prestart > preend)
    {
        return nullptr;
    }

    int key = pre[prestart];
    int len = 0;
    for (int i = instart; i < inend; i++)
    {
        if (key == in[i])
        {
            len = i - instart;
            break;
        }
    }

    TreeNode* root = new TreeNode();
    root->data = key;

    root->left = rebuildFromPreIn_helper(pre, prestart + 1, prestart + len, 
                                        in, instart, instart + len -1);

    root->right = rebuildFromPreIn_helper(pre, prestart + len + 1, preend, 
                                        in, instart + len + 1, inend);
    
    return root;
}

TreeNode* rebuildFromPreIn(vector<char>& pre, vector<char>& in)
{
    return 
        rebuildFromPreIn_helper(pre, 0, pre.size()- 1, in, 0, in.size() - 1);
}

TreeNode* rebuildFromInPost_helper(vector<char>& in, int instart, int inend,
    vector<char>& post, int poststart, int postend)
{
    if (poststart > postend)
    {
        return nullptr;
    }

    int key = post[postend];
    int len = 0;
    for (int i = instart; i < inend; i++)
    {
        if (key == in[i])
        {
            len = i - instart;
            break;
        }
    }

    TreeNode* root = new TreeNode();
    root->data = key;

    root->left = rebuildFromInPost_helper(in, instart, instart + len - 1,
                                post, poststart, poststart + len - 1);
    root->right = rebuildFromInPost_helper(in, instart + len + 1, inend,
                                post, poststart + len, postend - 1);
}

TreeNode* rebuildFromInPost(vector<char>& in, vector<char>& post)
{
    return 
        rebuildFromInPost_helper(in, 0, in.size() - 1, post, 0, post.size() - 1);
}
int main(int argc, char** argv)
{
    vector<char> nums{'A', 'B', 'C', '#', 'D', 'E', 'F'};
    TreeNode* root = createTree(nums, 0);

    preOrder_1(root); cout << endl;
    preOrder_2(root); cout << endl;
    inOrder_1(root); cout << endl;
    inOrder_2(root); cout << endl;
    postOrder_1(root); cout << endl;
    postOrder_2(root); cout << endl;
    levelOrder(root); cout << endl;

    cout << endl;
    vector<char> pre{'A', 'B', 'D', 'C', 'E', 'F'};
    vector<char> in{'B', 'D', 'A', 'E', 'C', 'F'};
    vector<char> post{'D', 'B', 'E', 'F', 'C', 'A'};
    TreeNode* r = rebuildFromPreIn(pre, in);
    postOrder_2(r); cout << endl;
    r = rebuildFromInPost(in, post);
    preOrder_1(r); cout << endl;
    // dfs_1(root); cout << endl;  // 深度优先就是前序遍历
    return 0;
}