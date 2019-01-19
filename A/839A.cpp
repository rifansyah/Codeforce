#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin>>n>>m;
    
    int result = 0;
    int sisa = 0;
    for(int i = 0; i < n; i++) {
    	result++;
    	int temp;
    	cin>>temp;
    	
    	sisa += temp;
    	
    	if(sisa > 8) {
    		m -= 8;
    		sisa -= 8;
		} else {
			temp = m;
			m -= sisa;
			sisa -= temp - m;
		}
		
		if(m <= 0) break;
	}
	
	if(m > 0) cout<<-1;
	else cout<<result;
}

