
/*
ID: heng_li1
LANG: JAVA
TASK: holstein
*/
import java.io.*;
import java.util.*;

public class holstein {

  static int best = 0;
  static List<Integer> bestList = null;

  public static boolean dfs(List<Integer> choice, int[]vitamins, int[][]feeds, int start) {
    boolean flag = true;

    for (int v:vitamins) {
      if (v>0) {
        flag = false;
        break;
      }
    }

    if (flag) {
      if (best>choice.size()) {
        best = choice.size();
        bestList.clear();
        for (int c:choice) {
          bestList.add(c);
        }
      }
      return true;
    }

    for (int i = start;i<feeds.length;i++) {
      choice.add(i);
      for (int j =0;j<vitamins.length;j++) {
        vitamins[j] -= feeds[i][j];
      }
      if (dfs(choice, vitamins, feeds, i+1)) {
        flag = true;
      }
      for (int j =0;j<vitamins.length;j++) {
         vitamins[j] += feeds[i][j];
      }
      choice.remove(choice.size()-1);
    }

    return flag;
  }

  public static void main (String [] args) throws IOException {
    
    Scanner sc = new Scanner(new File("holstein.in"));
                                                  // input file name goes above
    PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("holstein.out")));

    int v = sc.nextInt();

    int [] vitamins = new int [v];

    for (int i =0;i<v;i++) {
      vitamins[i] = sc.nextInt();
    }

    int g = sc.nextInt();

    int[][]feeds = new int[g][v];

    for (int [] row:feeds) {
      for(int i=0;i<v;i++) {
        row[i] = sc.nextInt();
      }
    }

    List<Integer> choice  = new ArrayList<>(g);

    best = g+1;
    bestList = new ArrayList<>(g);

    dfs(choice, vitamins,feeds, 0);

    StringBuilder stream = new StringBuilder();

    for (int i: bestList) {
      stream.append(i+1+" ");
    }
    
    if (stream.length()>0) {
      stream.deleteCharAt(stream.length()-1);
    }

    out.print(best+" ");

    out.println(stream.toString());
    
    out.close();                                  // close the output file
  }
}
