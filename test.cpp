
#include<vector>
#include<iostream>

using namespace std;
vector<int> factors(int n) {
        vector<int> f;
        for (int x = 2; x*x <= n; x++) {
           while (n%x == 0) {
               f.push_back(x);
				n /= x; }
        }
        if (n > 1) f.push_back(n);
        return f;
}

int main(){
	vector<int>arr = factors(12);
	for (int i = 0 ; i < arr.size(); i++){
		cout << arr[i] << "\n";
	}
}

