import java.util.Arrays;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Collectors;

public class Main {

	public static void main( String[] args ){
		Scanner sc = new Scanner(System.in);
		final double PI = 3.1415;
		
		int n = sc.nextInt();
		
		while( n-->0 ){
			List<Integer> val = Arrays.asList(sc.next().split("e")).stream().
					map(Integer::parseInt).
					collect(Collectors.toList());
			System.out.println((int)PI * val.get(0) * val.get(0) * val.get(1) * val.get(2));
		}
		sc.close();
	}
}
