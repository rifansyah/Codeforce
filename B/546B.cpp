#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin>>n;
    
    int numbs [n];
    
    map<int, int> mapnya;
    vector<int> temp;
    for(int i = 0; i < n; i++) {
    	cin>>numbs[i];
    	if(mapnya[numbs[i]] == 0) {
    		mapnya[numbs[i]] = 1;
		} else {
			mapnya[numbs[i]] += 1;
			temp.push_back(numbs[i]);
		}
	}
	
	sort(temp.begin(), temp.end(), greater<int>());
	
	int result = 0;
	int i = 1;
	while(temp.size() != 0) {
    	if(mapnya[i] == 0 && i >= temp.back()) {
    		result += i - temp.back();
    		temp.pop_back();
		}
		i++;
	}
	cout<<result;
}
