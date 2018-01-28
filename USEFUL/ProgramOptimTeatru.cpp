#include <iostream>
#include <fstream>
using namespace std;

ifstream f("spectacole.in");
ofstream g("spectacole.out");

int n,inceput[100],sfarsit[100],nr[100];

void citeste()
{
 int ora,min,i;
 f>>n;
 for (i=0;i<n;++i)
 {
 nr[i]=i+1;
 f>>ora>>min;
 inceput[i]=ora*60+min;
 f>>ora>>min;
 sfarsit[i]=ora*60+min;
 }
 f.close();
}

void sorteaza()
{
 int aux,schimb,i;
 do
 {
 schimb=0;
 for (i=0;i<n-1;++i)
 if (sfarsit[nr[i]]>sfarsit[nr[i+1]])
 {
 aux=nr[i];
 nr[i]=nr[i+1];
 nr[i+1]=aux;
 schimb=1;
 }
 }
  while (schimb);
}

void rezolva()
{
 int ultim,i;
 for (ultim=0,i=1;i<n;++i)
 if (inceput[nr[i]]>=sfarsit[nr[ultim]])
 {
 g<<nr[i]+1<<" ";
 ultim=i;
 }
 g<<endl;
}

int main()
{
 citeste();
 sorteaza();
 rezolva();
 return 0;
}
