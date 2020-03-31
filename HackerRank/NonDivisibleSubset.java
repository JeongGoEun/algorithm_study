import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.function.*;
import java.util.regex.*;
import java.util.stream.*;
import static java.util.stream.Collectors.joining;
import static java.util.stream.Collectors.toList;

class Result {

    /*
     * Complete the 'nonDivisibleSubset' function below.
     *
     * The function is expected to return an INTEGER.
     * The function accepts following parameters:
     *  1. INTEGER k
     *  2. INTEGER_ARRAY s
     */

    public static int nonDivisibleSubset(int k, List<Integer> s) {
    // Write your code here
        int arr[] = new int[k];
        Arrays.fill(arr,0);
        
        // 나머지 수 더함
        for(int i=0;i<s.size();i++) {
            arr[s.get(i)%k]++;
        }
        int rtn=0;
        // 1~k-1 subset순회
        for(int i=1;i<=k/2;i++) {
        if(i != k-i)
            rtn+=Math.max(arr[i],arr[k-i]);
        else
        	// 만약 4,4일때에도 하나만 있을땐 가능하지만, 두개라면 최대 한개일 때만 추가
            rtn++;
        }
        // 0을 어떤 나머지와 더해도 K가 되지 않지만, 나눠서 0인게 두개가 만나면 K로 나뉘기 때문에 최대 1개 추가
        if(arr[0]>0)rtn++;
        
        return rtn;
    }

}

public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String[] firstMultipleInput = bufferedReader.readLine().replaceAll("\\s+$", "").split(" ");

        int n = Integer.parseInt(firstMultipleInput[0]);

        int k = Integer.parseInt(firstMultipleInput[1]);

        List<Integer> s = Stream.of(bufferedReader.readLine().replaceAll("\\s+$", "").split(" "))
            .map(Integer::parseInt)
            .collect(toList());

        int result = Result.nonDivisibleSubset(k, s);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedReader.close();
        bufferedWriter.close();
    }
}
