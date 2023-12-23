struct node *LL(struct node *n)
{
    struct node *new_head = n->left;
    n->left = new_head->right;
    new_head->right = n;
    set_height(n);
    set_height(new_root);
    return new_head;
}

struct node *insert(struct node *root, int val)
{
    if (root == NULL)
    {
        root = allocate_node(val);
        return root;
    }
    if (root->val > val)
    {
        root->left = insert(root->left, val);
    }
    else
    {
        root->right = insert(root->right, val);
    }

    set_height(n);
    n = try_rotate(root);
    return n;
}

strcut node *try_rotate(strcut node *root)
{
    int bal = get_balance(root);
    if (bal < -1)
    {
        bal = get_balance(root->right);
        if (bal > 0)
        {
            n = rl(n);
        }
        else
        {
            n = rr(n);
        }
    }
    else if (bal > 1)
    {
        bal = get_balance(n->left);
        if (bal < 0)
        {
            n = LR(n);
        }
        else
        {
            n = LL(n);
        }
    }
    return n;
}
