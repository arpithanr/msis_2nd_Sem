package com.msis;

/**
 * 
 */
public class Clock {

    /**
     * Default constructor
     */
    public Clock() {
    }

    /**
     * 
     */
    private int hr;
    private int min;
    private int sec;
    private String ampm;

    /**
     * @param hr 
     * @param min 
     * @param sec 
     * @param ampm
     */
    public  Clock(int hr, int min, int sec, String ampm) {
        // TODO implement here
    	setHr(hr);
    	setMin(min);
    	setSec(sec);
    	setAmPm(ampm);
    }

    /**
     * @return
     */
    public int getHr() {
        // TODO implement here
        return this.hr;
    }

    /**
     * @return
     */
    public int getMin() {
        // TODO implement here
        return this.min;
    }

    /**
     * @return
     */
    public int getSec() {
        // TODO implement here
        return this.sec;
    }
	/**
     * @return
     */
    public String getAmPm() {
        // TODO implement here
        return this.ampm;
    }

    /**
     * @param hr 
     * @return
     */
    public void setHr(int hr) {
        // TODO implement here
       this.hr = hr;
    }

    /**
     * @param min 
     * @return
     */
    public void setMin(int min) {
        // TODO implement here
       this.min = min;
    }

    /**
     * @param sec 
     * @return
     */
    public void setSec(int sec) {
        // TODO implement here
      this.sec = sec;
    }

    /**
     * @param ampm 
     * @return
     */
    public void setAmPm(String ampm) {
        // TODO implement here
       this.ampm = ampm;
    }

    @Override
	public String toString() {
		return "Clock [hr=" + hr + ", min=" + min + ", sec=" + sec + ", ampm=" + ampm + "]";
	}

	/**
     * @param c1 
     * @return
     */
    public static boolean isValid(Clock c1) {
        // TODO implement here
    	if(c1.getHr()<= 12 && c1.getMin()<= 59 && c1.getSec()<= 59)
    	{
    		if(c1.getAmPm().equals("AM") || c1.getAmPm().equals("PM"))
    		{
    			return true;
    		}
    	}
        return false;
    }
}