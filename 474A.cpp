#include<iostream>
#include<stdio.h>
#include<vector>
typedef long long ll;
using namespace std;

int main(){
	char cc;
	int shift,i,count;
	cc = getchar();
	getchar();				// trim '\n'
	shift = (cc == 'L') ? 1 : -1; 
	string letters = "qwertyuiopasdfghjkl;zxcvbnm,./", inp, result;
	getline(cin, inp);
	for (i = 0; i < inp.length(); i++){
		for (count = 0; count < letters.length(); count++){
			if (inp[i] == letters[count]){
				result += letters[count + shift];
				break;
			}
		}
	}
	cout << result << endl;
	return 0;
}
