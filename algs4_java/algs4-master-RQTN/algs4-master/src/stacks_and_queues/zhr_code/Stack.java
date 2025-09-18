// 基础接口
public interface Stack<Item> {
    void push(Item item); // 添加元素
    Item pop(); // 删除元素
    boolean isEmpty(); // 是否为空
    int size(); // 元素数量
}
