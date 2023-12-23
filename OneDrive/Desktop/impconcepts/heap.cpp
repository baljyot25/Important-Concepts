



//heap is a complete binary tree, every level is fully filled except the last one ,and left nodes are filled first.
//left child=2*i,,right child=2*i+1,,, parient =i/2

#inlcude<iostream>

int size=0;//size of heap
int arr[100];//heap//1st elemen in arr is -1;

void insertheap(int val)//maxheap
{
    size+=1;
    int index=size;
    arr[index]=val;
    while(index>1)
    {
        int parent=index/2;
        if (arr[parent]<arr[index]) 
        {
            swap(arr[index],arr[parent]);
            index=parent;
        }
        else   return;
    }
}


void delete()//maxheap
{
    if(size==0)
    {
        cout<<"nothing to delete";
        return ;
    }
    arr[1]=arr[size];
    size--;   

    //take root node to its correct position;
    int i = 1;

    while (i < size)
    {
        int leftIndex = 2 * i;
        int rightIndex = 2 * i + 1;

        if (leftIndex < size && arr[i] < arr[leftIndex] && arr[leftIndex] > arr[rightIndex])
        {
            swap(arr[i], arr[leftIndex]);
            i = leftIndex;
        }

        else if (rightIndex < size && arr[i] < arr[rightIndex] && arr[leftIndex] < arr[rightIndex])
        {
            swap(arr[i], arr[rightIndex]);
            i = rightIndex;
        }

        else
        {
            return;
        }
    }

}


//heapify algo
void heapify(int arr[],int n,int i)
{
    int largest=i;
    int left=2*i;
    int right =2*i+1;
    if(right <=n && arr[right]>arr[largest] )
    {
        largest=right;
    }
    if (left <=n && arr[left]>arr[largest] )
    {
        largest=left;
    }
    if(largest!=i)
    {
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest);
    }   
}


void heapify_on_whole_arr()
{
    for (int i=n/2;i>0;i--)
    {
        heapify(arr,size,i);
    }
}



void heapsort(int arr[],int n)
{
    int size=n;  
    while(size>1)
    {
        swap(arr[size],arr[1]);
        size--;
        heapify(arr,size,1);
    }
}

// you can use priority queue in cpp from stl(search net).