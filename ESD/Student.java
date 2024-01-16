package msis;

import java.util.Arrays;

public class Student extends Person{
	
	private int numCourses = 0;
	private String[] courses = {};
	private int[] grades = {};
	
	public Student(String name, String address) {
		super(name, address);
		// TODO Auto-generated constructor stub
	}

	public void addCourseGrade(String course, int grade)
	{
		
	}
	
	public void printGrades()
	{
		
	}
	
	public double getAverageGrade()
	{
		double value = 12.34;  
		return value;
	}
}
