package com.msis;

import java.util.*;

/**
 * 
 */
public class Drug {

    /**
     * Default constructor
     */
    public Drug() {
    }

    /**
     * 
     */
    private int drug_id;                                                                                                                                                                                                                 
    private String drug_name;

    /**
     * 
     */
    private int price;

    /**
     * 
     */
    private String manufacturer;

    /**
     * 
     */
    private int stock_position;

    /**
     * @param int drug_id 
     * @param String drug_name 
     * @param int price 
     * @param String manufacturer 
     * @param int stock_position 
     * @return
     */
    public Drug(int drug_id,  String drug_name, int price, String manufacturer, int stock_position) {
        // TODO implement here
        
    }

    /**
     * @param int drug_id 
     * @param String drug_name
     */
    public Drug( int drug_id,  String drug_name) {
        // TODO implement here
    }

    /**
     * @return
     */
    public int getDrug_id() {
        // TODO implement here
        return 0;
    }

    /**
     * @return
     */
    public String getDrug_name() {
        // TODO implement here
        return "";
    }

    /**
     * @return
     */
    public int getPrice() {
        // TODO implement here
        return 0;
    }

    /**
     * @return
     */
    public String getManufacturer() {
        // TODO implement here
        return "";
    }

    /**
     * @return
     */
    public int getStock_position() {
        // TODO implement here
        return 0;
    }

    /**
     * @param int drug_id 
     * @return
     */
    public void setDrug_id( int drug_id) {
        // TODO implement here
    }

    /**
     * @param String drug_name 
     * @return
     */
    public void setDrug_name(String drug_name) {
        // TODO implement here
       
    }

    /**
     * @param int price 
     * @return
     */
    public void setPrice(int price) {
        // TODO implement here
    }

    /**
     * @param String manufacturer 
     * @return
     */
    public void setManufacturer(String manufacturer) {
        // TODO implement here
    }

    /**
     * @param int stock_position 
     * @return
     */
    public void setStock_position(int stock_position) {
        // TODO implement here
    }

    /**
     * @param int drug_id 
     * @param String drug_name 
     * @return
     */
    public int searchById(int drug_id,String drug_name) {
        // TODO implement here
        return 0;
    }

    /**
     * @param int drug_id 
     * @return
     */
    public String isAvailable(int drug_id) {
        // TODO implement here
        return "";
    }

    /**
     * @return
     */
    public void getDetailsOfDrug() {
        // TODO implement here
      
    }

    /**
     * @param int drug_id 
     * @return
     */
    public int totalCost(int drug_id) {
        // TODO implement here
        return 0;
    }

    /**
     * @return
     */
    public String toString() {
        // TODO implement here
        return "";
    }

}