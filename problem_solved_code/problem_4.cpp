#include <iostream>
#include <string>

using namespace std;

int expand(){
	string s = "b3c6d15"; // b3c6d15 a1b10
	string output = "";
	string nums = "0123456789";
	int index = 0, count = 1;
	while (index < int(s.length())){
		string temp = "";
		while (nums.find(s[count]) != string::npos){
			 temp += s[count++];
		}
		int n = stoi(temp);
		while(n){
			output += s[index];
			n--;
		}
		index = count++;
	}
	cout << output;
	return 0;
}
