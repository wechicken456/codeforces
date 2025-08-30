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
  int n,i,j;
  cin >> n;
  vector<ll> arr(n);
  for (i = 0; i < n; i++){
    cin >> arr[i];
  }
  sort(arr.begin(), arr.end());

  int answer = 0,count, length;;

  for (i = 0; i <n ;i++){
    length = arr[i];
    count = 0;
    for (j = i; j < n && count < length; j ++){
        if (arr[j] > length){
          length = arr[j];
        }
        count ++; 
    }
    if (j == n && count < length) break;  // reached end of list and can't form a group
    else {
      answer ++;
      i = j-1;
    }
  }
  cout<< answer << "\n";
  
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

