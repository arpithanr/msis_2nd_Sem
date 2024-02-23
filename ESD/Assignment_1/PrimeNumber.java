package com.msis;

import java.util.*;

public class PrimeNumber {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Scanner sc = new Scanner(System.in);
		
		System.out.println("Enter the number of elements: ");
		int n = sc.nextInt();
		
		int arr[] = new int[n];
		System.out.println("Enter the elements: ");
		for(int i =0; i<n; i++)
		{
			arr[i] = sc.nextInt();
		}
		
		System.out.println("Prime numbers in the given array: ");
		for(int num: arr)
		{
			if(isPrime(num))
			{
				System.out.println(num + " ");
			}
		}

	}
	
	public static boolean isPrime(int num)
	{
		if(num <= 1)
		{
			return false;
		}
		for(int i=2; i<= Math.sqrt(num); i++)
		{
			if(num%i == 0)
			{
				return false;
			}
		}
		return true;		
	}

}
