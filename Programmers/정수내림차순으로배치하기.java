import java.util.Arrays;

class Solution {
  public long solution(long n) {
      long answer = 0;
      String str = Long.toString(n);
      String arr[] = str.split("");
      Arrays.sort(arr);
      String tmp="";
      for(int i=arr.length-1;i>=0;i--) {
    	  tmp+=Long.parseLong(arr[i]);
      }
      
      answer = Long.parseLong(tmp);
      return answer;
  }
}