import java.io.IOException;
import java.util.Scanner;

public class Main {
	private static int reverse( int num ){
		int x = num % 10;
		num /= 10;
		while( num > 0 ){
			x *= 10;
			x += num%10;
			num /= 10;
		}
		return x;
	}
			
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		
		
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		
		while( N --> 0  ){
			
			int num1 = sc.nextInt();
			int num2 = sc.nextInt();
			
			num1 = reverse(num1);
			num2 = reverse(num2);
			
			int num3 = num1 + num2;
			System.out.println(reverse(num3));
		}
		
		sc.close();
		
	}

}
