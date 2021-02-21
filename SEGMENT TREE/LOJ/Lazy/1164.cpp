#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 100005
struct lazy{
    ll prop,sum;
}tree[mx*4];
void update(int node,int ss,int se,int qs ,int qe,ll x){

       if(qs>se || qe<ss)
        return;
       if(ss>=qs&&se<=qe){
        tree[node].sum=((se-ss+1)*x);
        tree[node].prop+=x;
        return;
       }
       int l=node*2;
       int r=2*node+1;
       int mid=(ss+se)/2;
       update(l,ss,mid,qs,qe,x);
       update(r,mid+1,se,qs,qe,x);
       tree[node].sum=tree[l].sum+tree[r].sum+(se-ss+1)*tree[node].prop;
}
ll query(int node,int ss,int se,int qs,int qe,ll carry){
       if(qs>se || qe<ss)
        return 0;
       if(ss>=qs&&se<=qe){
       return tree[node].sum+((se-ss+1)*carry);
       }
       int l=node*2;
       int r=l+1;
       int mid=(ss+se)/2;

       ll lsum=query(l,ss,mid,qs,qe,carry+tree[node].prop);
       ll rsum=query(r,mid+1,se,qs,qe,carry+tree[node].prop);
       return lsum+rsum;

}
int main()
{
    int t,cs=1;
    scanf("%d",&t);
    while(t--){
        int n,q;
        scanf("%d%d",&n,&q);
        memset(tree,0,sizeof(tree));
        printf("Case %d:\n",cs++);
        while(q--){
            int type;
            scanf("%d",&type);
            int l,r;
            scanf("%d%d",&l,&r);

            if(type==0){
                ll x;
                scanf("%lld",&x);
                update(1,1,n,l+1,r+1,x);
            }
            else{

               ll ans=query(1,1,n,l+1,r+1,0);
               printf("%lld\n",ans);
            }
        }

    }

}
