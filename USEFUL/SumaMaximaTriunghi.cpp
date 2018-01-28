 #include<fstream>
 #include<iostream>
 using namespace std;

 int n,m,T[101][101],S[101][101];
 fstream fin("triunghi.in",ios::in),
 fout("triunghi.out",ios::out);

 void citire()
 {
 int i,j;
 fin>>n;
 for(i=1;i<=n;i++)
 for(j=1;j<=i;j++)
 {
 fin>>T[i][j];
 }
 }

 void triunghi()
 {
 int i,j;
 for (i=1; i<=n; i++)
 S[n][i]=T[n][i];
 for (i=n-1; i>0; i--)
 for (j=1; j<=i; j++)
 {
 S[i][j]=T[i][j]+S[i+1][j];
 if (S[i+1][j]<S[i+1][j+1])
 S[i][j]=T[i][j]+S[i+1][j+1];
 }
 }

 void tipar()
 {
 int i,j;
 for(i=1;i<=n;i++)
 {
 for(j=1;j<=i;j++)
 cout<<S[i][j]<<" ";
 cout<<endl;
 }
 }
 int main ()
 {
 citire();
 triunghi();
 tipar();
 fout<<S[1][1];
 fin.close();
 fout.close();
 return 0;
 }
