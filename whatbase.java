import java.io.*;
import java.util.*;

public class whatbase
{
	public static void main (String [] args) throws IOException	
	{
		BufferedReader in = new BufferedReader(new FileReader("data.in"));
		/*
		PrintWriter out = new PrintWriter(new File("data.in"));
		int N = 10000;
		out.println(N);
		for (int i = 0; i < N; ++i)
		{
			out.println((int)(Math.random()*700+200) + " " + (int)(Math.random()*700+200));
		}
		out.close();
		*/
		PrintWriter out = new PrintWriter(new File("data.out"));
		//sSystem.out.println("asdf");
		int x = Integer.parseInt(in.readLine());

		for (int i = 0; i < x; ++i)
		{
			//System.out.println("asdf");
			StringTokenizer st = new StringTokenizer(in.readLine());
			String a = st.nextToken();
			String b = st.nextToken();
			int c = Integer.parseInt(a.charAt(0) + "");
			int d = Integer.parseInt(a.charAt(1) + "");
			int e = Integer.parseInt(a.charAt(2) + "");
			int f = Integer.parseInt(b.charAt(0) + "");
			int g = Integer.parseInt(b.charAt(1) + "");
			int h = Integer.parseInt(b.charAt(2) + "");
			boolean asdf = false;
			for (int j = 10; j <= 15000; ++j)
			{
				double tmp1 = c*j*j+d*j+e;
				double tmp2 = (-1*g+Math.sqrt(g*g-4*(h-tmp1)*f))/(2*f);
				if (tmp2%1.0 == 0.0)
				{
					asdf = true;
					out.println(j + " " + (int)tmp2);
					break;
				}
			}
			if (!asdf)
				out.println("no answer");
		}
		out.close();
	}
}