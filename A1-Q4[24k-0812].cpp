#include <iostream>
using namespace std;

class BusRoute{
    private:
    int routeID;
    string stops[3];
    int stopCount;

    public:
    BusRoute(int id) : routeID(id), stopCount(0) {}

    void addStop(const string &stop){
        if (stopCount < 3){
            stops[stopCount++] = stop;
        }
        else{
            cout << "Cannot add more stops. Route is full.\n";
        }
    }

    void displayStops() const{
        cout << "Route " << routeID << " Stops: ";
        for (int i = 0; i < stopCount; i++){
            cout << stops[i] << " -> ";
        }
        cout << "End\n";
    }

    bool isValidStop(const string &stop) const{
        for (int i = 0; i < stopCount; i++)
        {
            if (stops[i] == stop)
            {
                return true;
            }
        }
        return false;
    }
};

class Student{
    private:
    string name;
    int studentID;
    string stop;
    double balance;
    bool cardActive;

    public:
    Student(string n, int id, string s)
        : name(n), studentID(id), stop(s), balance(0.0), cardActive(false) {}

    void payFees(double amount){
        balance += amount;
        if (balance >= 10000){ // Assuming 10000 is the semester fee
            cardActive = true;
            cout << "Payment successful! Transport card activated.\n";
        }
        else {
            cout << "Insufficient balance! Please pay the full fee.\n";
        }
    }

    void tapCard(BusRoute &route){
        if (!cardActive) {
            cout << "Access denied! Please pay the fees first.\n";
            return;
        }

        if (route.isValidStop(stop)) {
            cout << "Attendance recorded for " << name << " at stop " << stop << ".\n";
        }
        else
        {
            cout << "Invalid stop. You are not assigned to this route.\n";
        }
    }

    void displayInfo() const
    {
        cout << "Student ID: " << studentID << " | Name: " << name
             << " | Stop: " << stop << " | Card Active: " << (cardActive ? "Yes" : "No") << endl;
    }
};

int main(){
    BusRoute route1(101);
    route1.addStop("Main Gate");
    route1.addStop("Hostel");
    route1.addStop("Library");
    route1.displayStops();

    Student student1("Ali Khan", 1001, "Library");
    Student student2("Sara Ahmed", 1002, "Hostel");

    student1.displayInfo();
    student2.displayInfo();

    student1.payFees(5000);
    student2.payFees(3000);

    student1.tapCard(route1);
    student2.tapCard(route1);

    return 0;
}
