#include <iostream>
using namespace std;
/* 
merge sort sorting algorithm
time: O(nlog(n)) in all cases
space: O(n)
*/

void merge(int *Arr, int start, int mid, int end) {
	
	int temp[end - start + 1];  // create a temp array

	int i = start; // starting index for left subarray
	int j = mid+1; // starting index for right subarray
	int k = 0;		 // starting index for temporary arr 

	// traverse both arrays and in each iteration add smaller of both elements in temp 
	while(i <= mid && j <= end) {
		if(Arr[i] <= Arr[j]) {
			temp[k] = Arr[i++];
		}
		else {
			temp[k] = Arr[j++];
		}
		k++;
	}

	// add elements left (remaining) in the first interval 
	while(i <= mid) {
		temp[k++] = Arr[i++];
	}

	// add elements left in the second interval 
	while(j <= end) {
		temp[k++] = Arr[j++];
	}

	// copy temp to original interval
	for(i = start; i <= end; i++) {
		Arr[i] = temp[i - start];
	}
}

// Arr is an array of integer type
// start and end are the starting and ending index of current interval of Arr
void mergeSort(int *Arr, int start, int end) {

	if(start < end) {
		int mid = (start + end) / 2;
		mergeSort(Arr, start, mid);
		mergeSort(Arr, mid+1, end);
		merge(Arr, start, mid, end);
	}
}



int main() {
	int n;
	cout << "Enter size of an array: ";
	cin >> n;
	int myarr[n];
	cout << "Enter " << n << " random elements :";
	for(int i=0; i<n; i++)
	{
		cin >> myarr[i];
	}

	cout << "====Before Merge Sort==== :" << endl;
	for(int i=0; i<n; i++)
	{
		cout << myarr[i] << " ";
	}

	mergeSort(myarr,0,n);

	cout << "\n====After Merge Sort ==== :" << endl;
	for(int i=0; i<n; i++)
	{
		cout << myarr[i] << " ";
	}
	return 0;
}
