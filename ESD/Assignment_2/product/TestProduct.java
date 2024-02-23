package product;

public class TestProduct {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		ProductWarehouse warehouse = new ProductWarehouse("Electronics", 100);
		assert(warehouse.getName().equals("Electronics"));
		assert(warehouse.getCapacity() == 100);
		assert(warehouse.getBalance() == 0.0);
		assert(warehouse.howMuchSpaceLeft() == 100);
		
		warehouse.addToWarehouse(50);
		assert(warehouse.getBalance() == 50);
		assert(warehouse.howMuchSpaceLeft() == 50);
		
		double taken = warehouse.takeFromWarehouse(30);
		assert(taken == 30);
		assert(warehouse.getBalance() == 20);
	}

}
