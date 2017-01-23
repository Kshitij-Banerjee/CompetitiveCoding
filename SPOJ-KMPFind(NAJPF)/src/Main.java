import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Main {

	private static void solve( String s, String p ){
		
		List<Integer> lsp  = new ArrayList<Integer>(Collections.nCopies(p.length(), 0));
		
		populate_lsp(lsp, p);
		
	}

	private static void populate_lsp(List<Integer> lsp, String p) {
		
		// abab
	}

	public static void main( String[] args ){
		
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		
		while( n --> 0 ) {
			String s = sc.next();
			String p = sc.next();
			solve(s,p);
		}
	}
}
