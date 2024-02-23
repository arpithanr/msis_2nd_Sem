package com.msis;

import java.util.Scanner;

public class EvenOddSumAvg {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Scanner sc = new Scanner(System.in);
		
		System.out.println("Enter the number of elements: ");
		int n = sc.nextInt();
		
		int[] num = new int[n];
		int evenSum = 0, oddSum = 0, evenCount = 0, oddCount = 0;
		double evenAverage, oddAverage;
		
		System.out.println("Enter the elements:");
		for(int i =0; i<n; i++)
		{
			num[i] = sc.nextInt();
			
			if(num[i] %2 == 0)
			{
				evenSum = evenSum + num[i];
				evenCount++;
			}else {
				oddSum = oddSum + num[i];
				oddCount++;
			}
		}
		
		evenAverage = (evenCount > 0)? evenSum/ (double)evenCount : 0.0;
		oddAverage = (oddCount > 0)? oddSum/ (double)oddCount : 0.0;
		
		System.out.println("Sum of even numbers: " + evenSum);
		System.out.println("Sum of odd numbers: " +  oddSum);
		System.out.println("Average of even numbers: " + evenAverage);
		System.out.println("Average of odd numbers: " + oddAverage);
	}

}
