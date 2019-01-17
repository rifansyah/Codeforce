#include <bits/stdc++.h>

using namespace std;

vector<int> maxDays(map<int, vector<int>>& days, int k) {
	vector<int> result;
	
	for(map<int,vector<int>>::iterator it = days.begin(); it != days.end(); ++it) {
	  for(int i = 0; i < it->second.size(); i++) {
	  	if(k - it->first < 0){
	  		return result;
		}
		k -= it->first;
		result.push_back(it->second[i]); 
	  }
	}
}

int main() {
    int n, k;
    cin>>n>>k;

    map<int, vector<int>> days = {};
    
    for(int i = 1; i <= n; i++) {
    	int day;
    	cin>>day;
    	days[day].push_back(i);
	}
	
	vector<int> result;
	
	result = maxDays(days, k);
	
	cout<<result.size()<<endl;
	for(int i = 0; i < result.size(); i++) {
		cout<<result[i]<<" ";
	}
}
