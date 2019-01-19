#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, t;
    cin>>n>>t;
    
    char queue [n];
    
    for(int i = 0; i < n; i++) {
    	char temp;
    	cin>>temp;
    	queue[i] = temp;
	}
	
	for(int i = 0; i < t; i++) {
    	for(int j = 0; j < n; j++) {
    		if(queue[j] == 'B' && j+1 < n && queue[j+1] == 'G') {
    			queue[j] = 'G';
    			queue[j+1] = 'B';
    			j++;
			}
		}
	}
	
	for(int i = 0; i < n; i++) {
		cout<<queue[i];
	}
}	
