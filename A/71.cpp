#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin>>n;
    string words [n];
    string wordsChanged [n];

    for(int i = 0; i < n; i++) {
        cin>>words[i];

		wordsChanged[i] = words[i];

        if(words[i].length() > 10) {
            string temp = "";
            temp += words[i][0];
            temp += to_string(words[i].length() - 2);
            temp += words[i][words[i].length() - 1];

            wordsChanged[i] = temp;
        }

        cout<<wordsChanged[i]<<endl;
    }

}
