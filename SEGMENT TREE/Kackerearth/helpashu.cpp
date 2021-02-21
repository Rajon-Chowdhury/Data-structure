#include<bits/stdc++.h>
#define REP(i,n) for (int i = 1; i <= n; i++)
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
#define lli long long int
#define INF 1000000000

using namespace std;
const int maxN = 100001;
pair<int,int> tree[4*maxN];
int val[maxN];

void build(int si , int ss , int se)
{
	if(ss == se)
	{
		if(val[ss] % 2 == 1)
		tree[si] = {1 , 0};
		else
		tree[si] = {0 , 1};

		return;
	}

	int mid = (ss + se) / 2;
	build(2*si , ss , mid);
	build(2*si+1, mid+1 , se);

	tree[si].first = tree[2*si].ff + tree[2*si+1].ff;
	tree[si].second = tree[2*si].ss + tree[2*si+1].ss;
}

void update(int si , int ss , int se , int qi , int newVal)
{
	if(ss == se)
	{
		if(val[ss] % 2)
		tree[si] = {0 , 1};
		else
		tree[si] = {1 , 0};

		val[ss] = newVal;
		return;
	}

	int mid = (ss + se) / 2;
	if(qi <= mid) update(2*si , ss , mid , qi , newVal);
	else		  update(2*si+1 , mid+1 , se , qi , newVal);

	tree[si].first = tree[2*si].ff + tree[2*si+1].ff;
	tree[si].second = tree[2*si].ss + tree[2*si+1].ss;
}

int getEven(int si , int ss , int se , int qs , int qe)
{
	if(ss > qe || se < qs) return 0;

	if(ss >= qs && se <= qe)
	return tree[si].ss;

	int mid = (ss + se) / 2;

	int l = getEven(2*si , ss , mid , qs , qe);
	int r = getEven(2*si+1 , mid+1 , se , qs , qe);

	return l+r;
}

int getOdd(int si , int ss , int se , int qs , int qe)
{
	if(ss > qe || se < qs) return 0;

	if(ss >= qs && se <= qe)
	return tree[si].ff;

	int mid = (ss + se) / 2;

	int l = getOdd(2*si , ss , mid , qs , qe);
	int r = getOdd(2*si+1 , mid+1 , se , qs , qe);

	return l+r;
}

int main()
{
	int n , q , code , l , r;
	cin>>n;
	REP(i , n) cin>>val[i];

	build(1 , 1 , n);

	cin>>q;
	while(q--)
	{
		cin>>code;
		if(code == 0)
		{
			cin>>l>>r;
			if((val[l] % 2) == (r % 2)) continue;
			else update(1 , 1 , n , l , r);
		}
		else
		if(code == 1)
		{
			cin>>l>>r;
			cout<<getEven(1 , 1 , n , l , r)<<endl;
		}
		else
		{
			cin>>l>>r;
			cout<<getOdd(1 , 1 , n , l , r)<<endl;
		}
	}
}
