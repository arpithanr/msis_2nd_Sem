package pizza;

import java.util.*;

public class Pizza {

    public Pizza() {
    }

    private double price;
    private IShape shape;

    public double getPrice() {
        // TODO implement here
        return price;
    }

    public IShape getShape() {
        // TODO implement here
        return shape;
    }

    public Pizza(double price, IShape shape) {
        // TODO implement here
    	this.price = price;
    	this.shape = shape;
    }

}