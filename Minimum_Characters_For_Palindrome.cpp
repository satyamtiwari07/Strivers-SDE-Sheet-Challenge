int minCharsforPalindrome(string str) {
	// Write your code here.
	int n=str.length();
	int i=0;
	int j=n-1;
	int cnt=0;
	int temp=j;
	while(i<j){
		if(str[i]==str[j]){
			i++;
			j--;
		}
		else{
			cnt++;
			i=0;
			j=--temp;		
		}
	}
	return cnt;
	
}
