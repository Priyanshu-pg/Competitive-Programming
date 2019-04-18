#include <bits/stdc++.h>

    using namespace std;
     
    #define pb push_back
    #define mp make_pair
    #define fr first
    #define sc second
    #define ll long long
    #define ull unsigned long long
    #define PI 3.14159265358979323846
    #define r2 1.41421356237309504880
    #define rep(i,n) for(ll i=0;i<n;i++)
    #define REP(i,k,n) for(ll i=k;i<n;i++)
    #define REPR(i,k,n) for(ll i=k;i>n;i--)
    #define fastIO std::ios::sync_with_stdio(0)
    #define fileI freopen("input.txt","r",stdin)
    #define fileO freopen("output.txt","w",stdout)
    #define mod 1000000007
    #define max3(a,b,c) max(a,max(b,c))
    #define _USE_MATH_DEFINES
    #define ms(a) memset(a,0,sizeof(a))
    typedef pair<int, int> p;


vector<string> split(string str, char delimiter) {
  vector<string> internal;
  stringstream ss(str); // Turn the string into a stream.
  string tok;
 
  while(getline(ss, tok, delimiter)) {
    internal.push_back(tok);
  }
 
  return internal;
}

    void solve()
    {
        int t;
        cin>>t;
        cin.ignore();
        while(t--)
        {
            map<string, p> m;
            for(int i = 0; i < 12; i++)
            {
                string team1, team2, s;
                int goal1, goal2;
                vector<string> res;
                //cin>>team1>>goal1>>vs>>team2>>goal2;
                getline(cin, s);
                // cout<<s;
                res = split(s, ' ');
                // cout<<res[3]<<"."<<endl;
                team1=res[0];
                team2=res[4];
                goal1=stoi(res[1]);
                goal2=stoi(res[3]);
               // cout<<team1<<" "<<team2<<endl;
                int point1, point2, goal_diff1, goal_diff2;
                if(goal1 > goal2)
                {
                    point1 = 3;
                    point2 = 0;
                }
                else if(goal2 > goal1)
                {
                    point1 = 0;
                    point2 = 3;
                }
                else
                {
                    point2 = 1;
                    point1 = 1;
                }
                goal_diff1 = goal1 - goal2;
                goal_diff2 = goal2 - goal1;
                if(m.find(team1) != m.end())
                {
                    p pair1 = m[team1];
                    pair1.fr += point1;
                    pair1.sc += goal_diff1;
                    m[team1] = pair1;
                }
                else
                {
                    m[team1] = mp(point1, goal_diff1);
                }
                if(m.find(team2) != m.end())
                {
                    p pair2 = m[team2];
                    pair2.fr += point2;
                    pair2.sc += goal_diff2;
                    m[team2] = pair2;
                }
                else
                {
                    m[team2] = mp(point2, goal_diff2);
                }
                // p pair1 = m[team1];
                // m[team1].sc.fr += point1;
                // m[team1].sc.sc += goal_diff1;
                // p pair2 = m[team2];
                // m[team2].sc.fr += point2;
                // m[team2].sc.sc += goal_diff2;
            }
            // vector<pair<string, p> > mapcopy(m.begin(), m.end());
            // sort(m.begin(), m.end(), custom<string, p>();
            // string team1="", team2="";
            // p score1 = mp(INT_MIN, INT_MIN), score2=mp(INT_MIN, INT_MIN);
            map<p,string> m2;
            for( auto const& x : m)
            {
                m2[x.sc]=x.fr;
                // cout<<x.fr<<" ";
                // p z = x.sc;
                // cout<<z.fr<<" "<<z.sc<<endl;
                // if(z.fr > score1.fr)
                // {
                //     score2 = score1;
                //     team2 = team1;
                //     score1 = p;
                // }
            }
            int i = 0;
            for( auto x = m2.rbegin(); x != m2.rend() && i < 2; x++, i++)
            {
                
                // p z = x->first;
                // cout<<z.fr<<" "<<z.sc<<" ";
                cout<<x->second<<" ";
                // if(z.fr > score1.fr)
                // {
                //     score2 = score1;
                //     team2 = team1;
                //     score1 = p;
                // }
            }
            cout<<endl;
        }
    }

    int main()
    {
        #ifdef ONLINE_JUDGE
        #else
            fileI;
            fileO;
        #endif
        fastIO;
        solve();
        return 0;
    }
