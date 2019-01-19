#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, c;
    cin>>n>>c;
    
    int numbs [n];
    
    int mines = 0;
    
    for(int i = 0; i < n; i++) {
    	cin>>numbs[i];
    	if(numbs[i] <= 0 || (i >= c - 1 && numbs[i] < numbs[c - 1])) mines++;
	}

	cout<<n-mines;	
}
