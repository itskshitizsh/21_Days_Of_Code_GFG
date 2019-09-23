/*package whatever //do not write package name here */

import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
	public static void main (String[] args) {
		//code
		Scanner scan = new Scanner(System.in);
		int t = scan.nextInt();
		while(t--!=0){
		    Stack<Character> s = new Stack<>();
		    String str = scan.next();
		    int flag = 0;
		    for(char c : str.toCharArray()){
		        if(c=='{' || c=='(' || c=='['){
		            s.push(c);
		        }else {
		            if(s.isEmpty()){
		                System.out.println("not balanced");
		                flag = 1;
		                break;
		            }else{
		                if((s.peek()=='{' && c == '}') || (s.peek()=='[' && c==']')||(s.peek()=='(' && c == ')')){
		                    s.pop();
		                }else{
		                    System.out.println("not balanced");
		                    flag =1;
		                    break;
		                }
		            }
		        }
		    }
		    if(flag==0)
		    if(s.isEmpty()){
		            System.out.println("balanced");
		    }else{
		        System.out.println("not balanced");
		    }
		}
		
	}
}
