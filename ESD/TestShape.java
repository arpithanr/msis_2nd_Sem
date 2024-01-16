package com.msis;

public class TestShape{

	public static void main(String[] args) {

		Circle c = new Circle(2, "blue", true);
		assert(c.getArea() == 12.568);
		assert(c.getPerimeter() == 12.568);
		assert(c.getColor().equals("blue"));
		assert(c.isFilled() == true);
		
		
		Rectangle r = new Rectangle(2, 4, "yellow", false);
		assert(r.getArea() == 8.0);
		assert(r.getPerimeter() == 12);
		assert(r.isFilled() == false);
		assert(r.getLength() == 4);
		
		Square s = new Square(3, "black", true);
		assert(s.getArea() == 9.0);
		assert(s.getColor().equals("black"));
		assert(r.isFilled() == false);
	}
}