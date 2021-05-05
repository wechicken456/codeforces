#include<stdio.h>
#include<iostream>
#include<vector>
#include<map>
using namespace std;



void solve(){
	int n, dragon_strength, bonus_strength;
	static int s;
	cin >> s >> n;
	#include<stdio.h>
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

void solve(){
	int n, dragon_strength, bonus_strength;
  int s;
	cin >> s >> n;
	map<int,int> rounds;
	for (int i = 0 ; i < n; i ++){
		scanf("%d %d\n", &dragon_strength, &bonus_strength);
		/*if (rounds.find(dragon_strength) == rounds.end()){
			rounds.insert(pair<int,int>(dragon_strength, bonus_strength));	
		}
    else{ 
      rounds[dragon_strength] += bonus_strength;
    }
    auto it = rounds.insert(pair<int,int>(dragon_strength, 0));
    it.second += bonus_strength;
    */
    rounds[dragon_strength] += bonus_strength;
	}
  for (auto &i : rounds){
    if (i.first >= s){
      cout << "NO" << endl;
      return;
    }
    s += i.second;
  }
  cout << "YES" << endl;
	/*for (auto &i:rounds){
    cout << i.first << " " << i.second << endl;
  }
	sort(rounds.begin(), rounds.end());
  */
}

int main(){
	
	solve();
	return 0;
}

	for (int i = 0 ; i < n; i ++){
		scanf("%d %d\n", &dragon_strength, &bonus_strength);
		/*if (rounds.find(dragon_strength) == rounds.end()){
			rounds[dragon_strength] = 0;	
		}*/
		get<0>rounds += bonus_strength;
	}
	
	sort(rounds.begin(), rounds.end());
}

int main(){
	
	solve();
	return 0;
}
