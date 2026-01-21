#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;
class BinaryTree;
class Node
{
    int data;
    int level;
    Node *left = NULL;
    Node *right = NULL;

public:
    Node(int element)
    {
        data = element;
    }
    operator int()
    {
        return data;
    }
    operator string()
    {
        return "Data :  " + to_string(data) + "\tLevel : " + to_string(level);
    }
    int getLevel()
    {
        return level;
    }
    friend BinaryTree;
};

class BinaryTree
{
private:
    Node *root = NULL;

public:
    void add(int element)
    {
        Node *newNode = new Node(element);
        if (!root)
        {
            root = newNode;
            root->level = 0;
            cout << "Set root : " << (int)*root << endl;
            return;
        }
        queue<Node *> que;
        que.push(root);
        while (!que.empty())
        {
            Node *current = que.front();
            que.pop();
            if (current->left)
                que.push(current->left);
            else
            {
                newNode->level = current->getLevel() + 1;
                current->left = newNode;
                cout << " added " << (int)*newNode << " to the left of " << (int)*current << endl;
                return;
            }

            if (current->right)
                que.push(current->right);
            else
            {
                newNode->level = current->getLevel() + 1;
                current->right = newNode;
                cout << " added " << (int)*newNode << " to the right of " << (int)*current << endl;
                return;
            }
        }
    }

    void inorderTraversal()
    {
        ioTraversalHelper(root);
    }
    void ioTraversalHelper(Node *root)
    {
        if (!root)
            return;
        ioTraversalHelper(root->left);
        cout << (string)*root << endl;
        ioTraversalHelper(root->right);
    }
    void preorderTraversal()
    {
        preTraversalHelper(root);
    }

    void postorderTraversal()
    {
        postTraversalHelper(root);
    }

    vector<Node *> BFS()
    {
        if (!root)
        {
            vector<Node *> x;
            return x;
        }
        vector<Node *> visited;
        queue<Node *> que;
        que.push(root);
        while (!que.empty())
        {
            Node *current = que.front();
            visited.push_back(current);
            que.pop();
            cout << (string)*current << endl;
            if (current->left)
                que.push(current->left);
            if (current->right)
                que.push(current->right);
        }
        return visited;
    }

private:
    void postTraversalHelper(Node *root)
    {
        if (!root)
            return;
        postTraversalHelper(root->left);
        postTraversalHelper(root->right);
        cout << (string)*root << endl;
    }
    void preTraversalHelper(Node *root)
    {
        if (!root)
            return;
        cout << (string)*root << endl;
        preTraversalHelper(root->left);
        preTraversalHelper(root->right);
    }
};

int main()
{
    BinaryTree bt;
    bt.add(1);
    bt.add(2);
    bt.add(3);
    bt.add(4);
    bt.add(5);
    bt.add(6);
    bt.add(7);
    bt.add(8);

    cout << "Pre order : " << endl;
    bt.preorderTraversal();
    cout << "Inorder : " << endl;
    bt.inorderTraversal();
    cout << "Post order : " << endl;
    bt.postorderTraversal();
    cout << "BFS : " << endl;
    bt.BFS();

    return 0;
}