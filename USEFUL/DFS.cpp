#include<iostream>
#include<vector>
using namespace std;

void DFS(int x)
{
    int i;
    ///vizitam varful x
    viz[x]=1;
    ///parcurgem lista de adiacenta a varfului x
    for(int i=0;i<=A[x][0];i++)
    {
        if(!viz[A[x][i])
            ///A[x][i] este un vecin nevizitat a lui x
            DFS(A[x][i]);
    }
}
