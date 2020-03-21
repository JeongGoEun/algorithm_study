import java.util.*;
class Solution {
  public int[] solution(int[] arr, int divisor) {
      int[] answer = {};
      TreeSet<Integer> ts=new TreeSet<>();
      for(int i=0;i<arr.length;i++) {
    	  if(arr[i]%divisor == 0) {
    		  ts.add(arr[i]);
    	  }
      }
      answer = new int[ts.size()];
      Iterator<Integer> it = ts.iterator();
      int idx=0;
      while(it.hasNext()) {
    	  answer[idx++]=it.next();
      }
      return answer;
  }
}