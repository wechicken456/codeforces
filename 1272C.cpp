
  // http://codeforces.com/problemset/problem/1272/C

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
    string s;
    int n, k;
    cin >> n >> k;
    cin >> s;
    ll answer = 0;
    vector<char>avail(k);
    for (int i = 0 ; i < k ; i++) {
        cin >> avail[i];
    }

    vector<int>invalids;
    invalids.push_back(-1);

    for (int i = 0 ; i < n ; i++){
        bool check = false;
        for (int j = 0 ; j < k; j++){
            if (s[i] == avail[j]) {
                check = true;
                break;
            }
        }
        if (!check) invalids.push_back(i);
    }
    invalids.push_back(n);
    for (int i = 1 ; i < invalids.size() ; i++){
        //cout << invalids[i] << " ";
        ll temp = invalids[i] - invalids[i-1];
        answer += (temp*(temp-1))/2;
    }
    cout << answer << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    //cin >> t;
    //while (t--){
        solve();
    //}
    return 0;
}
