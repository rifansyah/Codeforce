#include <bits/stdc++.h>

using namespace std;

string createString(int i, int j) {
	
	string temp2 = "";
	temp2 += to_string(i) + "-" + to_string(j);
	
	return temp2;
}

void move(vector<vector<char>> &grid, int i, int j, vector<string> &visited, map<int, vector<char>> &regionMap, int regionId) {
	string indexString = createString(i, j);
	visited.push_back(indexString);
	
	if(grid[i][j] != '.' && grid[i][j] != '#' && find(regionMap[regionId].begin(), regionMap[regionId].end(), grid[i][j]) == regionMap[regionId].end()) {
		regionMap[regionId].push_back(grid[i][j]);
	}
	
	// move left
	indexString = createString(i, j-1);
	if(j-1 >= 0 && find(visited.begin(), visited.end(), indexString) == visited.end() && grid[i][j-1] != '#'){
		move(grid, i, j-1, visited, regionMap, regionId);
	}
	//move right
	indexString = createString(i, j+1);
	if(j+1 < grid[i].size() && find(visited.begin(), visited.end(), indexString) == visited.end() && grid[i][j+1] != '#'){
		move(grid, i, j+1, visited, regionMap, regionId);
	}
	//move up
	indexString = createString(i-1, j);
	if(i-1 >= 0 && find(visited.begin(), visited.end(), indexString) == visited.end() && grid[i-1][j] != '#'){
		move(grid, i-1, j, visited, regionMap, regionId);
	}
	//move down
	indexString = createString(i+1, j);
	if(i+1 < grid.size() && find(visited.begin(), visited.end(), indexString) == visited.end() && grid[i+1][j] != '#'){
		move(grid, i+1, j, visited, regionMap, regionId);
	}
}


int main() {
	int t;
	cin>>t;
	
	vector<map<string, int>> finalResult;
	
	for(int i = 0; i < t; i++) {
		int n,m;
		cin>>n>>m;
		
		vector<string> visited;
		map<int, vector<char>> regionMap;
		
		vector<vector<char>> grid;
		
		for(int j = 0; j < n; j++) {
			vector<char> temp;
			for(int k = 0; k < m; k++) {
				char tempChar;
				cin>>tempChar;
				temp.push_back(tempChar);
			}
			grid.push_back(temp);
		}
		
		int regionId = 0;
		for(int j = 0; j < n; j++) {
			for(int k = 0; k < m; k++) {
				string indexString = createString(j, k);
				if(find(visited.begin(), visited.end(), indexString) == visited.end() && grid[j][k] != '#' && grid[j][k] != '.'){
					regionId++;
					vector<char> temp;
					regionMap[regionId] = temp;
					move(grid, j, k, visited, regionMap, regionId);	
				}
			}
		}
		
		map<string, int> result;
		
		for (auto const& x : regionMap) {
    		if (regionMap[x.first].size() > 1) {
    			if(result.find("contested") == result.end()){
    				result["contested"] = 0;
				}
				result["contested"] += 1;
				continue;
			}
			for(auto j : regionMap[x.first]) {
				if (result.find(string(1, j)) == result.end()) {
					result[string(1, j)] = 0;
				}
				result[string(1, j)] += 1;
			}
		}
		finalResult.push_back(result);
	}
	
	for(int i = 0; i < finalResult.size(); i++) {
		printf("Case %d:\n", i+1);
		for (auto const& x : finalResult[i]) {
    		if(x.first != "contested"){
				cout<<x.first<<" "<<finalResult[i][x.first]<<endl;
			}
		}
		if (finalResult[i].find("contested") == finalResult[i].end()) {
			cout<<"contested"<<" "<<0<<endl;
		} else {
			cout<<"contested"<<" "<<finalResult[i]["contested"]<<endl;
		}
	}
}
