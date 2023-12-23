void morris_traversal(Node* root)
{
    Node * curr=root;
    while(curr!=NULL)
    {
        if (curr->left==NULL)
        {
            cout<<curr->data;
            curr=curr->right;

        }
        else
        {
            Node * pred=find_pred(curr);
            if (pred->right==NULL)
            {
                pred->right=curr;
                curr=curr->left;
            }
            else
            {
                pred->right=NULL;
                cout<<curr->data;
                curr=curr->right;
            }


        }
    }
}


Node* find_pred(Node * curr)
{
    Node * temp=curr->left;
    while(temp->right !=NULL && temp->right !=curr)
    {
        temp=temp->right;
    }
    return temp;
}