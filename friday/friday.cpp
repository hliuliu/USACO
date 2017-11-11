
/*
ID: heng_li1
TASK: friday
LANG: C++11                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int leap(int year) {
	if (year%100==0) {
		year/=100;
	}
	return year%4==0;
}

int numdays(int year,int month) {
	vector<int> shorts = {9,4,6,11};
	if (find(shorts.begin(),shorts.end(),month)!=shorts.end()) {
		return 30;
	}
	return month==2? 28+leap(year) : 31;
}

int main() {
    ofstream fout ("friday.out");
    ifstream fin ("friday.in");
    int start,end,n;
    fin >> n;
    start = 1900;
    end = start+n;
    int day = 0; // Monday
    vector<int> count13(7, 0); 
    for (int i=start; i<end;i++) {
    	for (int j =1;j<13;j++) {
    		count13[(day+12)%7]++;
    		day += numdays(i,j);
    		day%=7;
    	}
    }
    int i;
    for (i=0;i<6;i++) {
    	fout << count13[(i+5)%7] << " ";
    }
    fout << count13[(i+5)%7] << "\n";
    fout.close();
    return 0;
}
