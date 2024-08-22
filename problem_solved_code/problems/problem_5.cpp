#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

int removeUnbalancedParanthesis(){
	string paranthesis = "(((ab)";
	string open = "(";
	string close = ")";
	vector<string> s;
	map<int, string>::iterator iter;
	map<int, string> v;
	for(int i = 0; i < int(paranthesis.length()); i++){
		iter = v.end();
		if (open.find(paranthesis[i]) != string::npos){
			v[i] = paranthesis[i];
		}
		if (close.find(paranthesis[i]) != string::npos){
			if (v.empty()){
				v[-1] = to_string(i);
				continue;
			}
			if (i != int(paranthesis.length()) - 1)
				v.erase(--iter);
			else{
				iter = v.begin();
				if (iter->first == -1)
					v.erase(++iter);
				else
					v.erase(iter);
			}
		}
	}
	iter = v.begin();
	int temp = -1;
	for(int j = 0; j < int(paranthesis.length()); j++){
		if (iter->first == -1){
			temp = stoi(iter->second);
			iter++;
		}
		if (temp != -1 and j == temp){
			continue;
		}
		if (iter != v.end() and j == iter->first){
			iter++;
			continue;
		}
		cout << paranthesis[j];
	}
	return 0;
}
