#include <iostream>
using namespace std;

class Invoice
{
private:
    string partNumber;
    string partDescription;
    int quantity;
    double pricePerItem;

public:
    Invoice(string pNumber, string pDescription, int qty, double price)
    {
        partNumber = pNumber;
        partDescription = pDescription;
        quantity = (qty > 0) ? qty : 0;
        pricePerItem = (price > 0) ? price : 0.0;
    }

    string getPartNumber() const { return partNumber; }

    string getPartDescription() const { return partDescription; }

    int getQuantity() const { return quantity; }

    double getPricePerItem() const { return pricePerItem; }

    double getInvoiceAmount() const
    {
        return quantity * pricePerItem;
    }
};

int main()
{
    Invoice item("1234", "Hammer", 10, 15.99);

    cout << "Part Number: " << item.getPartNumber() << endl;
    cout << "Part Description: " << item.getPartDescription() << endl;
    cout << "Quantity: " << item.getQuantity() << endl;
    cout << "Price per Item: $" << item.getPricePerItem() << endl;
    cout << "Total Invoice Amount: $" << item.getInvoiceAmount() << endl;

    return 0;
}
