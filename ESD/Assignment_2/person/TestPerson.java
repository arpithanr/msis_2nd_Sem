package person;

public class TestPerson {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Student student = new Student("Alice", "123 Main St");
        student.addCourseGrade("Math", 95);
        student.addCourseGrade("Science", 80);
       
        assert(student.getAverageGrade() == 87.5);
        assert(student.toString().equals("Student: Alice (123 Main St)"));

        Teacher teacher = new Teacher("Bob", "456 Elm St");
        teacher.addCourse("English");
        teacher.addCourse("History");

        assert(teacher.toString().equals("Teacher: Bob (456 Elm St)"));
	}

}
