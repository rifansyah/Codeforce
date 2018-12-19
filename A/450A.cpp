#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, c;
    cin>>n>>c;
    
    map<int, int> mapnya = {};
 
	for(int i = 1; i <= n; i++) {
 		int temp;
 		cin>>temp;
 		mapnya[i] = temp;
	}
	
	int lastPerson = 0;
	int j = 0;
	int i = 1;
	
	while(j != n) {
 		if(mapnya[i] > 0) {
 			mapnya[i] -= c;
 			lastPerson = i;
 			
 			if(mapnya[i] <= 0) j++;
		}
		i++;
		if(i > n) i = 1;
	}
	
	cout<<lastPerson;
}

