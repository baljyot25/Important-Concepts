// structure of tree
struct node
{
    int val;
    int height;
    struct node *left;
    struct node *right;
};

// helper function
int get_balance(struct node *n)
{
    int l_height = (n->left) ? n->left->height : -1;
    int r_height = (n->right) ? n->right->height : -1;
    return l_height - r_height;
}
void set_height(struct node *n)
{
    int l_height = (n->left) ? n->left->height : -1;
    int r_height = (n->right) ? n->right->height : -1;
    n->height = (l_height > r_height) ? l_height + 1 : r_height + 1;
}

// ll rotation
struct node *LL(struct node *n)
{
    struct node *new_root = n->left;
    n->left = new_root->right;
    new_root->right = n;
    set_height(n);
    set_height(new_root);
    return new_root;
}

// rr rotation
struct node *RR(struct node *n)
{
    struct node *new_root = n->right;
    n->right = new_root->left;
    new_root->left = n;
    set_height(n);
    set_height(new_root);
    return new_root;
}

// lr rotation
static struct node *LR(struct node *n)
{
    struct node *mid = n->left;
    struct node *new_root = mid->right;
    mid->right = new_root->left;
    n->left = new_root->right;
    new_root->left = mid;
    new_root->right = n;
    set_height(n);
    set_height(mid);
    set_height(new_root);
    return new_root;
}

// rl rotation
static struct node *RL(struct node *n)
{
    struct node *mid = n->right;
    struct node *new_root = mid->left;
    mid->left = new_root->right;
    n->right = new_root->left;
    new_root->left = n;
    new_root->right = mid;
    set_height(n);
    set_height(mid);
    set_height(new_root);
    return new_root;
}

// try_rotate
struct node *try_rotate(struct node *n)
{
    int bal = get_balance(n);
    if (bal < -1)
    {
        bal = get_balance(n->right);
        if (bal > 0)
        {
            n = RL(n);
        }
        else
        {
            n = RR(n);
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

// insert

struct node *insert(struct node *root, int val)
{
    struct node *n;
    if (root == NULL)
    {
        root = allocate_node(val); // height =-1 karna
        return root;
    }
    if (val >= root->val)
    {
        root->right = insert(root->right, val);
    }
    else
    {
        root->left = insert(root->left, val);
    }
    set_height(root);
    n = try_rotate(root);
    return n;
}

// delete
struct node *delete(struct node *root, int val)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->val == val)
    {
        if (root->left == NULL)
        {
            struct node *ret = root->right;
            free(root);
            return ret;
        }
        else if (root->right == NULL)
        {
            struct node *ret = root->left;
            free(root);
            return ret;
        }
        else if (root->right != NULL && root->left != NULL)
        {
            struct node *min_node = find_min(root->right);
            root->val = min_node->val;
            root->right = delete (root->right, min_node->val);
        }
    }
    else if (val > root->val)
    {
        root->right = delete (root->right, val);
    }
    else
    {
        root->left = delete (root->left, val);
    }
    set_height(root);
    struct node *n = try_rotate(root);
    return n;
}