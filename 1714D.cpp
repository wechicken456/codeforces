#include<iostream>
#include<stdio.h>
#include<vector>
#include<map>
#include<iterator>
#include<algorithm>
#include<math.h>
#include<cmath>

using namespace std;
#define ull unsigned long long
#define pb push_back

void solve() {
    string t;
    cin >> t;
    int l = t.length();
    int n;
    cin >> n;
    vector<vector<pair<int, string>>>s(26);
    for (int i = 0 ; i < n ; i++) {
        string tmp;
        cin >> tmp;
        s[tmp[0] - 'a'].pb({i, tmp});
    }
    vector<pair<int, int>>ans;
    
    for (int i = 0; i < l; i++) {
        if (i == 0) {
            int max_len = -1, max_idx = -1;
            for (auto &p : s[ t[i] - 'a']) {
                int len = p.second.length(), cnt = 0;
                for (int j = 0 ; j < len && i + j < l; j++) {
                    if (t[i + j] != p.second[j]) {
                        break;
                    }
                    cnt++;
                }
                if (cnt == len) {
                    if (max_len < len) {
                        max_len = len;
                        max_idx = p.first;
                    }
                }
            }
            if (max_idx > -1) {
                ans.pb({max_idx, 0});
                i = max_len - 1;
            } 
            else {
                cout << "-1\n";
                return;
            }
        } 
        else {
            int threshold = i - 1;
            int max_threshold = threshold, max_idx = -1, start_idx =-1;
            while(i > ans.back().second) {
                for (auto &p : s[ t[i] - 'a']) {
                    int len = p.second.length(), cnt = 0;
                    if (i + len - 1 <= max_threshold) {
                        continue;
                    }
                    
                    for (int j = 0 ; j < len && i + j < l; j++) {
                        if (t[i + j] != p.second[j]) {
                            break;
                        }
                        cnt++;
                    }
                    if (cnt == len) {
                        if (max_threshold < i + len - 1) {
                            max_threshold = i + len - 1;
                            max_idx = p.first;
                            start_idx = i;
                        }
                    }
                } 
                i--;
            }
            if (max_idx > -1) {
                ans.pb({max_idx, start_idx});
                i = max_threshold;
            } 
            else {
                cout << "-1\n";
                return;
            }
        }
    }
    cout << ans.size() << "\n";
    for (auto &p : ans) {
        cout << p.first + 1 << " " << p.second + 1 << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    for (int i = 0 ; i < T; i++)
    solve();
}
