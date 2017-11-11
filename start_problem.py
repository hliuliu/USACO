
import sys,os

prob_name = sys.argv[1]


def write_content(fname,content):
	if os.path.exists(fname):
		print >>sys.stderr, '{} already exists.'.format(fname)
	else:
		with open(fname,'w') as fh:
			fh.write(content)

if not os.path.isdir(prob_name):
	os.mkdir(prob_name)

os.chdir(prob_name)

write_content(prob_name+'.in', '')

write_content(prob_name+'.c',
'''
/*
ID: {pid}
LANG: {lang}
TASK: {pname}
*/
#include <stdio.h>
main () {{
    FILE *fin  = fopen ("{pname}.in", "r");
    FILE *fout = fopen ("{pname}.out", "w");
    exit (0);
}}
'''.format(pid ='heng_li1', lang='C', pname=prob_name)
	)


write_content(prob_name+'.cpp',
'''
/*
ID: {pid}
TASK: {pname}
LANG: {lang}                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {{
    ofstream fout ("{pname}.out");
    ifstream fin ("{pname}.in");
    return 0;
}}
'''.format(pid ='heng_li1', lang='C++11', pname=prob_name)
	)



write_content(prob_name+'.py',
'''
"""
ID: {pid}
LANG: {lang}
TASK: {pname}
"""
fin = open ('{pname}.in', 'r')
fout = open ('{pname}.out', 'w')

fout.close()
'''.format(pid ='heng_li1', lang='PYTHON2', pname=prob_name)
	)



write_content(prob_name+'.java',
'''
/*
ID: {pid}
LANG: {lang}
TASK: {pname}
*/
import java.io.*;
import java.util.*;

public class {pname} {{
  public static void main (String [] args) throws IOException {{
    // Use BufferedReader rather than RandomAccessFile; it's much faster
    BufferedReader f = new BufferedReader(new FileReader("{pname}.in"));
                                                  // input file name goes above
    PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("{pname}.out")));
    // Use StringTokenizer vs. readLine/split -- lots faster
    StringTokenizer st = new StringTokenizer(f.readLine());
						  // Get line, break into tokens
    
    out.close();                                  // close the output file
  }}
}}
'''.format(pid ='heng_li1', lang='JAVA', pname=prob_name)
	)



