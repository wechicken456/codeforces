#include<bits/stdc++.h>
#include<set>
#include<stdio.h>
#include<vector>
#include<map>
#include<iterator>
#include<algorithm>
#include<math.h>
#include<cmath>
#include<fstream>

#define ll long long
#define ull unsigned long long
#define pb push_back

using namespace std;

int main() { 
	int n;
	string left;
	string right;
	cin >> n >> left >> right;
	map<char, vector<int>>occ_left;
	map<char, vector<int>>occ_right;
	vector<int>quest_left;
	vector<int>quest_right;
	for (int i = 0; i < n; i++){
		if (left[i] == '?') {
			quest_left.pb(i);
		}
		else {
			occ_left[left[i]].pb(i);
		}
		if (right[i] == '?') {
			quest_right.pb(i);
		}
		else {
			occ_right[right[i]].pb(i);
		}
	}
	vector<int>taken(n, false);	// if we've taken the ith character in right
	vector<pair<int ,int>>ans;
	for (auto &cur : occ_left) {
		char c = cur.first;
		int j = 0;
		for (int i = 0; i < cur.second.size(); i++) {
			if (j < occ_right[c].size()) {
				ans.pb({cur.second[i], occ_right[c][j]});
				taken[occ_right[c][j]] = true;
				j++;
			}
			else if (quest_right.size() > 0) {
				ans.pb({cur.second[i], quest_right[0]});
				quest_right.erase(quest_right.begin());
			}
			
		}
	}
	for (int i = 0 ; i < n; i++) {
		if (!taken[i] && right[i] != '?') {
			if (quest_left.size() > 0) {
				ans.pb({quest_left[0], i});
				quest_left.erase(quest_left.begin());
			}
		} 
	}
	for (int i = 0 ; i < min(quest_left.size(), quest_right.size()); i++) {
		ans.pb({quest_left[i], quest_right[i]});
	}
	printf("%d\n", ans.size());
	for (pair<int ,int > p : ans) {
		printf("%d %d\n", p.first + 1, p.second + 1);
	}
}

