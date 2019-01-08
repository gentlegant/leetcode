#include <iostream> 
#include<algorithm>
#include <vector>
#include<numeric>
using namespace std; 
  

int numberOfPainters(vector<int> arr, int n, int maxLen) 
{ 
    int total = 0, numPainters = 1; 
  
    for (int i = 0; i < n; i++) { 
        total += arr[i]; 
  
        if (total > maxLen) { 
            total = arr[i]; 
            numPainters++; 
        } 
    } 
  
    return numPainters; 
} 
  
int partition(vector<int> arr, int n, int k) 
{ 
    int lo = *max_element(arr.begin(),arr.end());
    
    int hi = accumulate(arr.begin(),arr.end(),0);
  
    while (lo < hi) { 
        int mid = lo + (hi - lo) / 2; 
        int requiredPainters = numberOfPainters(arr, n, mid); 

        if (requiredPainters <= k) 
            hi = mid; 
  
        else
            lo = mid + 1; 
    } 
  
    return lo; 
} 
  
int main() 
{ 
	int turn;
	cin>>turn;
	while(turn--){
		int k, n;
        cin>>n;
		
		
		vector<int> arr;
		for(int i = 0 ; i < n ; i++){
			int tmp;
            cin>>tmp;
            arr.push_back(tmp);
        }
        cin>>k;
		cout << partition(arr, n, k) << endl; 
	}
    return 0; 
} 