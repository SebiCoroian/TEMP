#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void BFS(int x)
{
    int i;
    ///vizitam varful de start
    viz[x]=1;
    ///initializam coada cu varful de start
    q.push(x);
    while(!q.empty())
    {
     ///extragem un element din coada
     x=q.top();
     q.pop();
     ///parcurgem lista de adiacenta a varfului x
     for(int i=1;i<=A[x][0];i++)
            if(!viz[A[x][i]])
            ///A[x][i] este un vecin nevizitat al lui x
     {
         ///il vizitam
         viz[A[x][i]]=1;
         q.push(A[x][i]);
     }
    }
}
