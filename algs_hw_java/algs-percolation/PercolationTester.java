// 无GUI的PercolationVisualizer,// 只能看到输出结果,// 不能看到可视化的图像// 只能看到是否渗透// 只能看到打开的格子数
// 不能看到格子的状态// 不能看到水流的状态// 不能看到动画// 不能看到动态变化过程// 只能看到最终结果
import edu.princeton.cs.algs4.In;
import edu.princeton.cs.algs4.StdOut;

public class PercolationTester {
    public static void draw(Percolation perc, int N) {
        // StdDraw.clear();
        // StdDraw.setPenColor(StdDraw.BLACK);
        // StdDraw.setXscale(0, N);
        // StdDraw.setYscale(0, N);
        // StdDraw.filledSquare(N/2.0, N/2.0, N/2.0);

        // draw N-by-N grid
        int opened = 0;
        for (int row = 1; row <= N; row++) {
            for (int col = 1; col <= N; col++) {
                if (perc.isFull(row, col)) {
                    // StdDraw.setPenColor(StdDraw.BOOK_LIGHT_BLUE);
                    opened++;
                }
                else if (perc.isOpen(row, col)) {
                    // StdDraw.setPenColor(StdDraw.WHITE);
                    opened++;
                }
                else
                    ;// StdDraw.setPenColor(StdDraw.BLACK);
                // StdDraw.filledSquare(col - 0.5, N - row + 0.5, 0.45);
            }
        }

        // write status text
        // StdDraw.setFont(new Font("SansSerif", Font.PLAIN, 12));
        // StdDraw.setPenColor(StdDraw.BLACK);
        // StdDraw.text(.25*N, -N*.025, opened + " open sites");
        StdOut.printf("%d open sites ", opened);
        if (perc.percolates()) {
            StdOut.println("\t percolates");
        }// StdDraw.text(.75*N, -N*.025, "percolates");
        else{
             StdOut.println("\t does not percolates");// StdDraw.text(.75*N, -N*.025, "does not percolate");
        }
    }


    public static void main(String[] args) {
        if(args.length != 2){
            StdOut.println("Need 2 args\nUsage: java-algs4 PercolationVisualizer input.txt 0");
            return;
        }
        In in = new In(args[0]);      // input file
        int N = in.readInt();         // N-by-N percolation system
        int choose_version = Integer.parseInt(args[1]); // choose which version of Percolation class to use
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

        // repeatedly read in sites to open and draw resulting system
        while (!in.isEmpty()) {
            int i = in.readInt();
            int j = in.readInt();
            perc.open(i, j);
            draw(perc, N);
            // StdDraw.show(DELAY);
        }
        // StdOut.println(perc.numberOfOpenSites() + " open sites");
        // if (perc.percolates()) StdOut.println("percolates");
        // else                   StdOut.println("does not percolate");
        // System.out.printf("%d open sites\n", perc.numberOfOpenSites());
        if (perc.percolates()) System.out.println("percolates");
        else                   System.out.println("does not percolate");
    } 
}


