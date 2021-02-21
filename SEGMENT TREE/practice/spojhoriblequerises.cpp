#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 100005
ll lazy[4*mx];
ll tree[4*mx];

void build(int low,int high,int node)
{
    if(low>high)
    return;
    if(low == high)
    {
        tree[node]=0;
        return;
    }
    int mid = low+high>>1;
    build(low,mid,2*node+1);
    build(mid+1,high,2*node+2);
    tree[node]=tree[2*node+1]+tree[2*node+2];
}

void updatelazy(int low,int high,int lq,int hq,int node,ll val)
{
    if(lazy[node])
    {
        tree[node]+=(high-low+1)*lazy[node];
        if(high!=low)
        {
            lazy[2*node+1]+=lazy[node];
            lazy[2*node+2]+=lazy[node];
        }
        lazy[node]=0;
    }
    if(low>hq || high<lq)
    return;
    if(lq<=low && high<=hq)
    {
        tree[node]+=(high-low+1)*val;
        if(high!=low)
        {
            lazy[2*node+1]+=val;
            lazy[2*node+2]+=val;
        }
        return;
    }
    int mid=low+high>>1;
    updatelazy(low,mid,lq,hq,2*node+1,val);
    updatelazy(mid+1,high,lq,hq,2*node+2,val);
    tree[node]=tree[2*node+1]+tree[2*node+2];
}

ll lazyquery(int low,int high,int lq,int hq,int node)
{
    if(lazy[node])
    {
        tree[node]+=(high-low+1)*lazy[node];
        if(high!=low)
        {
            lazy[2*node+1]+=lazy[node];
            lazy[2*node+2]+=lazy[node];
        }
        lazy[node]=0;
    }
    if(low>hq || high<lq)
    return 0;
    if(lq<=low && high<=hq)
    {
        return tree[node];
    }
    int mid=low+high>>1;
   return lazyquery(low,mid,lq,hq,2*node+1)+lazyquery(mid+1,high,lq,hq,2*node+2);
}
int main(){
    int T,N,C;
    scanf("%d",&T);

    while(T--)
    {
        memset(tree,0,sizeof(tree));
        memset(lazy,0,sizeof(lazy));
        scanf("%d %d",&N,&C);
        int ch,p,q;
        ll v;
        build(0,N-1,0);
        while(C--)
        {
            scanf("%d",&ch);

            if(ch)
            {
                scanf("%d %d",&p,&q);
                printf("%lld\n",lazyquery(0,N-1,p-1,q-1,0));
            }
            else
            {
                scanf("%d %d %lld",&p,&q,&v);
                updatelazy(0,N-1,p-1,q-1,0,v);
            }
        }

    }

    return 0;

}
