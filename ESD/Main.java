package thread_exa;
import java.util.*;
public class Main {
    public static void main(String[] args) {
  
        Scanner inputStrings=new Scanner(System.in);
        
        Thread[] threads = new Thread[3];
       
            String input = inputStrings.nextLine();
            System.out.println("Input: " + input);
            threads[0] = new Thread(() -> {
            	 String sortedString = sortString(input);
            	 System.out.println("Alphabetically sorted: " + sortedString);
            	
            });
            threads[1] = new Thread(() -> {
            	  String reversedString = reverseString(input);
            	  System.out.println("Reversed: " + reversedString);
           	
           });
            threads[2] = new Thread(() -> {
            	String upperCaseString = input.toUpperCase();
            	   System.out.println("Uppercase: " + upperCaseString);
           	
           });

            threads[0].start();
            threads[1].start();
            threads[2].start();    
              
         
            try{
            	threads[0].join();
            	threads[1].join();
            	threads[2].join();
            }
            catch(InterruptedException e)
            {
            	 e.printStackTrace();
            }

    }


    private static String sortString(String input) {
        char[] charArray = input.toCharArray();
        Arrays.sort(charArray);
        return new String(charArray);
    }


    private static String reverseString(String input) {
    	char[] charArray = input.toCharArray();
    	for(int i=0,j=input.length()-1;i<input.length()/2;i++,j--)
    	{
    		char temp;
    		temp=charArray[i];
    		charArray[i]=charArray[j];
    		charArray[j]=temp;
    	}
    	return new String(charArray);
        
    }
}



























