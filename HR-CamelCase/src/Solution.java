import java.util.Scanner;

public class Solution {


    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String s = in.next();
        
        long count = s.chars().filter(x -> x >= 'A' && x <= 'Z').count();

        System.out.println(count + 1);
        in.close();
    }
}