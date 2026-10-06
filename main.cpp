// COMSC 210 | Lab 20 | Yeji Kim
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

const int SIZE = 3;

class Chair {
    private: int legs;
    double * prices;
    public:
        // constructors
        Chair() {
            prices = new double[SIZE];

            // randomly select 3 or 4 legs
            legs = rand() % 2 + 3;

            // randomly select prices from $100.00 to $999.99
            const int MIN = 10000;
            const int MAX = 99999;

            for (int i = 0; i < SIZE; i++)
                prices[i] = (rand() % (MAX - MIN + 1) + MIN) / (double) 100;
        }

    Chair(int l, double p[]) {
        prices = new double[SIZE];
        legs = l;

        for (int i = 0; i < SIZE; i++)
            prices[i] = p[i];
    }

    // setters and getters
    void setLegs(int l) {
        legs = l;
    }
    int getLegs() {
        return legs;
    }

    void setPrices(double p1, double p2, double p3) {
        prices[0] = p1;
        prices[1] = p2;
        prices[2] = p3;
    }

    double getAveragePrices() {
        double sum = 0;
        for (int i = 0; i < SIZE; i++)
            sum += prices[i];
        return sum / SIZE;
    }

    void print() {
        cout << "CHAIR DATA - legs: " << legs << endl;
        cout << "Price history: ";
        for (int i = 0; i < SIZE; i++)
            cout << prices[i] << " ";
        cout << endl << "Historical avg price: " << getAveragePrices();
        cout << endl << endl;
    }
};

int main() {
    cout << fixed << setprecision(2);

    //seeding random number generator
    srand(time(0));

    //creating pointer to first chair object
    Chair * chairPtr = new Chair;
    chairPtr -> setLegs(4);
    chairPtr -> setPrices(121.21, 232.32, 414.14);
    cout << "First chair: " << endl;
    chairPtr -> print();

    delete chairPtr;
    chairPtr = nullptr;

    //creating dynamic chair object with constructor
    double livingPrices[SIZE] = {
        525.25,
        434.34,
        252.52
    };

    Chair * livingChair = new Chair(3, livingPrices);

    cout << "Living room chair: " << endl;
    livingChair -> print();

    delete livingChair;
    livingChair = nullptr;

    //creating dynamic array of chair objects
    //default constructors randomly populate each chair
    Chair * collection = new Chair[SIZE];

    cout << "Randomly generated chairs: " << endl;

    for (int i = 0; i < SIZE; i++) {
        collection[i].print();
    }

    delete[] collection;
    collection = nullptr;

    return 0;
}