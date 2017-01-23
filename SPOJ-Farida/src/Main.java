import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;
import java.util.stream.IntStream;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int t = sc.nextInt();

		IntStream.rangeClosed(1, t).forEach( T -> {
			int n = sc.nextInt();
			if (n == 0) {
				System.out.println("Case " + T + ": 0");
			} else {
				List<Long> input = new ArrayList<>();
				while (n-- > 0)
					input.add(sc.nextLong());
				List<Long> dp = new ArrayList<>(Collections.nCopies(input.size(), 0L));
				dp.set(0, input.get(0));
				if( dp.size() > 1 ) dp.set(1, Math.max(input.get(0), input.get(1)));
				
				IntStream.range(2,input.size()).forEach(x -> {
					dp.set(x, Math.max(dp.get(x-1), input.get(x) + dp.get(x-2)));
				});
				
				System.out.println("Case " + T + ": " + dp.get(dp.size()-1));
			}

		});
		sc.close();
	}
}
