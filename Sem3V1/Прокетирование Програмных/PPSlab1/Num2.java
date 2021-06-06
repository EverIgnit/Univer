public class Num2 {
	public static void main(String[] args) {
		int n = 1, n2 = 1;
		double acc=0.001,x, Sum = 0, Temp = 1, ex;
		x = Double.parseDouble(args[0]);
		ex = Math.pow(Math.E, x);
		acc = Double.parseDouble(args[1]);
		while (Temp>= acc) {
			Sum = Sum + Temp;
			Temp = (Math.pow(x,n)/n2);
			n = n + 1;
			n2 = n2*n;
		}
		//if (ex - Sum > Sum + Temp  - ex){
		//	Sum = Sum + Temp;
		//}
		System.out.println("Sum: " + Sum);
		System.out.println("ex: " + ex);
	}
}