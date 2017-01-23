import java.io.*;
import java.util.*;
public class Solution {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        String s = scan.nextLine();
        // Write your code here.
        s = s.trim();
        if( s.isEmpty() ) {
            System.out.println("0");
            return;
        }
        
        if( s.length() > 400000 ) return;
        
        String[] tokens = s.split("[ !,?._'@]+");
        
        System.out.println(tokens.length);

        for( String x : tokens ){
            System.out.println(x);
        }
        scan.close();
    }
}
