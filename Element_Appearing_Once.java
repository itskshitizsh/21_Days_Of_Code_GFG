/*package whatever //do not write package name here */

import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
	public static void main (String[] args) {
		//code
		Scanner scan = new Scanner(System.in);
		int testCases = scan.nextInt();
		while(testCases--!=0){
		    int N = scan.nextInt();
		    int A[] = new int[N];
		    int unique = 0;
		    for(int i=0;i<N;i++){
		        A[i] = scan.nextInt();
		        unique ^= A[i];
		    }
		    System.out.println(unique);
		}
	}
}
