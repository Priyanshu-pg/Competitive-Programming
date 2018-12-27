#include <iostream>
using namespace std;

int main() {
	long long int l, r;
	cin>>l>>r;
	cout<<"YES"<<endl;
       	for(long long int i=l;i<r;i+=2)
	{
	    cout<<i<<" "<<1+i<<endl;
	}
	return 0;
}
