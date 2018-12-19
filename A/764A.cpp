#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, z;
    cin>>n>>m>>z;
    
    int result = 0;
    map<int, int> mapnya = {};
    
    for(int i = n; i <= z; i+=n) {
    	mapnya[i] = 1;
	}
	
	for(int i = m; i <= z; i+=m) {
    	if(mapnya[i] == 1) {
    		result++;
		}
	}
	
	cout<<result;
}
