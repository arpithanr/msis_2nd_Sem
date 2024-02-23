package pizza;

import java.util.*;

public class Circle implements IShape {

    /**
     * Default constructor
     */
    public Circle() {
    }
    private double radius;
    
    public Circle(double radius) {
		super();
		this.radius = radius;
	}

    @Override
	public double getArea() {
        // TODO implement here
        return 3.142*radius*radius;
    }
}