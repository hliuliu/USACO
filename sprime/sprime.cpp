
/*
ID: heng_li1
TASK: sprime
LANG: C++11                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;


bool isprime(int val) {
	if(val<2) {return false;}
	for(int i =2;i*i<=val;i++) {
		if (val%i==0) {
			return false;
		}
	}
	return true;
}

vector<int> gensp(int n) {
	vector<int> result;
	if (n==0) {
		result.push_back(0);
		return result;
	}
	for (int sp:gensp(n-1)) {
		sp*=10;
		for (int i =1;i<10;i++) {
			if (isprime(sp+i)) {
				result.push_back(sp+i);
			}
		}
	}
	return result;
}

int main() {
    ofstream fout ("sprime.out");
    ifstream fin ("sprime.in");

    int n;
    fin >> n;

    vector<int> sps = gensp(n);
    //cout << sps.size() << endl;
    copy(sps.begin(),sps.end(),ostream_iterator<int>(fout,"\n"));

    // for (int sp:sps) {
    // 	fout << sp << endl;
    // 	break;
    // }

    fout.close();
    return 0;
}
