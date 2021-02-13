package Study;

import java.util.*;
import java.io.*;

class Doc implements Comparable<Doc> {
	Integer idx = 0;
	Integer priorityNum = 0;

	public Doc(int index, int priority) {
		this.idx = index;
		this.priorityNum = priority;
	}

	@Override
	public int compareTo(Doc o) {
		return this.priorityNum.compareTo(o.priorityNum);
	}

	public int getIdx() {
		return this.idx;
	}

	public int getPriorityNum() {
		return this.priorityNum;
	}
}

public class BOJ1966 {

	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		
		LinkedList<Doc> docArray = new LinkedList<Doc>();
		LinkedList<Integer> priorityArray = new LinkedList<Integer>();

		int T = Integer.parseInt(br.readLine());

		while (T-- > 0) {
			String input = br.readLine();
			StringTokenizer st = new StringTokenizer(input);
			int N = Integer.parseInt(st.nextToken());
			int M = Integer.parseInt(st.nextToken());
			int cnt = 0;

			StringTokenizer st2 = new StringTokenizer(br.readLine());
			int size = st2.countTokens();

			if (size == 1) {
				sb.append(1 + "\n");
			} else {
				for (int i = 0; i < size; i++) {
					Doc d = new Doc(i, Integer.parseInt(st2.nextToken()));

					docArray.add(d);
					priorityArray.add(d.priorityNum);
				}

				// 우선순위 먼저 정렬
				Collections.sort(priorityArray, Collections.reverseOrder());
				
//				for (Integer num: priorityArray) {
//					System.out.println(num);
//				}
				
				boolean flag = true;

				// 타겟이 잡힐 때 까지 반
				while (flag) {

					// queue에서 하나 꺼내기
					Doc curDoc = docArray.poll();

					// 현재 최대 우선순위랑 같다
					if (curDoc.getPriorityNum() == priorityArray.getFirst()) {
						// 출력한다
						priorityArray.poll();
						cnt++;

						// 현재 찾고있는 인덱스라면 끝낸다
						if (curDoc.getIdx() == M) {
							sb.append(cnt + "\n");
							flag = false;
						}

					} else {
						// 뒤로보내줌
						docArray.addLast(curDoc);
					}

				}
			}
			docArray.clear();
			priorityArray.clear();
		}
		
		System.out.println(sb.toString());
	}
}
