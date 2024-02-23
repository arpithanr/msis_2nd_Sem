package basic.calc;

public class TestCalculator {

	 	private static void testAddition() {

	        Calculator calc = BasicCalculator.getInstance();
	        assert(calc.put(10).put(25).add().read() == 35);
	        assert (calc.put(100).put(-25).add().read() == 75);
	        assert(calc.put(5).put(40).add().read() == 45);
	    }
	 
	    private static void testSubtraction() {
	    	Calculator calc = BasicCalculator.getInstance();
	    	assert(calc.put(80).put(40).sub().read() == 40);
	    	assert(calc.put(40).put(80).sub().read() == -40);
	    }
	    
	    private static void testMultiplication() {
	    	Calculator calc = BasicCalculator.getInstance();
	    	assert(calc.put(10).put(12).mul().read() == 120);
	    }

	    private static void testDivision() {
	        Calculator calc = BasicCalculator.getInstance();
	        assert(calc.put(80).put(40).div().read() == 2);
	        assert(calc.put(80).put(40).clear().put(100).div().read() == 0);
	    }
	    
	    private static void testNegotion() {
	        Calculator calculator = BasicCalculator.getInstance();
	        assert(calculator.put(5).neg().read()== -5);
	    }

	    private static void testClear() {
	        Calculator calculator = BasicCalculator.getInstance();
	        assert(calculator.put(4).clear().read() == 0);
	    }

	    private static void testClearAll() {
	        Calculator calculator = BasicCalculator.getInstance();
	        assert(calculator.put(4).add().put(2).clearAll().read() == 0);
	    }

	    public static void main(String[] args) {
	        testAddition();
	        testSubtraction();
	        testMultiplication();
	        testDivision();
	        testNegotion();
	        testClear();
	        testClearAll();
	    }

}
