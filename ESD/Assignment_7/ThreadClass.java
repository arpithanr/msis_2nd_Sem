package com;

import java.util.*;
public class ThreadClass {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Runnable r1=()->randomAvg();
		Thread t1 = new Thread(r1);
		t1.start();
		try {
			t1.join();
		} catch (Exception e) {
			// TODO: handle exception
		}
		int[] arr = {12, 11, 4, 56, 7, 0, 1, 18};
		char[] ch = "Test string".toCharArray();
		Runnable r2=()->{
		    Arrays.sort(arr);
		    System.out.println("Sorted Ten integers: ");
		    for(int i = 0; i<arr.length; i++)
		    {
		    	System.out.println(arr[i]);
		    }
		    Arrays.sort(ch);
		    System.out.println("Arranged characters: ");
			for(int i = 0; i<ch.length; i++)
		    {
		    	System.out.print(ch[i]);
		    }
			System.out.println();
		};
		Thread t2 = new Thread(r2);
		t2.start();
		try {
			t2.join();
		} catch (Exception e) {
			// TODO: handle exception
		}	 
	}
	
	public static void randomAvg()
	{
		int arr[] = new int[10];
		Random rand = new Random();
		double avg = 0;
		System.out.println("Random Numbers: ");
		for(int i = 0; i<arr.length; i++)
		{
			avg+= arr[i] = rand.nextInt(100);
			System.out.println(arr[i] + " ");
		}
		System.out.println("Average= " + (avg/arr.length) + "\n");
		
	}
}
