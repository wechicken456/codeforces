
// https://codeforces.com/contest/1339/problem/B

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

void solve(){
    int n;
    cin >> n;
    vector<ll>arr(n);
    for (int i = 0; i< n;i++){
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());


    int mid = floor(n/2);
    if (n % 2 == 0) mid--;
    cout << arr[mid] << " ";
    for (int count = 1; mid + count < n; count++){
        cout << arr[mid+count] << " ";
        if (mid - count >=0 ) cout << arr[mid-count] << " ";
    } 
    cout << "\n";
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
