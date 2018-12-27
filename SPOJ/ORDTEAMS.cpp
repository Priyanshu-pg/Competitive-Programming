#include<bits/stdc++.h>
using namespace std;

int betterContestant(int x, int y, int cont[3][3])
{
    int diff[3];
    int neg =0, pos =0;
    for(int i=0;i<3;i++)
    {
        diff[i]=cont[x][i]-cont[y][i];
        if(diff[i]<0)
            neg++;
        if(diff[i]>0)
            pos++;
    }
    if(neg == 0 && pos > 0)
        return y;
    if(neg > 0 && pos == 0)
        return x;
    return -1;
}

void swap(int x, int y, int (&a)[3][3])
{
    int temp[3];
    for(int i=0;i<3;i++)
    {
        temp[i]=a[x][i];
    }
    for(int i=0;i<3;i++)
    {
        a[x][i]=a[y][i];
    }
    for(int i=0;i<3;i++)
    {
        a[y][i]=temp[i];
    }
}

void display(int a[3][3])
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--)
    {
        int a[3][3];
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                cin>>a[i][j];
            }
        }

        int min=0;
        bool flag = true;
        for(int i=0;i<2 && flag;i++)
        {
            min=i;
            for(int j=i+1;j<3;j++)
            {
                min = betterContestant(min, j, a);
                if(min == -1)
                {
                    flag = false;
                    break;
                }
            }
            if(!flag)
            {
                break;
            }
            swap(min, i , a);
        }

        if(flag)
        {
            cout<<"yes"<<endl;
        }
        else
        {
            cout<<"no"<<endl;
        }
    }
    return 0;
}
