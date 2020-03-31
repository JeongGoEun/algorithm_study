import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

	import java.io.*;
	import java.util.*;

	public class Solution {
	    private static final Scanner scanner = new Scanner(System.in);

	    static void quick(List<Integer> list) {
	        if(list.size()<2) {
	            //모두 정렬이 된 상태
	            return;
	        }

	        int p=list.get(0);
	        List<Integer> left= new LinkedList<>();
	        List<Integer> right= new LinkedList<>();

	        for(int i=1;i<list.size();i++) {
	            // 더 작을 때
	            if(list.get(i)<p) {
	                left.add(list.get(i));
	            }else{
	                right.add(list.get(i));
	            }
	        }
	        // 모두 정렬 될 때까지 재귀
	        quick(left);
	        quick(right);

	        // 오름차순 정렬
	        Collections.sort(left);
	        Collections.sort(right);

	        List<Integer> ans = new LinkedList<>();
	        int idx=0;
	        for(int i=0;i<left.size();i++) {
	            ans.add(left.get(i));
	            System.out.print(ans.get(idx++)+" ");
	        }
	        ans.add(p);
	        System.out.print(ans.get(idx++)+" ");

	        for(int i=0;i<right.size();i++) {
	            ans.add(right.get(i));
	            System.out.print(ans.get(idx++)+" ");
	        }
	        System.out.println();
	    }
	    static int[] quickSort(int[] arr) {
	        List<Integer> li = new LinkedList<>();
	        for(int i=0;i<arr.length;i++) {
	            li.add(arr[i]);
	        }
	        quick(li);
	        return new int[8];
	    }
	    

	    public static void main(String[] args) {
	        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
	        int n = scanner.nextInt();
	        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

	        int[] arr = new int[n];
	        String strArr[] = scanner.nextLine().split(" ");
	        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

	        for(int i=0;i<n;i++) {
	            arr[i]=Integer.parseInt(strArr[i]);
	        }

	        int[] result = quickSort(arr);
	        scanner.close();
	    }
	}
	
	/*
	 * Impl Quicksort In-Place
	 * */
	static List<Integer> partition(List<Integer> li) {
        List<Integer> left = new ArrayList<>();
        List<Integer> right = new ArrayList<>();

        int p=li.get(li.size()-1), i=0, j=0, tmp=0; //j : 더 큰것들, i : 더 작은애들

        while(i<li.size() && j<li.size()) {
            if(li.get(j)<p) {
                tmp = li.get(j);
                li.set(j,li.get(i));
                li.set(i,tmp);
                i++;
            }
            j++;
        }
        tmp = li.get(i);
        li.set(i,p);
        li.set(li.size()-1,tmp);

        List<Integer> leftList = partition(left);
        leftList.add(p);
        List<Integer> rightList = partition(right);
        for(i=0;i<rightList.size();i++) {
            leftList.add(right.get(i));
        }
        return leftList;
    }
    static void quickSort(List<Integer> li) {
        while(true) {
            List<Integer> rtn = partition(li);
            print(rtn);
            boolean flag=true;
            for(int i=0;i<rtn.size()-1;i++) {
                if(rtn.get(i)>rtn.get(i+1)) {
                    flag=false;
                    break;
                }
            }
            if(!flag){
                break;
            }
        }
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int n = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        int[] arr = new int[n];

        String[] arrItems = scanner.nextLine().split(" ");
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int i = 0; i < n; i++) {
            int arrItem = Integer.parseInt(arrItems[i]);
            arr[i] = arrItem;
        }

        int[] result = quickSort(arr);

        for (int i = 0; i < result.length; i++) {
            bufferedWriter.write(String.valueOf(result[i]));

            if (i != result.length - 1) {
                bufferedWriter.write(" ");
            }
        }

        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
