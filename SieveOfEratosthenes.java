/*
Sieve of Eratosthenes
https://practice.geeksforgeeks.org/problems/sieve-of-eratosthenes/0
*/
import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
    static ArrayList<Integer> primes;
    private static void SieveOfEratosthenes(int n){
        int a[] = new int[n+1];
        primes = new ArrayList<Integer>();
        for(int i=0;i<=n;i++){
            a[i]=1;
        }
        a[0]=0;
        a[1]=0;
        for(int i=2;(i*i<=n);i++){
            if(a[i]==1)
            for(int j=i*i;j<=n;j+=i){
                a[j]=0;
            }
        }
        // Print Prime Numbers
        for(int p=2;p<=n;p++){
            if(a[p]==1){
                System.out.print(p+" ");
            }
        }
    }
    
	public static void main (String[] args) {
		//code
		Scanner scan = new Scanner(System.in);
		int t = scan.nextInt();
		while(t--!=0){
		    int n = scan.nextInt();
		    if(n>=1){
		        SieveOfEratosthenes(n);
		    }
		    System.out.println();
		}
	}
}
