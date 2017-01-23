import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.util.stream.Stream;

public class Main {

	private enum VERTEX_STATE {
		OPEN, SEEN, CLOSED
	};

	private static void dfs(List<List<Integer>> graph, List<VERTEX_STATE> vstate, int x) {

		if (vstate.get(x).equals(VERTEX_STATE.CLOSED))
			return;

		vstate.set(x, VERTEX_STATE.SEEN);
		for (Integer y : graph.get(x)) {
			if (vstate.get(y).equals(VERTEX_STATE.SEEN)) {
				System.out.println("NO");
				System.exit(0);
			}
			dfs(graph, vstate, y);
		}
		vstate.set(x, VERTEX_STATE.CLOSED);
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();

		if (m != n - 1) {

			System.out.println("NO");
		} else {
			List<List<Integer>> graph = Stream.
					generate(ArrayList<Integer>::new).
					limit(n).
					collect(Collectors.toList());

			List<VERTEX_STATE> vstate = new ArrayList<VERTEX_STATE>(Collections.nCopies(n, VERTEX_STATE.OPEN));

			while (m-- > 0) {
				int x = sc.nextInt();
				int y = sc.nextInt();

				graph.get(x-1).add(y-1);
			}

			IntStream.range(0, n).forEach(i -> {
				if (vstate.get(i).equals(VERTEX_STATE.OPEN)) {
					dfs(graph, vstate, i);
				}
			});

			System.out.println("YES");
		}
		sc.close();
	}
}
