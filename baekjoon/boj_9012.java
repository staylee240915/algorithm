package baekjoon;

import java.util.*;

public class boj_9012 {

    public static String checkVPS(String s){

        Stack<Character>st = new Stack<>();

        for(int i=0;i<s.length();i++){
            if(s.charAt(i) == '(') st.push(s.charAt(i));
            if(s.charAt(i)==')'){
                if(st.isEmpty()) return "NO";
                else st.pop();
            }
        }
        if(!st.isEmpty()) return "NO";
        return "YES";
    };
    public static void main(String[] args) {
        
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        for(int i=0;i<n;i++){
            String s = sc.next();
            System.out.println(checkVPS(s));
        }
    }
}
