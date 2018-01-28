#include<iostream>
#include<queue>

int di[] = {-2, -2, -1, 1, -1, 1, 2, 2};
int dj[] = {-1, 1, -2, -2, 2, 2, -1, 1};

bool OK(int x, int y)
{
    if(x>0 && y>0 && x<=m && y<=n)
        return true;
    return false;
}

void Lee()
{
    int newx, newy;
    board[xc][yc]=1;
    q.push(make_pair(xc,yc));
    while(!q.empty())
    {
        xc=q.front().first;
        yc=q.front().second;
        q.pop();
        for(int dir=0; dir<8;dir++)
        {
            newx=xc+di[dir];
            newy=yc+dj[dir];
            if(OK(newx,newy)&&board[newx][newy]==0)
            {
                board[newx][newy]=board[xc][yc]+1;
                q.push(make_pair(newx,newy));
            }
        }
    }
}
