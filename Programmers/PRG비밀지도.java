package Study;

public class PRG비밀지도 {
	public String[] solution(int n, int[] arr1, int[] arr2) {
        String[] answer = new String[n];
        
        for(int i=0;i<n;i++) {
            StringBuilder sb = new StringBuilder();
            StringBuilder sb2 = new StringBuilder();

            // bit or연산
            sb.append(Integer.toBinaryString(arr1[i] | arr2[i]));
            
            //갯수 모자란애들은 앞에 0으로 채워야 함
            int len = sb.toString().length();
            
            for(int j=0;j<n-len;j++) {
                sb.insert(0,"0");
            }
            
            // 문자 치환
            String str = sb.toString();
            str = str.replace('0',' ');
            str = str.replace('1', '#');
            
            // System.out.println(str);
           
            answer[i]=str;
        }
        
        return answer;
    }
}
