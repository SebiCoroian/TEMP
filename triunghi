#include<fstream>
using namespace std;
int tri[20][20],V[20],DP[1000001];
bool B[19][1000001];
int nr;
void backtrack(int n,int x){
 nr++;
 if(x-1>=1 && x-1<=n-1 && n-1>=1)
  backtrack(n-1,x-1);
 if(x>=1 && x<=n-1 && n-1>=1)
  backtrack(n-1,x);
}
int main(){
 int n,s,i,j,x,y;
 ifstream fin("triunghi.in");
 ofstream fout("triunghi.out");
 fin>>n>>s;
 V[1]=V[n]=n;
 for(i=2;i<=n-1;i++){
  nr=0;
  backtrack(n,i);
  V[i]=nr;
 }
  for(i=1;i<=n;i++){
  for(j=1;j<=s;j++){
  if(DP[j-V[i]]+V[i]>=DP[j])
  B[i][j]=1;
  if(j>=V[i])
  DP[j]=max(DP[j],DP[j-V[i]]+V[i]);
  }
 }
 
 if(DP[s]!=s)
  fout<<"imposibil"<<"\n";
 else{
 x=n;y=s;
 while(x!=1 && y!=1){
  if(B[x][y]==1){
   y=y-V[x];
   tri[n][x]++;
  }
  else{
   x--;}
 }
 for(i=n-1;i>=1;i--)
  for(j=1;j<=i;j++)
   tri[i][j]=tri[i+1][j]+tri[i+1][j+1];
 for(i=1;i<=n;i++){
  for(j=1;j<=i;j++){
   fout<<tri[i][j]<<" ";
  }
  fout<<"\n";
 }
 }
 return 0;
}
