import java.math.BigInteger;
import java.util.Scanner;

public class Main {

	private static void count_zeros( int n ){

		BigInteger result = new BigInteger("0");
		int i = 5;
		while( n / i > 0 ){
			result = result.add( BigInteger.valueOf(n/i) );
			i*=5;
		}
		
		System.out.println(result.toString());
	}

	public static void main( String[] args ){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		
		while( n-->0 ){
			count_zeros(sc.nextInt());
		}
		
		sc.close();
	}
}
