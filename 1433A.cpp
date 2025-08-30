#include<stdio.h>
#include<iostream>
#include<string>
typedef long long ull;
using namespace std;
void solve(){
	string num;
	int sum=0;
	getline(cin, num);
	sum += (1+2+3+4)*(num[0] - '0' - 1);
	for (int i = 1; i <= num.length(); i++){
		sum += i;
	}
	cout << sum << endl;
}

int main(){
	ull t;
	scanf("%lld\n", &t);
	while (t--){
		solve();
	}
	return 0;
}
