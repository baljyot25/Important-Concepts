#include<stdlib.h>

struct ans
{
    struct tree *root;
    struct tree * keynode;


};
struct tree
{
    int val;
    struct tree * left;
    struct tree * right;
};

struct ans* quicksearch(struct tree * root,int key)
{
    struct ans * ans;
    struct  tree * permroot=root;
    if(root==NULL)
    {
        ans->root=NULL;
        ans->keynode=NULL;
        return ans;

    }

    if (root->val==key)
    {
        //depth does not change
        ans->root=root;
        ans->keynode=root;
        return ans;

    }

    while(root->left!=NULL && root->right!=NULL)
    {
        //to be written ans->root=NULL;
        ans->keynode=NULL;
        return ans;
        
    }

    if(root->left!=NULL && root->left->val==key)
    {
        //rotation needs to be done
            
    }
    else if(root->right!=NULL && root->right->val==key)
    {
        //rotation needs to be done

    }
    else{
        //either left or right is null or key is not found in non null of the two
        //no rotation,null to be returned.
        ans->root=permroot;
        ans->keynode=NULL;
        return ans;

    }
}