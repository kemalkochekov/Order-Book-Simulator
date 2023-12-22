# Order-Book-Simulator

The Order Book Simulator is a C++ application that simulates an order book for trading based on historical stock data. The C++ code handles the order book simulation and matching orders, while the Python code retrieves the stock data, generates trading signals, and saves the prices into separate files for further analysis. The C++ code then reads those files and compares the prices with the simulated orders to determine the **number of successful orders**.

# Features
 - Add buy and sell orders to the order book.
 - Match orders based on price and quantity.
 - Print the order book to view buy and sell orders for a specific symbol.

# Requirements
- C++ compiler that supports C++11 or higher.
- Python3 (Jupyter Notebook)

# Usage
1. Clone the repository or download the source code files.
```
  git clone https://github.com/kemalkochekov/Order-Book-Simulator.git
```
3. Compile the Order_Book_Simulator.cpp file using a C++ compiler.
4. Run the compiled executable to execute the Order Book Simulator.

# Adding Orders
To add an order, you need to provide the following information:
- Symbol: The trading symbol of the stock.
- Side: "BUY" or "SELL" indicating the type of order.
- Price: The price of the order.
- Quantity: The quantity of shares in the order.

Example: 
```
Order order1{"RUB=X", "BUY", 77.625, 10};
Order order2{"RUB=X", "SELL", 82.40000, 5};
orderBook.addOrder(order1);
orderBook.addOrder(order2);
```
# Printing the Order Book
To view the current state of the order book for a specific symbol, use the printOrderBook() function and provide the symbol as an argument.

# Integration with Python
The Order Book Simulator can be integrated with Python using the provided Python script Random_Yfinance_Data.py. The Python script retrieves stock data, generates trading signals, and saves buy and sell prices into separate files. The C++ application can then read these files and compare the prices with the simulated orders.

Make sure to have Python and the required Python libraries (yfinance, pandas) installed before running the Python script.
