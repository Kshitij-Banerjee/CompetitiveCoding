import java.util.ArrayList;
import java.util.Collections;

class TreeNode {
	int val;
	TreeNode left;
	TreeNode right;

	TreeNode(int x) {
		val = x;
	}
}

/*
 * 
 *                    10
 *          3                    11
 *      0       6          8             12
 *   -1   1  4     7          9      13      15
 *      
 */
public class Solution {
	
	public ArrayList<Integer> from_top( TreeNode a, int min, int max ){

		if( a.val < min ) {
			return new ArrayList<Integer>(){{ add(a.val); add(min); }};
		}
		else if( a.val > max ){
			return new ArrayList<Integer>(){{ add(max); add(a.val); }};
		}
		
		if( a.right != null ) {
			ArrayList<Integer> right = from_top(a.right, Math.max(min, a.val), max);
			if( right != null ) return right;
		}
		
		if( a.left != null ) { 
			ArrayList<Integer> left = from_top(a.left, min, Math.min(max, a.val));
			if( left != null ) return left;
		}
		
		return null;
		
	}
	
	public ArrayList<Integer> from_bottom(TreeNode a, IntWrap min, IntWrap max){

		if( a == null ) return null;

		IntWrap leftMin = new IntWrap(Integer.MAX_VALUE);
		IntWrap leftMax = new IntWrap(Integer.MIN_VALUE);
		ArrayList<Integer> left = from_bottom(a.left, leftMin, leftMax);
		if( left != null ) return left;

		if( a.val < leftMax.value ){

			// a should be greater than rightmost in left tree
			return new ArrayList<Integer>(){{ add(a.val); add(leftMax.value); }};
		}

		IntWrap rightMin = new IntWrap(Integer.MAX_VALUE);
		IntWrap rightMax = new IntWrap(Integer.MIN_VALUE);
		ArrayList<Integer> right = from_bottom(a.right, rightMin, rightMax);
		if( right != null ) return right;
		
		if( a.val > rightMin.value ){
			
			return new ArrayList<Integer>() {{ add(a.val); add(rightMin.value); }};
		}
		
		min.value = Math.min(leftMin.value, a.val);
		max.value = Math.max(rightMax.value, a.val);
		return null;
	}
	
	class IntWrap{

		public IntWrap(int maxValue) {
			value = maxValue;
		}

		public int value;
	}

	public ArrayList<Integer> recoverTree(TreeNode a) {
		
		ArrayList<Integer>  top = from_top(a, Integer.MIN_VALUE, Integer.MAX_VALUE);
		IntWrap l = new IntWrap(Integer.MAX_VALUE);
		IntWrap r = new IntWrap(Integer.MIN_VALUE);
		ArrayList<Integer>  bottom = from_bottom(a, l, r);
		top.addAll(bottom);
		Collections.sort(top);
		return new ArrayList<Integer>(){{ add(top.get(0)); add(top.get(top.size()-1)); }};
	}
	
	
	public static void main( String[] args ){
		
//		TreeNode root = new TreeNode(3);
//		root.left = new TreeNode(1);
//		root.left.left = new TreeNode(0);
//		root.left.right = new TreeNode(2);
//		root.right = new TreeNode(6);
//		root.right.left = new TreeNode(4);
//		root.right.right = new TreeNode(7);

		TreeNode root = new TreeNode(0);
		root.left = new TreeNode(1);
		root.left.left = new TreeNode(3);
		root.left.right = new TreeNode(2);
		root.right = new TreeNode(6);
		root.right.left = new TreeNode(4);
		root.right.right = new TreeNode(7);
		
		new Solution().recoverTree(root).stream().forEach(System.out::println);
		
	}
}
