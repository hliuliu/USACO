
/*
ID: heng_li1
LANG: JAVA
TASK: combo
*/
import java.io.*;
import java.util.*;

public class combo {

  public static int rem(int x, int n) {
    int ans = x%n;
    if (ans<0) {ans+=n;}
    return ans;
  }

  public static void main (String [] args) throws IOException {
    // Use BufferedReader rather than RandomAccessFile; it's much faster
    BufferedReader f = new BufferedReader(new FileReader("combo.in"));
                                                  // input file name goes above
    PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("combo.out")));
    // Use StringTokenizer vs. readLine/split -- lots faster
    StringTokenizer st = new StringTokenizer(f.readLine());
						  // Get line, break into tokens
    
    int n = Integer.parseInt(st.nextToken());

    boolean [][][] expose = new boolean[n][n][n];

    int count =0;

    for (int i=0;i<2;i++) {
      int x,y,z;
      st = new StringTokenizer(f.readLine());
      x = Integer.parseInt(st.nextToken());
      y = Integer.parseInt(st.nextToken());
      z = Integer.parseInt(st.nextToken());
      x--;y--;z--;
      for (int r : new int[]{x-2,x-1,x,x+1,x+2}) {
        for (int s : new int[]{y-2,y-1,y,y+1,y+2}) {
          for (int t : new int[]{z-2,z-1,z,z+1,z+2}) {
            r = rem(r,n);
            s = rem(s,n);
            t = rem(t,n);
            if (!expose[r][s][t]) {
              count ++;
              expose[r][s][t] = true;
            }
          }
        }
      }
    }

    out.println(count);

    out.close();                                  // close the output file
  }
}
