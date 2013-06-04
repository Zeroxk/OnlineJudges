import java.awt.geom.Line2D;
import java.awt.geom.Point2D;
import java.util.ArrayList;
import java.util.Scanner;


public class Exactness_of_Projectile_Hit {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		double pointX = sc.nextDouble();
		double pointY = sc.nextDouble();
		
		Point2D.Double projectile = new Point2D.Double(pointX, pointY);
		
		int polyN = sc.nextInt();
		
		ArrayList<Point2D.Double> polyPoints = new ArrayList<Point2D.Double>();
		for(int i=0; i<polyN; i++) {
			
			double x = sc.nextDouble();
			double y = sc.nextDouble();
			
			Point2D.Double p = new Point2D.Double(x, y);
			
			polyPoints.add(p);
			
		}
		
		double min = Double.MAX_VALUE;
		if(isInside(polyPoints, projectile)) {
			//System.out.println("Inside");
			min = 0;
		}else {
			for(int i=0; i<polyPoints.size(); i++) {
				for(int j=i+1; j<polyPoints.size(); j++) {
					Point2D.Double p1 = polyPoints.get(i);
					Point2D.Double p2 = polyPoints.get(j);
					//System.out.println("Point 1 " + p1.toString() + " Point 2 " + p2.toString());
					
					double m = Line2D.ptSegDist(p1.getX(), p1.getY(), p2.getX(), p2.getY(), projectile.getX(), projectile.getY());
					//System.out.println("Dist from point to line " + m);
					
					if(m < min) min = m;
					
					
				}
			}
		}
		
		System.out.printf("%.3f\n", 2*min);
		//System.out.println("Minimum is " + 2*min);
		
		
	}

	private static boolean isInside(
			ArrayList<Point2D.Double> polyPoints,
			Point2D.Double point) {
			
		int j = polyPoints.size()-1;
		int hits = 0;
		
		for(int i=0; i<polyPoints.size(); i++) {
			Point2D.Double p1 = polyPoints.get(i);
			Point2D.Double p2 = polyPoints.get(j);
			
			if(p1.getY() < point.getY() && p2.getY() >= point.getY()
					|| p2.getY() < point.getY() && p1.getY() >= point.getY() ) {
				
				if( (p1.getX() + (point.getY()-p1.getY())/(p2.getY()-p1.getY())*(p2.getX()-p1.getX())) < point.getX()) {
					hits++;
				}
				
			}
			j = i;
		}
		return hits % 2 == 1;
	}


	
}

