// dz26.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//���������� ������� ��������� ����������.
//�������� ���� Order(����������), ���� ������ ���������� ��� ������� ���������� :
//������� ���
//�	��������� �������� ��� ���������
//��������� ���
//�	���� ����������
//�	��� ����������
//�	��������� ������������ ����������
//�	���� ����������
//�	ֳ��
//�	����� ����������
//
//�������� ���� OrdersSystem, ���� �� ����� �������� ������� ��������� :
//1.	�������� ���� ����������.
//2.	����������� ���������� �� ����� ���������(����������)
//3. �������� ����� ���������� �� �����(���������������� �� �������� ����)

#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;

class Order {
public:
    static int order_counter;
    time_t order_time;
    int preparation_time;
    string description;
    double price;

    Order(time_t order_time, int preparation_time, const string& description, double price)
        : order_time(order_time), preparation_time(preparation_time), description(description), price(price) {
        order_counter++;
    }

    bool operator<(const Order& other) const {
        return order_time < other.order_time;
    }
};

int Order::order_counter = 0;

class OrdersSystem {
public:
    vector<Order> orders;

    void add(const Order& order) {
        orders.push_back(order);
    }

    void sort() {
        std::sort(orders.begin(), orders.end());
    }

    void execute_first() {
        if (!orders.empty()) {
            cout << "Executing order: " << orders.front().description << endl;
            orders.erase(orders.begin());
        }
        else {
            cout << "No orders to execute." << endl;
        }
    }
};

int main() {
    OrdersSystem system;

    time_t current_time = time(nullptr);
    system.add(Order(current_time, 10, "Pizza", 15.99));
    system.add(Order(current_time + 60, 20, "Burger", 10.99));
    system.add(Order(current_time + 120, 30, "Salad", 8.99));

    system.sort();

    system.execute_first();

    return 0;
}