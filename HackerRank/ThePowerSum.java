import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    static int power(int X, int N, int n) {
        int val = (int)Math.pow(n,N);    //n^N��
        if(val == X) {
            return 1;
        }else if(val > X) {
            // ������ n�� ��� Ŀ���� ������ ã������ ������ ũ�� �� �ʿ䰡 ����
            return 0;
        }else{
            //1�� �����ؼ� X����� ��� + val�� ���� �� �����ϱ� X-val�� ��������
            return power(X,N,n+1) + power(X-val,N,n+1);
        }
    }
    // Complete the powerSum function below.
    static int powerSum(int X, int N) {
        int rtn = power(X,N,1);
        return rtn;

    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int X = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        int N = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        int result = powerSum(X, N);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
