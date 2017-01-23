import java.util.Collections;
import java.util.List;
import java.util.stream.Collectors;
import java.util.stream.Stream;

public class Solution {
	public static String add(List<String> summations) {

		String out = summations.get(0);
		for (int x = 1; x < summations.size(); x++) {
			String l = summations.get(x);
			String r = out;

			String res = "";

			int carry = 0;
			int i = l.length() - 1;
			int j = r.length() - 1;

			for (; i >= 0 && j >= 0; i--, j--) {
				int m = r.charAt(j) - '0';
				int n = l.charAt(i) - '0';

				res = (char) ((m + n) % 10 + carry + '0') + res;
				carry = (m + n + carry) / 10;
			}

			while (i >= 0) {
				int n = l.charAt(i) - '0';
				res = (char) (n + carry + '0') + res;
				carry = (n + carry) / 10;
				i--;
			}

			while (j >= 0) {
				int n = r.charAt(j) - '0';
				res = (char) (n + carry + '0') + res;
				carry = (n + carry) / 10;
				j--;
			}

			out = res;
		}
		return out;
	}

	public static String multiply(String a, String b) {

		if (b.length() > a.length()) {
			String save = a;
			a = b;
			b = save;
		}

		List<String> result = Stream.generate(String::new).limit(b.length()).collect(Collectors.toList());

		int units = b.length() - 1;
		for (Character c : b.toCharArray()) {
			int x = c - '0';

			String out = "";
			String ra = new StringBuilder(a).reverse().toString();

			int carry = 0;
			for (Character ii : ra.toCharArray()) {
				int y = ii - '0';
				out = (char) ((x * y + carry) % 10 + '0') + out;
				carry = (x * y + carry) / 10;
			}
			if (carry > 0)
				out = carry + out;

			out = out + Collections.nCopies(units, "0").stream().collect(Collectors.joining());
			result.set(units, out);
			units--;
		};

		return add(result);
	}

	public static void main(String[] args) {
		System.out.println(multiply("999", "999"));

	}
}
