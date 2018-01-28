#include<fstream>
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
fstream fin("traseu.in");
ofstream fout("traseu.out");
#define nmax 1005

int n,m;
bool viz[nmax];
int start;
int t[nmax];
stack < int > s;
bool ad[nmax][nmax];
void read()
{
    int k,l;
    fin>>n>>m;
    for(int i=1; i<=m; i++)
    {
        fin>>k>>l;
        ad[k][l]=1;
        ad[l][k]=1;
    }
}
void ciclu(int k)
{
    //fout<<start<<" ";
    while(k!=start)
    {
        fout<<k<<" "/*<<t[k]<<" * "*/;
        k=t[k];
    }
    fout<<start<<endl;
}
void DFS(int x)
{
    viz[x]=1;
    for(int i=1; i<=n; i++)
    {
        if(ad[x][i]==1)
        {
            ad[i][x]=0;
            if(viz[i]==0)
            {
                viz[i]=1;
                t[i]=x;
                DFS(i);
            }
            else
            {
                start=i;
                for(int j=1;j<=n;j++)
                    cout<<t[j]<<" ";
                cout<<endl;
                ciclu(x);

            }
        }

    }
}
int main()
{
    read();
    DFS(1);
}
