
//https://codeforces.com/problemset/problem/1492/B

#include<iostream>
#include<stdio.h>
#include<vector>
#include<map>
#include<iterator>
#include<algorithm>
#include<math.h>

typedef long long ll;

const ll maxN= 1e5+1;
using namespace std;

/*
void solve(int n){
  vector<int>arr = vector<int>(n+1);
  //vector<int>res;
  map<int, int>m;
  int original_n = n, max_index = 0, i;
  for ( i = 1 ; i <= n; i++){
      scanf("%d", &arr[i]);
      m[arr[i]] = i;
  }

  while (n >= 1){
    for (max_index = original_n; m[max_index] > n; max_index--){}
    for (i = m[max_index]; i <= n; i++ ){
      cout << arr[i] << " ";
    }
    n = m[max_index]-1;
    
  } 
  cout << "\n";
  

}
*/
void solve(int n){
  vector<int>arr = vector<int>(n+1);
  //vector<int>res;
  map<int, int>m;
  int original_n = n, max_index = 0, i;
  for ( i = 1 ; i <= n; i++){
      scanf("%d", &arr[i]);
      m[arr[i]] = i;
  }

  auto it = m.rbegin();
  int new_n;

  while (n >= 1){
    for ( it = m.rbegin(); it->second > n && it != m.rend(); it++){}
    new_n = it->second;			
    for (i = new_n; i <= n; i++ ){
      cout << arr[i] << " ";
      m.erase(arr[i]);			// erase the pair with key arr[i]
    }
    n = new_n-1;				// new boundary 
    //cout << "max : " << max_index << "  n: " << n << "\n";
    
  } 
  cout << "\n";
  

}

int main() {
  int t;
  ll n;
  scanf("%d", &t);
  while (t--){
    cin >> n; 
    solve(n);
  }
  
}
