package study;

public class 가운데글자가져오기 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.println(Solution("abcde"));
	}
		  public static String Solution(String s) {
		      String answer = "";
		      int idx=0,len=s.length();
		      
		      if(len < 3) {
		          answer = s;
		      }
		      if(len %2 == 0) {
		          idx=len/2;
		          answer = s.substring(idx-1,idx+1);
		      }else{
		          idx=len/2;
		          answer = s.substring(idx,idx+1);
		      }
		      return answer;
		  }
		
}

