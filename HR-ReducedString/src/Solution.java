import java.util.Scanner;

public class Solution {

	public static String reduce(String s) {
		StringBuilder output = new StringBuilder();

		int i = 0;
		while (i < s.length()) {
			int j = i + 1;

			while (j < s.length() && (s.charAt(j) == s.charAt(i))) {
				j++;
			}

			if ((j - i) % 2 != 0)
				output.append(s.charAt(i));

			i = j;
		}
		return output.toString();
	}

    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
    	
    	Scanner sc = new Scanner(System.in);
    	String s = sc.next();
    	
    	String output = "";
    	while( output.length() != s.length() ){
    		output = s;
    		s = reduce(s);
    	}
    	
    	if( output.toString().isEmpty() ) 
    		System.out.println("Empty String");
    	else
			System.out.println(output.toString());
    	sc.close();
    }
}