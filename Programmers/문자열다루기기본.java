class Solution {
  public boolean solution(String s) {
      boolean answer = true;
      if(s.length()==4 || s.length()==6){
          for(int i=0;i<s.length();i++) {
              if(s.charAt(i)>='a' && s.charAt(i)<='z') {
                  System.out.println(answer);
                  answer=false;
                  break;
              }
          }
      }else{
            answer=false;        
      }      
      return answer;
  }
}