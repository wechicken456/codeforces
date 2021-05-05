#include<iostream>
#include<stdio.h>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

map<int, vector<int>>x;
map<int, vector<int>>y;

int main() {
  int n, x_coor, y_coor,answer = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; i++){
      scanf("%d %d", &x_coor, &y_coor);
      x[x_coor].push_back(y_coor);
      y[y_coor].push_back(x_coor);
  }
  for (auto &cur : x){
    sort(cur.second.begin(), cur.second.end());
  }
  for (auto &cur : y){
    sort(cur.second.begin(), cur.second.end());
  }
  for (auto &current_item : x){
    for (int current_y = 1; current_y < current_item.second.size()-1; current_y ++){
      for (int current_x = 0; current_x < y[current_item.second[current_y]].size()-1; current_x ++){
          if (y[current_item.second[current_y]][current_x] == current_item.first && current_x != 0 && current_x != y[current_y].size()-1)
          answer += 1;
      }
    }
  }
  /*for (int i = 0; i < y[1].size(); i++){
    cout << y[0][i] << " ";
  }*/ 
  cout << answer << endl;
  return 0;
}
