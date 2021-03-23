
#include <iostream>
using namespace std;

int main() {
	int T, i, N;
	cin >> T;
	string s;
	
	while(T--) {
		int CountUpper=0, CountLower=0, CountNum=0, CountSpecial=0;
		s.clear();
		cin >> s;
		for(i=0; i<s.length(); i++) {
			if(s[i]>=48 && s[i]<=57)
				CountNum++;
			else if(s[i]>=65 && s[i]<=90)
				CountUpper++;
			else if(s[i]>=97 && s[i]<=122)
				CountLower++;
			else
				CountSpecial++;
		}
		cout << CountUpper << endl;
		cout << CountLower << endl;
		cout << CountNum << endl;
		cout << CountSpecial << endl;
	}
	return 0;
}