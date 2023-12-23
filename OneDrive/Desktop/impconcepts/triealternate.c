struct trienode
{
    char val;
    struct trienode * child ;
//linked list of every children
    struct trienode * next;
//in order to check leaf node next must be NULL;

};


//26* l operations will be taken to search a string
// in alternate implementation l  operation will will be taken thus char array of 26 elements is better;


