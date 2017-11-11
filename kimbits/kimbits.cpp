
/*
ID: heng_li1
TASK: kimbits
LANG: C++11                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int A[32][32];

int main() {
    ofstream fout ("kimbits.out");
    ifstream fin ("kimbits.in");

    for (int i =0;i<32;i++) {
    	for (int j=0;j<32;j++) {
    		A[i][j] = j? (i<=j? (1<<i) : A[i-1][j-1]+A[i-1][j]) : 1;
    	}
    }

    int n,l;
    unsigned int index;
    fin >> n >> l >> index;

    string bits = "";
    // cout << index << endl;
    while (n--) {
    	// cout << n << endl;
    	if (A[n][l]<index) {
    		bits.push_back('1');
			index -= A[n][l];
    		l--;
    		
    	}else {
    		bits.push_back('0');
    	}
    }

    fout << bits << endl;

    fout.close();
    return 0;
}
