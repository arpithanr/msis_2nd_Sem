package com;

public class TestBook {

    public static void main(String[] args) {
        // Create an author
        Author author = new Author("John Doe", "johndoe@example.com", 'M');

        // Create books using both constructors
        Book book1 = new Book("The Lord of the Rings", author, 20.99);
        Book book2 = new Book("The Hitchhiker's Guide to the Galaxy", author, 15.50, 2);

        // Test getters and setters
        assert(book1.getName().equals("The Lord of the Rings"));
        assert(book1.getPrice() == 20.99);
        assert(book1.getQty() == 0);

        book1.setPrice(19.99);
        book2.setQty(1);
        
        assert(book1.getPrice() == 19.99);
        assert(book2.getQty() == 1);
        
    }
}

