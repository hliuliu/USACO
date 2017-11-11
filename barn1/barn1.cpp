
/*
ID: heng_li1
TASK: barn1
LANG: C++11                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ofstream fout ("barn1.out");
    ifstream fin ("barn1.in");
    int m,s,c;
    fin >> m >> s >> c;
    vector <int> cows(c);
    for (int &ci:cows) {
    	fin >> ci;
    }
    sort(cows.begin(),cows.end());
    int total = cows[cows.size()-1] - cows[0]+1;
    vector<int> gaps;
    for (int i =1;i<c;i++) {
    	if (cows[i]>cows[i-1]) {
    		gaps.push_back(cows[i]-cows[i-1]-1);
    		// cout << gaps.back() << endl;
    	}
    }
    sort(gaps.begin(),gaps.end());
    for(int i =1;i<m;i++) {
    	if (gaps.empty()) {
    		break;
    	}
    	total -= gaps.back();
    	gaps.pop_back();
    }
    fout << total << endl;
    return 0;
}
