#include <bits/stdc++.h>
#define ma 100010
using namespace std;
#define ll long long

ll x,a,y,b,k;

int p[300000];
bool func(ll m,ll n){
    if(x<y) swap(x,y),swap(a,b);
    ll sum=0,xc=m/a,yc=m/b,j=1;
    if(m==4) cout<<xc<<" "<<yc<<endl;
  // if(m==4) cout<<x<<" "<<y<<" "<<a<<" "<<b<<endl;
   for(int i=1;i<=m;i++){
     if(xc>0&&(i%a==0)){
        sum+=(x*p[j])/100;
        j++;
        xc--;
     }
     else if(yc>0&&(i%b==0)){
        sum+=(y*p[j])/100;;
        j++;
        yc--;
     }
   }
   if(sum>=k) return 1;
   else return 0;

}
int main()
{
   int q;
   cin>>q;
   for(int i=1;i<=q;i++){
       ll n,ans=LONG_LONG_MAX;
       cin>>n;
       for(int j=1;j<=n;j++){
        cin>>p[j];
       }
       sort(p+1,p+n+1,greater<int>());

        cin>>x>>a;
        cin>>y>>b;
        cin>>k;
       ll lo=1,hi=n;
        while(lo<=hi){
          ll m=(lo+hi)/2;


          if(func(m,n)==1){
            hi=m-1;
            ans=m;
          }
          else{
            lo=m+1;
          }

        }
        if(ans==LONG_LONG_MAX) cout<<-1<<endl;
        else cout<<ans<<endl;
        for(int z=1;z<=300000;z++) p[i]=0;
   }

}

