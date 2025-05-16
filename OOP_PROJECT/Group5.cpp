/*
Chin Wen Hui  (241DC2418Q)
Aw Kak Yi (241DC240VD)
Muhammad Aiman Danish bin Ahmad Amri (1221202276)
Muhammad Danish bin Zulkipli (1221202333)
*/

#include <iostream> // Include the input/output stream library
#include <iomanip> // Include the input/output manipulation library
#include <string> // Include the string library
#include <cstdio> // Include the C standard input/output library
#include <cstdlib> // Include the C standard library
#include <vector> // Include the vector library

class Vehicle // Declare a class named "Vehicle"
{
protected: // Protected section of the class


    std::string name; // Declare a string variable to store the name of the vehicle
    int year; // Declare an integer variable to store the manufacturing year of the vehicle
    std::string engineType; // Declare a string variable to store the engine type of the vehicle
    int weight; // Declare an integer variable to store the weight of the vehicle
    int seatingCapacity; // Declare an integer variable to store the seating capacity of the vehicle
    int cargoCapacity; // Declare an integer variable to store the cargo capacity of the vehicle
    double condition; // Declare a double variable to store the condition of the vehicle
    double price; // Declare a double variable to store the price of the vehicle

public: // Public section of the class

    Vehicle() : name(""), year(0), engineType(""), weight(0), seatingCapacity(0), cargoCapacity(0), condition(0.0), price(0.0) {} // Default constructor for the Vehicle class

    Vehicle(std::string name, int year, std::string engineType, double weight, int seatingCapacity, double cargoCapacity, double condition, double price) // Parameterized constructor for the Vehicle class
        : name(name), year(year), engineType(engineType), weight(weight), seatingCapacity(seatingCapacity), cargoCapacity(cargoCapacity), condition(condition), price(price) {}

    virtual ~Vehicle() {} // Virtual destructor for the Vehicle class

    virtual void display() // Virtual function to display the details of the vehicle
    {
        std::cout << "                                                                     Name: " << name << std::endl; // Print the name of the vehicle
        std::cout << "                                                                     Manufacturing Year: " << year << std::endl; // Print the manufacturing year of the vehicle
        std::cout << "                                                                     Engine Type: " << engineType << std::endl; // Print the engine type of the vehicle
        std::cout << "                                                                     Weight: " << weight << std::endl; // Print the weight of the vehicle
        std::cout << "                                                                     Seating Capacity: " << seatingCapacity << " seat(s)" << std::endl; // Print the seating capacity of the vehicle
        std::cout << "                                                                     Cargo Capacity: " << cargoCapacity << " kg" << std::endl; // Print the cargo capacity of the vehicle
        std::cout << "                                                                     Condition: " << condition << "%" << std::endl; // Print the condition of the vehicle
        std::cout << "                                                                     Price: RM" << std::fixed << std::setprecision(2) << price << std::endl; // Print the price of the vehicle
    }

    const std::string& getName() const // Getter function to get the name of the vehicle
    {  
        return name;
    }

    friend std::ostream& operator<<(std::ostream& os, const Vehicle& vehicle); // Friend function to overload the insertion operator (<<) for the Vehicle class
};

std::ostream& operator<<(std::ostream& os, const Vehicle& vehicle) 
{
    os << "                                                                     Name: " << vehicle.name << std::endl; // Print the name of the vehicle
    os << "                                                                     Manufacturing Year: " << vehicle.year << std::endl; // Print the manufacturing year of the vehicle
    os << "                                                                     Engine Type: " << vehicle.engineType << std::endl; // Print the engine type of the vehicle
    os << "                                                                     Weight: " << vehicle.weight << " kg" << std::endl; // Print the weight of the vehicle
    os << "                                                                     Seating Capacity: " << vehicle.seatingCapacity << " seat(s)" << std::endl; // Print the seating capacity of the vehicle
    os << "                                                                     Cargo Capacity: " << vehicle.cargoCapacity << " kg" << std::endl; // Print the cargo capacity of the vehicle
    os << "                                                                     Condition: " << vehicle.condition << "%" << std::endl; // Print the condition of the vehicle
    os << "                                                                     Price: RM" << std::fixed << std::setprecision(2) << vehicle.price << std::endl; // Print the price of the vehicle
    return os; // Return the modified output stream object
}

class AirVehicle : public Vehicle
{
private:
    int maxAltitude; // Maximum altitude of the air vehicle

public:
    AirVehicle(std::string name, int year, std::string engineType, double weight, int seatingCapacity, double cargoCapacity, double condition, double price, int maxAltitude)
        : Vehicle(name, year, engineType, weight, seatingCapacity, cargoCapacity, condition, price), maxAltitude(maxAltitude) {} // Constructor for the AirVehicle class, initializes the base class and sets the maxAltitude

    void display() override {
        std::cout << "                                                                     Type: Air" << std::endl; // Print the vehicle type
        Vehicle::display(); // Call the base class display() function
        std::cout << "                                                                     Max Altitude: " << maxAltitude << " meter" << std::endl; // Print the maximum altitude
    }

    friend std::ostream& operator<<(std::ostream& os, const AirVehicle& airVehicle); // Friend function to overload the insertion operator (<<) for the AirVehicle class
};

std::ostream& operator<<(std::ostream& os, const AirVehicle& airVehicle) {
    os << "                                                                     Type: Air" << std::endl; // Print the vehicle type
    os << static_cast<const Vehicle&>(airVehicle); // Call the base class operator<< function using static_cast
    os << "                                                                     Max Altitude: " << airVehicle.maxAltitude << " meter" << std::endl; // Print the maximum altitude
    return os; // Return the modified output stream object
}


class LandVehicle : public Vehicle
{
private:
    int numWheels; // Number of wheels of the land vehicle

public:
    LandVehicle(std::string name, int year, std::string engineType, double weight, int seatingCapacity, double cargoCapacity, double condition, double price, int numWheels)
        : Vehicle(name, year, engineType, weight, seatingCapacity, cargoCapacity, condition, price), numWheels(numWheels) {} // Constructor for the LandVehicle class, initializes the base class and sets the numWheels

    void display() override
    {
        std::cout << "                                                                     Type: Land" << std::endl; // Print the vehicle type
        Vehicle::display(); // Call the base class display() function
        std::cout << "                                                                     Number of Wheels: " << numWheels << std::endl; // Print the number of wheels
    }

    friend std::ostream& operator<<(std::ostream& os, const LandVehicle& landVehicle); // Friend function to overload the insertion operator (<<) for the LandVehicle class
};

std::ostream& operator<<(std::ostream& os, const LandVehicle& landVehicle)
{
    os << "                                                                     Type: Land" << std::endl; // Print the vehicle type
    os << static_cast<const Vehicle&>(landVehicle); // Call the base class operator<< function using static_cast
    os << "                                                                     Number of Wheels: " << landVehicle.numWheels << std::endl; // Print the number of wheels
    return os; // Return the modified output stream object
}

class SeaVehicle : public Vehicle
{
private:
    int displacement; // Displacement of the sea vehicle

public:
    SeaVehicle(std::string name, int year, std::string engineType, double weight, int seatingCapacity, int cargoCapacity, double condition, double price, int displacement)
        : Vehicle(name, year, engineType, weight, seatingCapacity, cargoCapacity, condition, price), displacement(displacement) {} // Constructor for the SeaVehicle class, initializes the base class and sets the displacement

    void display() override
    {
        std::cout << "                                                                     Type: Sea" << std::endl; // Print the vehicle type
        Vehicle::display(); // Call the base class display() function
        std::cout << "                                                                     Displacement: " << displacement << " kg" << std::endl; // Print the displacement
    }

    friend std::ostream& operator<<(std::ostream& os, const SeaVehicle& seaVehicle); // Friend function to overload the insertion operator (<<) for the SeaVehicle class
};

std::ostream& operator<<(std::ostream& os, const SeaVehicle& seaVehicle)
{
    os << "                                                                     Type: Sea" << std::endl; // Print the vehicle type
    os << static_cast<const Vehicle&>(seaVehicle); // Call the base class operator<< function using static_cast
    os << "                                                                     Displacement: " << seaVehicle.displacement << " kg" << std::endl; // Print the displacement
    return os; // Return the modified output stream object
}


int main()
{
    const int MAX_VEHICLES = 100; // Maximum number of vehicles
    Vehicle* vehicles[MAX_VEHICLES]; // Array of vehicle pointers
    int numVehicles = 1; // Number of vehicles initialized to 1
    FILE *fptr; // File pointer
    char c, choice; // Characters used for reading from files and storing user input
    system("cls"); // Clears the console screen
    system("color 0B"); // Set console color
    fptr=fopen("Description.txt","r"); // Open and read the "Description.txt" file
    c = fgetc(fptr); // Read a character from the file
    while (c != EOF) // Loop until the end of the file is reached
    {
        printf("%c", c); // Print the character
        c = fgetc(fptr); // Read the next character
    }
    fclose(fptr); // Close the file
    system("pause"); // Pause the program execution

    do {
        system("cls"); // Clear the console screen
        fptr=fopen("MainMenu.txt","r"); // Open and read the "MainMenu.txt" file
        c = fgetc(fptr); // Read a character from the file
        while (c != EOF) // Loop until the end of the file is reached
        {
            printf("%c", c); // Print the character
            c = fgetc(fptr); // Read the next character
        }
        fclose(fptr); // Close the file
        std::cin >> choice; // Read user input

        switch (choice) {
            case '1':
            {
                system("cls"); // Clear the console screen
                fptr=fopen("Group5.txt","r"); // Open and read the "Group5.txt" file
                c = fgetc(fptr); // Read a character from the file
                while (c != EOF) // Loop until the end of the file is reached
                {
                    printf("%c", c); // Print the character
                    c = fgetc(fptr); // Read the next character
                }
                fclose(fptr); // Close the file
                std::cout << "\n                                                                     ====================== Enter Vehicle Information =====================" << std::endl; // Print a message
                if (numVehicles >= MAX_VEHICLES)
                {
                    std::cout << "                                                                     Invalid vehicle type!" << std::endl; // Print an error message
                    std::cout << "                                                                     ";
                    system("pause"); // Pause the program execution
                    break; // Exit the switch statement
                }

                std::cout << "                                                                     Enter vehicle type (A for Air, L for Land, S for Sea): "; // Prompt the user for vehicle type
                char vehicleType; // Variable to store the vehicle type
                std::cin >> vehicleType; // Read user input

                if (vehicleType!='A'&&vehicleType!='a'&&vehicleType!='L'&&vehicleType!='l'&&vehicleType!='S'&&vehicleType!='s')
                {
                    std::cout << "                                                                     Maximum number of vehicles reached!" << std::endl; // Print an error message
                    break; // Exit the switch statement
                }

                std::cout << "                                                                     Enter Name: "; // Prompt the user for vehicle name
                std::string name; // Variable to store the vehicle name
                std::cin.ignore(); // Ignore any remaining characters in the input buffer
                std::getline(std::cin, name); // Read the entire line of input

                std::cout << "                                                                     Enter Manufacturing Year: "; // Prompt the user for manufacturing year
                int year; // Variable to store the manufacturing year
                std::cin >> year; // Read user input

                std::cout << "                                                                     Enter Engine Type: "; // Prompt the user for engine type
                std::string engineType; // Variable to store the engine type
                std::cin >> engineType; // Read user input

                std::cout << "                                                                     Enter Weight(in kilograms): "; // Prompt the user for weight
                double weight; // Variable to store the weight
                std::cin >> weight; // Read user input

                std::cout << "                                                                     Enter Seating Capacity(seats): "; // Prompt the user for seating capacity
                int seatingCapacity; // Variable to store the seating capacity
                std::cin >> seatingCapacity; // Read user input

                std::cout << "                                                                     Enter Cargo Capacity(in kilograms): "; // Prompt the user for cargo capacity
                double cargoCapacity; // Variable to store the cargo capacity
                std::cin >> cargoCapacity; // Read user input

                std::cout << "                                                                     Enter Condition(in percentage): "; // Prompt the user for condition
                double condition; // Variable to store the condition
                std::cin >> condition; // Read user input

                if(condition>100)
                {
                    std::cout << "                                                                     Invalid Percentage Value: "; // Print an error message
                    std::cout << "                                                                     ";
                    system("pause"); // Pause the program execution
                    break; // Exit the switch statement
                }

                std::cout << "                                                                     Enter Price: RM"; // Prompt the user for price
                double price; // Variable to store the price
                std::cin >> price; // Read user input

                if (vehicleType == 'A' || vehicleType == 'a')
                {
                    std::cout << "                                                                     Enter Max Altitude(in meters): "; // Prompt the user for max altitude
                    int maxAltitude; // Variable to store the max altitude
                    std::cin >> maxAltitude; // Read user input
                    vehicles[numVehicles] = new AirVehicle(name, year, engineType, weight, seatingCapacity, cargoCapacity, condition, price, maxAltitude); // Create a new AirVehicle object
                }
                else if (vehicleType == 'L' || vehicleType == 'l')
                {
                    std::cout << "                                                                     Enter Number of Wheels: "; // Prompt the user for number of wheels
                    int numWheels; // Variable to store the number of wheels
                    std::cin >> numWheels; // Read user input
                    vehicles[numVehicles] = new LandVehicle(name, year, engineType, weight, seatingCapacity, cargoCapacity, condition, price, numWheels); // Create a new LandVehicle object
                }
                else if (vehicleType == 'S' || vehicleType == 's')
                {
                    std::cout << "                                                                     Enter Displacement(in kilograms): "; // Prompt the user for displacement
                    int displacement; // Variable to store the displacement
                    std::cin >> displacement; // Read user input
                    vehicles[numVehicles] = new SeaVehicle(name, year, engineType, weight, seatingCapacity, cargoCapacity, condition, price, displacement); // Create a new SeaVehicle object
                }
                else
                {
                    std::cout << "                                                                     Invalid vehicle type!" << std::endl; // Print an error message
                    break; // Exit the switch statement
                }
                numVehicles++; // Increment the number of vehicles
                std::cout << "                                                                     Vehicle added successfully!" << std::endl; // Print a success message
                std::cout << "                                                                     ";
                system("pause"); // Pause the program execution
                break; // Exit the switch statement
            }
            case '2': 
            {
                system("cls"); // Clear the console screen
                fptr=fopen("Group5.txt","r"); // Open the file "Group5.txt" in read mode
                c = fgetc(fptr); // Read the first character from the file
                while (c != EOF) // Loop until the end of the file is reached
                {
                    printf("%c", c); // Print the character to the console
                    c = fgetc(fptr); // Read the next character from the file
                }
                fclose(fptr); // Close the file
                std::cout << "\n                                                                     ======================= Edit Vehicle Information =====================" << std::endl; // Print a header message
                std::cout << "                                                                     Enter vehicle index to edit (1-" << numVehicles - 1 << "): "; // Prompt the user for the vehicle index to edit
                int index; // Variable to store the index
                std::cin >> index; // Read user input
                std::cout << std::endl;

                if (index >= 0 && index < numVehicles) // Check if the index is valid
                {
                    vehicles[index]->display(); // Display the details of the vehicle at the specified index

                    std::cout  << "\n                                                                     Enter new Name: "; // Prompt the user for the new name
                    std::string name; // Variable to store the new name
                    std::cin.ignore();
                    std::getline(std::cin, name); // Read user input

                    std::cout << "                                                                     Enter new Manufacturing Year: "; // Prompt the user for the new manufacturing year
                    int year; // Variable to store the new manufacturing year
                    std::cin >> year; // Read user input

                    std::cout << "                                                                     Enter new Engine Type: "; // Prompt the user for the new engine type
                    std::string engineType; // Variable to store the new engine type
                    std::cin >> engineType; // Read user input

                    std::cout << "                                                                     Enter new Weight(in kilograms): "; // Prompt the user for the new weight
                    double weight; // Variable to store the new weight
                    std::cin >> weight; // Read user input

                    std::cout << "                                                                     Enter new Seating Capacity(seats): "; // Prompt the user for the new seating capacity
                    int seatingCapacity; // Variable to store the new seating capacity
                    std::cin >> seatingCapacity; // Read user input

                    std::cout << "                                                                     Enter new Cargo Capacity(in kilograms): "; // Prompt the user for the new cargo capacity
                    double cargoCapacity; // Variable to store the new cargo capacity
                    std::cin >> cargoCapacity; // Read user input

                    std::cout << "                                                                     Enter new Condtion(in percentage): "; // Prompt the user for the new condition
                    double condition; // Variable to store the new condition
                    std::cin >> condition; // Read user input

                    if(condition>100)
                    {
                        std::cout << "                                                                     Invalid Percentage Value: "; // Print an error message
                        std::cout << "                                                                     ";
                        system("pause"); // Pause the program execution
                        break; // Exit the switch statement
                    }


                    std::cout << "                                                                     Enter new Price: RM"; // Prompt the user for the new price
                    double price; // Variable to store the new price
                    std::cin >> price; // Read user input

                    if (dynamic_cast<AirVehicle*>(vehicles[index])) // Check if the vehicle at the specified index is an AirVehicle
                    {
                        std::cout << "                                                                     Enter new Max Altitude(in meters): "; // Prompt the user for the new max altitude
                        int maxAltitude; // Variable to store the new max altitude
                        std::cin >> maxAltitude; // Read user input
                        delete vehicles[index]; // Delete the existing vehicle object
                        vehicles[index] = new AirVehicle(name, year, engineType, weight, seatingCapacity, cargoCapacity, condition, price, maxAltitude); // Create a new AirVehicle object and assign it to the specified index
                    }
                    else if (dynamic_cast<LandVehicle*>(vehicles[index])) // Check if the vehicle at the specified index is a LandVehicle
                    {
                        std::cout << "                                                                     Enter new Number of Wheels: "; // Prompt the user for the new number of wheels
                        int numWheels; // Variable to store the new number of wheels
                        std::cin >> numWheels; // Read user input
                        delete vehicles[index]; // Delete the existing vehicle object
                        vehicles[index] = new LandVehicle(name, year, engineType, weight, seatingCapacity, cargoCapacity, condition, price, numWheels); // Create a new LandVehicle object and assign it to the specified index
                    }
                    else if (dynamic_cast<SeaVehicle*>(vehicles[index])) // Check if the vehicle at the specified index is a SeaVehicle
                    {
                        std::cout << "                                                                     Enter new Displacement(in kilograms): "; // Prompt the user for the new displacement
                        int displacement; // Variable to store the new displacement
                        std::cin >> displacement; // Read user input
                        delete vehicles[index]; // Delete the existing vehicle object
                        vehicles[index] = new SeaVehicle(name, year, engineType, weight, seatingCapacity, cargoCapacity, condition, price, displacement); // Create a new SeaVehicle object and assign it to the specified index
                    }
                    std::cout << "                                                                     Vehicle edited successfully!" << std::endl; // Print a success message
                }
                else
                {
                    std::cout << "                                                                     Invalid vehicle index!" << std::endl; // Print an error message
                }
                std::cout << "                                                                     ";
                system("pause"); // Pause the program execution
                break; // Exit the switch statement
            }
            case '3': 
            {
                system("cls"); // Clear the console screen
                fptr=fopen("Group5.txt","r"); // Open the file "Group5.txt" in read mode
                c = fgetc(fptr); // Read the first character from the file
                while (c != EOF) // Loop until the end of the file is reached
                {
                    printf("%c", c); // Print the character to the console
                    c = fgetc(fptr); // Read the next character from the file
                }
                fclose(fptr); // Close the file
                std::cout << "\n                                                                     =========================== Delete Vehicle ==========================" << std::endl; // Print a header message
                std::cout << "                                                                     Enter vehicle index to delete (1-" << numVehicles - 1 << "): "; // Prompt the user for the vehicle index to delete
                int index; // Variable to store the index
                std::cin >> index; // Read user input

                if (index >= 0 && index < numVehicles) // Check if the index is valid
                {
                    delete vehicles[index]; // Delete the vehicle object at the specified index
                    vehicles[index] = nullptr; // Set the pointer to null

                    // Shift remaining vehicles to fill the gap
                    for (int i = index; i < numVehicles - 1; i++) // Iterate over the remaining vehicles
                    {
                        vehicles[i] = vehicles[i + 1]; // Move each vehicle one position up
                    }
                    numVehicles--; // Decrease the total number of vehicles
                    std::cout << "                                                                     Vehicle deleted successfully!" << std::endl; // Print a success message
                }
                else
                {
                    std::cout << "                                                                     Invalid vehicle index!" << std::endl; // Print an error message
                }
                std::cout << "                                                                     ";
                system("pause"); // Pause the program execution
                break; // Exit the switch statement
            }
            case '4': 
            {
                system("cls"); // Clear the console screen
                fptr=fopen("Group5.txt","r"); // Open the file "Group5.txt" in read mode
                c = fgetc(fptr); // Read the first character from the file
                while (c != EOF) // Loop until the end of the file is reached
                {
                    printf("%c", c); // Print the character to the console
                    c = fgetc(fptr); // Read the next character from the file
                }
                fclose(fptr); // Close the file
                std::cout << "\n                                                                     ======================= Displaying All Vehicles ======================" << std::endl; // Print a header message
                for (int i = 1; i < numVehicles; i++) // Iterate over the vehicles
                {
                    std::cout << "                                                                     Vehicle " << i << ":" << std::endl; // Print the vehicle number
                    vehicles[i]->display(); // Display the vehicle information
                    std::cout << std::endl; // Print a new line
                }
                std::cout << "                                                                     ";
                system("pause"); // Pause the program execution
                break; // Exit the switch statement
            }
            case '5': 
            {
                system("cls"); // Clear the console screen
                fptr = fopen("Group5.txt", "r"); // Open the file "Group5.txt" in read mode
                c = fgetc(fptr); // Read the first character from the file
                while (c != EOF) // Loop until the end of the file is reached
                {
                    printf("%c", c); // Print the character to the console
                    c = fgetc(fptr); // Read the next character from the file
                }
                fclose(fptr); // Close the file
                std::cout << "\n                                                                     ======================= Search Vehicles By Name ======================" << std::endl; // Print a header message
                if (numVehicles > 0) // Check if there are vehicles available
                {
                    std::cout << "                                                                     Enter vehicle name to search: "; // Prompt the user for the vehicle name
                    std::string name; // Variable to store the vehicle name
                    std::cin.ignore(); // Ignore any previous input
                    std::getline(std::cin, name); // Read the vehicle name from the user

                    std::vector<Vehicle*> matchingVehicles; // Vector to store the matching vehicles
                    for (int i = 1; i < numVehicles; i++) // Iterate over the vehicles
                    {
                        if (vehicles[i]->getName() == name) // Check if the vehicle name matches
                        {
                            matchingVehicles.push_back(vehicles[i]); // Add the vehicle to the matching vehicles vector
                        }
                    }
                    int i=0; // Counter for displaying vehicle number
                    if (!matchingVehicles.empty()) // Check if there are matching vehicles
                    {
                        std::cout << std::endl;
                        for (Vehicle* vehicle : matchingVehicles) // Iterate over the matching vehicles
                        {
                            i++;
                            std::cout << "                                                                     Vehicle " << i << ":" << std::endl; // Print the vehicle number
                            vehicle->display(); // Display the vehicle information
                            std::cout << std::endl; // Print a new line
                        }
                    }
                    else
                    {
                        std::cout << "                                                                     Vehicle not found." << std::endl; // Print a message indicating no matching vehicles were found
                    }
                }
                else
                {
                    std::cout << "                                                                     No vehicles available." << std::endl; // Print a message indicating no vehicles are available
                }
                std::cout << "                                                                     ";
                system("pause"); // Pause the program execution
                break; // Exit the switch statement
            }
            case '6': 
            {
                system("cls"); // Clear the console screen
                fptr=fopen("Group5.txt","r"); // Open the file "Group5.txt" in read mode
                c = fgetc(fptr); // Read the first character from the file
                while (c != EOF) // Loop until the end of the file is reached
                {
                    printf("%c", c); // Print the character to the console
                    c = fgetc(fptr); // Read the next character from the file
                }
                fclose(fptr); // Close the file
                std::cout << "\n                                                                     ===================== Search Vehicles By Filter ======================" << std::endl; // Print a header message
                if (numVehicles > 0) // Check if there are vehicles available
                {
                    char vehicleType; // Variable to store the vehicle type
                    std::cout << "                                                                     Enter vehicle type to filter (A for Air, L for Land, S for Sea): "; // Prompt the user for the vehicle type
                    std::cin >> vehicleType; // Read the vehicle type from the user

                    bool found = false; // Flag to track if any vehicles were found
                    for (int i = 1; i < numVehicles; i++) // Iterate over the vehicles
                    {
                        std::cout << std::endl;
                        if (vehicleType == 'A'||vehicleType == 'a' && dynamic_cast<AirVehicle*>(vehicles[i])) // Check if the vehicle type is 'A' or 'a' and the vehicle is an AirVehicle
                        {
                            vehicles[i]->display(); // Display the vehicle information
                            found = true; // Set the found flag to true
                        }
                        else if (vehicleType == 'L'||vehicleType == 'l' && dynamic_cast<LandVehicle*>(vehicles[i])) // Check if the vehicle type is 'L' or 'l' and the vehicle is a LandVehicle
                        {
                            vehicles[i]->display(); // Display the vehicle information
                            found = true; // Set the found flag to true
                        } 
                        else if (vehicleType == 'S'||vehicleType == 's' && dynamic_cast<SeaVehicle*>(vehicles[i])) // Check if the vehicle type is 'S' or 's' and the vehicle is a SeaVehicle
                        {
                            vehicles[i]->display(); // Display the vehicle information
                            found = true; // Set the found flag to true
                        }
                    }
                    if (!found) // Check if no vehicles of the specified type were found
                    {
                        std::cout << "                                                                     No vehicles of the specified type found." << std::endl; // Print a message indicating no vehicles were found
                    }
                }
                else
                {
                    std::cout << "                                                                     No vehicles available." << std::endl; // Print a message indicating no vehicles are available
                }
                std::cout << std::endl << "                                                                     ";
                system("pause"); // Pause the program execution
                break; // Exit the switch statement
            }
            case '0':
            {
                system("cls"); // Clears the console screen
                fptr=fopen("Exit.txt","r"); // Opens the file "Exit.txt" in read mode
                c = fgetc(fptr); // Reads the first character from the file

                while (c != EOF) // Loops until the end of the file is reached
                {
                    printf("%c", c); // Prints the character to the console
                    c = fgetc(fptr); // Reads the next character from the file
                }

                fclose(fptr); // Closes the file
                system("pause"); // Pauses the program and waits for user input
                break; // Exits the switch statement
            }
            default:
                std::cout << "                                                                     Invalid choice!" << std::endl; // Prints an error message
                std::cout << "                                                                     ";
                system("pause"); // Pauses the program and waits for user input
                break; // Exits the switch statement
        }
        std::cout << std::endl; // Prints a new line
    } while (choice != '0'); // Loops until the user enters '0'
    // Clean up allocated memory
    for (int i = 0; i < numVehicles; i++) 
    {
        delete vehicles[i]; // Deletes each vehicle object
    }
    return 0; // Indicates successful program execution
}