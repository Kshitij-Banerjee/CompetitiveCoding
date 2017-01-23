import java.util.Scanner;

public class Solution1 {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);

		int m = sc.nextInt();
		int d = sc.nextInt();

		int days = 0;

		if (m == 2) {
			days = 28;
		}
		else if (m < 8) {

			if (m % 2 == 0) {
				days = 30;
			} else {
				days = 31;
			}
		}
		else{
			
			if (m % 2 != 0) {
				days = 30;
			} else {
				days = 31;
			}
		}

		days += d - 1;

		System.out.println((int) (Math.ceil(days / 7.0)));
		sc.close();
	}
}
