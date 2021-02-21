#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
      int n,r,ans=1,cr=0;
      cin>>n>>r;
     int x[n+10];

     for(int i=1;i<=n;i++) cin>>x[i];
     sort(x+1,x+n+1);

     cr=r;
     for(int i=n-1;i>=1;i--){
      if((x[i]-cr>0)&&(x[i]!=x[i+1])){
      ans++;
      cr+=r;
     }
     }

     cout<<ans<<endl;

    }
}
