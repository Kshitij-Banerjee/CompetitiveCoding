import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

public class Main {
	
	private static void solve( int n ){
		
		if( n <= 2 ){
			System.out.println(n);
			return;
		}
		
		List<Long> list = new ArrayList<Long>(Collections.nCopies(n+1, 0L));
		list.set(0, 0L);
		list.set(1, 1L);
		list.set(2, 2L);
		
		for( int i = 3; i <= n ; i ++ ) {
			
			list.set(i, Math.max(i, list.get(i/2) + list.get(i/3) + list.get(i/4) ) );
		}
		System.out.println(list.get(n));
	}
	
	private static Map<Integer, Long> _dp = new HashMap<Integer, Long>();
	
	private static long solve_recursive( int n ){
		
		if( n <= 2 ){
			return n ;
		}

		if( _dp.containsKey(n) ) return _dp.get(n);
		
		_dp.put(n, Math.max(n,  solve_recursive(n/2) + solve_recursive(n/3) + solve_recursive(n/4)));
		return _dp.get(n);
	}

	public static void main( String[] args ){
		
		Scanner sc = new Scanner(System.in);
		while( sc.hasNextInt()){
			int n = sc.nextInt();
			if( n > 1e6)
				System.out.println(solve_recursive(n));
			else
				solve(n);
		}
		sc.close();
		
	}

}
