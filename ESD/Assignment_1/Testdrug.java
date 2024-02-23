
import java.util.*;

public class Testdrug
{
	
	public static void main(String[] args)
     {
     	Drug_shop arr[]=new Drug_shop[5];
        Scanner input=new Scanner(System.in);
         
         int set=0;
         int n;
         int id;
         String name;
     

        arr[0]=new Drug_shop(1,"dolo",5,10,"star company");
        arr[1]=new Drug_shop(2,"paracetamal",10,20,"quality company");
        arr[2]=new Drug_shop(3,"saridon",3,25,"Max company");
        arr[3]=new Drug_shop(4,"vicks",8,20,"costic company");
        arr[4]=new Drug_shop(5,"painlock",23,16,"prist company");

      
        do 
     	{
     		System.out.println("enter the 1 to search drug  and 2 exit");
     		n=input.nextInt();

        if(n==1)
        {
           System.out.println("enter the drug_id");
           id=input.nextInt();
           System.out.println("enter the drug_name");
           name=input.next();
           

          for(int i=0;i<5;i++)
          {
           set=arr[i].search(id,name);
           if(set==1)
            break;
          }
           if(set==0)
            System.out.println("the drug is not available");

      }
      }while(n!=2);
     }
}