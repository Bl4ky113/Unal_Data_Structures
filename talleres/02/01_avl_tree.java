import java.util.List;
import java.util.ArrayList;
import java.util.Stack;
import java.util.Iterator;

public class TreeSetAVL<T extends Comparable<T>> implements Iterable<T> {

  private Node root;
  private int size;

  public TreeSetAVL() {
    size = 0;
    root = null;
  }

  public boolean add(T val) {
    if (contains(val))
      return false;
    root = add_rec(val, root);
    size++;
    return true;
  }

  private Node add_rec(T val, Node node) {
    if (node == null)
      return new Node(val);
    if (val.compareTo(node.data) < 0)
      node.left = add_rec(val, node.left);
    else
      node.right = add_rec(val, node.right);
    node = balance(node);
    node.update_h();
    return node;
  }

  public boolean contains(T val) {
    return contains_rec(val, root);
  }

  private boolean contains_rec(T val, Node node) {
    if (node == null)
      return false;
    if (val.compareTo(node.data) == 0)
      return true;
    if (val.compareTo(node.data) < 0)
      return contains_rec(val, node.left);
    else
      return contains_rec(val, node.right);
  }

  public boolean remove(T val) {
    if (contains(val) == false)
      return false;
    root = remove_rec(val, root);
    size--;
    return true;
  }

  private Node remove_rec(T val, Node node) {
    if (val.compareTo(node.data) < 0)
      node.left = remove_rec(val, node.left);
    else if (val.compareTo(node.data) > 0)
      node.right = remove_rec(val, node.right);
    else {
      if (node.left == null && node.right == null)
        return null;
      if (node.right == null)
        return node.left;
      if (node.left == null)
        return node.right;
      Node suc = node.right;
      while (suc.left != null)
        suc = suc.left;
      node.data = suc.data;
      node.right = remove_rec(suc.data, node.right);
    }
    node = balance(node);
    node.update_h();
    return node;
  }

  public T floor (T key) {
    Stack<Node> find_path = new Stack<Node>();
    Node current_node, prev_node, tmp_node;
    
    tmp_node = root;
    current_node = root;
    while (tmp_node != null) {
        find_path.add(tmp_node);

        if (key.compareTo(tmp_node.data) < 0) {
            current_node = tmp_node;
            tmp_node = tmp_node.left;
        } else if (key.compareTo(tmp_node.data) > 0) {
            tmp_node = tmp_node.right;
        } else {
            current_node = tmp_node;
            break;
        }
    }

    if (current_node == root && key.compareTo(root.data) != 0) {
        prev_node = find_path.pop();

        if (key.compareTo(prev_node.data) > 0) {
            return prev_node.data;
        }

        return null;
    }

    if (key.compareTo(current_node.data) == 0) {
        // Found
        return current_node.data;
    }

    // Not found, but has bound available
    // Might have reached a leaf, check last pair of nodes in the path
    current_node = find_path.pop();
    prev_node = find_path.pop();
    if (prev_node.data.compareTo(current_node.data) < 0) {
        return prev_node.data;
    } else if (prev_node.data.compareTo(current_node.data) > 0) {
        return current_node.data;
    }

    return null;
  }

  public void print_tree (Node base_node, int current_depth) {
    if (base_node == null) {
        return;
    }

    int i = 1;
    if (current_depth > 0) {
        System.out.print("|");
        for (; i < current_depth; i++) {
            System.out.print("\t|");
        }
        System.out.print("\t");
    }

    System.out.print("(");
    System.out.print(base_node.data);
    System.out.print(")\n");

    if (base_node.left != null) {
        print_tree(base_node.left, current_depth + 1);
    }

    if (base_node.right != null) {
        print_tree(base_node.right, current_depth + 1);
    }

    return;
  }

  public int size() {
    return size;
  }

  private void traversal(Node node, List<T> list) {
    if (node == null)
      return;
    traversal(node.left, list);
    list.add(node.data);
    traversal(node.right, list);
  }

  public String toString() {
    List<T> list = new ArrayList<T>();
    traversal(root, list);
    return list.toString();
  }

  public Iterator<T> iterator() {
    List<T> list = new ArrayList<T>();
    traversal(root, list);
    return list.iterator();
  }

  private Node balance(Node node) {
    if (Math.abs(balance_factor(node)) <= 1)
      return node;
    if (height(node.left) > height(node.right)) { // IZQ
      if (height(node.left.left) > height(node.left.right)) { // IZQ-IZQ
        return right_rotate(node);
      } else { // IZQ-DER
        node.left = left_rotate(node.left);
        return right_rotate(node);
      }
    } else { // DERECHA
      if (height(node.right.left) > height(node.right.right)) { // DER-IZQ
        node.right = right_rotate(node.right);
        return left_rotate(node);
      } else { // DER-DER
        return left_rotate(node);
      }
    }
  }

  private Node left_rotate(Node node) {
    if (node.right == null)
      return node;
    Node pivot = node.right;
    node.right = pivot.left;
    pivot.left = node;
    node.update_h();
    pivot.update_h();
    return pivot;
  }

  private Node right_rotate(Node node) {
    if (node.left == null)
      return node;
    Node pivot = node.left;
    node.left = pivot.right;
    pivot.right = node;
    node.update_h();
    pivot.update_h();
    return pivot;
  }

  private int balance_factor(Node node) {
    if (node == null)
      return 0;
    return height(node.left) - height(node.right);
  }

  private int height(Node node) {
    if (node == null)
      return -1;
    return node.h;
  }

  private class Node {
    T data;
    Node left;
    Node right;
    int h;

    Node(T d) {
      data = d;
      h = 0;
    }

    void update_h() {
      h = Math.max(height(left), height(right)) + 1;
    }
  }

  public static void main (String[] args) {
      TreeSetAVL<Integer> new_tree = new TreeSetAVL<Integer>();

      new_tree.add(11);
      new_tree.add(71);
      new_tree.add(18);
      new_tree.add(12);
      new_tree.add(61);
      new_tree.add(31);
      new_tree.add(15);
      new_tree.add(91);
      new_tree.add(10);
      new_tree.add(1);
      new_tree.add(7);
      new_tree.add(8);
      new_tree.add(2);
      new_tree.add(6);
      new_tree.add(3);
      new_tree.add(5);
      new_tree.add(9);
      new_tree.add(-1);
      new_tree.add(-2);
      new_tree.add(-3);

      new_tree.print_tree(new_tree.root, 0);

      Integer foo;
      foo = new_tree.floor(31);
      System.out.print("Searching floor of 31, found: ");
      System.out.println(foo);

      foo = new_tree.floor(32);
      System.out.print("Searching floor of 32, found: ");
      System.out.println(foo);

      foo = new_tree.floor(0);
      System.out.print("Searching floor of 0, found: ");
      System.out.println(foo);

      foo = new_tree.floor(1);
      System.out.print("Searching floor of 1, found: ");
      System.out.println(foo);

      foo = new_tree.floor(3);
      System.out.print("Searching floor of 3, found: ");
      System.out.println(foo);

      foo = new_tree.floor(4);
      System.out.print("Searching floor of 4, found: ");
      System.out.println(foo);

      foo = new_tree.floor(9);
      System.out.print("Searching floor of 9, found: ");
      System.out.println(foo);

      foo = new_tree.floor(13);
      System.out.print("Searching floor of 13, found: ");
      System.out.println(foo);

      foo = new_tree.floor(71);
      System.out.print("Searching floor of 71, found: ");
      System.out.println(foo);

      foo = new_tree.floor(72);
      System.out.print("Searching floor of 72, found: ");
      System.out.println(foo);

      foo = new_tree.floor(-1000);
      System.out.print("Searching floor of -1000, found: ");
      System.out.println(foo);

      foo = new_tree.floor(1000);
      System.out.print("Searching floor of 1000, found: ");
      System.out.println(foo);
  }
}
