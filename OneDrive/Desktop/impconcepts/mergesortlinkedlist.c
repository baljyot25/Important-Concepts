Node * merge(Node *left,Node * right )
    {
        if (left==NULL)
        {
            return right;
            
        }
        if(right==NULL) return left;
        
        Node * ans= new Node(-1);
        Node * temp=ans;
        while(left!=NULL && right!=NULL)
        {
            if(left->data<right->data)
            {
                temp->next=left;
                temp=left;
                left=left->next;
                
            }
            else
            {
                temp->next=right;
                temp=right;
                right=right->next;
                
            }
        }
        while(left!=NULL)
        {
            temp->next=left;
            temp=left;
            left=left->next;
                
            
        }
        while(right!=NULL)
        {
            temp->next=right;
            temp=right;
            right=right->next;
            
        }
        ans=ans->next;
        return ans;
    }
    Node * findmid(Node * head)
    {
        Node * slow=head;
        Node * fast =head->next  ;
        while(fast!=NULL && fast->next!=NULL)
        {
            fast=fast->next->next;
            slow=slow->next;
     
        }
        return slow;
    }
    //Function to sort the given linked list using Merge Sort.
    Node* mergeSort(Node* head) {
        // your code here
        if (head==NULL|| head->next==NULL)
        {
            return head;
        }
        Node* mid=findmid(head);
        
        Node* left=head;
        Node* right=mid->next;
        mid->next=NULL;
        left=mergeSort(left);
        right=mergeSort(right);
        Node* result=merge(left ,right);
        
        return result ;
        
    }
};