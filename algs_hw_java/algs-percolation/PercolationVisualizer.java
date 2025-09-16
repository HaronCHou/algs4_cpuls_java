/****************************************************************************
 *  Compilation:  javac PercolationVisualizer.java
 *  Execution:    java PercolationVisualizer input.txt
 *  Dependencies: Percolation.java StdDraw.java In.java
 *
 *  This program takes the name of a file as a command-line argument.
 *  From that file, it
 *
 *    - Reads the grid size N of the percolation system.
 *    - Creates an N-by-N grid of sites (intially all blocked)
 *    - Reads in a sequence of sites (row i, column j) to open.
 *
 *  After each site is opened, it draws full sites in light blue,
 *  open sites (that aren't full) in white, and blocked sites in black,
 *  with with site (1, 1) in the upper left-hand corner.
 *
 ****************************************************************************/

import java.awt.Font;
import edu.princeton.cs.algs4.StdDraw;
import edu.princeton.cs.algs4.In;
import edu.princeton.cs.algs4.StdOut;

public class PercolationVisualizer {

    // delay in miliseconds (controls animation speed)
    private static final int DELAY = 100;

    // draw N-by-N percolation system
    public static void draw(Percolation perc, int N) {
        StdDraw.clear();
        StdDraw.setPenColor(StdDraw.BLACK);
        StdDraw.setXscale(0, N);
        StdDraw.setYscale(0, N);
        StdDraw.filledSquare(N/2.0, N/2.0, N/2.0);

        // draw N-by-N grid
        int opened = 0;
        for (int row = 1; row <= N; row++) {
            for (int col = 1; col <= N; col++) {
                if (perc.isFull(row, col)) {
                    StdDraw.setPenColor(StdDraw.BOOK_LIGHT_BLUE);
                    opened++;
                }
                else if (perc.isOpen(row, col)) {
                    StdDraw.setPenColor(StdDraw.WHITE);
                    opened++;
                }
                else
                    StdDraw.setPenColor(StdDraw.BLACK);
                StdDraw.filledSquare(col - 0.5, N - row + 0.5, 0.45);
            }
        }

        // write status text
        StdDraw.setFont(new Font("SansSerif", Font.PLAIN, 12));
        StdDraw.setPenColor(StdDraw.BLACK);
        StdDraw.text(.25*N, -N*.025, opened + " open sites");
        if (perc.percolates()) {
            StdDraw.text(.75*N, -N*.025, "percolates");
             StdOut.println("\t percolates");
        }
        else {
            StdDraw.text(.75*N, -N*.025, "does not percolate");
            // StdOut.println("\t does not percolates");
        }

    }
    // usage: java-agls4 PercolationVisualizer input.txt 0
    public static void main(String[] args) {
        if(args.length != 2){
            StdOut.println("Need 2 args\nUsage: java-algs4 PercolationVisualizer input.txt 0");
            return;
        }
        In in = new In(args[0]);      // input file
        int N = in.readInt();         // N-by-N percolation system
        int choose_version = Integer.parseInt(args[1]); // choose which version of Percolation class to use
        // turn on animation mode
        StdDraw.show(0);

        // repeatedly read in sites to open and draw resulting system
        // Percolation perc = new Percolation(N);
        /* 重载多个类，切换着用
            0-PercolationAnswer 标准答案里的
            1-Percolation_zhr_v1 自己写的
        */
        Percolation perc;
        switch (choose_version)
        {
            case 0 :
                perc = new PercolationAnswer(N);
                StdOut.println("Using PercolationAnswer");
                break;
            case 1 :
                perc = new Percolation_zhr_v1(N);
                StdOut.println("Using Percolation_zhr_v1 no virtual bottom node");
                break;
            case 2 :
                perc = new Percolation_zhr_v2(N);
                StdOut.println("Using Percolation_zhr_v2 with virtual bottom node");
                break;
            case 3 :
                perc = new Percolation_zhr_v3(N);
                StdOut.println("Using Percolation_zhr_v2 with virtual bottom node");
                break;
            default:
                perc = new PercolationAnswer(N);  // 默认选择 PercolationAnswer
                StdOut.println("Invalid choice, using default PercolationAnswer");
                break;
            // Percolation perc = new PercolationAnswer(N);
            // Percolation perc = new Percolation_zhr_v1(N);
        }
        draw(perc, N);
        StdDraw.show(DELAY);
        while (!in.isEmpty()) {
            int i = in.readInt();
            int j = in.readInt();
            perc.open(i, j);
            draw(perc, N);
            StdDraw.show(DELAY);
        }
        if (perc.percolates()) {
            StdOut.println("\t percolates");
        }
        else {
            StdOut.println("\t does not percolates");
        }
    }
}