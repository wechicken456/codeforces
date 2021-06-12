#include<numeric>
#include<vector>
#include<iostream>
#include<cmath>
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
	//vector<int>arr = factors(12);
	/*for (int i = 0 ; i < arr.size(); i++){
		cout << arr[i] << "\n";
	}*/
	//cout << (long long)7/4 << "\n";
	int arr[] = {437 ,519 ,865 ,808 ,909 ,391 ,194 ,291 ,237 ,395 ,323 ,365 ,511 ,497 ,781 ,737 ,871 ,559 ,731 ,697 ,779 ,841}
	for (int i = 0 ; i < arr.size(); i++){
		cout << gcd(961, arr[i]) << " ";
	}
}

