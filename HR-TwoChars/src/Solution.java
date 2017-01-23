import java.util.List;
import java.util.Scanner;
import java.util.stream.Collectors;

public class Solution {
	
	public static Boolean isAlternating(String s){
		for( int i =1; i < s.length(); i ++ ){
			if( s.charAt(i) == s.charAt(i-1)) return false;
		}
		return true;
	}

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int len = in.nextInt();
		String s = in.next();

		List<Character> uniqs = s.chars().distinct().mapToObj(x -> (char) x).collect(Collectors.toList());
		
		int count = Integer.MIN_VALUE;
		for( int i = 0; i < uniqs.size(); i ++ ){
			for( int j = i+1; j < uniqs.size(); j ++ ) {
				
				Character p = uniqs.get(i);
				Character q = uniqs.get(j);
				String n = s.chars().
						filter(x -> (x == p || (x == q))).
						mapToObj(x->(char)x).
						map(Object::toString).
						collect(Collectors.joining());

				if( isAlternating(n))
					count = Math.max(count, n.length());
			}
		}
		
		
		System.out.println(Math.max(0, count));
	}
}
