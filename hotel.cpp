#include <iostream.h>
#include <fstream.h>
#include <conio.h>
#include <stdio.h>

// Function declarations
void viewRooms();
void bookRoom();
void viewBookings();

void main() {
    int choice;

    while (1) { // 1 means true in old C++
        clrscr(); // Clears the screen on every loop execution
        
        cout << "====================================\n";
        cout << "     --- HOTEL MANAGEMENT SYSTEM --- \n";
        cout << "====================================\n";
        cout << "1. View Available Rooms & Rates\n";
        cout << "2. Book a New Room\n";
        cout << "3. View All Booking Records\n";
        cout << "4. Exit Program\n";
        cout << "------------------------------------\n";
        cout << "Enter your choice (1-4): ";
        cin >> choice;

        switch (choice) {
            case 1:
                viewRooms();
                break;
            case 2:
                bookRoom();
                break;
            case 3:
                viewBookings();
                break;
            case 4:
                cout << "\nExiting system. Press any key to close...";
                getch();
                return;
            default:
                cout << "\n[Error] Invalid choice! Press any key to try again.";
                getch();
        }
    }
}

// 1. Function to display room information
void viewRooms() {
    clrscr();
    cout << "====================================\n";
    cout << "        --- ROOM DETAILS ---        \n";
    cout << "====================================\n";
    cout << "Room 101 -> Deluxe Suite    ($150 / night)\n";
    cout << "Room 102 -> Super Deluxe    ($250 / night)\n";
    cout << "Room 103 -> Executive Room  ($400 / night)\n";
    cout << "====================================\n";
    cout << "\nPress any key to return to main menu...";
    getch();
}

// 2. Function to book a room and save to a file
void bookRoom() {
    clrscr();
    char guestName[50];
    int roomNo;
    int days;
    int rent = 0;

    cout << "--- New Booking Form ---\n";
    cout << "------------------------\n\n";
    
    // Clear input buffer so gets() works properly
    fflush(stdin); 
    cout << "Enter Guest Full Name: ";
    gets(guestName); // Allows inputting names with spaces

    cout << "Select Room Number (101, 102, 103): ";
    cin >> roomNo;

    // Calculate rent based on room selection
    if (roomNo == 101) rent = 150;
    else if (roomNo == 102) rent = 250;
    else if (roomNo == 103) rent = 400;
    else {
        cout << "\n[Error] Invalid room number! Booking cancelled.\n";
        cout << "Press any key to return...";
        getch();
        return;
    }

    cout << "Enter number of days to stay: ";
    cin >> days;

    int totalBill = rent * days;

    // Open file in append mode (ios::app saves new data below old data)
    ofstream outFile("hotel.txt", ios::app);
    
    if (outFile) {
        outFile << "Guest: " << guestName << " | Room: " << roomNo 
                << " | Days: " << days << " | Total Bill: $" << totalBill << "\n";
        outFile.close(); // Close file after writing
        
        cout << "\n====================================\n";
        cout << "  [Success] Room booked successfully!\n";
        cout << "  Total Payable Amount: $" << totalBill << "\n";
        cout << "====================================\n";
    } else {
        cout << "\n[Error] Failed to open database file!\n";
    }

    cout << "\nPress any key to return to main menu...";
    getch();
}

// 3. Function to read and display booking data from the file
void viewBookings() {
    clrscr();
    char line[100];
    
    // Open file for reading
    ifstream inFile("hotel.txt"); 

    cout << "====================================\n";
    cout << "     --- ALL BOOKING RECORDS ---    \n";
    cout << "====================================\n";

    if (inFile) {
        int count = 0;
        // Read file line by line using old Turbo C++ string extraction
        while (inFile.getline(line, 100)) {
            cout << line << "\n";
            count++;
        }
        inFile.close();

        if (count == 0) {
            cout << "No bookings found in the system.\n";
        }
    } else {
        cout << "No record file found. Try making a booking first!\n";
    }

    cout << "====================================\n";
    cout << "\nPress any key to return to main menu...";
    getch();
}
