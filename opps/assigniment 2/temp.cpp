#include <iostream>
#include <cmath>


class DM; // Forward declaration

class DB {
private:
    int feet;
    float inches;

public:
    DB(float distance) {
        feet = static_cast<int>(distance);
        inches = (distance - feet) * 12;
    }

    // Friend function declaration for DM + DB addition
    friend DM add(const DM &dm, const DB &db);

    // Display the distance in feet and inches
    void display() {
        std::cout << "Distance: " << feet << " feet " << inches << " inches" << std::endl;
    }
};

class DM {
private:
    int meters;
    float centimeters;

public:
    DM(float distance) {
        meters = static_cast<int>(distance);
        centimeters = (distance - meters) * 100;
    }

    // Friend function declaration for DM + DB addition
    friend DM add(const DM &dm, const DB &db);

    // Display the distance in meters and centimeters
    void display() {
        std::cout << "Distance: " << meters << " meters " << centimeters << " centimeters" << std::endl;
    }
};

// Friend function definition for DM + DB addition
DM add(const DM &dm, const DB &db) {
    // Convert DB to DM (1 foot = 0.3048 meters, 1 inch = 2.54 cm)
    float meters_from_db = db.feet * 0.3048 + db.inches * 0.0254;

    // Perform the addition
    int total_meters = dm.meters + static_cast<int>(meters_from_db);
    float total_centimeters = dm.centimeters + (meters_from_db - static_cast<int>(meters_from_db)) * 100;

    // Adjust for overflow in centimeters
    if (total_centimeters >= 100) {
        total_meters += static_cast<int>(total_centimeters / 100);
        total_centimeters = fmod(total_centimeters, 100);
    }

    return DM(total_meters + total_centimeters / 100.0);

}

int main() {
    // Create objects of DM and DB with single arguments in meters and feet
    DM dm1(5.25);
    DB db1(16.5);

    // Add DM and DB using the friend function
    DM result = add(dm1, db1);

    // Display the result in the appropriate format
    std::cout << "Result in DM format:" << std::endl;
    result.display();

    return 0;
}

