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

    p knapsack(int fun[], int cost[], int curr_cost, int n, map<p, int> & m)
    {
        if(n == 0 || curr_cost == 0)
        {
            m[mp(n, curr_cost)] = 0;
        }

        if(m.find(mp(n, curr_cost)) != m.end())
            return mp(m[mp(n, curr_cost)], curr_cost);

        p without = knapsack(fun, cost, curr_cost, n-1, m);
        p with = knapsack(fun, cost, curr_cost - cost[n-1], n-1, m);
        if(cost[n-1] > curr_cost)
        {
            m[mp(n, curr_cost)] = without.fr;
            return mp(m[mp(n, curr_cost)], curr_cost);
        }    
        else
        {
            if(fun[n-1] + with.fr > without.fr)
            {
                m[mp(n, curr_cost)] = fun[n-1] + with.fr;
                return mp(m[mp(n, curr_cost)], curr_cost - cost[n-1]);
            }
            else
            {
                m[mp(n, curr_cost)] = without.fr;
                return mp(m[mp(n, curr_cost)], curr_cost);
            }
        }    
    }

    void solve()
    {
        while(true)
        {
            int budget, n;
            cin>>budget>>n;
            if(budget == 0 && n == 0)
                break;

            int cost[n], fun[n];
            for(int i=0;i<n;i++)
            {
                cin>>cost[i]>>fun[i];
            }

            int dp[n+1][budget+1];

            for(int i=0;i<=n;i++)
            {
                for(int j=0;j<=budget;j++)
                {
                    if(i==0 || j==0)
                        dp[i][j]=0;
                    else
                    {
                        if(cost[i-1] <= j)
                        {
                            dp[i][j] = max(fun[i-1] + dp[i-1][j-cost[i-1]],
                                            dp[i-1][j]);
                        }
                        else
                        {
                            dp[i][j] = dp[i-1][j];
                        }
                    }
                }
            }

            int exp=0, res=dp[n][budget];
            for(int i=1;i<=budget;i++)
            {
                if(dp[n][i] == res)
                {
                    exp=i;
                    break;
                }
            }
            cout<<exp<<" "<<dp[n][budget]<<endl;
        }

    }

    int main()
    {
        fileI;
        fileO;
        fastIO;
        solve();
        return 0;
    }
