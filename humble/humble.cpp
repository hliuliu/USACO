
/*
ID: heng_li1
TASK: humble
LANG: C++11                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
typedef unsigned int UI;

void fetch(vector<UI> &elts, vector<UI> &start, vector<UI> &res) {
	UI minval = (1<<31);
	int last = res.back();
	for (int i =0;i<elts.size();i++) {
		for (int j = start[i];j<res.size();j++) {
			UI ans = res[j]*elts[i];
			if (ans<= last) {
				continue;
			}
			if (minval> ans) {
				minval = ans;
			}
			start[i] = j;
			break;
		}
	}
	res.push_back(minval);
}

int main() {
    ofstream fout ("humble.out");
    ifstream fin ("humble.in");

    int n,k;
    fin >> k >> n;

    vector<UI> elts(k), start(k,0), res;

    for (UI &p: elts) {
    	fin >> p;
    }


    res.push_back(1);

    while (res.size()<=n) {
    	fetch(elts,start,res);
    }


    fout << res[n] << endl;

    fout.close();
    return 0;
}
