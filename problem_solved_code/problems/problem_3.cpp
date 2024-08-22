#include <iostream>
#include <string>
#include <vector>

using namespace std;

void operations(vector<int>& v1, string ops){
	int a = v1[int(v1.size()) - 1];
	v1.pop_back();
	int b = v1[int(v1.size()) - 1];
	v1.pop_back();

	if (ops == "+"){
		v1.push_back((a + b));
	}else if (ops == "-"){
		v1.push_back((b - a));
	}else if (ops == "/"){
		v1.push_back((b / a));
	}else if (ops == "*"){
		v1.push_back((a * b));
	}else if (ops == "%"){
		v1.push_back((b % a));
	}
}

int reversePolish(){
	vector<string> v = {"2", "1", "+", "3", "*"};
	vector<int> v1;
	string s = "+-/%*";
	for(int i = 0; i < int(v.size()); i++){
		auto pos = s.find(v[i]);
		if (pos != string::npos){
			operations(v1, v[i]);
		}else{
			v1.push_back(stoi(v[i]));
		}
	}
	cout << v1[0];
	return 0;
}
