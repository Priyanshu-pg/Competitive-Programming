#include<bits/stdc++.h>
using namespace std;

int main(){
    while(true){
        int perimeter;
        cin>>perimeter;
        if(perimeter==0)
            break;
        double area = perimeter*perimeter/(M_PI*2);
        printf("%.2f\n", area);
    }
    return 0;
}
