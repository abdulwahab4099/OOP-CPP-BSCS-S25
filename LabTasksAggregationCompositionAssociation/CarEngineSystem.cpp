/*
 				Question 2: Composition- Car and Engine System
 Implement a car system using Composition where Car contains Engine.
 Requirements:
	 • Engine class: horsepower, fuel consumption per km
	 • Car class: model name, contains one Engine object
	 • Engine cannot exist without Car
	 • When Car is destroyed, Engine is also destroyed
 Basic Calculations:
	 (a) Fuel needed for trip: Fuel = Distance × Consumption per km
	 (b) Trip cost: Cost = Fuel needed ×Price per liter
	 (c) Speed calculation: Speed = Distance/Time
 	(d) Fuel efficiency: Efficiency =
 Implementation:
	 100
	 Consumption per 100km
	 • Create 2 different cars with different engines
	 • Calculate fuel cost for a 200km trip (fuel price = $1.50/liter)
	 • Compare which car is more fuel efficient
*/


#include <iostream>
#include <string>
using namespace std;

// Engine class: Part of Car (composition)
class Engine {
public:
    double horsepower;        // Engine horsepower
    double fuel_per_km;       // Fuel consumption per km (liters/km)

    // Constructor to initialize engine
    Engine(double hp, double fpk) {
        horsepower = hp;
        fuel_per_km = fpk;
    }

    // Calculate fuel needed for a distance
    double fuel_needed(double distance) {
        return distance * fuel_per_km;
    }

    // Calculate fuel efficiency (km per 100 liters)
    double get_efficiency() {
        return 100.0 / (fuel_per_km * 100.0); // km per 100 liters
    }
};

// Car class: Contains Engine (composition)
class Car {
private:
    string model_name;        // Car model name
    Engine engine;            // Engine object (destroyed when Car is destroyed)

public:
    // Constructor to initialize car and engine
    Car(string model, double hp, double fpk) : model_name(model), engine(hp, fpk) {}

    // Calculate fuel needed for a trip
    double fuel_for_trip(double distance) {
        return engine.fuel_needed(distance);
    }

    // Calculate trip cost
    double trip_cost(double distance, double price_per_liter) {
        return fuel_for_trip(distance) * price_per_liter;
    }

    // Calculate speed (km/h)
    double calculate_speed(double distance, double time) {
        if (time == 0) return 0.0;
        return distance / time;
    }

    // Get fuel efficiency
    double get_efficiency() {
        return engine.get_efficiency();
    }

    // Display car details
    void display_details() {
        cout << "Car: " << model_name << endl;
        cout << "Horsepower: " << engine.horsepower << " HP" << endl;
        cout << "Fuel Consumption: " << engine.fuel_per_km << " liters/km" << endl;
        cout << "Fuel Efficiency: " << get_efficiency() << " km/100 liters" << endl;
    }
};

// Main program
int main() {
    // Create 2 cars with different engines
    Car car1("Toyota Camry", 200.0, 0.08); // 0.08 liters/km
    Car car2("Honda Civic", 180.0, 0.06);  // 0.06 liters/km

    // Trip details
    double distance = 200.0;      // 200 km trip
    double fuel_price = 1.50;     // $1.50 per liter
    double time = 2.5;            // 2.5 hours (example time for speed calculation)

    // Display details and calculations for car1
    cout << "\n--- Car 1 Details ---\n";
    car1.display_details();
    double fuel1 = car1.fuel_for_trip(distance);
    cout << "Fuel needed for 200km: " << fuel1 << " liters" << endl;
    cout << "Trip cost: $" << car1.trip_cost(distance, fuel_price) << endl;
    cout << "Speed: " << car1.calculate_speed(distance, time) << " km/h" << endl;

    // Display details and calculations for car2
    cout << "\n--- Car 2 Details ---\n";
    car2.display_details();
    double fuel2 = car2.fuel_for_trip(distance);
    cout << "Fuel needed for 200km: " << fuel2 << " liters" << endl;
    cout << "Trip cost: $" << car2.trip_cost(distance, fuel_price) << endl;
    cout << "Speed: " << car2.calculate_speed(distance, time) << " km/h" << endl;

    // Compare fuel efficiency
    cout << "\n--- Efficiency Comparison ---\n";
    double eff1 = car1.get_efficiency();
    double eff2 = car2.get_efficiency();
    cout << "Toyota Camry Efficiency: " << eff1 << " km/100 liters" << endl;
    cout << "Honda Civic Efficiency: " << eff2 << " km/100 liters" << endl;
    if (eff1 > eff2) {
        cout << "Toyota Camry is more fuel efficient" << endl;
    } else if (eff2 > eff1) {
        cout << "Honda Civic is more fuel efficient" << endl;
    } else {
        cout << "Both cars have the same fuel efficiency" << endl;
    }

    return 0;
}