def solve(ans,output,index,s):
    if index>=len(s):
        ans.append(s)
        
        return
    for i in range(index,len(s)):
        s[index],s[i]=s[i],s[index]
        solve(ans,output[:],index+1,s[:])
        s[index],s[i]=s[i],s[index]

def an():
    index=0
    output=[]
    ans=[]
    s=list("abc")
    solve(ans,output[:],index,s[:])
    ans.sort()
    print((ans))
an()
