
//not yet completed
#include<iostream>
using namespace std;

int main()
{
    int max=4;
   float input=10;
    int i,j,a[10];
    int k=0;
    cout<<"Enter elements(row major): \n";
    for(i=0;i<input;i++)
    {
        cin>>a[i];
    }
    cout<<"The matrix is: \n";
    for(i=0;i<max;i++)
    {
        for(j=0;j<max;j++)
        {
            if(i<=j)
            cout<<a[k++]<<" ";
            else
            cout<<0<<" ";
        }
        cout<<"\n";
    }
    return 0;
}