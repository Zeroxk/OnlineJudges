import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;


public class Freckles {

	public static void main(String[] args) {
		int cases = 0;
		Scanner in = new Scanner(System.in);
		cases = in.nextInt();
		
		for (int t = 0; t < cases; t++) {
			
			int freckles;
			freckles = in.nextInt();
			ArrayList<Node> nodes = new ArrayList<Node>();
			for (int i = 0; i < freckles; i++) {
				
				double a,b;
				a = in.nextDouble();
				b = in.nextDouble();
				Node n = new Node(a, b);
				nodes.add(n);
			}
			
			ArrayList<Edge> edges = new ArrayList<Edge>();
			for (int i = 0; i < nodes.size(); i++) {
				Node a = nodes.get(i);
				
				for (int j = i+1; j < nodes.size(); j++) {
					Node b = nodes.get(j);
					double c,d,len;
					c = Math.pow((a.getX()-b.getX()), 2.0);
					d = Math.pow( (a.getY()-b.getY()), 2.0);
					len = Math.sqrt( (c + d) );
					Edge e = new Edge(a, b, len);
					edges.add(e);
				}
			}
			
			ArrayList<Node> tree = new ArrayList<Node>();
			ArrayList<Edge> treeEdges = new ArrayList<Edge>();
			tree.add(nodes.get(0));
			Collections.sort(edges);
			
			double sumLen = 0.0;
			while(tree.size() < nodes.size()) {

				for (Edge e : edges) {
					if(treeEdges.contains(e)) continue;
					Node a = e.getA();
					Node b = e.getB();
					if(tree.contains(a) && tree.contains(b)) continue;

					Node v = tree.contains(a) ? b : a;

					tree.add(v);
					treeEdges.add(e);
					sumLen += e.getLen();
				}
//				sumLen += 0;

			}
			
			System.out.printf("%.2f\n", sumLen);
			
		}
	}

}

class Node{
	double x,y;

	Node(double x, double y) {
		this.x = x;
		this.y = y;
	}

	public double getX() {
		return x;
	}

	public void setX(double x) {
		this.x = x;
	}

	public double getY() {
		return y;
	}

	public void setY(double y) {
		this.y = y;
	}

	@Override
	public boolean equals(Object obj) {
		if (this == obj)
			return true;
		if (obj == null)
			return false;
		if (getClass() != obj.getClass())
			return false;
		Node other = (Node) obj;
		if (Double.doubleToLongBits(x) != Double.doubleToLongBits(other.x))
			return false;
		if (Double.doubleToLongBits(y) != Double.doubleToLongBits(other.y))
			return false;
		return true;
	}

	@Override
	public String toString() {
		return "Node [x=" + x + ", y=" + y + "]";
	}
	
	

}

class Edge implements Comparable<Edge>{
	Node a,b;
	double len;

	public Edge(Node a, Node b, double len) {
		this.a = a;
		this.b = b;
		this.len = len;
	}

	public Node getA() {
		return a;
	}

	public void setA(Node a) {
		this.a = a;
	}

	public Node getB() {
		return b;
	}

	public void setB(Node b) {
		this.b = b;
	}

	public double getLen() {
		return len;
	}

	public void setLen(double len) {
		this.len = len;
	}

	@Override
	public int compareTo(Edge e) {
		if(this.len < e.len) return -1;
		if(this.len == e.len) return 0;
		if(this.len > e.len) return 1;
		return 0;
	}

	@Override
	public String toString() {
		return "Edge [a=" + a + ", b=" + b + ", len=" + len + "]";
	}
	
	
}