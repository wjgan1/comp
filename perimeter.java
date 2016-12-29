import java.io.*;
import java.util.*;

public class perimeter
{
	static int n;
	static File in1 = new File("_data.in");
	static File out1 = new File("_data.out");
	static File in2 = new File("perimeter.in");
	static File out2 = new File("perimeter.out");

	public static void main (String [] args) throws IOException
	{
		BufferedReader fin = new BufferedReader(new FileReader(in1));
		PrintWriter fout = new PrintWriter(out1);
		n = Integer.parseInt(fin.readLine());

		int [] x = new int[n];
		int [] y = new int[n];
		for (int i = 0; i < n; ++i)
		{
			StringTokenizer st = new StringTokenizer(in.readLine());
			x[i] = Integer.parseInt(st.nextToken());
			y[i] = Integer.parseInt(st.nextToken());
		}

	}
}