#include<bits/stdc++.h>
using namespace std;

#define ll           long long
#define pii          pair<ll,ll>
#define bug(a)       cerr << #a << " : " << a << endl;
#define FastRead     ios_base::sync_with_stdio(false);cin.tie(NULL);

const int MAX = 1e5+10;

struct Info
{
    int val[3], prop;
};
Info tree[4*MAX];

void build(int pos,int l,int r)
{
    if(l == r)
    {
        tree[pos].val[0] = 1;
        tree[pos].val[1] = tree[pos].val[2] = tree[pos].prop = 0;
        return;
    }

    int mid = (l+r)/2, lt = pos*2, rt = pos*2+1;

    build(lt,l,mid);
    build(rt,mid+1,r);

    for(int i=0; i<3; i++)
        tree[pos].val[i] = tree[lt].val[i]+tree[rt].val[i];
    tree[pos].prop = 0;
}
void propagate(int pos,int l,int r)
{
    if(!tree[pos].prop)
        return;

    int mid = (l+r)/2, lt = pos*2, rt = pos*2+1;

    if(tree[pos].prop == 1)
    {
        tree[pos].val[2] = tree[pos].val[1];
        tree[pos].val[1] = tree[pos].val[0];
        tree[pos].val[0] = (r-l+1) - (tree[pos].val[1]+tree[pos].val[2]);
    }
    else
    {
        tree[pos].val[1] = tree[pos].val[2];
        tree[pos].val[2] = tree[pos].val[0];
        tree[pos].val[0] = (r-l+1) - (tree[pos].val[1]+tree[pos].val[2]);
    }

    if(l != r)
    {
        tree[lt].prop += tree[pos].prop;
        tree[rt].prop += tree[pos].prop;

        tree[lt].prop %= 3;
        tree[rt].prop %= 3;
    }
    tree[pos].prop = 0;
}
void update(int pos,int l,int r,int L,int R)
{
    propagate(pos,l,r);

    if(l > R || r < L)
        return;
    else if(l >= L && r <= R)
    {
        tree[pos].prop++;
        propagate(pos,l,r);
        return;
    }

    int mid = (l+r)/2, lt = pos*2, rt = pos*2+1;

    update(lt,l,mid,L,R);
    update(rt,mid+1,r,L,R);

    for(int i=0; i<3; i++)
        tree[pos].val[i] = tree[lt].val[i]+tree[rt].val[i];
}
int query(int pos,int l,int r,int L,int R)
{
    propagate(pos,l,r);

    if(l > R || r < L)
        return 0;
    else if(l >= L && r <= R)
        return tree[pos].val[0];

    int mid = (l+r)/2, lt = pos*2, rt = pos*2+1;

    int x = query(lt,l,mid,L,R);
    int y = query(rt,mid+1,r,L,R);

    for(int i=0; i<3; i++)
        tree[pos].val[i] = tree[lt].val[i]+tree[rt].val[i];

    return x+y;
}
int main()
{
    FastRead

    //freopen("output.txt","w",stdout);

    int t,cas=1;

    cin >> t;

    while(t--)
    {
        int n,q,type,u,v;

        cin >> n >> q;

        build(1,1,n);

        cout << "Case " << cas++ << ":\n";
        while(q--)
        {
            cin >> type >> u >> v;

            if(type)
                cout << query(1,1,n,u+1,v+1) << endl;
            else
                update(1,1,n,u+1,v+1);
        }
    }
}
