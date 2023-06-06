int singleNonDuplicate(vector<int>& arr)
{
	// Write your code here
	//if the array is not sorted we can do xor operation
	//tc->o(n) and sc->o(1)

	//but here array is sorted so we can use binary search
	//tc->o(logn) and sc->o(1)

	//1 1 2 2 3 3 4 4 7 
	int lo=0;
	int hi=arr.size()-1;

	while(lo<=hi){
		int mid=(lo+hi)/2;

		//means mid is odd check with odd-1 and if even check with even +1 
		if(arr[mid]==arr[mid^1])lo=mid+1;
		else hi=mid-1;
	}
	// cout<<lo<<" "<<hi;
	return arr[lo];
}
