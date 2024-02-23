package matrix;

import java.util.Random;

public class MainThread {
	
   public static void main(String[] args)
   {	
	   int arr1[][] = new int[3][4];
	   
	   
	   populateMatrix(arr1);
	   printMatrix(arr1);

	   System.out.println( "Sum without Threads: " + printSum(arr1));
	   System.out.println("--------------------------------");
	   RowThread r1 = new RowThread(arr1, 0);
	   r1.start();
	   RowThread r2 = new RowThread(arr1, 1);
	   r2.start();
	   RowThread r3 = new RowThread(arr1, 2);
	   r3.start();
	   
	   try {
		r1.join();
		r2.join();
		r3.join();
	} catch (InterruptedException e) {
		// TODO Auto-generated catch block
		e.printStackTrace();
	}
	   
	   System.out.println("Sum of Row1 is " + r1.getRowSum());
	   System.out.println("Sum of Row2 is " +r2.getRowSum());
	   System.out.println("Sum of Row3 is " +r3.getRowSum());
	   
	   int total = 0;
	   total = r1.getRowSum() + r2.getRowSum() + r3.getRowSum();
	   System.out.println("Total sum with thread " + total);

   }

    public static void printMatrix(int arr[][]) 
    {
        for(int i =0 ; i<3; i++)
        {
        	for(int j=0; j<4; j++)
        	{
        		System.out.print(arr[i][j]+ " \t");
        	}
        	System.out.print("\n");
        }
    }

    public static void populateMatrix(int arr[][]) 
    {
    	Random rand = new Random();
    	
    	 for(int i =0 ; i<3; i++)
         {
         	for(int j=0; j<4; j++)
         	{
         		arr[i][j] = rand.nextInt(100);
         	}
         	System.out.println("\n");
         }
        
    }

    public static int printSum(int arr[][]) 
    {
        int sum =0;
        for(int i =0 ; i<3; i++)
        {
        	for(int j=0; j<4; j++)
        	{
        		sum = sum + arr[i][j];
        	}
        }
        return sum;
    }

}