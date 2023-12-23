//trie is like trre but with multiple childs
//jaldi karna h isko

class trienode
{
    char data;
    trienode *children[26];
    bool isterminal;
    trienode(char ch)
    {
        data=ch;
        for(int i=0;i<26;i++)
        {
            children[i]=NULL;

        }
        isterminal=0;

    }
};

class trie
{
    public:
    trienode *root;
    trie(){
        root=new trienode('\0');

    }
    void insertutil(trienode * root,string word)
    {
        if (word.length()==0)
        {
            root ->isterminal=true;
            return;


        }
        int index=word[0]-'A';
        trienode *child;
        if(root->children[index]!= NULL)
        {
            child=root->children[index];
        }
        else{
            child=new trienode (word[0]);
            root->children[index]=child;

        }
        inserutil(child,s.substr(1));


    }
    
    void insertword(string s)
    {
        void insertutil(root,s)
    }




    bool searchutil(trienode* root,string word)
    {
        if(word.length()==0)
        {
            return root->isterminal;
        }
        int index=word[0]-'A'; 

    }

    bool search(string s)
    {
        return searchutil(root,s)
    }
}
