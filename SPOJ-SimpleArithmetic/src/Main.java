import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Collectors;

public class Main {
	private static void simple_solve(String l, String r, Character op) {
		List<String> output = new ArrayList<>();
		output.add(l);
		if (r.length() + 1 < l.length()) {
			output.add(Collections.nCopies(l.length() - r.length() - 1, " ").stream().collect(Collectors.joining()) + op
					+ r);
		} else
			output.add(op + r);

		BigInteger ll = new BigInteger(l);
		BigInteger rr = new BigInteger(r);

		if (op.equals('+')) {
			output.add(ll.add(rr).toString());
		} else if (op.equals('-')) {
			output.add(ll.subtract(rr).toString());
		} else {
			BigInteger rr_last = BigInteger.valueOf(r.charAt(r.length() - 1) - '0');
			output.add(ll.multiply(rr_last).toString());
		}
		int dash_length = Math.max(r.length()+1, output.get(2).length());
		String dash = Collections.nCopies(dash_length, "-").stream().collect(Collectors.joining());
		output.add(2, dash);

		if (op.equals('*') && (r.length() > 1)) {
			int units = 1;
			for (int i = r.length() - 2; i >= 0; i--) {

				String next = ll.multiply(BigInteger.valueOf(r.charAt(i) - '0')).toString()
						+ Collections.nCopies(units, " ").stream().collect(Collectors.joining());
				output.add(next);
				units++;
			}
			output.add(ll.multiply(rr).toString());
			String last_last = output.get(output.size() - 1);
			String second_last = output.get(output.size() - 2);
			dash_length = Math.max(last_last.length(), second_last.length());
			dash = Collections.nCopies(dash_length, "-").stream().collect(Collectors.joining());
			output.add(output.size() - 1, dash);
		}

		final int length = output.stream().map(String::length).max(Comparator.naturalOrder()).get();
		output.stream().forEach(x -> {
			if (x.length() < length) {
				x = Collections.nCopies(length - x.length(), " ").stream().collect(Collectors.joining()) + x;
			}
			System.out.println(x);
		});
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int n = sc.nextInt();

		while (n-- > 0) {
			String s = sc.next();
			String[] inp = s.split("\\+|-|\\*");
			if (s.contains("+")) {
				simple_solve(inp[0], inp[1], '+');
			} else if (s.contains("-")) {
				simple_solve(inp[0], inp[1], '-');
			} else {
				simple_solve(inp[0], inp[1], '*');
			}
			System.out.print("\n");
		}

		sc.close();
	}

}
