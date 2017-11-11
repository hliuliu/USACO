
/*
ID: heng_li1
TASK: fact4
LANG: C++11                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream fout ("fact4.out");
    ifstream fin ("fact4.in");

    int n;
    fin >> n;
    unsigned long long fact =1;
    for (int i =1;i<=n;i++) {
    	fact*= i;
    	while (fact%10==0) {
    		fact /= 10;
    	}
    	// cout << fact << endl;
    	fact %= 100000000;
    	// cout << fact << endl;
    }

    fout << fact%10 << endl;

    fout.close();
    return 0;
}
