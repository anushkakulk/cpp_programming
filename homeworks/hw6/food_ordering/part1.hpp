/*
Anushka Kulkarni
6/18/2023
c++ API header files to represent a food delivery system
CRC cards and description included in submission
*/
#include <string>
#include <vector>

using namespace std;

class Restaurant
{
public:
    string name;
    string address;
    pair<int, int> hoursOfOperation; // the int shoudl be from 0 to 23 w/ first being open hour, second being close hour
    vector<Order> orders;            // list of orders
    Menu currMenu;                   // restaurant's menu

    Restaurant(const string &name, const string &address, const pair<int, int> &hoursOfOperation);

    // adds the given item to the menu
    void addFoodToMenu(FoodItem foodItem);
    // deletes the given item from the menu
    void deleteFoodFromMenu(FoodItem foodItem);
    // takes in the order, makes sure its valid, then creates a Delivery object for the order
    void confirmDelivery(Order order);
};

class Customer
{
public:
    string name;
    string address;
    Cart cart;
    UserAccount acc;

    Customer(const string &name, const string &address);

    // updates favorite Food in User Acc: if the given item is in the acc list then it delets it, otherwise it adds to the acc list
    void favoriteFood(FoodItem foodItem);
    // takes in a Restaurant and gets that Restauarnts menu
    void viewMenu(Restaurant restaurant);
    // makes an order from all items in this customer's cart
    void placeOrder();
    // updates cart: if the given item is in the cart's list if food then it delets it, otherwise it adds to the cart
    void updateCart(FoodItem foodItem);
    // returns the status of any Delivery the customer is associated with
    void trackDelivery();
};

class Menu
{
public:
    vector<FoodItem> items; // all items on the menu
    Restaurant src;         // this menu's source restaurant

    Menu(const Restaurant &src);

    // adds given item to menu
    void addItemToMenu(FoodItem foodItem);
    // deleted given item from menu
    void deleteItemFromMenu(FoodItem foodItem);
};

// states of a delivery
enum class TrackerState
{
    PENDING,
    IN_TRANSIT,
    DELIVERED,
    CANCELED
};
class Delivery
{
public:
    int order_id; // unique num for this delivery
    string origin_address;
    string dest_address;
    TrackerState tracker; // the current state of this delivery

    Delivery(int order_id, const string &origin_address, const string &dest_address, TrackerState tracker);

    void trackDelivery();            // returns tracker state
    void updateStatus(TrackerState); // updates this Delivery's tracker status
};

class FoodItem
{
private:
    string name;
    int price;
    vector<string> ingredients; // list of ingerdeients in item
    string desc;

public:
    FoodItem(const string &name, int price, const vector<string> &ingredients, const string &desc);

    // food getters and setters
    string getName();
    int getPrice();
    vector<string> getIngredients();
    string getDescription();
    // all setters can only be done by restaurants
    void setName(const string &newName);
    void setPrice(int newPrice);
    void setIngredients(const vector<string> &newIng);
    void setDescription(const string &newDesc);
};

class UserAccount
{
private:
    Customer user; // src user
    int payment;   // credit card num
    vector<FoodItem> favorites;

public:
    UserAccount(const Customer &user, int payment);

    void addToFavorites(FoodItem foodItem);      // adds given to favs vector
    void removeFromFavorites(FoodItem foodItem); // removes given from favs vector
    void viewFavorites();
    void validatePayment(Order o); // takes in the order and does any payment validation
};

class Cart
{
public:
    vector<FoodItem> curr_items;

    Cart();
    // editing given item in cart
    void addToCart(FoodItem foodItem);
    void removeFromCart(FoodItem foodItem);
    // called when user places order, the method makes an Order from items in this cart
    void makeOrderFromCart();
};

class Order
{
public:
    Cart items; // all items bought
    int cost;   // sum of itesm in cart
    Customer placed_by;
    Restaurant food_by;

    Order(const Cart &items, int cost, const Customer &placed_by, const Restaurant &food_by);

    // displays all the items, cost, placed_by, and restaurant of this order
    void viewDetails();
};
