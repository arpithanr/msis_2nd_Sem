package msis;

public class Student {
	
	private String name;
	private String id;
	private String department_name;
	
	public Student(String name, String id, String department_name) {
		super();
		this.name = name;
		this.id = id;
		this.department_name = department_name;
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public String getId() {
		return id;
	}

	public void setId(String id) {
		this.id = id;
	}

	public String getDepartment_name() {
		return department_name;
	}

	public void setDepartment_name(String department_name) {
		this.department_name = department_name;
	}

	@Override
	public String toString() {
		return "Student [name=" + name + ", id=" + id + ", department_name=" + department_name + "]";
	}
}
