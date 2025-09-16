// package union_find;

import edu.princeton.cs.algs4.StdIn;
import edu.princeton.cs.algs4.StdOut;
import edu.princeton.cs.algs4.Stopwatch;
public class QuickUnionUF {
	
	private int[] id;
	private int count;
	private int findCount;
	private int unionCount;
	
	public QuickUnionUF(int N) {
		StdOut.println(this.getClass());
		count = N;
		id = new int[N];
		for (int i = 0; i < N; i++) {
			id[i] = i;
		}
		findCount = 0;
		unionCount = 0;
	}
	
	public int count() {
		return count;
	}
	public int getfindCount() {
		return findCount;
	}	
	public int getUnionCount() {
		return unionCount;
	}
	
	public int find(int p) {
		findCount++;
		while (p != id[p]) {
			p = id[p];
		}
		return p;
	}
	
	public boolean connected(int p, int q) {
		return find(p) == find(q);		
	}
	
	public void union(int p, int q) {
		unionCount++;
		int pRoot = find(p);
		int qRoot = find(q);
		if (pRoot == qRoot) {
			return ;
		}
		id[pRoot] = qRoot;
		count--;		
	}
	
	public static void main(String[] args) {
		int N = StdIn.readInt();
		QuickUnionUF uf = new QuickUnionUF(N);

        Stopwatch sw = new Stopwatch();
		while(!StdIn.isEmpty()) {
			int p = StdIn.readInt();
			int q = StdIn.readInt();
			if (uf.connected(p, q)) {
				continue;
			}
			uf.union(p, q);
//			StdOut.println(p + " " + q);
		}
//		StdOut.println(uf.count() + " components");
        double time = sw.elapsedTime() * 1000; // ms
        StdOut.println("  >>>  Input file: " + uf.count() + " components  cost " + time + "ms");
	}
	
}
