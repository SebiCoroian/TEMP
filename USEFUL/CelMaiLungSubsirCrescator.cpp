#include<fstream>
#include<iostream>
using namespace std;
#define MAX 100001
ifstream fin("sir.in");
int a[MAX],l[MAX],poz[MAX];
int n,m,prim;

void citire()
 {
 int i;
 fin>>n;
 for(i=1;i<=n;i++)
 fin>>a[i];
 }

 void subsir()
 {
 int i,j;
 for(i=n;i>=1;i--)
 { l[i]=1;poz[i]=0;
 for(j=i+1;j<=n;j++)
 if(a[i]<a[j] && l[i]<1+l[j])
 {l[i]=1+l[j];poz[i]=j;}
 if(m<l[i]) {m=l[i];prim=i;}
 }
 }

 void tipar()
 {
 int i;
 cout<<m<<endl;
 for(i=prim;i>0;i=poz[i])
 cout<<a[i]<<' ';
 }
 int main()
 {
 citire();
 subsir();
 tipar();
 fin.close();
 return 0;
 }
