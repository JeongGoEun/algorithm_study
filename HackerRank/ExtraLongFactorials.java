import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the extraLongFactorials function below.
    static void extraLongFactorials(int n) {
        // 엄청 큰 숫자가 나올 수 있기 때문에 Big Integer로 커버
        BigInteger fact = BigInteger.valueOf(1);
        for(int i=1;i<=n;i++) {
            //BigInteger.multiply => 곱셈
            // BigInteger.valueOf(val) => value setting
            fact = fact.multiply(BigInteger.valueOf(i));
        }
        System.out.println(fact);
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        int n = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        extraLongFactorials(n);

        scanner.close();
    }
}
