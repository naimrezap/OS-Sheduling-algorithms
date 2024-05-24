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
    int id,at,bt,ct,tat,wt,pt;
};
bool compareByat(const process &a, const process &b)
{
    return a.at<b.at;
}
void fi_CT(process proc[], int n)
{
    vector<bool>ok(n,false);
  //  proc[0].ct=proc[0].at+proc[0].bt;
    int hpt, cnt=0;

    for(int j=0; j<n; j++)
    {
        int mn=INT_MIN, ind=-1;
        for(int i=0; i<n; i++)
        {
            if(proc[i].at<=cnt && ok[i]==false && proc[i].pt>mn)
            {

               mn=proc[i].pt;
               ind=i;

            }
        }
        if(ind!=-1){
              proc[ind].ct=cnt+proc[ind].bt;
        ok[ind]=true;
        cnt=proc[ind].ct;
        }


    }
}






void fiTAT(process proc[],int n)
{
    for(int i=0; i<n; i++)
    {
        proc[i].tat=proc[i].ct-proc[i].at;
    }
}
void fiWT(process proc[],int n)
{
    for(int i=0; i<n; i++)
    {
        proc[i].wt=proc[i].tat-proc[i].bt;
    }
}
int  main()
{

    int n,q;
    cin>>n;
    process proc[n];
    for(int i=0; i<n; i++)
    {
        proc[i].id=i+1;
        cin>>proc[i].pt>>proc[i].at>>proc[i].bt;

    }
    sort(proc,proc+n, compareByat);
    fi_CT(proc,n);
    fiTAT(proc,n);
    fiWT(proc,n);
    cout<<"pn\t\t"<<"at\t\t"<<"bt\t\t"<<"ct\t\t"<<"tat\t\t"<<"wt\t\t"<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<proc[i].id<<"\t\t"<<proc[i].at<<"\t\t"<<proc[i].bt<<"\t\t"<<proc[i].ct<<"\t\t"<<proc[i].tat<<"\t\t"<<proc[i].wt<<endl;
    }

    return 0;
}
