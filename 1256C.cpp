#include<bits/stdc++.h>
#include<set>
#include<stdio.h>
#include<vector>
#include<map>
#include<iterator>
#include<algorithm>
#include<math.h>
#include<cmath>
#include<fstream>

#define ll long long
#define ull unsigned long long
#define pb push_back

using namespace std;

ull power(ll x, ull y) {
    if (y == 0)
        return 1;
    else if (y % 2 == 0)
        return power(x, y / 2) * power(x, y / 2);
    else
        return x * power(x, y / 2) * power(x, y / 2);
}
 
ll my_ceil(ll a, ll b) {
	return (a/b) + ( (a%b)!=0 );
}

void solve(){

}

int main(){
	int n,m ,d;
	scanf("%d %d %d" , &n, &m, &d);
	vector<int>c(m);
	for (int i = 0 ; i < m; i++) {
		scanf("%d", &c[i]);
	}
	vector<pair<int, int>>plats(m);
	int cur = n;
	for (int i = m -1 ; i >= 0 ; i--) {
		plats[i].second = cur;
		plats[i].first = cur - c[i] + 1;
		cur -= c[i];
	}
	int cur_plat = 0;
	int pos = 0;
	vector<int>ans(n + 2);
	while (pos < n + 1) {
		if (pos + d < plats[cur_plat].first) {
			plats[cur_plat].first = pos + d;
			plats[cur_plat].second = pos + d + c[cur_plat] - 1;
			pos = plats[cur_plat].second;
			cur_plat++;
		}
		else {
			break;
		}
		if(cur_plat == m && pos + d < n + 1) {
			puts("NO");
			return 0;
		} 
	}
	for (int j = 0; j < m; j++)  {
		pair<int, int> p = plats[j];
		for (int i = p.first; i <= p.second; i++) {
			ans[i] = j + 1;
		}
	}
	puts("YES");
	for (int i = 1 ; i <= n; i++) {
		printf("%d ", ans[i]);
	}
}


