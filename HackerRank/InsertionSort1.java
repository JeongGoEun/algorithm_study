import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the insertionSort1 function below.
    static void printArr(int n, int []arr) {
        for(int i=0;i<n;i++) {
            System.out.print(arr[i]+" ");
        }
        System.out.println();
    }
    static void insertionSort1(int n, int[] arr) {
        for(int i=1;i<n;i++) {
            if(arr[i]<arr[i-1]) {
                int key=arr[i];
                int j=0;
                // 0~i-1까지 순회해서 바꿔주기
                for(j=i-1;j>=0 && arr[j] > key;j--) {
                    arr[j+1]=arr[j];
                    printArr(n,arr);
                }
                arr[j+1]=key;
                printArr(n,arr);
                //break;
            }
        }
    }
 // Complete the insertionSort2 function below.
    static void insertionSort2(int n, int[] arr) {
        for(int i=1;i<n;i++) {
            // 이전보다 값이 작다면
            if(arr[i] < arr[i-1]) {
                int j=0, key=arr[i];
                // 이전 수가 더 크면 계속 밀어줘야 함
                for(j=i-1;j>=0 && arr[j] > key;j--) {
                    arr[j+1]=arr[j];
                }
                arr[j+1]=key;
            }
            printArr(n,arr);
        }
    }
    
 // insertion sort에서 shift된 갯수 return
    static int runningTime(int[] arr) {
        int rtn=0,key=0,j=0;
        for(int i=1;i<arr.length;i++) {
            if(arr[i] < arr[i-1]) {
                key=arr[i];
                for(j=i-1;j>=0&&arr[j]>key;j--) {
                    arr[j+1]=arr[j];
                    rtn++;
                }
                arr[j+1]=key;
            }
        }
        return rtn;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        int n = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        int[] arr = new int[n];

        String[] arrItems = scanner.nextLine().split(" ");
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int i = 0; i < n; i++) {
            int arrItem = Integer.parseInt(arrItems[i]);
            arr[i] = arrItem;
        }

        insertionSort1(n, arr);

        scanner.close();
    }
}
