
import java.util.*;
public class Drug_shop {

Scanner input=new Scanner(System.in);
    

    public int drug_id;
    public String drug_name;
    public int drug_price;
    public int stock_quantity;
    public String manufacturer;

    public Drug_shop(int drug_id,String drug_name,int drug_price,int stock_quantity,String manufacturer) 
    {
        
        this.drug_id=drug_id;
        this.drug_name=drug_name;
        this.drug_price=drug_price;
        this.stock_quantity=stock_quantity;
        this.manufacturer=manufacturer;
 }

  
    public void setStock(int stock)
     {
        
        stock_quantity=stock;
    }

   
    public void setPrice(int price) 
    {
        drug_price=price;
    }

   
    public int getPrice() {
        
        return drug_price;
    }

    public int getStock() {
        
        return stock_quantity;
    }

    
    public int search(int drugid,String drugname) 
    {
        if(drug_id==drugid && (drug_name.equals(drugname)))
        {
           System.out.println("The drug is available and the information about stock is:");
           System.out.println("drug id:"+drug_id+'\n'+"drug_name:"+drug_name+'\n'+"drug_price:"+drug_price+'\n'+"stock_quantity:"+stock_quantity+'\n'+"manufacturer:"+manufacturer+'\n');
           System.out.println("enter how many drugs you required");
              int n=input.nextInt();

              if(n<=stock_quantity)
              {
                System.out.println("The cost for total drug is"+(n*drug_price));
                stock_quantity=stock_quantity-n;
                return 1;
              }

              else  
              {
                System.out.println("The stock what you are entered is more than available stock");
                return 1;
         }
}

 else  
    return 0;

}
}