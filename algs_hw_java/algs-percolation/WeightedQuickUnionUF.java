// package union_find;

import edu.princeton.cs.algs4.StdIn;
import edu.princeton.cs.algs4.StdOut;
import edu.princeton.cs.algs4.Stopwatch;
import edu.princeton.cs.algs4.Stopwatch;

public class WeightedQuickUnionUF {
	
	private int[] id;
	private int[] sz;
	private int count;

	private int unionCount;
	private int findCount;
	
	public WeightedQuickUnionUF(int N) {
		StdOut.println(this.getClass());
		count = N;
		unionCount = 0;
		findCount = 0;
		id = new int[N];
		sz = new int[N];
		for (int i = 0; i < N; i++) {
			id[i] = i;
			sz[i] = 1;
		}
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
		if (sz[pRoot] < sz[qRoot]) {
			id[pRoot] = qRoot;
			sz[qRoot] += sz[pRoot];
		}
		else {
			id[qRoot] = pRoot;
			sz[pRoot] += sz[qRoot];
		}
		count--;
	}
	
	public static void main(String[] args) {
		int N = StdIn.readInt();
		WeightedQuickUnionUF uf = new WeightedQuickUnionUF(N);

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
