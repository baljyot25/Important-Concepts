def solve(a,ans,output,index):
    if index>=len(a):
        ans.append(output[:])
        
        return 
    #exclude
    
    solve(a,ans,output[:],index+1)
    #include
   
    x=a[index]
    
    output.append(x)
    solve(a,ans,output[:],index+1)


def subsets():
    a=[1,2,3]
    ans=[]
    output=[]
    index=0
    solve(a,ans,output[:],index)
    print(ans)
subsets()




    