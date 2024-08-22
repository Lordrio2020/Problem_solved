/*
 Google problem to convert a numeric value into words
 */

#include <iostream>
#include <map>
#include <string>
#include <tuple>
#include <limits>

using namespace std;

map<int, tuple<string, string, string>> v;

string create_text(int rem){
	string output = "";
	if ((rem / 100) != 0 && (rem % 100) != 0){
		if ((rem % 100) / 10 != 0 && (rem % 100) % 10 != 0){
			if ((rem % 100) / 10 == 1){
				output = get<1>(v[(rem % 100) % 10]) + output;
			}else{
				output = get<2>(v[(rem % 100) / 10]) + " "+ get<0>(v[(rem % 100) % 10]) + " " + output;
			}
		}else{
			if ((rem % 100) / 10 == 1){
				output = " ten " + output;
			}else{
				if ((rem % 100) / 10 != 0)
					output = get<2>(v[(rem % 100) / 10]) + output;
				else
					output = get<0>(v[(rem % 100) % 10]) + output;
			}
		}
		output = get<0>(v[rem / 100]) + " hundred " + output;
	}else{
		if (rem / 100 != 0){
			output = get<0>(v[rem / 100]) + " hundred " + output;
		}else{
			if ((rem % 100) / 10 != 0 && (rem % 100) % 10 != 0){
				if ((rem % 100) / 10 == 1){
					output = get<1>(v[(rem % 100) % 10]) + output;
				}else{
					output = get<2>(v[(rem % 100) / 10]) + " "+ get<0>(v[(rem % 100) % 10]) + output;
				}
			}else{
				if ((rem % 100) / 10 == 1){
					output = " ten " + output;
				}else{
					if ((rem % 100) / 10 != 0)
						output = get<2>(v[(rem % 100) / 10]) + output;
					else
						output = get<0>(v[(rem % 100) % 10]) + output;
				}
			}
		}
	}

	return output;
}

string flow(int count, int rem){
	string res = "";
	switch(count){
		case 1:
			res = create_text(rem) + "thousand " + res;
			break;
		case 2:
			res = create_text(rem) + "million "+ res;
			break;
		case 3:
			res = create_text(rem) + " billion " + res;
			break;
		default:
			res = create_text(rem) + res;
	}
	return res;
}

void convert(){
	cout << "Enter the number: ";
	int number;
	cin >> number;

	string res = "";
	int count = 0;

	v.insert({1, {"one", "eleven", "ten"}});
	v.insert({2, {"two", "twelve", "twenty"}});
	v.insert({3, {"three", "thirteen", "thirty"}});
	v.insert({4, {"four", "fourteen", "fourty"}});
	v.insert({5, {"five", "fifteen", "fifty"}});
	v.insert({6, {"six", "sixteen", "sixty"}});
	v.insert({7, {"seven", "seventeen", "seventy"}});
	v.insert({8, {"eight", "eighteen", "eighty"}});
	v.insert({9, {"nine", "nineteen", "ninety"}});

	do{
		int rem = number % 1000;
		number /= 1000;
		res = flow(count, rem) + res;
		count ++;
	}while ((number / 1000) != 0 && (number % 1000) != 0);

	if (number != 0)
		res = flow(count, number) + res;

	cout << res;
}
