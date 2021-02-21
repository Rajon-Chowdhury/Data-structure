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
      build(low, mid, 2*pos);
      build(mid+1, high, 2*pos+1);
	tree[pos] = (tree[2*pos]+tree[2*pos+1]);

	return tree[pos];


}
int main()
{
     for (int i = 1; i <=4; i++) {
			scanf("%d",&arr[i]);
		}

		build(1, 4, 1);
		for(int j=1;j<=7;j++){
               cout<<tree[j]<<" ";
		}
}
