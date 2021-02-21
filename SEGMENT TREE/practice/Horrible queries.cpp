#include<cstdio>
#include<limits.h>
#include<iostream>
using namespace std;
#define ll long long
#define mx 100001
int A[mx]={};
int tree[mx * 3];
int lazy[3*mx];
void build(int node, int start, int end)
{
    if(start == end)
    {
        tree[node] = A[start];
    }
    else
    {
        int mid = (start + end) / 2;
        build(2*node, start, mid);
        build(2*node+1, mid+1, end);
        tree[node] = tree[2*node] + tree[2*node+1];
    }
}
 int query(int node, int b, int e, int i, int j)
  {
    if (i > e || j < b)
        return 0; //বাইরে চলে গিয়েছে
    if (b >= i && e <= j)
        return tree[node]; //রিলেভেন্ট সেগমেন্ট
    int Left = node * 2; //আরো ভাঙতে হবে
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    int p1 = query(Left, b, mid, i, j);
    int p2 = query(Right, mid + 1, e, i, j);
    return p1 + p2; //বাম এবং ডান পাশের যোগফল
}
void update(int node, int b, int e, int i, int newvalue)
{
    if (i > e || i < b)
        return; //বাইরে চলে গিয়েছে
    if (b >= i && e <= i) { //রিলেভেন্ট সেগমেন্ট
        tree[node] = newvalue;
        return;
    }
    int Left = node * 2; //আরো ভাঙতে হবে
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    update(Left, b, mid, i, newvalue);
    update(Right, mid + 1, e, i, newvalue);
    tree[node] = tree[Left] + tree[Right];
}
/*void updateRange(int node, int start, int endd, int l, int r, int val)
{
    if(lazy[node] != 0)
    {
        // This node needs to be updated
        tree[node] += (endd - start + 1) * lazy[node];    // Update it
        if(start != endd)
        {
            lazy[node*2] += lazy[node];                  // Mark child as lazy
            lazy[node*2+1] += lazy[node];                // Mark child as lazy
        }
        lazy[node] = 0;                                  // Reset it
    }
    if(start > endd or start > r or endd < l)              // Current segment is not within range [l, r]
        return;
    if(start >= l and endd <= r)
    {
        // Segment is fully within range
        tree[node] += (endd - start + 1) * val;
        if(start != end)
        {
            // Not leaf node
            lazy[node*2] += val;
            lazy[node*2+1] += val;
        }
        return;
    }
    int mid = (start + end) / 2;
    updateRange(node*2, start, mid, l, r, val);        // Updating left child
    updateRange(node*2 + 1, mid + 1, end, l, r, val);   // Updating right child
    tree[node] = tree[node*2] + tree[node*2+1];        // Updating root with max value
}

int queryRange(int node, int start, int end, int l, int r)
{
    if(start > end or start > r or end < l)
        return 0;         // Out of range
    if(lazy[node] != 0)
    {
        // This node needs to be updated
        tree[node] += (end - start + 1) * lazy[node];            // Update it
        if(start != end)
        {
            lazy[node*2] += lazy[node];         // Mark child as lazy
            lazy[node*2+1] += lazy[node];    // Mark child as lazy
        }
        lazy[node] = 0;                 // Reset it
    }
    if(start >= l and end <= r)             // Current segment is totally within range [l, r]
        return tree[node];
    int mid = (start + end) / 2;
    int p1 = queryRange(node*2, start, mid, l, r);         // Query left child
    int p2 = queryRange(node*2 + 1, mid + 1, end, l, r); // Query right child
    return (p1 + p2);
}*/

int main()
{
    int T,N,C,ch,p,q,v;
    scanf("%d",&T);
    for(int i=1;i<=T;i++){
     scanf("%d %d",&N,&C);
     for(int a=1;a<=C;a++){
          cin>>ch;
          if(ch==0){
            cin>>p>>q>>v;
            updateRange(1,1,8,p,q,v);
          }
          else{
                    cin>>p>>q;
               cout<<queryRange(1,1,8,p,q)<<endl;
          }
     }
    }

}


