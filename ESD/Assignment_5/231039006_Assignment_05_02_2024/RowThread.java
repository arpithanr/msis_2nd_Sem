package matrix;

public class RowThread extends Thread {

    
    RowThread() {
    	
    }
    
    private int rowSum = 0;
    private int row = 0;
    private int arr[][];

    RowThread(int arr[][], int r) 
    {
        this.row = r;
        this.arr = arr;
    }
    
    public void run() 
    {
    	calculateSum();     
    }

    public void calculateSum() {
    	 for(int i =0; i<arr[row].length; i++)
         {
    		 rowSum = rowSum + arr[row][i];
         }
    }

    public int getRowSum() 
    {
        return rowSum;
    }

}