#include <iostream>
using namespace std;

int main() {
	string s;
	cin>>s;
	char first = s[0];
	int ascii = (int)first;
	if(ascii>=97 && ascii <= 122)
	{
	    ascii-=32;
	    char c = (char)(ascii);
	    s[0]=c;
	}
	cout<<s<<endl;
	return 0;
}
