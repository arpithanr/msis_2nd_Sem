package com.msis;

public class TestClock {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Clock c1 = new Clock(12, 59, 59, "AM" );
		Clock c2 = new Clock(8, 02, 23, "PM" );
		Clock c3 = new Clock(8, 13, 59, "AM" );
		
		assert(Clock.isValid(c1));
		assert(Clock.isValid(c2) == false);
		assert(Clock.isValid(c3));

	}

}
