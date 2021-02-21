#include <bits/stdc++.h>
#define ma 100010
using namespace std;

int arr[ma];
int tree[4*ma];

int build(int low, int high, int pos)
{

     int mid;
	if(low == high) {
		tree[pos] = arr[low];
		return arr[low];
	}

      mid=(low+high)/2;

	tree[pos] = min((build(low, mid, 2*pos)),(build(mid+1, high, 2*pos+1)));

	return tree[pos];
}

int query(int low, int high, int qlow, int qhigh, int pos)
{
	int mid;
	if(qlow <= low && qhigh >= high) {
		return tree[pos];
	}

	if(qlow > high || qhigh < low) {
		return INT_MAX;
	}
      mid=(low+high)/2;

	return min(query(low, mid,qlow,qhigh, 2*pos),query(mid+1, high,qlow,qhigh, 2*pos+1));
}


int main()
{
	int t,test,n,qnum,qlow,qhigh;

      scanf("%d",&t);

	for (test=1;test<=t;test++) {
		scanf("%d %d",&n,&qnum);
		for (int i = 1; i <= n; i++) {
			scanf("%d",&arr[i]);
		}

		build(1, n, 1);

		printf("Scenario #%d:\n",test);

		for(int i = 1; i <= qnum; i++) {
			scanf("%d %d",&qlow,&qhigh);

			printf("%d\n", query(1, n, qlow, qhigh, 1));
		}


	}


}

