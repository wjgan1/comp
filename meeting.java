import java.io.*;
import java.util.*;

public class meeting
{
	static ArrayList<Integer> list1;
	static ArrayList<Integer> list2;
	public static void main (String [] args) throws IOException	
	{
		list1 = new ArrayList<Integer>();
		list2 = new ArrayList<Integer>();

		BufferedReader in = new BufferedReader(new FileReader("data.in"));
		PrintWriter out = new PrintWriter(new File("data.out"));

		StringTokenizer st = new StringTokenizer(in.readLine());
		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());

		int [][][] arr = new int[N][N][2];
		for (int i = 0; i < M; ++i)
		{
			st = new StringTokenizer(in.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			arr[a-1][b-1][0] = Integer.parseInt(st.nextToken());
			arr[a-1][b-1][1] = Integer.parseInt(st.nextToken());
		}

		dfs(arr,0,0,0);
		/*
		for (int i = 0; i < list1.size(); ++i)
		{
			System.out.println(list1.get(i) + " " + list2.get(i));
		}
		*/
		int min = Integer.MAX_VALUE;
		for (int i = 0; i < list1.size(); ++i)
		{
			for (int j = 0; j < list2.size(); ++j)
			{
				if (list1.get(i) == list2.get(j) && list1.get(i) < min)
				{
					System.out.println(min);
					min = list1.get(i);
				}
				if (list1.get(i) == 1159 && list2.get(j) == 1159)
				{
					if (list1.get(i).compareTo(list2.get(j)) == 0)
					System.out.println(i + " " + min);
				}
			}
		}

		if (min == Integer.MAX_VALUE)
			out.println("IMPOSSIBLE");
		else
			out.println(min);
		out.close();
	}

	public static void dfs(int [][][] arr, int spot, int bsum, int esum)
	{
		if (spot == arr.length-1)
		{
			list1.add(bsum);
			list2.add(esum);
			return;
		}
		for (int i = 0; i < arr[spot].length; ++i)
		{
			if (arr[spot][i][0] != 0)
			{
				bsum += arr[spot][i][0];
				esum += arr[spot][i][1];
				dfs(arr,i,bsum,esum);
				bsum -= arr[spot][i][0];
				esum -= arr[spot][i][1];
			}
		}
	}
}