package HakerRank;

import java.util.*;

class Solution {

	public static void main(String[] argh) {
		Scanner sc = new Scanner(System.in);

		while (sc.hasNext()) {
			String input = sc.next();
			// Complete the code
			System.out.println(check(input));
		}

	}

	public static boolean check(String input) {
		// !! Collection사용할 때 객체형으로 넣어줘야 함
		Stack<Character> st = new Stack<>();

		for (int i = 0; i < input.length(); i++) {
			char ch = input.charAt(i);
			if (ch == '(' || ch == '[' || ch == '{') {
				st.push(ch);
			} else {
				if (!st.isEmpty()) {
					if (ch == ')' && st.peek() == '(') {
						st.pop();
					} else if (ch == ']' && st.peek() == '[') {
						st.pop();
					} else if (ch == '}' && st.peek() == '{') {
						st.pop();
					}
				} else {
					return false;
				}
			}
		}
		return st.isEmpty();
	}
}
