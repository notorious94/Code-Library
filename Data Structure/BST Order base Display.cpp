#include<bits/stdc++.h>
using namespace std;

/// M A C R O Starts Here
#define pf printf
#define sf scanf
#define MAX 500000
#define pi acos(-1.0)
#define get_stl(s) getline(cin,s)
#define sif(a) scanf("%d",&a)
#define pif(a) printf("%d\n",a)

typedef long long ll;
typedef unsigned long long ull;

struct bst
{
    int data;
    bst *left;
    bst *right;
};

bst* insert(int n, bst* _root)
{
    bst *node;
    node = new bst();
    node->data=n;
    node->left=node->right=NULL;

    if(!_root)
        _root=node;
    else if(n<_root->data)
        _root->left=insert(n,_root->left);
    else
        _root->right=insert(n,_root->right);

    return _root;
}

void preorder(bst *_root)
{
    if(!_root)
        return;

    pf("%d ",_root->data);
    preorder(_root->left);
    preorder(_root->right);
}

void inorder(bst *_root)
{
    if(!_root)
        return;

    inorder(_root->left);
    pf("%d ",_root->data);
    inorder(_root->right);
}


void postorder(bst *_root)
{
    if(!_root)
        return;

    postorder(_root->left);
    postorder(_root->right);
    pf("%d ",_root->data);
}

int main()
{
    bst *root;
    root = NULL;

    pf("****MENU****\n\n");
    pf("1. Insert\n");
    pf("2. Display in Preorder\n");
    pf("3. Display in Inorder\n");
    pf("4. Display in Postorder\n");
    pf("5. Exit\n\n");

    int c, item;

    while(1)
    {
        pf("Enter Choice: ");
        sif(c);
        if(c==5)
        {
            pf("Exiting Program.....\n");
            break;
        }
        else if(c>5)
        {
            pf("\nInvalid Choice\n");
            continue;
        }
        switch(c)
        {
            case 1:
                pf("\nInput Element: ");
                sif(item);
                root = insert(item, root);
                pf("Item Inserted\n\n");
                break;
            case 2:
                pf("BST In Preorder: ");
                preorder(root);
                pf("\n\n");
                break;
            case 3:
                pf("BST In Inorder: ");
                inorder(root);
                pf("\n\n");
                break;
            case 4:
                pf("BST In Postrder: ");
                postorder(root);
                pf("\n\n");
                break;
        }
    }
    return 0;
}
