#include<bits/stdc++.h>
using namespace std;

enum class VehicleType {
    CAR,
    MOTORCYCLE,
    TRUCK,
    BUS
};

enum class SpotType {
    COMPACT,
    REGULAR,
    LARGE
};

class Vehicle {
  private:
    string licensePlate;
    VehicleType type;
    string color;
    
  public:
    Vehicle(string plate, VehicleType type, string color){

    }

    string getLicensePlate() {
        return licensePlate;
    }
    VehicleType getType() {
        return type;
    }
    string getVehicleColor() {
        return color;
    }

    void displayInfo() const {
        switch(type){
            case VehicleType::CAR: cout<<"CAR"<<endl; break;
            case VehicleType::MOTORCYCLE: cout<<"MOTORCYCLE"<<endl; break;
            case VehicleType::TRUCK: cout<<"TRUCK"<<endl; break;
            case VehicleType::BUS: cout<<"BUS"<<endl; break;
        }
        cout<< "License plate: " << licensePlate <<endl;
        cout<< "Color: " << color <<endl;
    }
};

class ParkingSpot {
  private:
    int spotNumber;
    SpotType type;

    Vehicle* vehicle;
    bool available;

  public:
    ParkingSpot(int num, SpotType type){
    
    }

    int getSpotNumber() const {
        return spotNumber;
    }
    SpotType getType() const {
        return type;
    }
    Vehicle* getVehicle() {
        return vehicle;
    }
    bool isAvailable() {
        return available;
    }

    bool canFitVehicle(const Vehicle* v) const {
        if(!v) return false;

        switch (v -> getType()){
            case VehicleType:: MOTORCYCLE: return true; 
            case VehicleType:: CAR: return type != SpotType::COMPACT; 
            case VehicleType:: TRUCK: return true; 
            case VehicleType:: BUS: return type == SpotType::LARGE;
        }
    }

    bool parkVehicle(Vehicle* v){
        if(!available || !canFitVehicle(v)) return false;

        vehicle = v;
        available = false;      // Stopping other vehicles
        return true;
    }

    Vehicle* removeVehicle() {
        if(!vehicle) return nullptr;

        Vehicle* temp = vehicle;
        vehicle = nullptr;

        available = true;
        return temp;
    }

    void displayInfo() {
        cout<< " Spot "<<spotNumber << endl;
        switch(type){
            case SpotType::COMPACT: cout<<"COMPACT"<<endl; break;
            case SpotType::REGULAR: cout<<"REGULAR"<<endl; break;
            case SpotType::LARGE: cout<<"LARGE"<<endl; break;
        }

        if(available){
            cout<<"Available"<<endl;
        }
        else{
            cout<<"Occupied"<<endl;
        }

        if(vehicle){
            vehicle -> displayInfo();
        }
    }
}

class ParkingLot {
  private:
    vector<ParkingSpots*> spots;
    map<string, ParkingSpot*> occupiedSpots;

    int capacity;
    int availableSpots;

    ParkingSpot* findAvailableSpot(const Vehicle* vehicle) const {
        for(auto spot: spots){
            if(spot -> isAvailable() && spot -> canFitVehicle(vehicle)){
                return spot;
            }
        }
        return nullptr;
    }

  public:
    ParkingLot(int compact,int regular,int large){
        int id = 1;
        for(int i=0;i<compact;i++){
            spots.push_back(new ParkingSpot(id++, SpotType::COMPACT));
        }
        for(int i=0;i<regular;i++){
            spots.push_back(new ParkingSpot(id++, SpotType::REGULAR));
        }
        for(int i=0;i<large;i++){
            spots.push_back(new ParkingSpot(id++, SpotType::LARGE));
        }
    }

    ~ParkingLot(){
        for(auto spot: spots){
            delete spot;
        }
    }

    bool parkVehicle(Vehicle* v){
        if(!v || occupiedSpots.count(vehicle -> getLicensePlate())) return false;

        ParkingSpot* spot = findAvailableSpot(v);
        if(!spot || !spot -> parkVehicle(v)) return false;

        occupiedSpots[v -> getLicensePlate()] = spot;   // LicensePlate is a primary key
        availableSpots--;

        return true;
    }

    Vehicle* removeVehicle(const string& licensePlate){
        auto it = occupiedSpots.find(licensePlate);

        if(it == occupiedSpots.end()) return nullptr;
        Vehicle* removed = it -> second -> removeVehicle();

        if(removed){
            occupiedSpots.erase(it);
            availableSpots++;
        }
        return removed;
    }
}