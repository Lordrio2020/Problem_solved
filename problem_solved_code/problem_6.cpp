#include <iostream>
#include <string>

using namespace std;

int create_pattern(){
	cout << "Enter the string: ";
	string s;
	cin >> s;
	int l = 0, r = s.length() - 1;
	while (l < int(s.length()) and r >= 0){
		for(int i = 0; i < int(s.length()); i++){
			if (i == l and l != r){
				cout << s[l] << " ";
			}
			else if(i == r and l != r){
				cout << s[r] << " ";
			}
			else if ((i == l or i == r) and l == r){
				cout << s[l] << " ";
			}
			else{
				cout << "  ";
			}
		}
		cout << endl;
		l++;r--;
	}
	return 0;
}
