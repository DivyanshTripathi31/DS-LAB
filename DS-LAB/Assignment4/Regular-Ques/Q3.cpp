//q3
#include<iostream>
using namespace std;
#define MAX 100
int main(){
	int n,a[MAX],q1[MAX],q2[MAX],f1=0,r1=-1,f2=0,r2=-1;
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n/2;i++)q1[++r1]=a[i];
	for(int i=n/2;i<n;i++)q2[++r2]=a[i];
	while(f1<=r1&&f2<=r2){
		cout<<q1[f1++]<<" "<<q2[f2++]<<" ";
	}
	cout<<"\n";
}