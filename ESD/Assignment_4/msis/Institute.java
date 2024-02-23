package msis;

import java.util.ArrayList;
import java.util.List;

public class Institute {
	
	 private String instituteName;
	 private List<Department> departments;
	 
	 public Institute(String instituteName) {
	        this.instituteName = instituteName;
	        this.departments = new ArrayList<>();
	    }

	 public void addDepartment(Department department) {
	        this.departments.add(department);
	    }

	 public int getTotalStudents() {
	        int total = 0;
	        for (Department department : departments) {
	            total += department.getStudents().size();
	        }
	        return total;
	 }

}
