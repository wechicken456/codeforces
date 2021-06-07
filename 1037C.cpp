#include<iostream>
#include<stdio.h>
#include<vector>
#include<map>
#include<iterator>
#include<algorithm>
#include<math.h>
#include<cmath>

typedef unsigned long long ll;

using namespace std;

void solve(){
	ll n;
	cin >> n;
	char *a = (char*)malloc(n), *b = (char*)malloc(n);
	scanf("%s", a);
	scanf("%s", b);
	vector<ll> diff;
	for (int i = 0 ; i < n; i++){
		if (a[i] != b[i]) {
			diff.push_back(i);
		}
	}
	ll answer = 0 ;
	if (diff.size() == 1) answer++;
	else {
		ll diff_size = diff.size();
		for (ll i = 0 ; i < diff_size; i++){
			if (i == diff_size-1 ) {
				answer++;
				break;
			}
			if (diff[i+1] - diff[i] == 1 && b[i+1] != b[i]){
				answer++;
				i++;
			}
			else {
				answer++;
			}
		}
	}
	printf("%lld\n", &answer);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
}


