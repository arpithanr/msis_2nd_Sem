package msis;

public class University {
	
	public static void main(String[] args) {

        // Create the Institute object
        Institute msis = new Institute("MSIS");

        // Create departments
        Department es = new Department("ES");
        Department vlsi = new Department("VLSI");

        // Create students and add them to departments
        es.addStudent(new Student("John Doe", "ES123", "ES"));
        es.addStudent(new Student("Jane Doe", "ES456", "ES"));
        es.addStudent(new Student("Alice Smith", "ES789", "ES"));
        es.addStudent(new Student("Bob Jones", "ES012", "ES"));

        vlsi.addStudent(new Student("Michael Li", "VLSI321", "VLSI"));
        vlsi.addStudent(new Student("Emily Chen", "VLSI098", "VLSI"));
        vlsi.addStudent(new Student("David Wang", "VLSI567", "VLSI"));
        vlsi.addStudent(new Student("Sarah Kim", "VLSI432", "VLSI"));

        // Add departments to the institute
        msis.addDepartment(es);
        msis.addDepartment(vlsi);

        // Get total students
        int totalStudents = msis.getTotalStudents();

        System.out.println("Total students in MSIS: " + totalStudents);
        
        assert(totalStudents == 8);
        
    }

}
