int removeDuplicates(vector<int> &arr, int n) {
	// Write your code here.
	int lo=0;
	int hi=1;

	while(hi<n){
		while(hi<n and arr[lo]==arr[hi]) hi++;
		lo++;
		arr[lo]=arr[hi];
	}
	return lo;
}
