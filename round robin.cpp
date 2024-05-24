#include<bits/stdc++.h>
using namespace std;
// to use this write  "std::sort(foo.begin(), foo.end(), compare_pair_second<>());"
template<template <typename> class P = std::less >
struct compare_pair_second
{
    template<class T1, class T2> bool operator()(const std::pair<T1, T2>& left, const std::pair<T1, T2>& right)
    {
        return P<T2>()(left.second, right.second);
    }
};
struct process
{
    int id,at,bt,ct,tat,wt;
};
bool compareByat(const process &a, const process &b)
{
    return a.at<b.at;
}
void fi_CT(process proc[], int n, int q)
{
   vector<int>rem(n);
   for(int i=0;i<n;i++)
   {
       rem[i]=proc[i].bt;
   }
   int cnt=0;
   deque<int>ready;
   ready.push_back(0);
   deque<int>::iterator it;
   while(!ready.empty())
   {
       int i=ready.front();
       ready.pop_front();
       if(rem[i]>0 && proc[i].at<=cnt)
       {
           if(rem[i]>q)
           {
               rem[i]-=q;
               cnt+=q;
               for(int j=i+1;j<n;j++)
               {
                   if(proc[j].at<cnt)
                   {
                       it=find(ready.begin(),ready.end(), j);
                       if(it==ready.end()) ready.push_back(j);
                   }
               }
               ready.push_back(i);
           }
           else{
                cnt+=rem[i];
                rem[i]=0;
                proc[i].ct=cnt;
                for(int j=i+1;j<n;j++)
               {
                   if(proc[j].at<cnt)
                   {
                       it=find(ready.begin(),ready.end(), j);
                       if(it==ready.end()) ready.push_back(j);
                   }
               }


           }
       }
   }








}






void fiTAT(process proc[],int n)
{
    for(int i=0;i<n;i++)
    {
        proc[i].tat=proc[i].ct-proc[i].at;
    }
}
void fiWT(process proc[],int n)
{
    for(int i=0;i<n;i++)
    {
        proc[i].wt=proc[i].tat-proc[i].bt;
    }
}
int  main()
{

    int n,q;
    cin>>n>>q;
    process proc[n];
    for(int i=0; i<n; i++)
    {
        proc[i].id=i+1;
        cin>>proc[i].at>>proc[i].bt;

    }
    sort(proc,proc+n, compareByat);
    fi_CT(proc, n,q);
    fiTAT(proc,n);
    fiWT(proc,n);
    cout<<"pn\t\t"<<"at\t\t"<<"bt\t\t"<<"ct\t\t"<<"tat\t\t"<<"wt\t\t"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<proc[i].id<<"\t\t"<<proc[i].at<<"\t\t"<<proc[i].bt<<"\t\t"<<proc[i].ct<<"\t\t"<<proc[i].tat<<"\t\t"<<proc[i].wt<<endl;
    }

    return 0;
}

