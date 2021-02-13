package Study;

import java.io.*;
import java.util.*;

public class BOJ10846 {
	public static void main(String[] args) throws Exception{
		StringBuilder sb = new StringBuilder();
		Scanner sc = new Scanner(System.in);
		
		int n = sc.nextInt();
		LinkedList<Integer> q = new LinkedList<Integer>();
		
		
		// n--가 0보다 클 때까지 돈
		for(int i=0;i<n;i++) {
			String code = sc.next();

			switch(code) {
			case "push" :
				int num = sc.nextInt();
				q.addLast(num);
				break;
			case "pop":
				if(q.isEmpty()) {
					sb.append(-1+"\n");
				}else {
					sb.append(q.pollFirst()+"\n");
					// q.removeFirst();
					// q.pollFirst();
				}
				break;
			case "size":
				sb.append(q.size()+"\n");
				break;
			case "empty":
				if(q.isEmpty()) {
					sb.append(1+"\n");
				}else {
					sb.append("0"+"\n");
				}
				break;
			case "front":
				if(q.isEmpty()) {
					sb.append("-1"+"\n");
				}else {
					sb.append(q.peekFirst()+"\n");
				}
				break;
			case "back":
				if(q.isEmpty()) {
					sb.append("-1"+"\n");
				}else {
					sb.append(q.peekLast()+"\n");
				}
				break;
			}
		}
	    System.out.println(sb.toString());
	}
}
