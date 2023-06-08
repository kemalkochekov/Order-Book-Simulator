#include <bits/stdc++.h>
#include <fstream>
#include <time.h>
using namespace std;

bool AreSame(double a, double b)
{
    return a==b;
}
// Structure to represent an order
struct Order {
    string symbol;
    string side;  // "BUY" or "SELL"
    double price;
    int quantity;
};

// Comparator function for sorting orders based on price
struct CompareOrders {
    bool operator()(const Order& order1, const Order& order2) const {
        if (order1.side == "BUY")
            return order1.price > order2.price;
        else
            return order1.price < order2.price;
    }
};

class OrderBookSimulator {
public:
    void addOrder(const Order& order) {
        orders[order.symbol][order.side].push_back(order);
        matchOrders(order.symbol);
    }

    void printOrderBook(const string& symbol) const {
        const auto& symbolOrders = orders.find(symbol);
        if (symbolOrders == orders.end()) {
            cout << "No orders found for symbol: " << symbol << '\n';
            return;
        }

        const auto& buyOrders = symbolOrders->second.find("BUY");
        const auto& sellOrders = symbolOrders->second.find("SELL");

        cout << "------ Order Book (" << symbol << ") ------\n";
        cout << "BUY ORDERS:\n";
        if (buyOrders != symbolOrders->second.end()) {
            for (const auto& buyOrder : buyOrders->second) {
                cout << "Price: " << buyOrder.price << ", Quantity: " << buyOrder.quantity << '\n';
            }
        }

        cout << "SELL ORDERS:\n";
        if (sellOrders != symbolOrders->second.end()) {
            for (const auto& sellOrder : sellOrders->second) {
                cout << "Price: " << sellOrder.price << ", Quantity: " << sellOrder.quantity << '\n';
            }
        }
        cout << "---------------------------------------\n";
    }

private:
    map<string, map<string, vector<Order>>> orders;

    void matchOrders(const string& symbol) {
        auto symbolOrders = orders.find(symbol);
        if (symbolOrders == orders.end())
            return;

        auto& buyOrders = symbolOrders->second["BUY"];
        auto& sellOrders = symbolOrders->second["SELL"];

        while (!buyOrders.empty() && !sellOrders.empty()) {
            auto& bestBuyOrder = buyOrders.front();
            auto& bestSellOrder = sellOrders.front();

            if (bestBuyOrder.price >= bestSellOrder.price) {
                int matchQuantity = min(bestBuyOrder.quantity, bestSellOrder.quantity);

                cout << "Matched orders for " << symbol << ":\n";
                cout << "BUY Order: Price: " << bestBuyOrder.price << ", Quantity: " << matchQuantity << '\n';
                cout << "SELL Order: Price: " << bestSellOrder.price << ", Quantity: " << matchQuantity << '\n';

                bestBuyOrder.quantity -= matchQuantity;
                bestSellOrder.quantity -= matchQuantity;

                if (bestBuyOrder.quantity == 0)
                    buyOrders.erase(buyOrders.begin());
                if (bestSellOrder.quantity == 0)
                    sellOrders.erase(sellOrders.begin());
            } else {
                break;  // No more matching orders
            }
        }
    }
};

int main() {
    OrderBookSimulator orderBook;
    
    string ticker = "RUB=X";
    // Adding sample orders
    Order order1{ticker, "BUY", 77.625, 10};
    Order order2{ticker, "SELL", 81.63099670410156, 5};
    Order order3{ticker, "SELL", 82.4000015258789, 7};
    Order order4{ticker, "BUY", 80.84 , 6};

    orderBook.addOrder(order1);
    orderBook.addOrder(order2);
    orderBook.addOrder(order3);
    orderBook.addOrder(order4);

    // Print the order book
    orderBook.printOrderBook(ticker);

    ifstream buy_file("stock_data_buy.txt");
    ifstream sell_file("stock_data_sell.txt");
    
    string line;
    // Read and process the data
    int succesful_orders_from_book=0;
    while (getline(buy_file, line)) {
        double price=stod(line);
        if(AreSame(price,order1.price) or AreSame(price,order4.price)){
            succesful_orders_from_book++;
            cout<<"ahuiasd"<<endl;
        }
    }
    while (getline(sell_file, line)) {
        double price=stod(line);
        if(AreSame(price,order2.price) or AreSame(price,order3.price)){
            succesful_orders_from_book++;
        }
    }
    buy_file.close();
    sell_file.close();
    cout<<succesful_orders_from_book<<endl;
    return 0;
}
