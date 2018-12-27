#include <iostream>
using namespace std;

int min(int a, int b)
{
    if(a<b)
    return a;
    return b;
}

int mod(int x)
{
    if(x<0)
    return -x;
    return x;
}

int main() {
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
	    cin>>a[i];
	}
	int diff[n];
	int sum=a[0];
	diff[0]=sum;
	for(int i=1;i<n;i++)
	{
	    sum+=mod(a[i]-a[i-1]);
	    diff[i]=mod(a[i]-a[i-1]);
	}
	int minsum=sum;
	for(int i=0;i<n-1;i++)
	{
	    for(int j=i+1;j<n;j++)
	    {
	       int temp2=0;
	       
	       //calc temp2 from calc
	       temp2 = sum;
	       temp2 -= diff[i];
	       temp2 -= diff[i+1];
	       if(i+1!=j)
	       temp2 -= diff[j];
	       if(j<n-1)
	       temp2 -= diff[j+1];
	       if(i==0)
	       {
	           temp2+=a[j];
	       }
	       else
	       {
	           temp2+=mod(a[j]-a[i-1]);
	       }
	       temp2+=mod(a[i+1]-a[j]);
	       temp2+=mod(a[j-1]-a[i]);
	       if(j<n-1)
	       {
	           temp2+=mod(a[j+1]-a[i]);
	       }
	       if(i+1==j)
	       {
	           temp2+=mod(a[i]-a[j]);
	       }
	   
	       minsum = min(minsum, temp2);
	       
	    }
	}
	cout<<minsum<<endl;
	return 0;
}
