package product;

public class Warehouse {
	
	private double capacity;
	private double balance;
	
	public Warehouse(double capacity) {
		super();
		this.capacity = capacity;
		this.balance = 0.0;
	}

	public double getCapacity() {
		return capacity;
	}

	public double getBalance() {
		return balance;
	}
	
	public double howMuchSpaceLeft() {
		double spaceLeft = capacity - balance;
		return spaceLeft;
	}
	
	public void addToWarehouse(double amount)
	{
		if(amount <= howMuchSpaceLeft())
		{
			balance = balance + amount;
		}else
		{
			System.out.println("Not enough space in the warehouse");
		}
	}
	
	public double takeFromWarehouse(double amount)
	{
		if(amount <= balance)
		{
			balance = balance - amount;
			return amount;
		}else
		{
			System.out.println("Not enough items in the warehouse");
			return 0.0;
		}
	}

	@Override
	public String toString() {
		return "Warehouse with capacity=" + capacity + ", balance=" + balance;
	}
	
	

}
