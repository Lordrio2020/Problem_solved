#include <iostream>
#include <vector>
#include <limits>

using namespace std;


void countingSort(vector<int>* v){
	int m = numeric_limits<int>::min();
	for(int i = 0; i < int(v->size()); i++){
		if((*v)[i] > m){
			m = (*v)[i];
		}
	}
	vector<int> temp(m+1, 0), output(int(v->size()), 0);

	for(int m = 0; m < int(output.size()); m++){
		temp[(*v)[m]] += 1;
	}

	for(int j = 1; j < int(temp.size()); j++){
		temp[j] += temp[j - 1];
	}

	for(int l = 0; l < int(output.size()); l++){
		output[temp[(*v)[l]] - 1] = (*v)[l];
		temp[(*v)[l]]--;
	}

	*v = output;
}


void selectionSort(vector<int> *v){
	for(int i = 0; i < int(v->size()); i++){
		int mini = i;
		for(int j = i + 1; j < int(v->size()); j++){
			if ((*v)[j] < (*v)[mini]){
				mini = j;
			}
		}
		if (mini != i)
			swap((*v)[i], (*v)[mini]);
	}
}

void insertionSort(vector<int>* v){
	for(int i = 1; i < int(v->size()); i++){
		int key = (*v)[i];
		int j = i - 1;
		while (j >= 0 and (*v)[j] > key){
			(*v)[j + 1] = (*v)[j];
			j--;
		}
		(*v)[j + 1] = key;
	}
}

void merge(vector<int>* v, int& l, int& m, int& r){
	int n1 = m - l + 1;
	int n2 = r - m;

	int L[n1], R[n2];

	for(int i = 0; i < n1; i++){
		L[i] = (*v)[l + i];
	}
	for(int j = 0; j < n2; j++){
		R[j] = (*v)[m + 1 + j];
	}

	int i = 0, j = 0, k = l;

	while(i < n1 && j < n2){
		if (L[i] < R[j]){
			(*v)[k] = L[i];
			i++;
		}else{
			(*v)[k] = R[j];
			j++;
		}
		k++;
	}

	while(i < n1){
		(*v)[k] = L[i];
		i++;k++;
	}

	while(j < n2){
		(*v)[k] = R[j];
		k++;j++;
	}
}

void mergeSort(vector<int>* v, int l, int r){
	if(l < r){
		int m = l + (r - l) / 2;
		mergeSort(v, l, m);
		mergeSort(v, m+1, r);

		merge(v, l, m, r);
	}
}

int partition(vector<int> * v, int l, int r){
	int pivot = (*v)[r];
	int storeIndex = l - 1;
	for(int i = l; i < r; i++){
		if ((*v)[i] < pivot){
			int temp = (*v)[++storeIndex];
			(*v)[storeIndex] = (*v)[i];
			(*v)[i] = temp;
		}
	}
	int temp = (*v)[++storeIndex];
	(*v)[storeIndex] = (*v)[r];
	(*v)[r] = temp;
	return ++storeIndex;
}

void quickSort(vector<int> *v, int l, int r){
	if (l < r){
		int pivotIndex = partition(v, l, r);
		quickSort(v, l, pivotIndex - 1);
		quickSort(v, pivotIndex + 1, r);
	}
}

int check(){
	vector<int> arr = {3, 2, 4, 5, 1};
	countingSort(&arr);
	for(int& i: arr){
		cout << i << " ";
	}
	return 0;
}
