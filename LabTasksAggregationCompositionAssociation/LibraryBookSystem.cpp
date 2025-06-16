/*
				Question 3: Aggregation- Library and Books System
 Design a library system using Aggregation between Library and Book classes.
 Requirements:
	 • Book class: title, author, price, pages
	 • Library class: name, collection of Book objects
	 • Books can exist independently of Library
	 • Library uses existing Book objects
 Simple Math Operations:
	 (a) Total library value: Total Value = Price of all books
	 (b) Average book price: Average Price = Total Value
	 Number of books
	 (c) Average pages: Average Pages = Sum of all pages
	 Number of books
	 (d) Find most and least expensive books
 Tasks:
	 • Create a library with 6 books
	 • Calculate total collection value
	 • Find books above and below average price
	 • Display library statistics
*/

#include <iostream>
#include <string>
using namespace std;

// Book class: Stores book details
class Book {
public:
    string title;    // Book title
    string author;   // Book author
    double price;    // Book price
    int pages;       // Number of pages

    // Constructor to initialize book
    Book(string t, string a, double p, int pg) {
        title = t;
        author = a;
        price = p;
        pages = pg;
    }
};

// Library class: Aggregates Book objects
class Library {
public:
    string name;          // Library name
    Book* books[10];      // Array of book pointers (aggregation)
    int book_count;       // Number of books

    // Constructor to initialize library
    Library(string n) {
        name = n;
        book_count = 0;
    }

    // Add book to library collection
    void add_book(Book* b) {
        books[book_count] = b;
        book_count++;
    }

    // Calculate total library value
    double total_value() {
        double sum = 0.0;
        for (int i = 0; i < book_count; i++) {
            sum += books[i]->price;
        }
        return sum;
    }

    // Calculate average book price
    double average_price() {
        if (book_count == 0) return 0.0;
        return total_value() / book_count;
    }

    // Calculate average pages
    double average_pages() {
        if (book_count == 0) return 0.0;
        double sum = 0.0;
        for (int i = 0; i < book_count; i++) {
            sum += books[i]->pages;
        }
        return sum / book_count;
    }

    // Find most and least expensive books
    void find_extreme_prices(Book*& most_expensive, Book*& least_expensive) {
        if (book_count == 0) return;
        most_expensive = books[0];
        least_expensive = books[0];
        for (int i = 1; i < book_count; i++) {
            if (books[i]->price > most_expensive->price) most_expensive = books[i];
            if (books[i]->price < least_expensive->price) least_expensive = books[i];
        }
    }

    // Display books above and below average price
    void display_price_comparison() {
        double avg_price = average_price();
        cout << "\nBooks Above Average Price ($" << avg_price << "):\n";
        for (int i = 0; i < book_count; i++) {
            if (books[i]->price > avg_price) {
                cout << "  " << books[i]->title << " by " << books[i]->author << ": $" << books[i]->price << endl;
            }
        }
        cout << "\nBooks Below Average Price ($" << avg_price << "):\n";
        for (int i = 0; i < book_count; i++) {
            if (books[i]->price <= avg_price) {
                cout << "  " << books[i]->title << " by " << books[i]->author << ": $" << books[i]->price << endl;
            }
        }
    }

    // Display library statistics
    void display_stats() {
        cout << "\nLibrary: " << name << endl;
        cout << "Total Books: " << book_count << endl;
        cout << "Total Collection Value: $" << total_value() << endl;
        cout << "Average Book Price: $" << average_price() << endl;
        cout << "Average Pages: " << average_pages() << endl;
        Book* most_exp = nullptr;
        Book* least_exp = nullptr;
        find_extreme_prices(most_exp, least_exp);
        cout << "Most Expensive Book: " << most_exp->title << " ($" << most_exp->price << ")" << endl;
        cout << "Least Expensive Book: " << least_exp->title << " ($" << least_exp->price << ")" << endl;
    }
};

// Main program
int main() {
    // Create 6 books
    Book b1("The Great Gatsby", "F. Scott Fitzgerald", 12.99, 180);
    Book b2("1984", "George Orwell", 15.50, 328);
    Book b3("To Kill a Mockingbird", "Harper Lee", 18.75, 281);
    Book b4("Pride and Prejudice", "Jane Austen", 9.99, 432);
    Book b5("Moby Dick", "Herman Melville", 22.00, 635);
    Book b6("The Catcher in the Rye", "J.D. Salinger", 14.25, 277);

    // Create library and add books
    Library lib("Central Library, QAU");
    lib.add_book(&b1);
    lib.add_book(&b2);
    lib.add_book(&b3);
    lib.add_book(&b4);
    lib.add_book(&b5);
    lib.add_book(&b6);

    // Display library statistics
    lib.display_stats();

    // Display books above and below average price
    lib.display_price_comparison();

    return 0;
}