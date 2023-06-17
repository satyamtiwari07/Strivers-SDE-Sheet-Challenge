int search(int* arr, int n, int key) {
    // Write your code here.
    int lo=0;
    int hi=n-1;

    while(lo<=hi){
        int mid = (lo+hi)/2;
        if(arr[mid]==key) return mid;

        if(arr[mid]<=arr[hi]){
            if(key>arr[mid] and key<=arr[hi]) lo=mid+1;
            else hi=mid-1;
        }
        else if(arr[lo]<=arr[mid]){
             if(key>=arr[lo] and key<arr[mid]) hi=mid-1;
             else lo=mid+1;
        }
    }
    return -1;
}
