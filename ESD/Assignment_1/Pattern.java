package com.msis;

import java.util.*;

public class Pattern {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Scanner sc = new Scanner(System.in);
		
		System.out.println("Enter the value of n: ");
		int n = sc.nextInt();
		
		for(int i = 1; i<=n; i++)
		{
			for(int j=1; j<=i; j++)
			{
				System.out.print( i + "\t" );
			}
			System.out.println();
		}

	}

}
