package inheritexample;

public abstract class SensorDevice {
	
	private int id;
	private String name;
	
	public SensorDevice() {
		
	}
	
	public SensorDevice(int id, String name) {
		this.id = id;
		this.name = name;
	}
	
	public int getValue() {
		return 1;
	}
	
	public abstract void normalize();
	
	public abstract void read();

}
