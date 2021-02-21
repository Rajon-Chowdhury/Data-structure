#include<bits/stdc++.h>
using namespace std;


int BIT[1000], a[1000], n;
void update(int x, int delta)
{
      for(; x <= n; x += x&-x)
        BIT[x] += delta;
}
int query(int x)
{
     int sum = 0;
     for(; x > 0; x -= x&-x)
        sum += BIT[x];
     return sum;
}

int main()
{
     scanf("%d", &n);
     int i;
     for(i = 1; i <= n; i++)
     {
           scanf("%d", &a[i]);
           update(i, a[i]);
     }
    printf("sum of first 5 elements is %d\n", query(4));
    int ans= query(5) - query(3);
     cout<<ans<<endl;
     return 0;
}
