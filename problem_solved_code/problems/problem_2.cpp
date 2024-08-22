#include <iostream>
#include <vector>

using namespace std;

void reversal(int left, int right, vector<int>& v){
	while (left < right){
		swap(v[left], v[right]);
		left++;
		right--;
	}
}

void rotateSortedArray(){
	cout << "Enter the number: ";
	int k;
	cin >> k;
	vector<int> v = {1, 2, 3, 4, 5, 6, 7};
	reversal(0, (int)v.size() - k - 1, v);
	reversal((int)v.size() - k, (int)v.size() - 1, v);
	reversal(0, int(v.size()) - 1, v);
	for(int &i: v){
		cout << i << " ";
	}
}
