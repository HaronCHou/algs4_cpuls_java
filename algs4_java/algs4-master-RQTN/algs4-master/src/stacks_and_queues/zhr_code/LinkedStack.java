import edu.princeton.cs.algs4.StdIn;
import edu.princeton.cs.algs4.StdOut;

public class LinkedStack<Item> implements Stack<Item>{
    // list node
    private class Node{
        Item Item;
        Node next;
    }
    private Node first; // 栈顶元素
    private int N; // 元素数量

    // public Stack<Item>(){ // 构造函数
    //     first = new Node();
    //     first.next = null;
    //     N = 0;
    // }

    public void push(Item Item){// 添加元素
        Node node = new Node();
        node.Item = Item;
        node.next = first;
        first = node;
        N++;
    }
    public Item pop(){
        Item Item = first.Item;
        Node tmp = first;
        first = first.next;
        tmp.next = null; // help GC
        N--;
        return Item;
    } // 删除元素
    public boolean isEmpty(){
        return N == 0;   // or return first == null;
    } // 是否为空
    public int size(){
        return N;
    } // 元素数量
    // <Item> stack = new LinkedStack<>(); // 创建栈对象

    public static void main(String[] args) {
        LinkedStack<String> stack = new LinkedStack<String>();
        while (!StdIn.isEmpty()) {
            
            String s = StdIn.readString();
            if (s.equals("-")) {
                stack.pop();
            }
            else {
                stack.push(s);
            }
            // 手动遍历
            StdOut.printf("%4s | Stack Display: ", s);
            LinkedStack<String>.Node cur = stack.first;
            while (cur != null) {
                StdOut.print(cur.Item + " ");
                cur = cur.next; 
            }
            StdOut.println(); // 换行
        }
        StdOut.println("(" + stack.size() + " left on stack)");
        // 遍历打印栈里的内容
        // for (String s : stack) {
        //     StdOut.println(s);
        // }  // 需要实现Iterable接口



    }
}