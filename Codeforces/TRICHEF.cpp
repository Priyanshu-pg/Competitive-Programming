#include<bits/stdc++.h>
using namespace std;
#define MP make_pair

typedef long long int ll;
typedef pair<int, ll> pp;

bool comp(pp a, pp b)
{
    return a.second<b.second;
}
int binarySearch(double x){
    ll low = 0;
    ll high = 1000001;
    ll mid;
    while(low <= high){
        mid = low + (high-low)/2;
        if(mid==x){
            return mid;
        }
        else if(mid>x){
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return low;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<ll> x1, x2, x3;
        int x;
        ll y;
        double area=0;
        for(int i=0;i<n;i++)
        {
            cin>>x>>y;
            switch(x)
            {
                case 1:
                x1.push_back(y);
                break;
                case 2:
                x2.push_back(y);
                break;
                case 3:
                x3.push_back(y);
                break;
            }
        }
        sort(x1.begin(), x1.end());
        sort(x2.begin(), x2.end());
        sort(x3.begin(), x3.end());

        int my_points[1000001]={0};
        ll num_points = x2.size();
        double dist_fwd[x2.size()+1];
        double dist_bckwd[x2.size()+1];
        dist_fwd[0] = 0.0;
        dist_bckwd[num_points] = 0.0;
        dist_fwd[1] = 1000001-x2[0];
        dist_bckwd[num_points-1] = x2[num_points-1];
        ll i;
        for(i=2;i<x2.size();i++){
            dist_fwd[i] = dist_fwd[i-1] + (1000001-x2[i]);
        }
        for(i=n-1;i>=0;i--){
            dist_bckwd[i] = dist_bckwd[i+1] + x2[i];
        }
        for(i=0;i<x2.size();i++){
            my_points[x2[i]]=1;
        }


        for(i=1;i<1000001;i++){
            my_points[i] += my_points[i-1];
        }

        double rmax = 0.0;
        for(i=0;i<x2.size();i++){
            rmax += abs(1000001-x2[i]);
        }
        double lmax = 0.0;
        for(i=0;i<x2.size();i++){
            lmax += abs(x2[i]);
        }

        for(int i=1;i<x1.size();i++)
        {
            area+=1.5*(x1[i]-x1[i-1]);
            cout<<"yay1\n";
        }

        for(int i=1;i<x2.size();i++)
        {
            area+=(x2[i]-x2[i-1]);
            cout<<"yay2\n";
        }

        for(int i=1;i<x3.size();i++)
        {
            area+=1.5*(x3[i]-x3[i-1]);
            cout<<"yay3\n";
        }
        //cout<<area<<endl;
        ll sum2=0.0;
        for(int i=0;i<x2.size();i++)
        {
            sum2+=x2[i];
        }
        for(int i=0;i<x1.size();i++)
        {
            for(int k=0;k<x3.size();k++)
            {
                double y_point = (double)(x1[i]+x3[k])/2.0;
                int temp = binarySearch(y_point);
                int less_points = my_points[temp];
                int more_points = num_points - less_points;

                double sum_of_distances = dist_fwd[less_points] - (less_points)*(1000001-y_point) + dist_bckwd[num_points-more_points] - (more_points)*(y_point);
                area += sum_of_distances;
                cout<<"yay4\n";
            }
        }
        printf("%0.2f\n",area);
    }

    return 0;
}


