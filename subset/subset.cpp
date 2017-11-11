
/*
ID: heng_li1
TASK: subset
LANG: C++11                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
typedef long long LL;

int main() {
    ofstream fout ("subset.out");
    ifstream fin ("subset.in");

    int n;
    fin >> n;

    vector<LL> cansum((((n+1)*n)>>1)+1,0);

    if (cansum.size()&1) {

	    cansum[0] = 1;

	    for (int i =1;i<=n;i++) {
	    	for (int j=cansum.size()-1;j>=i;j--) {
	    		cansum[j] += cansum[j-i];
	    	}
	    }

	    fout << (cansum[cansum.size()>>1]>>1) << endl;
	} else {
		fout << 0 << endl;
	}

    fout.close();
    return 0;
}
