#include<bits/stdc++.h>
using namespace std;
int main()
{
    cout<<"Enter the size of partition: ";
    int n;
    cin>>n;
    cout<<"enter the size of "<<n<<" partition"<<endl;
    vector<pair<int,int>>v;
    for(int i=0;i<n;i++)
    {
        int x=i+1,y;
        cin>>y;
        v.push_back({x,y});
    }
    cout<<"enter the process nUMBER: ";
    int m;
    cin>>m;
     cout<<"enter the process size: "<<endl;
    vector<int>pro(m);
    vector<int>ans(n,-1);
    for(int i=0;i<m;i++)
    {
        cin>>pro[i];
    }
    vector<bool>c(n,false);
    int k=0;
    for(int i=0;i<m;i++)
    {
        int a=-1;
        for(int j=0;j<n;j++)
        {
            if(v[j].second>=pro[i] && c[j]==false)
            {
                c[j]=true;
                a=1;
                ans[k++]=(j+1);
                break;
            }

        }
       // if(a==-1) ans.push_back(-1);
    }
    cout<<"p\t\t"<<"pro size\t\t"<<"bl"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<v[i].first<<"\t\t"<<v[i].second<<"\t\t\t"<<"process="<<i+1<<"->"<<ans[i]<<endl;
    }


    return 0;
}
