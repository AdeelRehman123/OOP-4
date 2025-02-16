#include <iostream>
#include <vector>
using namespace std;

class MenuItem {
public:
    string name;
    string type;
    double price;

    MenuItem(string n, string t, double p) : name(n), type(t), price(p) {}
};

class CoffeeShop {
private:
    string name;
    vector<MenuItem> menu;
    vector<string> orders;

public:
    CoffeeShop(string shopName, vector<MenuItem> shopMenu) : name(shopName), menu(shopMenu) {}

    string addOrder(string itemName) {
        for (MenuItem &item : menu) {
            if (item.name == itemName) {
                orders.push_back(itemName);
                return "Order added: " + itemName;
            }
        }
        return "This item is currently unavailable";
    }

    string fulfillOrder() {
        if (!orders.empty()) {
            string item = orders.front();
            orders.erase(orders.begin());
            return "The " + item + " is ready";
        }
        return "All orders have been fulfilled";
    }

    vector<string> listOrders() {
        return orders;
    }

    double dueAmount() {
        double total = 0.0;
        for (string &order : orders) {
            for (MenuItem &item : menu) {
                if (item.name == order) {
                    total += item.price;
                    break;
                }
            }
        }
        return total;
    }

    string cheapestItem() {
        if (menu.empty()) return "No items available";
        MenuItem *cheapest = &menu[0];
        for (MenuItem &item : menu) {
            if (item.price < cheapest->price) {
                cheapest = &item;
            }
        }
        return cheapest->name;
    }

    vector<string> drinksOnly() {
        vector<string> drinks;
        for (MenuItem &item : menu) {
            if (item.type == "drink") {
                drinks.push_back(item.name);
            }
        }
        return drinks;
    }

    vector<string> foodOnly() {
        vector<string> foods;
        for (MenuItem &item : menu) {
            if (item.type == "food") {
                foods.push_back(item.name);
            }
        }
        return foods;
    }
};

int main() {
    vector<MenuItem> menu = {
        MenuItem("Coffee", "drink", 2.5),
        MenuItem("Tea", "drink", 1.5),
        MenuItem("Sandwich", "food", 5.0),
        MenuItem("Cake", "food", 3.0)
    };

    CoffeeShop shop("Java Haven", menu);

    cout << shop.addOrder("Coffee") << endl;
    cout << shop.addOrder("Sandwich") << endl;
    cout << shop.addOrder("Burger") << endl;

    cout << "Due amount: $" << shop.dueAmount() << endl;

    cout << shop.fulfillOrder() << endl;
    cout << shop.fulfillOrder() << endl;
    cout << shop.fulfillOrder() << endl;
    
    cout << "Cheapest item: " << shop.cheapestItem() << endl;

    vector<string> drinks = shop.drinksOnly();
    cout << "Drinks: ";
    for (string d : drinks) cout << d << " ";
    cout << endl;

    vector<string> foods = shop.foodOnly();
    cout << "Foods: ";
    for (string f : foods) cout << f << " ";
    cout << endl;

    return 0;
}
