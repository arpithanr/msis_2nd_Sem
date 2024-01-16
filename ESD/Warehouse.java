package product;

public class Warehouse {
	
	private double capacity;
	private double balance;
	
	public Warehouse(double capacity) {
		super();
		this.capacity = capacity;
	}

	public double getCapacity() {
		return capacity;
	}

	public double getBalance() {
		return balance;
	}
	
	public double howMuchSpaceLeft() {
		return capacity;
	}
	
	public void addToWarehouse(double amount)
	{
		
	}
	
	public double takeFromWarehouse(double amount)
	{
		return amount;
	}

	@Override
	public String toString() {
		return "Warehouse [capacity=" + capacity + ", balance=" + balance + "]";
	}
	
	

}
