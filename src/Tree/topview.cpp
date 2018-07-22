#include<bits/stdc++.h>
using namespace std;

class TreeNode
{
public :

    int data;
    TreeNode *left, *right;
    TreeNode(int x){
        data = x;
        left = right = NULL;
    }
};

class Tree{

public:

    TreeNode* root;
    Tree()
    {
        root = NULL;
    }
    Tree(TreeNode* n)
    {
        root = n;
    }

    void printTopView()
    {
        if (root == NULL)
            return;

        unordered_map<int,int>ump;
        queue<pair<TreeNode*, int>>q;

        q.push(make_pair(root,0));
        while(!q.empty()){

            pair<TreeNode*, int>p = q.front();
            TreeNode *n = p.first;
            int dist = p.second;
            q.pop();

            if(ump.find(dist) == ump.end())
            {
                ump[dist] = n->data;
                cout<<n->data;
            }
            if(n->left != NULL){

                q.push(make_pair(n->left,dist-1));
            }
            if(n->right != NULL){

                q.push(make_pair(n->right, dist+1));
            }
        }

    }




};

int main()
{

    /*Create following Binary Tree
             1
           /  \
          2    3
           \
            4
             \
              5
               \
                6
    */

    TreeNode *root = new TreeNode(1);
    root->left= new TreeNode(2);
    root->right= new TreeNode(3);
    root->left->right= new TreeNode(4);
    root->left->right->right= new TreeNode(5);
    root->left->right->right->right= new TreeNode(6);

    Tree *t = new Tree(root);
    t->printTopView();
    return 0;
}
