#include<bits/stdc++.h>
using namespace std;
//template for sort pair according to the second value of a vector
// to use this write  "std::sort(foo.begin(), foo.end(), compare_pair_second<>());"
template<template <typename> class P = std::less >
struct compare_pair_second
{
    template<class T1, class T2> bool operator()(const std::pair<T1, T2>& left, const std::pair<T1, T2>& right)
    {
        return P<T2>()(left.second, right.second);
    }
};
int main()
{
    cout<<"Enter the size of partition: ";
    int n;
    cin>>n;
    cout<<"enter the size of "<<n<<" partition"<<endl;
    vector<pair<int,int>>v;
    for(int i=0; i<n; i++)
    {
        int x=i+1,y;
        cin>>y;
        v.push_back({x,y});
    }
    std::sort(v.begin(), v.end(), compare_pair_second<>());
    cout<<"enter the process nUMBER: ";
    int m;
    cin>>m;
    cout<<"enter the process size: "<<endl;
    vector<int>pro(m);
    vector<int>ans(n,-1);
    for(int i=0; i<m; i++)
    {
        cin>>pro[i];
    }
    sort(pro.begin(),pro.end());
    vector<bool>c(n,false);
    int k=0;
    for(int i=0; i<m; i++)
    {
        int y=0,value=INT_MAX;
        for(int j=n-1; j>=0; j--)
        {
            if(v[j].second>=pro[i])
            {


                    v[j].second-=pro[i];
                    //c[j]=true;
//a=1;
                    ans[k++]=(v[j].first);
                    break;

            }


        }


    }
          // if(a==-1) ans.push_back(-1);

cout<<"p\t\t"<<"pro size\t\t"<<"bl"<<endl;
for(int i=0; i<m; i++)
{
    cout<<i+1<<"\t\t"<<pro[i]<<"\t\t\t"<<"process="<<i+1<<"->"<<ans[i]<<endl;
}


return 0;
}


