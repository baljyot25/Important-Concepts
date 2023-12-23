def issafe(newx,newy,vis,mat):
    if newx>=0 and newy>=0 and newx<4 and newy<4:
        if vis[newx][newy]==0 and mat[newx][newy]==1 :
            return True
    return False
def solve(x,y,mat,ans,seq,vis):
    if x==len(mat)-1 and y==len(mat[0])-1:
        ans.append(seq)
        print(seq,ans)
        return 

    vis[x][y]=1
    #down
    newx=x+1
    newy=y
    if issafe(newx,newy,vis[:],mat[:]):
        seq.append("D")
        solve(newx,newy,mat[:],ans[:],seq[:],vis[:])
        seq.pop()
    #up
    newx=x-1
    newy=y
    if issafe(newx,newy,vis[:],mat[:]):
        seq.append("U")
        solve(newx,newy,mat[:],ans[:],seq[:],vis[:])
        seq.pop()
    #right
    newx=x
    newy=y+1
    if issafe(newx,newy,vis[:],mat[:]):
        seq.append("R")
        solve(newx,newy,mat[:],ans[:],seq[:],vis[:])
        seq.pop()
    #left
    newx=x
    newy=y-1
    if issafe(newx,newy,vis[:],mat[:]):
        seq.append("L")
        solve(newx,newy,mat[:],ans[:],seq[:],vis[:])
        seq.pop()
    vis[x][y]=0
    

def an():
    mat=[[1,0,0,0],[1,1,0,1],[1,1,0,0],[0,1,1,1]]
    vis=[[0,0,0,0],[0,0,0,0],[0,0,0,0],[0,0,0,0]]
     
    seq=[]
    ans=[]
    solve(0,0,mat,ans[:],seq[:],vis)
    print(ans)
    print(seq)
an()