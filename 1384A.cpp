
// https://codeforces.com/problemset/problem/1384/A

#include<iostream>
#include<stdio.h>
#include<vector>
#include<map>
#include<iterator>
#include<algorithm>
#include<math.h>
#include<cmath>

typedef  long long ll;

using namespace std;

string s=  "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbba";

void solve(){
    int n,max;
    cin >> n;
    vector<int>length(n);
    string cur = s;
    for (int i = 0 ; i < n; i++){
        cin >> length[i];
    }
    cout << s << "\n";
    char temp;
    for (int i = 0; i < n; i++){
        temp = cur[length[i]];
        temp += (temp+1>'z') ? -1 : 1;
        cur = cur.substr(0, length[i]) + temp + cur.substr(length[i]+1, 51);
        cout << cur << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}
