package pizza;

import java.util.*;

/**
 * 
 */
public class Rectangle implements IShape {

    /**
     * Default constructor
     */
    public Rectangle() {
    }
    
    private double height;
    private double width;

    public Rectangle(double height, double width) {
		super();
		this.height = height;
		this.width = width;
	}
    
    @Override
    public double getArea() {
        // TODO implement here
        return height*width;
    }
}