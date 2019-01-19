#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin>>n;
    int count [5] = {0};
    for(int i = 0; i < n; i++) {
    	int temp;
    	cin>>temp;
    	if(temp == 4) count[4]++;
    	else if(temp == 3) count[3]++;
    	else if(temp == 2) count[2]++;
    	else count[1]++;
	}
	
	count[1]-=count[3];
    if(count[1] < 0) count[1] = 0;
    	
   	int result = 0;
    	
    result += count[4];
    result += count[3];
    	
    result += (count[2] / 2);
    	
    if(count[2] % 2 == 1) {
    	count[1] -= 2;
    	result++;
	}
		
	if(count[1] < 0) count[1] = 0;
		
	result += (count[1] / 4);
    	
    if(count[1] % 4 != 0) result++;
	
	cout<<result;
}	
