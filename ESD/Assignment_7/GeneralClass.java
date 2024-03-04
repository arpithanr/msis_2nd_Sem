package com;

@FunctionalInterface
interface General{
	int genericTask(int n);
}

public class GeneralClass {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		General num = (n)->fact(n);
		System.out.println("fact of 5 is: " + num.genericTask(5));
		General character = (n)->checkChar(n);
		character.genericTask('@');
		General prime = (n)->checkPrime(n);
		prime.genericTask(20);
		General year = (n)->checkLeapyear(n);
		year.genericTask(1996);
		General pattern = (n)-> printPattern(n);
		pattern.genericTask(4);
	}
	
	public static int fact(int n) {
		// TODO Auto-generated method stub
		int fact = 1;
		for(int i =1; i<=n; i++)
		{
			fact = fact * i;
		}
		return fact;
	}
	
	public static int checkChar(int n)
	{
		if(n >= 65 && n<= 90 || n>= 97 && n<=122)
		{
			System.out.println("Entered value is a charater. ");
		}else if(n>= 48 && n<= 57)
		{
			System.out.println("Entered value is a digit. ");
		}else
			System.out.println("Entered value is a special character. ");
		return 0;	
	}
	
	public static int checkPrime(int n)
	{
		int i = 2;
	    boolean flag = false;
	    while (i <= n / 2) {
	      if (n % i == 0) {
	        flag = true;
	        break;
	      }

	      ++i;
	    }

	    if (!flag)
	      System.out.println(n + " is a prime number.");
	    else
	      System.out.println(n + " is not a prime number.");
		return 1;
	}
	
	public static int checkLeapyear(int n)
	{
		 boolean isLeapYear;

		    // divisible by 4
		    isLeapYear = (n % 4 == 0);

		    // divisible by 4, not by 100, or divisible by 400
		    isLeapYear = isLeapYear && (n % 100 != 0 || n % 400 == 0);

		    if (isLeapYear) {
		      System.out.println(n + " is a leap year.");
		    } else {
		      System.out.println(n + " is not a leap year.");
		    }
		return 0;
	}
	
	public static int printPattern(int n)
	{
		for(int i = 1; i<=n; i++)
		{
			for(int j=1; j<=i; j++)
			{
				System.out.print( i + "\t" );
			}
			System.out.println();
		}
		return 0;
	}
	
}
