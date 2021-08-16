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
	ll n, m;
	cin >> n >> m;
	ll pos = n *  (ll)(n - 1) / 2 ;
	ll neg =  ((ll) (n - 1)/2)* ( (ll) (n - 1)/ 2 + 1 );
	if ( n % 2 == 0 ) neg += n / 2;
	ll ans = 0;
	for (int i = 0 ; i < m ; i++) {
		ll x , d;
		cin >> x >> d;
		ans += n * x;
		
		if (d < 0) ans += neg * d;
		else ans += pos * d;
		
	} 
	cout << setprecision(15) << (double) ans / n << "\n";
}


