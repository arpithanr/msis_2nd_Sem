package pizza;

public class Test_Pizza {
    
    public static void main(String[] args) {
    	
    	Pizza p1 = new Pizza(200, new Rectangle(10.0, 20.0));
    	assert(p1.getPrice() == 200);
		assert(p1.getShape().getArea() == 200);
		Pizza p2 = new Pizza(100, new Circle(3));
		assert(p2.getPrice() == 100);
		assert(p2.getShape().getArea() == 28.278);
	}
}