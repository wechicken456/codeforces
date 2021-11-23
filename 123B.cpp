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
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll a, b, x1, y1, x2, y2;
	cin >> a >> b >> x1 >> y1 >> x2 >> y2;
	
	ll diff_1 = (x1 - y1) / (2*b);
	if (x1 - y1 < 0) diff_1--;
	ll diff_2 = (x2 - y2) / (2*b);
	if (x2 - y2 < 0) diff_2--;
	ll sum_1 =  (x1 + y1) / (2*a);
	if (x1 + y1 < 0) sum_1--;
	ll sum_2 = (x2 + y2) / (2*a);
	if (x2 + y2 < 0) sum_2--;
	
	cout << max(abs(diff_1-diff_2), abs(sum_1-sum_2));
}


