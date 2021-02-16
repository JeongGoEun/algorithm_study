package Study;

import java.util.Arrays;

/*
 * [문제점 1]
 *	만약, {1114,12,113}을 정렬한다면 {1114,113,12}로 되기 때문에 무조건 이전에 있는것이 작다고 할 수 없다.
 *	그래서 현재와 다음 길이를 비교한 다음 추출해서 처리하도록 변경했다.
 * 
 */

public class PRG전화번호목록 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String[] arr = {"111113","1112","12"};
		System.out.println(solution(arr));
		
	}
	public static boolean solution(String[] phone_book) {
        boolean answer = true;
        int curLen=0;
        int nextLen=0;
        
        if(phone_book.length == 1) {
        	answer = false;
        } else {
        	// 정렬한다 
            Arrays.sort(phone_book);
            
            // 앞에서 부터 차례대로 비교한다 
            for(int i=0;i<phone_book.length-1;i++) {
            	curLen = phone_book[i].length();
            	nextLen = phone_book[i+1].length();
            	
            	// 더 길이가 작은 애부터 비교하도록 해야 함 
            	if(curLen < nextLen) {
            		// 이전과 같은 접두어가 있다면 그대로 종료 
                	if(phone_book[i].equals(phone_book[i+1].substring(0, curLen))) {
                		answer = false;
                		break;
                	}
            	}else {
            		// 이전과 같은 접두어가 있다면 그대로 종료 
                	if(phone_book[i+1].equals(phone_book[i].substring(0, nextLen))) {
                		answer = false;
                		break;
                	}
            	}
            	
            	
            }
        }
        
        return answer;
    }

}
