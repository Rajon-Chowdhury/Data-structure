#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define Max(a,b) ((a>=b)? a : b)
#define Min(a,b) ((a<=b)? a : b)
#define pb push_back
#define MOD 1000000007
#define MP make_pair
#define vi vector<int>
#define vll vector<ll>
#define MAX 1123456
//typedef __int128 bigll;
int a[1002][1002];
int bit[1002][1002];

int query_sum(int x,int y)
{
    int ret=0;
    if(x<0 || y<0)return 0;
    for(int i=x; i>=0; i=(i&(i+1))-1)
        for(int j=y; j>=0; j=(j&(j+1))-1)
            ret+=bit[i][j];
    return ret;
}

void update(int x,int y,int val)
{
    for (int i = x; i <=1000; i = i | (i+1))
            for (int j = y; j <=1000 ; j = j | (j+1))
                bit[i][j] += val;
}

int get_sum(int x,int y,int l,int r)
{
    return query_sum(l,r) - query_sum(x-1,r) - query_sum(l,y-1) + query_sum(x-1,y-1);
}

int main()
{

    int x,y,t,q,l,r,c;
    scanf("%d",&t);
    for(int tc=1;tc<=t;tc++)
    {
        memset(bit,0,sizeof(bit));
        memset(a,0,sizeof(a));
        printf("Case %d:\n",tc);
        scanf("%d",&q);
        while(q--)
        {
            scanf("%d",&c);
            if(c==0)
            {
                scanf("%d %d",&x,&y);
                if(a[x][y]!=1)
                {
                    a[x][y]=1;
                    update(x,y,1);
                }
            }
            else
            {
                scanf("%d %d %d %d",&x,&y,&l,&r);
                printf("%d\n",get_sum(x,y,l,r));
            }
        }
    }

    return 0;
}
