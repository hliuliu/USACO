
/*
ID: heng_li1
TASK: frac1
LANG: C++11                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>


using namespace std;
typedef pair<int,int> PII;

int gcd(int a, int b) {
	while (b) {
		int r = a%b;
		a =b;
		b=r;
	}
	return a;
}

bool fraccmp(PII &a, PII &b) {
	return a.first*b.second < b.first*a.second;
}

int main() {
    ofstream fout ("frac1.out");
    ifstream fin ("frac1.in");

    int n;
    fin >> n;

    vector<PII> frac;

    frac.push_back(make_pair(1,1));

    for (int i =0;i<n;i++) {
    	for (int j =i+1;j<=n;j++) {
    		if (gcd(j,i)==1) {
    			frac.push_back(make_pair(i,j));
    		}
    	}
    }
    sort(frac.begin(),frac.end(),fraccmp);

    for (PII &f:frac) {
    	fout << f.first << "/" << f.second << endl;
    }

    fout.close();
    return 0;
}
