/* Generate all the possible and valid paranthesis for a given number */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void helper(string* s, int* l, int* r, int n, vector<string>* p){
	if (int(s->length()) == (2 * n)){
		p->push_back((*s));
		return;
	}
	if ((*l) < n){
		*s += "(";
		(*l)++;
		helper(s, l, r, n, p);
		(*l)--;
		s->pop_back();
	}
	if ((*r) < (*l)){
		*s += ")";
		(*r)++;
		helper(s, l, r, n, p);
		(*r)--;
		s->pop_back();
	}
}


int generate(){
	vector<string> paran;
	string p = "";
	int i = 0, j = 0, n;
	cout << "Enter the number: ";
	cin >> n;
	helper(&p, &i, &j, n, &paran);
	for(string& m: paran)
		cout  << m << " ";
	return 0;
}
