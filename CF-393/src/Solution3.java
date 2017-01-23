import java.util.List;
import java.util.Scanner;
import java.util.stream.Collectors;
import java.util.stream.Stream;

public class Solution3 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
	
		Scanner sc = new Scanner(System.in);
		
		long n = sc.nextLong();

		long time = 0L;
		long charged = 0L;
		
		List<Long> dp = Stream.generate(() -> 0L).
				limit(n).collect(Collectors.toList());

		List<Long> timings = Stream.generate(() -> 0L).
				limit(n).collect(Collectors.toList());

		for( int i = 0; i < n; i ++ ){
			Long T = sc.nextLong();
			timings.set(i, T);

			long optimal = 20;
			if( i > 0 ) optimal += dp.get(i-1);
			
			int x = i-1;
			while( x >= 0 && (T-timings.get(x) < 90) ) x--;

			if( x >= 0 )
				optimal = Math.min( optimal, dp.get(x) + 50 );
			else 
				optimal = Math.min( optimal, 50);

			while( x >= 0 && (T-timings.get(x) < 1440 ) ) x--;

			if( x >= 0 )
				optimal = Math.min( optimal, dp.get(x) + 120 );
			else 
				optimal = Math.min( optimal, 120 );

			dp.set(i, optimal);

			System.out.println(optimal-charged);

			charged = optimal;
		}

		sc.close();
	}

}
