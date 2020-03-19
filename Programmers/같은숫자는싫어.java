import java.util.*;

public class Solution {
	public int[] solution(int []arr) {
        int[] answer = {};
        int idx=0,prev=arr[0];
        ArrayList<Integer> li = new ArrayList<Integer>();
        
        Set<Integer> s = new HashSet<>();
        for(int i=1;i<arr.length;i++) {
        	if(prev != arr[i]) {
        		li.add(prev);
        		prev = arr[i];
        	}
        	if(i==arr.length-1) {
        		li.add(arr[i]);
        	}
        }
        answer = new int[li.size()];
        // collectionÀº length¾Æ´Ñ size
        for(int i=0;i<li.size();i++) {
        	System.out.println(li.get(i));
        	answer[i]=li.get(i);
        }
        return answer;
	}
}