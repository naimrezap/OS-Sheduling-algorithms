#include<bits/stdc++.h>
using namespace std;
//template for sort pair according to the second value of a vector
// to use this write  "std::sort(foo.begin(), foo.end(), compare_pair_second<>());"
template<template <typename> class P = std::less >
struct compare_pair_second {
    template<class T1, class T2> bool operator()(const std::pair<T1, T2>& left, const std::pair<T1, T2>& right) {
        return P<T2>()(left.second, right.second);
    }
};

void calculate(vector<pair<int,int>>&v, int n)
{
    vector<int>ct(n),tr(n),wt(n);
    //completion time
    ct[0]=v[0].first+ v[0].second;
    int cnt=ct[0];
    for(int i=1;i<n;i++)
    {
        if(cnt<v[i].first) cnt+=v[i].first-cnt;
        ct[i]=cnt+v[i].second;
        cnt=ct[i];
    }
    //turn time
    for(int i=0;i<n;i++)
    {
        tr[i]=ct[i]-v[i].first;
    }
    //waiting time
   // wt[0]=v[0].first;
    for(int i=0;i<n;i++)
    {
        wt[i]=tr[i]-v[i].second;
    }
    cout<<"pn\t\t"<<"at\t\t"<<"bt\t\t"<<"ct\t\t"<<"trn\t\t"<<"wt\t\t"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<i+1<<"\t\t"<<v[i].first<<"\t\t"<<v[i].second<<"\t\t"<<ct[i]<<"\t\t"<<tr[i]<<"\t\t"<<wt[i]<<endl;
    }
}
int main()
{

    int n;
    cin>>n;
    vector<pair<int,int>>v;
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        v.push_back({x,y});
    }
sort(v.begin(),v.end());
   calculate(v,n);
    return 0;
}
