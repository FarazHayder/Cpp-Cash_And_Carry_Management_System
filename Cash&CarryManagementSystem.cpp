// Project: Cash & Carry Management System
// Made By: Faraz Hayder

#include <iostream>
#include <windows.h>
using namespace std;

class Product
{
protected:
    string name;
    string supplier;
    int id;
    int quantity;        // Quantity currently in inventory
    int orderedQuantity; // Quantity in which the product is ordered
    float price;         // Current Price
    float updatedPrice;  // Price to be after product take
    int cart;            // Quantity of this product in cart

public:
    // Constructors
    Product()
    {
        name = "";
        supplier = "";
        id = 0;
        quantity = 0;
        orderedQuantity = 0;
        price = 0.0;
        updatedPrice = 0.0;
        cart = 0;
    }
    Product(string name, string supplier, int id, int quantity, float price)
    {
        this->name = name;
        this->supplier = supplier;
        this->id = id;
        while (id < 1) // input validation
        {
            cout << "Invalid input." << endl;
            cout << "Enter Product ID: ";
            cin >> id;
        }
        this->quantity = quantity;
        while (quantity < 0) // input validation
        {
            cout << "Invalid input." << endl;
            cout << "Enter quantity: ";
            cin >> quantity;
        }
        orderedQuantity = 0;
        this->price = price;
        while (price < 0) // input validation
        {
            cout << "Invalid input." << endl;
            cout << "Enter price: ";
            cin >> price;
        }
        updatedPrice = 0.0;
        cart = 0;
    }
    Product(Product &product)
    {
        this->name = product.name;
        this->id = id;
        this->quantity = product.quantity;
        this->price = product.price;
    }
    // Setters and getters
    void setProduct(string name, string supplier, int id, int quantity, float price) // To set all the attributes at once
    {
        this->name = name;
        this->supplier = supplier;
        this->id = id;
        while (id < 1) // input validation
        {
            cout << "Invalid input." << endl;
            cout << "Enter Product ID: ";
            cin >> id;
        }
        this->quantity = quantity;
        while (quantity < 0) // input validation
        {
            cout << "Invalid input." << endl;
            cout << "Enter quantity: ";
            cin >> quantity;
        }
        this->price = price;
        while (price < 0) // input validation
        {
            cout << "Invalid input." << endl;
            cout << "Enter price: ";
            cin >> price;
        }
    }
    void getProduct() // To get all the information
    {
        cout << "Name: " << name << endl;
        cout << "Id: " << id << endl;
        cout << "Quantity: " << quantity << endl;
        cout << "Price: $" << price << endl;
    }
    void setName(string name)
    {
        this->name = name;
    }
    string getName() const
    {
        return this->name;
    }
    void setSupplier(string supplier)
    {
        this->supplier = supplier;
    }
    string getSupplier() const
    {
        return this->supplier;
    }
    void setId(int id)
    {
        this->id = id;
        while (id < 1) // input validation
        {
            cout << "Invalid input." << endl;
            cout << "Enter Product ID: ";
            cin >> id;
        }
    }
    int getId() const
    {
        return this->id;
    }
    void setQuantity(int quantity)
    {
        this->quantity = quantity;
        while (quantity < 0) // input validation
        {
            cout << "Invalid input." << endl;
            cout << "Enter quantity: ";
            cin >> quantity;
        }
    }
    int getQuantity() const
    {
        return this->quantity;
    }
    void setOrderedQuantity(int orderedQuantity)
    {
        this->orderedQuantity = orderedQuantity;
    }
    int getOrderedQuantity() const
    {
        return this->orderedQuantity;
    }
    void setPrice(float price)
    {
        this->price = price;
        while (price < 0) // input validation
        {
            cout << "Invalid input." << endl;
            cout << "Enter price: ";
            cin >> price;
        }
    }
    float getPrice() const
    {
        return this->price;
    }
    void setUpdatedPrice(float updatedPrice)
    {
        this->updatedPrice = updatedPrice;
    }
    float getUpdatedPrice() const
    {
        return this->updatedPrice;
    }
    void setCart(int cart)
    {
        this->cart = cart;
    }
    int getCart() const
    {
        return this->cart;
    }
};

class Warehouse : public Product
{
protected:
    int noOfProducts;     // Total number of products in warehouse
    float totalCartPrice; // Total Price of all the objects in cart
    string location;

public:
    Product *products;
    // Constructors
    Warehouse(int noOfProducts = 10, string location = "Islamabad")
    {
        totalCartPrice = 0.0;
        this->noOfProducts = noOfProducts;
        this->location = location;
        products = new Product[noOfProducts];
        // Initial products in warehouse
        products[0].setProduct("Apples", "Fruits", 1, 1500, 80);
        products[1].setProduct("Iphones", "Electronics", 2, 40, 1599.99);
        products[2].setProduct("Bananas", "Fruits", 3, 2000, 50);
        products[3].setProduct("Laptops", "Electronics", 4, 30, 899.99);
        products[4].setProduct("Milk", "Dairy", 5, 100, 2.99);
        products[5].setProduct("Headphones", "Electronics", 6, 20, 149.99);
        products[6].setProduct("Toothpaste", "Groceries", 7, 500, 4.99);
        products[7].setProduct("Sunglasses", "Accessories", 8, 10, 199.99);
        products[8].setProduct("Socks", "Clothing", 9, 500, 9.99);
        products[9].setProduct("Chocolate", "Edibles", 10, 200, 3.49);
    }
    // Getter to get the number of products present currently in the warehouse
    int getNoOfProducts()
    {
        return noOfProducts;
    }
    // Methods
    void addProduct()
    {
        Product *newProducts = new Product[noOfProducts + 1];
        for (int i = 0; i < noOfProducts; i++)
        {
            newProducts[i] = products[i];
        }
        delete[] products;
        products = nullptr;
        products = newProducts;
        string name = "";
        int id = 0, quantity = 0;
        float price = 0.0;
        cout << "\nEnter name of the Product: ";
        cin >> name;
        cout << "\nEnter name of the Supplier: (Example: Clothing, Edibles, Fruits, Accessories, Groceries, Electronics) ";
        cin >> supplier;
        id = noOfProducts + 1;
        cout << "Enter the quantity: ";
        cin >> quantity;
        while (quantity < 0) // input validation
        {
            cout << "Invalid input." << endl;
            cout << "Enter quantity: ";
            cin >> quantity;
        }
        cout << "Enter the price for the product: ";
        cin >> price;
        while (price < 0) // input validation
        {
            cout << "Invalid input." << endl;
            cout << "Enter price: ";
            cin >> price;
        }
        products[noOfProducts].setProduct(name, supplier, id, quantity, price);
        noOfProducts += 1;
        cout << "\nProduct has been added successfully!" << endl;
        // For a brief pause of 2 seconds
        Sleep(2000);
        // For clearing console screen
        char screenRefresher = ' ';
        cout << "\nDo you want to refresh screen? ('y' or 'n') ";
        cin >> screenRefresher;
        while (screenRefresher != 'y' && screenRefresher != 'n') // input validation
        {
            cout << "Invalid input." << endl;
            cin >> screenRefresher;
        }
        if (screenRefresher == 'y')
        {
            system("cls");
        }
    }
    // Product Ordering
    void productsOrdering(int id, int orderedQuantity, float updatedPrice)
    {
        bool check = false;
        for (int i = 0; i < noOfProducts; i++)
        {
            if (id == products[i].getId())
            {
                check = true;
                if (products[i].getQuantity() <= 100)
                {
                    products[i].setOrderedQuantity(orderedQuantity);
                    products[i].setUpdatedPrice(updatedPrice);
                    cout << "\nOrder placed to '" << products[i].getSupplier() << "' Supplier." << endl;
                }
                else
                {
                    cout << "\nOrder cannot be placed, since the inventory level is above product's ordering threshold." << endl;
                }
            }
        }
        if (!check)
        {
            cout << "\nProduct not found." << endl;
        }
        // For a brief pause of 2 seconds
        Sleep(2000);
        // For clearing console screen
        char screenRefresher = ' ';
        cout << "\nDo you want to refresh screen? ('y' or 'n') ";
        cin >> screenRefresher;
        while (screenRefresher != 'y' && screenRefresher != 'n') // input validation
        {
            cout << "Invalid input." << endl;
            cin >> screenRefresher;
        }
        if (screenRefresher == 'y')
        {
            system("cls");
        }
    }
    // Products Take
    void productsTake()
    {
        for (int i = 0; i < noOfProducts; i++)
        {
            if (products[i].getOrderedQuantity() > 0)
            {
                products[i].setQuantity(products[i].getQuantity() + products[i].getOrderedQuantity());
                products[i].setPrice(products[i].getUpdatedPrice());
            }
        }
        cout << "\nProducts take performed." << endl;
        // For a brief pause of 2 seconds
        Sleep(2000);
        // For clearing console screen
        char screenRefresher = ' ';
        cout << "\nDo you want to refresh screen? ('y' or 'n') ";
        cin >> screenRefresher;
        while (screenRefresher != 'y' && screenRefresher != 'n') // input validation
        {
            cout << "Invalid input." << endl;
            cin >> screenRefresher;
        }
        if (screenRefresher == 'y')
        {
            system("cls");
        }
    }
    // Price Management
    void priceManagement(int id, float price)
    {
        bool check = false;
        for (int i = 0; i < noOfProducts; i++)
        {
            if (id == products[i].getId())
            {
                check = true;
                products[i].setPrice(price);
                cout << "Price has been updated.\n"
                     << endl;
                products[i].getProduct();
                cout << endl;
                return;
            }
        }
        if (!check)
        {
            cout << "\nProduct not found." << endl;
        }
        // For a brief pause of 2 seconds
        Sleep(2000);
        // For clearing console screen
        char screenRefresher = ' ';
        cout << "\nDo you want to refresh screen? ('y' or 'n') ";
        cin >> screenRefresher;
        while (screenRefresher != 'y' && screenRefresher != 'n') // input validation
        {
            cout << "Invalid input." << endl;
            cin >> screenRefresher;
        }
        if (screenRefresher == 'y')
        {
            system("cls");
        }
    }
    // Add to Cart
    void addToCart(int id)
    {
        bool check = false, check2 = true;
        char buy = ' ';
        int n = 0;
        for (int i = 0; i < noOfProducts; i++)
        {
            if (id == products[i].getId())
            {
                check = true;
                do
                {
                    cout << "\nProduct name: " << products[i].getName() << endl;
                    cout << "Product price: $" << products[i].getPrice() << endl;
                    if (products[i].getQuantity() > 0)
                    {
                        cout << "Quantity: " << products[i].getQuantity() << endl;
                        if (n == 0)
                        {
                            cout << "\nDo you want to add one to your cart? ('y' or 'n') ";
                        }
                        else
                        {
                            cout << "\nDo you wish to buy more? ('y' or 'n') ";
                        }
                        cin >> buy;
                        while (buy != 'y' && buy != 'n') // input validation
                        {
                            cout << "Invalid input." << endl;
                            if (n == 0)
                            {
                                cout << "\nDo you want to add one to your cart? ('y' or 'n') ";
                            }
                            else
                            {
                                cout << "\nDo you wish to buy more? ('y' or 'n') ";
                            }
                            cin >> buy;
                        }
                        if (buy == 'y')
                        {
                            products[i].setQuantity(products[i].getQuantity() - 1);
                            products[i].setCart(products[i].getCart() + 1);
                            n++;
                        }
                        else
                        {
                            // For clearing console screen
                            char screenRefresher = ' ';
                            cout << "\nDo you want to refresh screen? ('y' or 'n') ";
                            cin >> screenRefresher;
                            while (screenRefresher != 'y' && screenRefresher != 'n') // input validation
                            {
                                cout << "Invalid input." << endl;
                                cin >> screenRefresher;
                            }
                            if (screenRefresher == 'y')
                            {
                                system("cls");
                            }
                            return;
                        }
                    }
                    else
                    {
                        cout << "\nOut of stock!" << endl;
                        check2 = false;
                    }
                } while (check2);
            }
        }
        if (!check)
        {
            cout << "\nProduct not found." << endl;
        }
        // For a brief pause of 2 seconds
        Sleep(2000);
        // For clearing console screen
        char screenRefresher = ' ';
        cout << "\nDo you want to refresh screen? ('y' or 'n') ";
        cin >> screenRefresher;
        while (screenRefresher != 'y' && screenRefresher != 'n') // input validation
        {
            cout << "Invalid input." << endl;
            cin >> screenRefresher;
        }
        if (screenRefresher == 'y')
        {
            system("cls");
        }
    }
    // Apply Discounts
    void applyDiscounts(int saleOption)
    {
        bool empty = true;
        totalCartPrice = 0.0;
        for (int i = 0; i < noOfProducts; i++)
        {
            if (products[i].getCart() > 0)
            {
                empty = false;
                totalCartPrice += (products[i].getPrice() * products[i].getCart());
            }
        }
        if (!empty)
        {
            cout << "\nTotal price before applying discount: " << totalCartPrice << endl;
            if (saleOption == 1) // Ramadan Sale
            {
                totalCartPrice /= 2; // 50% discount
                cout << "\n50% discount applied due to Ramadan Sale!" << endl;
            }
            if (saleOption == 2) // 11/11 Sale
            {
                totalCartPrice -= ((totalCartPrice / 100) * 11); // 11% discount
                cout << "\n11% discount applied due to 11/11 Sale!" << endl;
            }
            if (saleOption == 3) // 14th August Sale
            {
                totalCartPrice -= ((totalCartPrice / 100) * 14); // 14% discount
                cout << "\n14% discount applied due to 14th August Sale!" << endl;
            }
            if (saleOption == 4) // Loyalty Points Discount (It gives 2% discount on every 1000, with a maximum of 20% discount)
            {
                for (int i = 0; i < noOfProducts; i++)
                {
                    if (products[i].getCart() > 0)
                    {
                        if (totalCartPrice < 2000)
                        {
                            totalCartPrice -= ((totalCartPrice / 100) * 2);
                            cout << "\n2% discount applied due to your Loyalty with us!" << endl;
                        }
                        else if (totalCartPrice < 20000)
                        {
                            int n = totalCartPrice / 1000;
                            totalCartPrice -= ((totalCartPrice / 100) * 2 * n);
                            cout << "\n"
                                 << n * 2 << "% discount applied due to your Loyalty with us!" << endl;
                        }
                        else
                        {
                            totalCartPrice -= ((totalCartPrice / 100) * 20);
                            cout << "\n20% discount applied due to your Loyalty with us!" << endl;
                        }
                    }
                }
            }
            if (saleOption == 5) // Buy one get one free
            {
                totalCartPrice = 0.0;
                for (int i = 0; i < noOfProducts; i++)
                {
                    if (products[i].getCart() > 0)
                    {
                        if (products[i].getCart() % 2 == 0)
                        {
                            totalCartPrice += (products[i].getPrice() * (products[i].getCart() / 2));
                        }
                        if (products[i].getCart() % 2 == 1)
                        {
                            totalCartPrice += (products[i].getPrice() * ((products[i].getCart() / 2) + 1));
                        }
                    }
                }
                cout << "\n'Buy One Get One Free' discount applied." << endl;
            }
            cout << "\nTotal price after applying discount: " << totalCartPrice << endl;
        }
        else if (empty)
        {
            cout << "\nCart is empty!" << endl;
        }
        // For a brief pause of 2 seconds
        Sleep(2000);
        // For clearing console screen
        char screenRefresher = ' ';
        cout << "\nDo you want to refresh screen? ('y' or 'n') ";
        cin >> screenRefresher;
        while (screenRefresher != 'y' && screenRefresher != 'n') // input validation
        {
            cout << "Invalid input." << endl;
            cin >> screenRefresher;
        }
        if (screenRefresher == 'y')
        {
            system("cls");
        }
    }
    // Issue Refunds
    void issueRefunds(int id, int quantity)
    {
        bool check = false;
        for (int i = 0; i < noOfProducts; i++)
        {
            if (id == products[i].getId())
            {
                check = true;
                if (quantity <= products[i].getCart())
                {
                    products[i].setQuantity(products[i].getQuantity() + quantity);
                    products[i].setCart(products[i].getCart() - quantity);
                }
                else
                {
                    cout << "\nYou cannot return more than that you have in your cart." << endl;
                    return;
                }
            }
        }
        if (!check)
        {
            cout << "\nProduct not found." << endl;
        }
        if (check)
        {
            cout << "\nReturned items have been refunded." << endl;
        }
        // For a brief pause of 2 seconds
        Sleep(2000);
        // For clearing console screen
        char screenRefresher = ' ';
        cout << "\nDo you want to refresh screen? ('y' or 'n') ";
        cin >> screenRefresher;
        while (screenRefresher != 'y' && screenRefresher != 'n') // input validation
        {
            cout << "Invalid input." << endl;
            cin >> screenRefresher;
        }
        if (screenRefresher == 'y')
        {
            system("cls");
        }
    }
    // Sales Reports
    void salesReports(int option)
    {
        if (option == 1)
        {
            // Generate report by Product
            cout << "\n<----- Sales by Product ----->" << endl;
            for (int i = 0; i < noOfProducts; i++)
            {
                cout << "\nProduct: " << products[i].getName() << endl
                     << "Sales: " << products[i].getCart() << endl;
            }
        }
        if (option == 2)
        {
            bool check = true;
            // Generate report by Day
            cout << "\n<----- Sales by Day ----->" << endl;
            for (int i = 0; i < noOfProducts; i++)
            {
                if (products[i].getCart() > 0)
                {
                    check = false;
                    cout << "\nProduct: " << products[i].getName() << endl
                         << "Sales: " << products[i].getCart() << endl;
                }
            }
            if (check)
            {
                cout << "Empty report! Since there were no sales for today." << endl;
            }
        }
        if (option == 3)
        {
            bool check = true;
            // Generate report by Customer
            cout << "\n<----- Sales by Customer ----->" << endl;
            for (int i = 0; i < noOfProducts; i++)
            {
                if (products[i].getCart() > 0)
                {
                    check = false;
                    cout << "\nProduct: " << products[i].getName() << endl
                         << "Sales: " << products[i].getCart() << endl;
                }
            }
            if (check)
            {
                cout << "Empty report! Since there were no customers today." << endl;
            }
        }
        // For a brief pause of 2 seconds
        Sleep(2000);
        // For clearing console screen
        char screenRefresher = ' ';
        cout << "\nDo you want to refresh screen? ('y' or 'n') ";
        cin >> screenRefresher;
        while (screenRefresher != 'y' && screenRefresher != 'n') // input validation
        {
            cout << "Invalid input." << endl;
            cin >> screenRefresher;
        }
        if (screenRefresher == 'y')
        {
            system("cls");
        }
    }
    // Inventory Reports
    void inventoryReports(int option)
    {
        if (option == 1)
        {
            // Generate report by Product
            cout << "\n<----- Inventory by Product ----->" << endl;
            for (int i = 0; i < noOfProducts; i++)
            {
                cout << "\nProduct: " << products[i].getName() << endl
                     << "Inventory: " << products[i].getQuantity() << endl;
            }
        }
        if (option == 2)
        {
            // Generate report by Location
            cout << "\n<----- Inventory by Location ----->" << endl;
            cout << "\nInventory in the warehouse of " << location << ":" << endl;
            for (int i = 0; i < noOfProducts; i++)
            {
                cout << "\nProduct: " << products[i].getName() << endl
                     << "Inventory: " << products[i].getQuantity() << endl;
            }
        }
        if (option == 3)
        {
            // Generate report by Supplier
            cout << "\n<----- Inventory by Supplier ----->" << endl;
            for (int i = 0; i < noOfProducts; i++)
            {
                cout << "\nProduct: " << products[i].getName() << endl
                     << "Supplier: " << products[i].getSupplier() << " Supplier" << endl;
            }
        }
        // For a brief pause of 2 seconds
        Sleep(2000);
        // For clearing console screen
        char screenRefresher = ' ';
        cout << "\nDo you want to refresh screen? ('y' or 'n') ";
        cin >> screenRefresher;
        while (screenRefresher != 'y' && screenRefresher != 'n') // input validation
        {
            cout << "Invalid input." << endl;
            cin >> screenRefresher;
        }
        if (screenRefresher == 'y')
        {
            system("cls");
        }
    }
    // Profit Reports
    void profitReports(int option)
    {
        if (option == 1)
        {
            // Generate report by Product
            cout << "\n<----- Profit by Product ----->" << endl;
            for (int i = 0; i < noOfProducts; i++)
            {
                cout << "\nProduct: " << products[i].getName() << endl
                     << "Profit: $" << (((products[i].getCart() * products[i].getPrice()) / 100) * 10) << endl; // Since profit is 10% of the price.
            }
        }
        if (option == 2)
        {
            bool check = true;
            // Generate report by Day
            cout << "\n<----- Profit by Day ----->" << endl;
            for (int i = 0; i < noOfProducts; i++)
            {
                if (products[i].getCart() > 0)
                {
                    check = false;
                    cout << "\nProduct: " << products[i].getName() << endl
                         << "Profit: $" << (((products[i].getCart() * products[i].getPrice()) / 100) * 10) << endl; // Since profit is 10% of the price.
                }
            }
            if (check)
            {
                cout << "Empty report! Since there were no sales for today." << endl;
            }
        }
        if (option == 3)
        {
            bool check = true;
            // Generate report by Customer
            cout << "\n<----- Profit by Customer ----->" << endl;
            for (int i = 0; i < noOfProducts; i++)
            {
                if (products[i].getCart() > 0)
                {
                    check = false;
                    cout << "\nProduct: " << products[i].getName() << endl
                         << "Profit: $" << (((products[i].getCart() * products[i].getPrice()) / 100) * 10) << endl; // Since profit is 10% of the price.
                }
            }
            if (check)
            {
                cout << "Empty report! Since there were no customers today." << endl;
            }
        }
        // For a brief pause of 2 seconds
        Sleep(2000);
        // For clearing console screen
        char screenRefresher = ' ';
        cout << "\nDo you want to refresh screen? ('y' or 'n') ";
        cin >> screenRefresher;
        while (screenRefresher != 'y' && screenRefresher != 'n') // input validation
        {
            cout << "Invalid input." << endl;
            cin >> screenRefresher;
        }
        if (screenRefresher == 'y')
        {
            system("cls");
        }
    }
    // Destructor
    ~Warehouse()
    {
        delete[] products;
        products = nullptr;
    }
};

void ProductsOrdering(Warehouse &warehouse);
void ProductsTake(Warehouse &warehouse);
void PriceManagement(Warehouse &warehouse);
void AddProduct(Warehouse &warehouse);
void AddToCart(Warehouse &warehouse);
void ApplyDiscounts(Warehouse &warehouse);
void IssueRefunds(Warehouse &warehouse);
void SalesReports(Warehouse &warehouse);
void InventoryReports(Warehouse &warehouse);
void ProfitReports(Warehouse &warehouse);

void Manager(Warehouse &warehouse)
{
    int option;
    bool check = true;
    int n = 0;
    do
    {
        if (n > 0)
        {
            cout << "\nInvalid input." << endl;
        }
        cout << "\n<=========== Manager's Menu ===========>" << endl
             << "\nPress '1' for 'Ordering Products'" << endl
             << "Press '2' for performing 'Products take'" << endl
             << "Press '3' for 'Price Management'" << endl
             << "Press '4' to 'Add Product'" << endl
             << "Press '5' to go back." << endl;
        cin >> option;
        n++;
        if (option == 1 || option == 2 || option == 3 || option == 4 || option == 5)
        {
            check = false;
            n = 0;
        }
    } while (check);

    switch (option)
    {
    case 1:
        ProductsOrdering(warehouse);
        break;

    case 2:
        ProductsTake(warehouse);
        break;

    case 3:
        PriceManagement(warehouse);
        break;

    case 4:
        AddProduct(warehouse);
        break;

    case 5:
        return;
    }
}

void ProductsOrdering(Warehouse &warehouse)
{
    int id = 0, orderedQuantity = 0;
    float updatedPrice = 0.0;
    cout << "\nEnter the Product ID: "; // Product ID to identify the product placed in the warehouse.
    cin >> id;
    while (id < 1) // input validation
    {
        cout << "Invalid input." << endl;
        cout << "Enter the Product ID: ";
        cin >> id;
    }
    for (int i = 0; i < warehouse.getNoOfProducts(); i++)
    {
        if (warehouse.products[i].getId() == id)
        {
            warehouse.products[i].getProduct();
            cout << endl;
        }
    }
    cout << "Enter the number of units you want to order: "; // Number of units to increase the inventory of the product.
    cin >> orderedQuantity;
    while (orderedQuantity < 0) // input validation
    {
        cout << "Invalid input." << endl;
        cout << "Enter the number of units you want to order: ";
        cin >> orderedQuantity;
    }
    cout << "Enter the updated price of the product: ";
    cin >> updatedPrice;
    while (updatedPrice < 0) // input validation
    {
        cout << "Invalid input." << endl;
        cout << "Enter the updated price of the product: ";
        cin >> updatedPrice;
    }
    warehouse.productsOrdering(id, orderedQuantity, updatedPrice);
    Manager(warehouse);
}
void ProductsTake(Warehouse &warehouse)
{
    warehouse.productsTake();
    Manager(warehouse);
}
void PriceManagement(Warehouse &warehouse)
{
    int id = 0;
    float price = 0.0;
    cout << "\nEnter the Product ID you want to set/update price for: "; // Product ID to identify the product placed in the warehouse.
    cin >> id;
    while (id < 1) // input validation
    {
        cout << "Invalid input." << endl;
        cout << "Enter the Product ID: ";
        cin >> id;
    }
    for (int i = 0; i < warehouse.getNoOfProducts(); i++)
    {
        if (warehouse.products[i].getId() == id)
        {
            warehouse.products[i].getProduct();
            cout << endl;
        }
    }
    cout << "Enter the updated price of the product: ";
    cin >> price;
    while (price < 0) // input validation
    {
        cout << "Invalid input." << endl;
        cout << "Enter the updated price of the product: ";
        cin >> price;
    }
    warehouse.priceManagement(id, price);
    Manager(warehouse);
}
void AddProduct(Warehouse &warehouse)
{
    warehouse.addProduct();
    Manager(warehouse);
}

void Salesman(Warehouse &warehouse)
{
    int option;
    bool check = true;
    int n = 0;
    do
    {
        if (n > 0)
        {
            cout << "\nInvalid input." << endl;
        }
        cout << "\n<======== Salesman's Menu ========>" << endl
             << "\nPress '1' to 'Add Products to Cart'" << endl
             << "Press '2' to 'Apply Discounts'" << endl
             << "Press '3' for 'Issuing Refunds'" << endl
             << "Press '4' to go back." << endl;
        cin >> option;
        n++;
        if (option == 1 || option == 2 || option == 3 || option == 4)
        {
            check = false;
            n = 0;
        }
    } while (check);

    switch (option)
    {
    case 1:
        AddToCart(warehouse);
        break;

    case 2:
        ApplyDiscounts(warehouse);
        break;

    case 3:
        IssueRefunds(warehouse);
        break;

    case 4:
        return;
    }
}

void AddToCart(Warehouse &warehouse)
{
    cout << "\n<----- Product Catalogue ----->" << endl;
    for (int i = 0; i < warehouse.getNoOfProducts(); i++)
    {
        cout << "\nName: " << warehouse.products[i].getName() << endl;
        cout << "ID: " << warehouse.products[i].getId() << endl;
    }
    int id = 0;
    cout << "\nEnter the Product ID: "; // Product ID to identify the product placed in the warehouse.
    cin >> id;
    while (id < 1) // input validation
    {
        cout << "Invalid input." << endl;
        cout << "Enter the Product ID: ";
        cin >> id;
    }
    warehouse.addToCart(id);
    Salesman(warehouse);
}
void ApplyDiscounts(Warehouse &warehouse)
{
    int saleOption;
    bool check = true;
    int n = 0;
    do
    {
        if (n > 0)
        {
            cout << "\nInvalid input." << endl;
        }
        cout << "\nPress '1' for applying 'Ramadan Sale'" << endl
             << "Press '2' for applying '11/11 Sale'" << endl
             << "Press '3' for applying '14th August Sale'" << endl
             << "Press '4' for applying 'Loyalty Points Discount'" << endl
             << "Press '5' for applying 'Buy One Get One Free'" << endl
             << "Press '6' to go back." << endl;
        cin >> saleOption;
        n++;
        if (saleOption == 1 || saleOption == 2 || saleOption == 3 || saleOption == 4 || saleOption == 5 || saleOption == 6)
        {
            check = false;
            n = 0;
        }
    } while (check);

    switch (saleOption)
    {
    case 1:
        warehouse.applyDiscounts(saleOption);
        break;

    case 2:
        warehouse.applyDiscounts(saleOption);
        break;

    case 3:
        warehouse.applyDiscounts(saleOption);
        break;

    case 4:
        warehouse.applyDiscounts(saleOption);
        break;

    case 5:
        warehouse.applyDiscounts(saleOption);
        break;

    case 6:
        return;
    }
    Salesman(warehouse);
}
void IssueRefunds(Warehouse &warehouse)
{
    int id = 0, quantity = 0;
    cout << "\nEnter the Product ID: "; // Product ID to identify the product placed in the warehouse.
    cin >> id;
    for (int i = 0; i < warehouse.getNoOfProducts(); i++)
    {
        if (warehouse.products[i].getId() == id)
        {
            warehouse.products[i].getProduct();
            cout << endl;
        }
    }
    while (id < 1) // input validation
    {
        cout << "Invalid input." << endl;
        cout << "Enter the Product ID: ";
        cin >> id;
    }
    cout << "Enter the quantity of the product being refunded: ";
    cin >> quantity;
    while (quantity < 0) // input validation
    {
        cout << "Invalid input." << endl;
        cout << "Enter the quantity: ";
        cin >> quantity;
    }
    warehouse.issueRefunds(id, quantity);
    Salesman(warehouse);
}

void Reports(Warehouse &warehouse)
{
    int option;
    bool check = true;
    int n = 0;
    do
    {
        if (n > 0)
        {
            cout << "\nInvalid input." << endl;
        }
        cout << "\n<============ Report's Menu ============>" << endl
             << "\nPress '1' to generate 'Sales Reports'" << endl
             << "Press '2' to generate 'Inventory Reports'" << endl
             << "Press '3' to generate 'Profit Reports'" << endl
             << "Press '4' to go back." << endl;
        cin >> option;
        n++;
        if (option == 1 || option == 2 || option == 3 || option == 4)
        {
            check = false;
            n = 0;
        }
    } while (check);

    switch (option)
    {
    case 1:
        SalesReports(warehouse);
        break;

    case 2:
        InventoryReports(warehouse);
        break;

    case 3:
        ProfitReports(warehouse);
        break;

    case 4:
        return;
    }
}

void SalesReports(Warehouse &warehouse)
{
    int option;
    bool check = true;
    int n = 0;
    do
    {
        if (n > 0)
        {
            cout << "\nInvalid input." << endl;
        }
        cout << "\n<================= Sales Reports' Menu =================>" << endl
             << "\nPress '1' to generate reports based on 'Sales by Product'" << endl
             << "Press '2' to generate reports based on 'Sales by Day'" << endl
             << "Press '3' to generate reports based on 'Sales by Customer'" << endl
             << "Press '4' to go back." << endl;
        cin >> option;
        n++;
        if (option == 1 || option == 2 || option == 3 || option == 4)
        {
            check = false;
            n = 0;
        }
    } while (check);

    switch (option)
    {
    case 1:
        warehouse.salesReports(option);
        break;

    case 2:
        warehouse.salesReports(option);
        break;

    case 3:
        warehouse.salesReports(option);
        break;

    case 4:
        return;
    }
    Reports(warehouse);
}
void InventoryReports(Warehouse &warehouse)
{
    int option;
    bool check = true;
    int n = 0;
    do
    {
        if (n > 0)
        {
            cout << "\nInvalid input." << endl;
        }
        cout << "\n<================= Inventory Reports' Menu =================>" << endl
             << "\nPress '1' to generate reports based on 'Inventory by Product'" << endl
             << "Press '2' to generate reports based on 'Inventory by Location'" << endl
             << "Press '3' to generate reports based on 'Inventory by Supplier'" << endl
             << "Press '4' to go back." << endl;
        cin >> option;
        n++;
        if (option == 1 || option == 2 || option == 3 || option == 4)
        {
            check = false;
            n = 0;
        }
    } while (check);

    switch (option)
    {
    case 1:
        warehouse.inventoryReports(option);
        break;

    case 2:
        warehouse.inventoryReports(option);
        break;

    case 3:
        warehouse.inventoryReports(option);
        break;

    case 4:
        return;
    }
    Reports(warehouse);
}
void ProfitReports(Warehouse &warehouse)
{
    int option;
    bool check = true;
    int n = 0;
    do
    {
        if (n > 0)
        {
            cout << "\nInvalid input." << endl;
        }
        cout << "\n<================= Profit Reports' Menu =================>" << endl
             << "\nPress '1' to generate reports based on 'Profits by Product'" << endl
             << "Press '2' to generate reports based on 'Profits by Day'" << endl
             << "Press '3' to generate reports based on 'Profits by Customer'" << endl
             << "Press '4' to go back." << endl;
        cin >> option;
        n++;
        if (option == 1 || option == 2 || option == 3 || option == 4)
        {
            check = false;
            n = 0;
        }
    } while (check);

    switch (option)
    {
    case 1:
        warehouse.profitReports(option);
        break;

    case 2:
        warehouse.profitReports(option);
        break;

    case 3:
        warehouse.profitReports(option);
        break;

    case 4:
        return;
    }
    Reports(warehouse);
}

void menu(Warehouse &warehouse)
{
    int option;
    bool check = true;
    int n = 0;
    do
    {
        if (n > 0)
        {
            cout << "\nInvalid input." << endl;
        }
        cout << "\n<============== Main Menu ==============>" << endl
             << "\nPress '1' to continue as 'Manager'" << endl
             << "Press '2' to continue as 'Store Salesman'" << endl
             << "Press '3' to generate  'Reports'" << endl
             << "Press '4' to 'Exit'" << endl;
        cin >> option;
        n++;
        if (option == 1 || option == 2 || option == 3 || option == 4)
        {
            check = false;
            n = 0;
        }
    } while (check);

    switch (option)
    {
    case 1:
        Manager(warehouse);
        break;

    case 2:
        Salesman(warehouse);
        break;

    case 3:
        Reports(warehouse);
        break;

    case 4:
        exit(0);
        break;
    }
    menu(warehouse);
}

int main()
{
    // Initital warehouse
    int noOfProducts = 10;
    Warehouse warehouse(noOfProducts);

    // Main Menu
    menu(warehouse);

    return 0;
}