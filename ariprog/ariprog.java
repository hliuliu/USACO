
/*
ID: heng_li1
LANG: JAVA
TASK: ariprog
*/
import java.io.*;
import java.util.*;

public class ariprog {
  public static void main (String [] args) throws IOException {
    // Use BufferedReader rather than RandomAccessFile; it's much faster
    BufferedReader f = new BufferedReader(new FileReader("ariprog.in"));
                                                  // input file name goes above
    PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("ariprog.out")));
    // Use StringTokenizer vs. readLine/split -- lots faster
    StringTokenizer st = new StringTokenizer(f.readLine());
						  // Get line, break into tokens
    
    out.close();                                  // close the output file
  }
}
