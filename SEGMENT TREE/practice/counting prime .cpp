#include<bits/stdc++.h>
using namespace std;
int arr[10001];
int tree[3*10001];
const int m = 2000000;
bool prime[m];

void seive()
{
    prime[1]=true;
    for(int i = 2; i * i < m; i++)
    {
        for(int j = 2; i * j < m; j++)
            prime[i*j] = true;
    }
}

int main(){

    int T,i,n,q,i,j,k,bin;
    scanf("%d",&T);
    for(i=1;i<=T;i++){
     scanf("%d %d",&n,&q);
     for(j=0;j<n;j++){
          scanf("%d",&arr[i]);
     }
     for(k=1;k<=q;k++){
          scanf("%d",bin);
         if(bin==0){
          scanf("%d %d% %d",&x,&y,&v);
         }
         else{
          scanf("%d %d",&x,&y);

         }

     }
    }

}
