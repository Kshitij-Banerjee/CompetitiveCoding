import java.util.Scanner;

public class Solution2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
	
		Scanner sc = new Scanner(System.in);
		
		long n = sc.nextLong();
		long m = sc.nextLong();
		long k = sc.nextLong();
		
		long low = 1;
		long high = m-n+1;
		
		long ans = low;

		while( low <= high ){
			
			long mid  = (low + high) /2 ;
			
			if( canAllocate2(n,m,k,mid) ){
				low = mid+1;
				ans = mid;
			}
			else{
				high = mid-1;
			}
		}
		
		System.out.println(ans);

		sc.close();
		
	}
// 1 2 3 4
// 1 2 1 1
	private static boolean canAllocate2(long n, long m, long k, long mid) {
		m -= mid;

		long range1 = n - k;
		long range2 = k - 1;

		long allocate1 = (mid-1)* (mid)/2;
		// 5 4 3 2 1
		if( range1  > mid-1 ){
			allocate1 += (range1 - mid + 1);
		}
		else{
			long shortcoming = mid - 1 - range1;
			allocate1 -= (shortcoming* (shortcoming+1))/2;
		}
		
		m -= allocate1;
		
		if( m < 0 ) return false;
		
		long allocate2 = (mid-1)* (mid)/2;
		// 5 4 3 2 1
		if( range2  > mid-1 ){
			allocate2 += (range2 - mid + 1);
		}
		else{
			long shortcoming = mid - 1 - range2;
			allocate2 -= (shortcoming* (shortcoming+1))/2;
		}
		
		m -= allocate2;
		if( m < 0 ) return false;
		
		
		return true;
		
	}

	private static boolean canAllocate(long n, long m, long k, long mid) {
		// TODO Auto-generated method stub
		long reduce = mid;
		m -= reduce;
		
		long i = k+1;
		while( i <= n ){
			m -= Math.max(--reduce, 1);
			if( m < 0 ){
				return false;
			}
			i++;
		}

		i = k-1;
		reduce = mid;
		while( i > 0 ){
			m -= Math.max(--reduce, 1);
			if( m < 0 ){
				return false;
			}
			i--;
		}

		return true;
	}

}
