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
	int n;
	cin >> n;
	char *a = (char*)malloc(n), *b = (char*)malloc(n);
	scanf("%s", a);
	scanf("%s", b);
	vector<int> diff;
	for (int i = 0 ; i < n; i++){
		if (a[i] != b[i]) {
			diff.push_back(i);
		}
	}
	int answer = 0 ;
	if (diff.size() == 1) answer++;
	else
	for (int i = 1 ; i < diff.size(); i++){
		if (diff[i] - diff[i-1] == 1){
			answer++;
			i++;
		}
		else {
			answer++;
		}
	}
	cout << answer << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
}


