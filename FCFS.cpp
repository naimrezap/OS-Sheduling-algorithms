#include<bits/stdc++.h>
using namespace std;
void completiont(vector<int> &a,vector<int>&bt,vector<int> &ct,vector<int> &wt,vector<int> &tr, int pn)
{
    int cnt=a[0]+bt[0];
    ct[0]=cnt;
    //completion time
    for(int i=1;i<pn;i++)
    {
        if(cnt<a[i]) cnt+=a[i]-cnt;
        ct[i]=cnt+bt[i];
        cnt=ct[i];
    }
    //turn aro;und time
    for(int i=0;i<pn;i++)
    {
        tr[i]=ct[i]-a[i];
    }
    // waiting time
    double  total=0;
    wt[0]=a[0];
    for(int i=1;i<pn;i++)
    {
        wt[i]=tr[i]-bt[i];
        total+=wt[i];
    }
    //average waiting time
    double aw=total/pn;

    cout<<"pn\t\t"<<"at\t\t"<<"bt\t\t"<<"ct\t\t"<<"trn\t\t"<<"wt\t\t"<<endl;
    for(int i=0;i<pn;i++)
    {
        cout<<i+1<<"\t\t"<<a[i]<<"\t\t"<<bt[i]<<"\t\t"<<ct[i]<<"\t\t"<<tr[i]<<"\t\t"<<wt[i]<<endl;
    }

    cout<<"\n\nThe average time of  the algorithm is = ";
    cout<<aw<<endl;

}
int main()
{

    int pn;
    cin>>pn;
    vector<int>a(pn);
    vector<int>bt(pn);
    vector<int>ct(pn),wt(pn),tr(pn);
    cout<<"Enter arrival time: ";
    for(int i=0;i<pn;i++)
    {
        cin>>a[i];
    }
    cout<<"Burst time: ";
    for(int i=0;i<pn;i++)
    {
        cin>>bt[i];
    }
    completiont(a,bt,ct,wt,tr,pn);

    return 0;
}
