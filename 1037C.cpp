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
	cout << a << "\n" << b;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
}


