#all tuples that were unique are printed only.confirmed by TA.printing is not in order

def ansprog(l1,l2,ans,i):
    if len(l2)==0:
        ansprog(l1,x1,ans,i+1)
    if i>=x :
        return
    if len(ans)==x*len(x1):
        return
    
    ans.append(tuple([l1[i],l2[0]]))
    print(ans)
    
    ansprog(l1,l2[1:],ans,i)
    


    
    return 

ans=[]
l1=[1,2,5]
x=len(l1)
l2=[5,6,7,5]
x1=l2.copy()
ansprog(l1,l2,ans,0)
print(ans)
#printing is not in order