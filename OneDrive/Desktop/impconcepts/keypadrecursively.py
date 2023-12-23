def solve(ans,output,index,l,d):
    if index>=len(d):
        ans.append(output)
        return 
    a=l[int(d[(index)])]
  
    for i in range(len(a)):
        output.append(a[i])
        solve(ans,output[:],index+1,l,d)
        
        output.pop()

def an():
    index=0
    output=[]
    ans=[]
    d="346"
    l=["","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"]
    solve(ans,output[:],index,l,d)
    print(ans)
an()
