#include <iostream>
#include <vector>
using namespace std;

class Book
{
private:
    string author;
    string title;
    double price;
    string publisher;
    int stock;

public:
    Book(string auth, string tit, double pr, string pub, int stk)
    {
        author = auth;
        title = tit;
        price = pr;
        publisher = pub;
        stock = stk;
    }

    bool isMatch(string tit, string auth)
    {
        return (title == tit && author == auth);
    }

    void displayDetails()
    {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Price: $" << price << endl;
        cout << "Publisher: " << publisher << endl;
        cout << "Stock: " << stock << " copies available" << endl;
    }

    void purchaseBook(int quantity)
    {
        if (quantity <= stock)
        {
            double totalCost = quantity * price;
            cout << "Total Cost: $" << totalCost << endl;
            stock -= quantity;
        }
        else
        {
            cout << "Required copies not in stock" << endl;
        }
    }
};

int main()
{
    vector<Book> inventory = {
        Book("J.K. Rowling", "Harry Potter", 29.99, "Bloomsbury", 10),
        Book("George Orwell", "1984", 19.99, "Secker & Warburg", 5),
        Book("J.R.R. Tolkien", "The Hobbit", 25.99, "HarperCollins", 8)};

    string searchTitle, searchAuthor;
    cout << "Enter book title: ";
    getline(cin, searchTitle);
    cout << "Enter book author: ";
    getline(cin, searchAuthor);

    bool found = false;
    for (Book &b : inventory)
    {
        if (b.isMatch(searchTitle, searchAuthor))
        {
            found = true;
            b.displayDetails();
            cout << "Enter number of copies required: ";
            int copies;
            cin >> copies;
            b.purchaseBook(copies);
            break;
        }
    }

    if (!found)
    {
        cout << "Book not available." << endl;
    }

    return 0;
}
