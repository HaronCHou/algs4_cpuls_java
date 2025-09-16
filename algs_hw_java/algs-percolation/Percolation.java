public interface Percolation {
    public void open(int i, int j);
    public boolean isOpen(int i, int j);
    public boolean isFull(int i, int j);
    public boolean percolates();
    public int getUnionCount();
    public int getfindCount();
}



