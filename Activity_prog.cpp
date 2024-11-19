#include <iostream>
#include <string>

using namespace std;

const int Max_Passengers = 100;

class Passenger
{
protected:
    string name;
    int age;
    string ticketID;

public:
    // Constructor
    Passenger()
    {
        name = "NULL";
        age = 0;
        ticketID = "NULL";
    }

    Passenger(string name, int a, string tid)
    {
        this->name = name;
        age = a;
        ticketID = tid;
    }

    // Getter
    string getTicketID()
    {
        return ticketID;
    }

    // Member Function
    void displayDetails()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Ticket Number: " << ticketID << endl;
    }
};

class TicketReservationSystem : public Passenger
{
protected:
    Passenger passengers[Max_Passengers]; // Array of all passengers
    int passengerCount;

public:
    // Constructor
    TicketReservationSystem() : passengerCount(0) {}

    // Member Functions
    void addPassenger(Passenger &p)
    {
        if (passengerCount < Max_Passengers)
        {
            passengers[passengerCount] = p;
            passengerCount++;
        }
        else
        {
            cout << "Reservation system is full. Cannot add more passengers." << endl;
        }
    }

    void displayAllPassengers() 
    {
        for (int i = 0; i < passengerCount; i++)
        {
            passengers[i].displayDetails();
            cout << endl;
        }
    }

    void searchPassengerByTicketID(const string &ticketID)
    {
        for (int i = 0; i < passengerCount; i++)
        {
            if (passengers[i].getTicketID() == ticketID)
            {
                cout << "Passenger found:" << endl;
                passengers[i].displayDetails();
                return;
            }
        }
        cout << "No passenger found with ticket number: " << ticketID << endl;
    }
};

int main()
{
    TicketReservationSystem trs;

    Passenger p1("Bunty", 30, "A12345");
    Passenger p2("Babli", 25, "B67890");
    Passenger p3("Shambu", 40, "C11223");

    trs.addPassenger(p1);
    trs.addPassenger(p2);
    trs.addPassenger(p3);

    cout << "All Passengers:" << endl;
    trs.displayAllPassengers();

    cout << "Search for Passenger with Ticket Number 'B67890':" << endl;
    trs.searchPassengerByTicketID("B67890");

    return 0;
}
