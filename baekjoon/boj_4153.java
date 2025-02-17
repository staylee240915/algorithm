package baekjoon;
import java.util.*;

public class boj_4153{
    public static void main(String[] args) {
        //직각삼각형 여부를 판단.

        Scanner sc = new Scanner(System.in);

        while(true){

            String s = sc.nextLine();
            if("0 0 0".equals(s)) break;

            String[] arr = s.split(" ");
            
            int[] numbers = new int[3];
            
            int a = Integer.parseInt(arr[0]);
            int b = Integer.parseInt(arr[1]);
            int c = Integer.parseInt(arr[2]);

            numbers[0] = a*a;
            numbers[1] = b*b;
            numbers[2] = c*c;

            Arrays.sort(numbers);

            if(numbers[2] == numbers[1]+numbers[0]){
                System.out.println("right");
            }else{
                System.out.println("wrong");
            }
        }
        return;

    }
}