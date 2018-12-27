#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int mode(char c)
{
    if(c=='d' || c=='f')
        return 0;
    return 1;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        map<string, double> word;
        cin>>n;
        string s;
        double tot_time=0.0, curr_time=0.0;
        for(int i=0;i<n;i++)
        {
            cin>>s;
            if(word.find(s)!=word.end())
            {
                curr_time=word[s]/2;

            }
            else
            {
                int prev_mod = mode(s[0]), curr_mod;
                curr_time=0.2;
                for(int i=1;i<s.length();i++)
                {
                    curr_mod=mode(s[i]);
                    if(curr_mod==prev_mod)
                    {
                        curr_time+=0.4;
                    }
                    else
                    {
                        curr_time+=0.2;
                    }
                    prev_mod=curr_mod;
                }
                word[s]=curr_time;
            }
            tot_time+=curr_time;
            //cout<<s<<" "<<curr_time<<" "<<tot_time<<endl;
        }
        cout<<tot_time*10<<endl;
    }
    return 0;
}
