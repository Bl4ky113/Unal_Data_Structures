/* 
 * El método removeAll(l, x) elimina todas las ocurrencias de x de la lista l.
 * Implemente el método de manera que su complejidad temporal sea O(n)
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    static <T> void removeAll(List<T> list, T itemToDelete) {
        ArrayList<T> deleteList = new ArrayList<T>();
        deleteList.add(itemToDelete);

        list.removeAll(deleteList);
        return;
	}

	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(in.readLine());
        
		int n = Integer.parseInt(st.nextToken());
		int x = Integer.parseInt(st.nextToken());
        
		st = new StringTokenizer(in.readLine());
		List<Integer> al = new ArrayList<>();
		List<Integer> ll = new LinkedList<>();
        
		for(int i = 0; i < n; i++) {
            int usrInput = Integer.parseInt(st.nextToken());

            ll.add(usrInput);
        	al.add(usrInput);   
		}
        
        
		removeAll(al, x);
		removeAll(ll, x);
        
		System.out.println(al);
		System.out.println(ll);
    }
}
