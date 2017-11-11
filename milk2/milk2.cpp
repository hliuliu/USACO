
/*
ID: heng_li1
TASK: milk2
LANG: C++11                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

typedef pair<int,int> PII;

int main() {
    ofstream fout ("milk2.out");
    ifstream fin ("milk2.in");

    int n;
    fin >> n;
    vector<PII> farmers(n, PII());

    for (PII &p: farmers) {
    	fin >> p.first >> p.second;
    }

    sort(farmers.begin(),farmers.end());

    int idle=0 , contig = 0,maxcontig = 0;
    int last = farmers[0].first;

    for (PII p: farmers) {
    	cerr << p.first << " " << p.second << endl;
    	if (p.second<=last) {
    		continue;
    	}
    	if (p.first> last) {
    		idle = max(idle, p.first-last);
    		maxcontig = max(contig, maxcontig);
    		contig = p.second-p.first;
    	}else {
    		contig += p.second - last;
    	}
    	last = p.second;
    }

    maxcontig = max(maxcontig,contig);

    fout << maxcontig << " " << idle << endl;

    fout.close();


    return 0;
}
