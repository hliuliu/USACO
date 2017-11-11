
/*
ID: heng_li1
LANG: JAVA
TASK: palsquare
*/
import java.io.*;
import java.util.*;

class Node {
  int digit,length;
  Node next;
}

public class palsquare {

  public static Node parse(int n,int b) {
    if(n==0) {
      return null;
    }
    Node node = new Node();
    node.digit = n%b;
    node.next = parse(n/b, b);
    node.length = node.next==null? 1: node.next.length+1;
    return node;
  }

  public static boolean isPal(Node head) {
    if (head== null) {
      return true;
    }
    int n = head.length;
    if (n==1) {
      return true;
    }
    Node curr = head;
    int [] digits = new int[n>>1];
    for (int i =0;i<(n>>1);i++) {
      digits[i] = curr.digit;
      curr=curr.next;
    }
    if ((n&1)==1) {
      curr=curr.next;
    }
    int di = digits.length-1;
    while (curr!=null) {
      if (digits[di--]!=curr.digit) {
        return false;
      }
      curr = curr.next;
    }
    return true;
  }

  public static void printInBase(Node head, PrintWriter out) {
    if (head!=null) {
      printInBase(head.next,out);
      out.print(head.digit<10? (char)(head.digit+(int)('0')): (char)(head.digit-10+(int)('A')));
    }
  }

  public static void process(int n, int b, PrintWriter out) {
    Node lsb = parse(n*n,b);
    Node nlsb = parse(n,b);
    if (isPal(lsb)) {
      printInBase(nlsb, out);
      out.print(" ");
      printInBase(lsb,out);
      out.println();
    }
  }

  public static void main (String [] args) throws IOException {
    // Use BufferedReader rather than RandomAccessFile; it's much faster
    BufferedReader f = new BufferedReader(new FileReader("palsquare.in"));
                                                  // input file name goes above
    PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("palsquare.out")));
    // Use StringTokenizer vs. readLine/split -- lots faster
    StringTokenizer st = new StringTokenizer(f.readLine());
						  // Get line, break into tokens


    int b = Integer.parseInt(st.nextToken());

    // System.out.println(b);

    for (int n=1;n<=300;n++) {
      process(n,b,out);
    }

    out.close();                                  // close the output file
  }
}
