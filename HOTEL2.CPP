#include <iostream.h>
#include <fstream.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <dos.h>

#define GST 0.18
#define DAY_SECONDS 86400L

// ======================================================
//                  BAAV HOTEL
//          HOTEL MANAGEMENT SYSTEM
//              TURBO C++ VERSION
// ======================================================

// ======================================================
// GLOBAL GUEST INFORMATION
// ======================================================

char loggedGuestName[50];
char loggedGuestPhone[20];
int loggedGuestID = 0;


// ======================================================
// FUNCTION DECLARATIONS
// ======================================================

// MAIN
void startMenu();
void adminLogin();
void mainMenu();

// GUEST
void guestRegistration();
int guestLogin();
void guestMenu();
void guestBookRoom();
void guestMyBooking();
void guestCancelBooking();

// ADMIN
void viewRooms();
void bookRoom();
void viewBookings();
void searchBooking();
void cancelBooking();
void checkoutBooking();
void revenueReport();

// ROOM
int getRoomRate(int roomNo);
int isRoomBooked(int roomNo);
int getNextBookingID();

// FOOD
int getFoodRate(int foodChoice);
void getFoodName(int foodChoice, char foodName[]);

// DATABASE
void cleanupExpiredBookings();

// TIME
void displayDateTime(long t);

// PAYMENT
void paymentMenu(float amount);
void cashPayment(float amount);
void cardPayment(float amount);
void upiPayment(float amount);

// OTHER
void pauseScreen();


// ======================================================
// MAIN
// ======================================================

void main()
{
    clrscr();

    startMenu();
}


// ======================================================
// START MENU
// ======================================================

void startMenu()
{
    int choice;

    while (1)
    {
        clrscr();

        cout << "\n";
        cout << "====================================================\n";
        cout << "                    BAAV HOTEL\n";
        cout << "             HOTEL MANAGEMENT SYSTEM\n";
        cout << "====================================================\n";

        cout << "\n";
        cout << " 1. Admin Login\n";
        cout << " 2. Guest Login\n";
        cout << " 3. Guest Registration\n";
        cout << " 4. Exit";

        cout << "\n\n----------------------------------------------------\n";
        cout << " Enter Your Choice : ";

        cin >> choice;

        switch (choice)
        {
            case 1:
                adminLogin();
                mainMenu();
                break;

            case 2:
                if (guestLogin())
                    guestMenu();
                break;

            case 3:
                guestRegistration();
                break;

            case 4:
                clrscr();

                cout << "\n";
                cout << "====================================================\n";
                cout << "                    BAAV HOTEL\n";
                cout << "====================================================\n";

                cout << "\n Thank You For Visiting BAAV HOTEL!";

                cout << "\n\n====================================================\n";

                getch();

                return;

            default:
                cout << "\nInvalid Choice!";
                getch();
        }
    }
}


// ======================================================
// ADMIN LOGIN
// ======================================================

void adminLogin()
{
    char username[20];
    char password[20];

    int attempts = 0;

    while (attempts < 3)
    {
        clrscr();

        cout << "\n";
        cout << "====================================================\n";
        cout << "                    BAAV HOTEL\n";
        cout << "                  ADMIN LOGIN\n";
        cout << "====================================================\n";

        cout << "\nUsername : ";
        cin >> username;

        cout << "Password : ";
        cin >> password;

        if (strcmp(username, "vishnu") == 0 &&
            strcmp(password, "baavlo12") == 0)
        {
            cout << "\n\nLogin Successful!";

            delay(1000);

            return;
        }

        attempts++;

        cout << "\n\nInvalid Username or Password!";
        cout << "\nAttempts Left : " << 3 - attempts;

        getch();
    }

    cout << "\n\nToo Many Failed Attempts!";

    getch();

    exit(0);
}


// ======================================================
// GUEST REGISTRATION
// ======================================================

void guestRegistration()
{
    clrscr();

    char name[50];
    char phone[20];
    char username[30];
    char password[30];

    char savedName[50];
    char savedPhone[20];
    char savedUsername[30];
    char savedPassword[30];

    int guestID;
    int savedID;

    int found = 0;

    cout << "====================================================\n";
    cout << "                    BAAV HOTEL\n";
    cout << "                GUEST REGISTRATION\n";
    cout << "====================================================\n";

    fflush(stdin);

    cout << "\nFull Name : ";
    gets(name);

    if (strlen(name) == 0)
    {
        cout << "\nName Cannot Be Empty!";
        pauseScreen();
        return;
    }

    cout << "Phone     : ";
    gets(phone);

    if (strlen(phone) == 0)
    {
        cout << "\nPhone Cannot Be Empty!";
        pauseScreen();
        return;
    }

    cout << "Username  : ";
    gets(username);

    if (strlen(username) == 0)
    {
        cout << "\nUsername Cannot Be Empty!";
        pauseScreen();
        return;
    }

    cout << "Password  : ";
    gets(password);

    if (strlen(password) == 0)
    {
        cout << "\nPassword Cannot Be Empty!";
        pauseScreen();
        return;
    }

    // --------------------------------------------------
    // CHECK USERNAME
    // --------------------------------------------------

    ifstream checkFile("guest.dat");

    if (checkFile)
    {
        while (checkFile >> savedID)
        {
            checkFile.ignore();

            checkFile.getline(
                savedName,
                50,
                '|'
            );

            checkFile.getline(
                savedPhone,
                20,
                '|'
            );

            checkFile.getline(
                savedUsername,
                30,
                '|'
            );

            checkFile.getline(
                savedPassword,
                30
            );

            if (strcmp(
                savedUsername,
                username
            ) == 0)
            {
                found = 1;
                break;
            }
        }

        checkFile.close();
    }

    if (found)
    {
        cout << "\n\nUsername Already Exists!";

        pauseScreen();

        return;
    }

    // --------------------------------------------------
    // GET GUEST ID
    // --------------------------------------------------

    guestID = 1000;

    ifstream idFile("guest.dat");

    if (idFile)
    {
        while (idFile >> savedID)
        {
            idFile.ignore();

            idFile.getline(savedName, 50, '|');
            idFile.getline(savedPhone, 20, '|');
            idFile.getline(savedUsername, 30, '|');
            idFile.getline(savedPassword, 30);

            if (savedID >= guestID)
                guestID = savedID + 1;
        }

        idFile.close();
    }
    else
    {
        guestID = 1001;
    }

    // --------------------------------------------------
    // SAVE GUEST
    // --------------------------------------------------

    ofstream outFile(
        "guest.dat",
        ios::app
    );

    if (!outFile)
    {
        cout << "\n\n[ERROR] Cannot Open Guest Database!";

        pauseScreen();

        return;
    }

    outFile << guestID << "|";
    outFile << name << "|";
    outFile << phone << "|";
    outFile << username << "|";
    outFile << password << "\n";

    outFile.close();

    cout << "\n\n====================================================\n";
    cout << "             REGISTRATION SUCCESSFUL\n";
    cout << "====================================================\n";

    cout << "\nGuest ID  : " << guestID;
    cout << "\nName      : " << name;
    cout << "\nUsername  : " << username;

    cout << "\n\nYou Can Now Login As Guest.";

    pauseScreen();
}


// ======================================================
// GUEST LOGIN
// ======================================================

int guestLogin()
{
    char username[30];
    char password[30];

    char savedName[50];
    char savedPhone[20];
    char savedUsername[30];
    char savedPassword[30];

    int savedID;

    int attempts = 0;
    int found = 0;

    while (attempts < 3)
    {
        clrscr();

        cout << "====================================================\n";
        cout << "                    BAAV HOTEL\n";
        cout << "                  GUEST LOGIN\n";
        cout << "====================================================\n";

        cout << "\nUsername : ";
        cin >> username;

        cout << "Password : ";
        cin >> password;

        ifstream file("guest.dat");

        if (!file)
        {
            cout << "\n\nNo Guest Account Found!";
            cout << "\nPlease Register First.";

            pauseScreen();

            return 0;
        }

        found = 0;

        while (file >> savedID)
        {
            file.ignore();

            file.getline(
                savedName,
                50,
                '|'
            );

            file.getline(
                savedPhone,
                20,
                '|'
            );

            file.getline(
                savedUsername,
                30,
                '|'
            );

            file.getline(
                savedPassword,
                30
            );

            if (strcmp(
                username,
                savedUsername
            ) == 0 &&
                strcmp(
                password,
                savedPassword
            ) == 0)
            {
                loggedGuestID = savedID;

                strcpy(
                    loggedGuestName,
                    savedName
                );

                strcpy(
                    loggedGuestPhone,
                    savedPhone
                );

                found = 1;

                break;
            }
        }

        file.close();

        if (found)
        {
            cout << "\n\nLogin Successful!";

            delay(1000);

            return 1;
        }

        attempts++;

        cout << "\n\nInvalid Username or Password!";
        cout << "\nAttempts Left : "
             << 3 - attempts;

        getch();
    }

    cout << "\n\nToo Many Failed Attempts!";

    getch();

    return 0;
}


// ======================================================
// GUEST MENU
// ======================================================

void guestMenu()
{
    int choice;

    while (1)
    {
        cleanupExpiredBookings();

        clrscr();

        cout << "====================================================\n";
        cout << "                    BAAV HOTEL\n";
        cout << "                  GUEST DASHBOARD\n";
        cout << "====================================================\n";

        cout << "\nWelcome, "
             << loggedGuestName
             << "!";

        cout << "\n\n";
        cout << " 1. View Rooms & Rates\n";
        cout << " 2. Book a Room\n";
        cout << " 3. My Booking\n";
        cout << " 4. Cancel My Booking\n";
        cout << " 5. Logout";

        cout << "\n\n----------------------------------------------------\n";
        cout << " Enter Your Choice : ";

        cin >> choice;

        switch (choice)
        {
            case 1:
                viewRooms();
                break;

            case 2:
                guestBookRoom();
                break;

            case 3:
                guestMyBooking();
                break;

            case 4:
                guestCancelBooking();
                break;

            case 5:
                return;

            default:
                cout << "\nInvalid Choice!";
                getch();
        }
    }
}


// ======================================================
// MAIN ADMIN MENU
// ======================================================

void mainMenu()
{
    int choice;

    while (1)
    {
        cleanupExpiredBookings();

        clrscr();

        cout << "\n";
        cout << "====================================================\n";
        cout << "                    BAAV HOTEL\n";
        cout << "           HOTEL MANAGEMENT SYSTEM\n";
        cout << "                  ADMIN PANEL\n";
        cout << "====================================================\n";

        cout << "\n";
        cout << " 1. View Rooms & Rates\n";
        cout << " 2. Book a New Room\n";
        cout << " 3. View All Bookings\n";
        cout << " 4. Search Booking\n";
        cout << " 5. Cancel Booking\n";
        cout << " 6. Check-Out\n";
        cout << " 7. Revenue Report\n";
        cout << " 8. Logout\n";

        cout << "\n----------------------------------------------------\n";
        cout << " Enter Your Choice : ";

        cin >> choice;

        switch (choice)
        {
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
                searchBooking();
                break;

            case 5:
                cancelBooking();
                break;

            case 6:
                checkoutBooking();
                break;

            case 7:
                revenueReport();
                break;

            case 8:
                return;

            default:
                cout << "\nInvalid Choice!";
                getch();
        }
    }
}


// ======================================================
// GET ROOM RATE
// ======================================================

int getRoomRate(int roomNo)
{
    if (roomNo == 101)
        return 150;

    if (roomNo == 102)
        return 250;

    if (roomNo == 103)
        return 400;

    if (roomNo == 104)
        return 500;

    if (roomNo == 105)
        return 800;

    return 0;
}


// ======================================================
// GET FOOD RATE
// ======================================================

int getFoodRate(int foodChoice)
{
    if (foodChoice == 1)
        return 80;

    if (foodChoice == 2)
        return 70;

    if (foodChoice == 3)
        return 75;

    return 0;
}


// ======================================================
// GET FOOD NAME
// ======================================================

void getFoodName(
    int foodChoice,
    char foodName[]
)
{
    if (foodChoice == 1)
        strcpy(
            foodName,
            "Punjabi Breakfast"
        );

    else if (foodChoice == 2)
        strcpy(
            foodName,
            "Gujarati Breakfast"
        );

    else if (foodChoice == 3)
        strcpy(
            foodName,
            "South Indian Breakfast"
        );

    else
        strcpy(
            foodName,
            "No Breakfast"
        );
}


// ======================================================
// CHECK ROOM BOOKED
// ======================================================

int isRoomBooked(int roomNo)
{
    ifstream file("hotel.dat");

    int bookingID;

    char guestName[50];
    char phone[20];

    int savedRoom;
    int days;
    int rate;

    int foodChoice;
    int foodRate;

    float subtotal;
    float gst;
    float total;

    long checkoutTime;

    if (!file)
        return 0;

    while (file >> bookingID)
    {
        file.ignore();

        file.getline(
            guestName,
            50,
            '|'
        );

        file.getline(
            phone,
            20,
            '|'
        );

        file >> savedRoom;
        file.ignore();

        file >> days;
        file.ignore();

        file >> rate;
        file.ignore();

        file >> foodChoice;
        file.ignore();

        file >> foodRate;
        file.ignore();

        file >> subtotal;
        file.ignore();

        file >> gst;
        file.ignore();

        file >> total;
        file.ignore();

        file >> checkoutTime;
        file.ignore();

        if (savedRoom == roomNo)
        {
            if (time(NULL) < checkoutTime)
            {
                file.close();

                return 1;
            }
        }
    }

    file.close();

    return 0;
}


// ======================================================
// CLEANUP EXPIRED BOOKINGS
// ======================================================

void cleanupExpiredBookings()
{
    ifstream oldFile("hotel.dat");

    if (!oldFile)
        return;

    ofstream tempFile("temp.dat");

    if (!tempFile)
    {
        oldFile.close();

        return;
    }

    int bookingID;

    char guestName[50];
    char phone[20];

    int roomNo;
    int days;
    int rate;

    int foodChoice;
    int foodRate;

    float subtotal;
    float gst;
    float total;

    long checkoutTime;
    long currentTime;

    currentTime = time(NULL);

    while (oldFile >> bookingID)
    {
        oldFile.ignore();

        oldFile.getline(
            guestName,
            50,
            '|'
        );

        oldFile.getline(
            phone,
            20,
            '|'
        );

        oldFile >> roomNo;
        oldFile.ignore();

        oldFile >> days;
        oldFile.ignore();

        oldFile >> rate;
        oldFile.ignore();

        oldFile >> foodChoice;
        oldFile.ignore();

        oldFile >> foodRate;
        oldFile.ignore();

        oldFile >> subtotal;
        oldFile.ignore();

        oldFile >> gst;
        oldFile.ignore();

        oldFile >> total;
        oldFile.ignore();

        oldFile >> checkoutTime;
        oldFile.ignore();

        if (currentTime < checkoutTime)
        {
            tempFile
                << bookingID << "|"
                << guestName << "|"
                << phone << "|"
                << roomNo << "|"
                << days << "|"
                << rate << "|"
                << foodChoice << "|"
                << foodRate << "|"
                << subtotal << "|"
                << gst << "|"
                << total << "|"
                << checkoutTime
                << "\n";
        }
    }

    oldFile.close();
    tempFile.close();

    remove("hotel.dat");

    rename(
        "temp.dat",
        "hotel.dat"
    );
}


// ======================================================
// NEXT BOOKING ID
// ======================================================

int getNextBookingID()
{
    ifstream file("hotel.dat");

    int bookingID;

    int lastID = 1000;

    char guestName[50];
    char phone[20];

    int roomNo;
    int days;
    int rate;

    int foodChoice;
    int foodRate;

    float subtotal;
    float gst;
    float total;

    long checkoutTime;

    if (!file)
        return 1001;

    while (file >> bookingID)
    {
        file.ignore();

        file.getline(
            guestName,
            50,
            '|'
        );

        file.getline(
            phone,
            20,
            '|'
        );

        file >> roomNo;
        file.ignore();

        file >> days;
        file.ignore();

        file >> rate;
        file.ignore();

        file >> foodChoice;
        file.ignore();

        file >> foodRate;
        file.ignore();

        file >> subtotal;
        file.ignore();

        file >> gst;
        file.ignore();

        file >> total;
        file.ignore();

        file >> checkoutTime;
        file.ignore();

        if (bookingID > lastID)
            lastID = bookingID;
    }

    file.close();

    return lastID + 1;
}


// ======================================================
// DISPLAY DATE TIME
// ======================================================

void displayDateTime(long t)
{
    time_t temp;

    temp = (time_t)t;

    cout << ctime(&temp);
}


// ======================================================
// VIEW ROOMS
// ======================================================

void viewRooms()
{
    clrscr();

    cleanupExpiredBookings();

    cout << "====================================================\n";
    cout << "                    BAAV HOTEL\n";
    cout << "                  ROOM DETAILS\n";
    cout << "====================================================\n\n";

    cout << "Room     Room Type                Rate       Status\n";

    cout << "----------------------------------------------------\n";

    cout << "101      Deluxe Suite             $150       ";

    if (isRoomBooked(101))
        cout << "BOOKED\n";
    else
        cout << "AVAILABLE\n";

    cout << "102      Super Deluxe             $250       ";

    if (isRoomBooked(102))
        cout << "BOOKED\n";
    else
        cout << "AVAILABLE\n";

    cout << "103      Executive Room           $400       ";

    if (isRoomBooked(103))
        cout << "BOOKED\n";
    else
        cout << "AVAILABLE\n";

    cout << "104      Family Suite             $500       ";

    if (isRoomBooked(104))
        cout << "BOOKED\n";
    else
        cout << "AVAILABLE\n";

    cout << "105      Presidential Suite       $800       ";

    if (isRoomBooked(105))
        cout << "BOOKED\n";
    else
        cout << "AVAILABLE\n";

    cout << "\n====================================================\n";

    cout << "                 BREAKFAST MENU\n";

    cout << "====================================================\n";

    cout << "1. Punjabi Breakfast       $80 / Day\n";
    cout << "2. Gujarati Breakfast      $70 / Day\n";
    cout << "3. South Indian Breakfast  $75 / Day\n";
    cout << "4. No Breakfast            $0\n";

    cout << "\n====================================================\n";

    pauseScreen();
}


// ======================================================
// GUEST BOOK ROOM
// ======================================================

void guestBookRoom()
{
    clrscr();

    int roomNo;
    int days;
    int rate;

    int foodChoice;
    int foodRate;

    int bookingID;

    char foodName[50];

    float roomCharges;
    float foodCharges;

    float subtotal;
    float gstAmount;
    float totalBill;

    long bookingTime;
    long checkoutTime;

    cleanupExpiredBookings();

    cout << "====================================================\n";
    cout << "                    BAAV HOTEL\n";
    cout << "                  GUEST BOOKING\n";
    cout << "====================================================\n";

    cout << "\nGuest Name  : "
         << loggedGuestName;

    cout << "\nPhone       : "
         << loggedGuestPhone;

    cout << "\n\n----------------------------------------------------\n";

    cout << "ROOM LIST\n";

    cout << "----------------------------------------------------\n";

    cout << "101 - Deluxe Suite           $150 / Night\n";
    cout << "102 - Super Deluxe           $250 / Night\n";
    cout << "103 - Executive Room         $400 / Night\n";
    cout << "104 - Family Suite           $500 / Night\n";
    cout << "105 - Presidential Suite     $800 / Night\n";

    cout << "\nSelect Room Number : ";

    cin >> roomNo;

    rate = getRoomRate(roomNo);

    if (rate == 0)
    {
        cout << "\nInvalid Room Number!";

        pauseScreen();

        return;
    }

    if (isRoomBooked(roomNo))
    {
        cout << "\n====================================================\n";
        cout << "              ROOM ALREADY BOOKED\n";
        cout << "====================================================\n";

        pauseScreen();

        return;
    }

    cout << "\nNumber of Days : ";

    cin >> days;

    if (days <= 0)
    {
        cout << "\nInvalid Number of Days!";

        pauseScreen();

        return;
    }

    cout << "\n====================================================\n";
    cout << "                 BREAKFAST MENU\n";
    cout << "====================================================\n";

    cout << "1. Punjabi Breakfast       $80 / Day\n";
    cout << "2. Gujarati Breakfast      $70 / Day\n";
    cout << "3. South Indian Breakfast  $75 / Day\n";
    cout << "4. No Breakfast            $0\n";

    cout << "\nSelect Breakfast : ";

    cin >> foodChoice;

    if (
        foodChoice < 1 ||
        foodChoice > 4
    )
    {
        cout << "\nInvalid Breakfast Choice!";

        pauseScreen();

        return;
    }

    foodRate =
        getFoodRate(foodChoice);

    getFoodName(
        foodChoice,
        foodName
    );

    // --------------------------------------------------
    // BILL
    // --------------------------------------------------

    roomCharges =
        rate * days;

    foodCharges =
        foodRate * days;

    subtotal =
        roomCharges + foodCharges;

    gstAmount =
        subtotal * GST;

    totalBill =
        subtotal + gstAmount;

    bookingTime =
        time(NULL);

    checkoutTime =
        bookingTime +
        (days * DAY_SECONDS);

    bookingID =
        getNextBookingID();

    // --------------------------------------------------
    // SAVE BOOKING
    // --------------------------------------------------

    ofstream outFile(
        "hotel.dat",
        ios::app
    );

    if (!outFile)
    {
        cout << "\n[ERROR] Database File Cannot Be Opened!";

        pauseScreen();

        return;
    }

    outFile
        << bookingID << "|"
        << loggedGuestName << "|"
        << loggedGuestPhone << "|"
        << roomNo << "|"
        << days << "|"
        << rate << "|"
        << foodChoice << "|"
        << foodRate << "|"
        << subtotal << "|"
        << gstAmount << "|"
        << totalBill << "|"
        << checkoutTime
        << "\n";

    outFile.close();

    // --------------------------------------------------
    // RECEIPT
    // --------------------------------------------------

    clrscr();

    cout << "====================================================\n";
    cout << "                    BAAV HOTEL\n";
    cout << "                 BOOKING RECEIPT\n";
    cout << "====================================================\n";

    cout << "\nBooking ID       : "
         << bookingID;

    cout << "\nGuest Name       : "
         << loggedGuestName;

    cout << "\nPhone Number     : "
         << loggedGuestPhone;

    cout << "\nRoom Number      : "
         << roomNo;

    cout << "\nNumber of Days   : "
         << days;

    cout << "\nRoom Rate        : $"
         << rate;

    cout << "\n----------------------------------------------------";

    cout << "\nRoom Charges     : $"
         << roomCharges;

    cout << "\nBreakfast        : "
         << foodName;

    cout << "\nBreakfast Rate   : $"
         << foodRate;

    cout << "\nBreakfast Charge : $"
         << foodCharges;

    cout << "\n----------------------------------------------------";

    cout << "\nSubtotal         : $"
         << subtotal;

    cout << "\nGST (18%)        : $"
         << gstAmount;

    cout << "\n----------------------------------------------------";

    cout << "\nTOTAL BILL       : $"
         << totalBill;

    cout << "\n----------------------------------------------------";

    cout << "\nBooking Time     : ";

    displayDateTime(
        bookingTime
    );

    cout << "Checkout Time    : ";

    displayDateTime(
        checkoutTime
    );

    cout << "====================================================\n";

    paymentMenu(
        totalBill
    );

    pauseScreen();
}


// ======================================================
// GUEST MY BOOKING
// ======================================================

void guestMyBooking()
{
    clrscr();

    cleanupExpiredBookings();

    ifstream file("hotel.dat");

    int bookingID;

    char guestName[50];
    char phone[20];

    int roomNo;
    int days;
    int rate;

    int foodChoice;
    int foodRate;

    float subtotal;
    float gst;
    float total;

    long checkoutTime;

    int found = 0;

    cout << "====================================================\n";
    cout << "                    BAAV HOTEL\n";
    cout << "                   MY BOOKING\n";
    cout << "====================================================\n";

    if (!file)
    {
        cout << "\nNo Booking Found!";

        pauseScreen();

        return;
    }

    while (file >> bookingID)
    {
        file.ignore();

        file.getline(
            guestName,
            50,
            '|'
        );

        file.getline(
            phone,
            20,
            '|'
        );

        file >> roomNo;
        file.ignore();

        file >> days;
        file.ignore();

        file >> rate;
        file.ignore();

        file >> foodChoice;
        file.ignore();

        file >> foodRate;
        file.ignore();

        file >> subtotal;
        file.ignore();

        file >> gst;
        file.ignore();

        file >> total;
        file.ignore();

        file >> checkoutTime;
        file.ignore();

        if (
            strcmp(
                guestName,
                loggedGuestName
            ) == 0 &&
            strcmp(
                phone,
                loggedGuestPhone
            ) == 0
        )
        {
            found = 1;

            cout << "\n====================================================";

            cout << "\nBooking ID       : "
                 << bookingID;

            cout << "\nRoom Number      : "
                 << roomNo;

            cout << "\nNumber of Days   : "
                 << days;

            cout << "\nRoom Rate        : $"
                 << rate;

            cout << "\nBreakfast Rate   : $"
                 << foodRate;

            cout << "\nSubtotal         : $"
                 << subtotal;

            cout << "\nGST              : $"
                 << gst;

            cout << "\nTotal Bill       : $"
                 << total;

            cout << "\nCheckout Time    : ";

            displayDateTime(
                checkoutTime
            );

            cout << "====================================================";
        }
    }

    file.close();

    if (!found)
        cout << "\n\nYou Have No Active Booking.";

    pauseScreen();
}


// ======================================================
// GUEST CANCEL BOOKING
// ======================================================

void guestCancelBooking()
{
    clrscr();

    cleanupExpiredBookings();

    ifstream oldFile("hotel.dat");

    if (!oldFile)
    {
        cout << "\nNo Booking Records Found!";

        pauseScreen();

        return;
    }

    ofstream tempFile("temp.dat");

    int cancelID;
    int bookingID;

    char guestName[50];
    char phone[20];

    int roomNo;
    int days;
    int rate;

    int foodChoice;
    int foodRate;

    float subtotal;
    float gst;
    float total;

    long checkoutTime;

    int found = 0;

    cout << "====================================================\n";
    cout << "                    BAAV HOTEL\n";
    cout << "               CANCEL MY BOOKING\n";
    cout << "====================================================\n";

    cout << "\nEnter Booking ID : ";

    cin >> cancelID;

    while (oldFile >> bookingID)
    {
        oldFile.ignore();

        oldFile.getline(
            guestName,
            50,
            '|'
        );

        oldFile.getline(
            phone,
            20,
            '|'
        );

        oldFile >> roomNo;
        oldFile.ignore();

        oldFile >> days;
        oldFile.ignore();

        oldFile >> rate;
        oldFile.ignore();

        oldFile >> foodChoice;
        oldFile.ignore();

        oldFile >> foodRate;
        oldFile.ignore();

        oldFile >> subtotal;
        oldFile.ignore();

        oldFile >> gst;
        oldFile.ignore();

        oldFile >> total;
        oldFile.ignore();

        oldFile >> checkoutTime;
        oldFile.ignore();

        if (
            bookingID == cancelID &&
            strcmp(
                guestName,
                loggedGuestName
            ) == 0 &&
            strcmp(
                phone,
                loggedGuestPhone
            ) == 0
        )
        {
            found = 1;

            cout << "\n====================================================";
            cout << "\n              BOOKING CANCELLED";
            cout << "\n====================================================";

            cout << "\nRoom No. : "
                 << roomNo;

            cout << "\nRoom "
                 << roomNo
                 << " is now AVAILABLE.";
        }
        else
        {
            tempFile
                << bookingID << "|"
                << guestName << "|"
                << phone << "|"
                << roomNo << "|"
                << days << "|"
                << rate << "|"
                << foodChoice << "|"
                << foodRate << "|"
                << subtotal << "|"
                << gst << "|"
                << total << "|"
                << checkoutTime
                << "\n";
        }
    }

    oldFile.close();
    tempFile.close();

    if (!found)
    {
        remove("temp.dat");

        cout << "\n\nBooking Not Found!";
        cout << "\nPlease Check Booking ID.";

        pauseScreen();

        return;
    }

    remove("hotel.dat");

    rename(
        "temp.dat",
        "hotel.dat"
    );

    pauseScreen();
}


// ======================================================
// ADMIN BOOK ROOM
// ======================================================

void bookRoom()
{
    clrscr();

    char guestName[50];
    char phone[20];
    char foodName[50];

    int roomNo;
    int days;
    int rate;

    int foodChoice;
    int foodRate;

    int bookingID;

    float roomCharges;
    float foodCharges;

    float subtotal;
    float gstAmount;
    float totalBill;

    long bookingTime;
    long checkoutTime;

    cleanupExpiredBookings();

    cout << "====================================================\n";
    cout << "                    BAAV HOTEL\n";
    cout << "                 NEW ROOM BOOKING\n";
    cout << "====================================================\n";

    fflush(stdin);

    cout << "\nGuest Full Name : ";
    gets(guestName);

    if (strlen(guestName) == 0)
    {
        cout << "\nGuest Name Cannot Be Empty!";

        pauseScreen();

        return;
    }

    cout << "Phone Number    : ";
    gets(phone);

    cout << "\nSelect Room Number : ";
    cin >> roomNo;

    rate =
        getRoomRate(roomNo);

    if (rate == 0)
    {
        cout << "\nInvalid Room Number!";

        pauseScreen();

        return;
    }

    if (isRoomBooked(roomNo))
    {
        cout << "\nRoom Already Booked!";

        pauseScreen();

        return;
    }

    cout << "Number of Days : ";
    cin >> days;

    if (days <= 0)
    {
        cout << "\nInvalid Number of Days!";

        pauseScreen();

        return;
    }

    cout << "\n1. Punjabi Breakfast       $80\n";
    cout << "2. Gujarati Breakfast      $70\n";
    cout << "3. South Indian Breakfast  $75\n";
    cout << "4. No Breakfast            $0\n";

    cout << "\nSelect Breakfast : ";
    cin >> foodChoice;

    if (
        foodChoice < 1 ||
        foodChoice > 4
    )
    {
        cout << "\nInvalid Breakfast Choice!";

        pauseScreen();

        return;
    }

    foodRate =
        getFoodRate(foodChoice);

    getFoodName(
        foodChoice,
        foodName
    );

    roomCharges =
        rate * days;

    foodCharges =
        foodRate * days;

    subtotal =
        roomCharges + foodCharges;

    gstAmount =
        subtotal * GST;

    totalBill =
        subtotal + gstAmount;

    bookingTime =
        time(NULL);

    checkoutTime =
        bookingTime +
        (days * DAY_SECONDS);

    bookingID =
        getNextBookingID();

    ofstream outFile(
        "hotel.dat",
        ios::app
    );

    if (!outFile)
    {
        cout << "\nDatabase Error!";

        pauseScreen();

        return;
    }

    outFile
        << bookingID << "|"
        << guestName << "|"
        << phone << "|"
        << roomNo << "|"
        << days << "|"
        << rate << "|"
        << foodChoice << "|"
        << foodRate << "|"
        << subtotal << "|"
        << gstAmount << "|"
        << totalBill << "|"
        << checkoutTime
        << "\n";

    outFile.close();

    cout << "\n\nBooking Successful!";
    cout << "\nBooking ID : "
         << bookingID;

    cout << "\nTotal Bill : $"
         << totalBill;

    paymentMenu(
        totalBill
    );

    pauseScreen();
}


// ======================================================
// PAYMENT MENU
// ======================================================

void paymentMenu(float amount)
{
    int choice;

    clrscr();

    cout << "====================================================\n";
    cout << "                    BAAV HOTEL\n";
    cout << "                  PAYMENT SECTION\n";
    cout << "====================================================\n";

    cout << "\nTOTAL BILL : $"
         << amount;

    cout << "\n\n1. Cash Payment";
    cout << "\n2. Card Payment";
    cout << "\n3. UPI / QR Payment";

    cout << "\n\nSelect Payment Method : ";

    cin >> choice;

    switch (choice)
    {
        case 1:
            cashPayment(amount);
            break;

        case 2:
            cardPayment(amount);
            break;

        case 3:
            upiPayment(amount);
            break;

        default:
            cout << "\nInvalid Payment Method!";
    }
}


// ======================================================
// CASH PAYMENT
// ======================================================

void cashPayment(float amount)
{
    clrscr();

    cout << "====================================================\n";
    cout << "                    BAAV HOTEL\n";
    cout << "                  CASH PAYMENT\n";
    cout << "====================================================\n";

    cout << "\nAmount To Pay : $"
         << amount;

    cout << "\n\nPayment Status : PAID";

    cout << "\n\nCash Payment Successful!";

    getch();
}


// ======================================================
// CARD PAYMENT
// ======================================================

void cardPayment(float amount)
{
    char cardNo[30];

    clrscr();

    cout << "====================================================\n";
    cout << "                    BAAV HOTEL\n";
    cout << "                  CARD PAYMENT\n";
    cout << "====================================================\n";

    cout << "\nAmount : $"
         << amount;

    cout << "\nEnter Card Number : ";

    cin >> cardNo;

    cout << "\nProcessing Payment...";

    delay(1500);

    cout << "\n\nPayment Status : PAID";

    cout << "\nCard Payment Successful!";

    getch();
}


// ======================================================
// UPI PAYMENT
// ======================================================

void upiPayment(float amount)
{
    int choice;

    clrscr();

    cout << "====================================================\n";
    cout << "                    BAAV HOTEL\n";
    cout << "                   UPI PAYMENT\n";
    cout << "====================================================\n";

    cout << "\nAmount To Pay : $"
         << amount;

    cout << "\n\nUPI ID : yourhotel@upi";

    cout << "\n\n----------------------------------------------------";
    cout << "\n                  SCAN QR CODE";
    cout << "\n----------------------------------------------------";

    cout << "\n\n";
    cout << "        +-----------------------+\n";
    cout << "        |  [] []  [][] []  []  |\n";
    cout << "        |  [][] []  [] [] [][]  |\n";
    cout << "        |  [] [] [][][] [] []   |\n";
    cout << "        |  [][] []  [] [] [][]  |\n";
    cout << "        |  [] [][][] [] [] []   |\n";
    cout << "        +-----------------------+\n";

    cout << "\n----------------------------------------------------";

    cout << "\n1. Payment Successful";
    cout << "\n2. Payment Failed";

    cout << "\n\nEnter Payment Status : ";

    cin >> choice;

    if (choice == 1)
    {
        cout << "\n\nPayment Successful!";
        cout << "\nUPI Payment Received.";
    }
    else
    {
        cout << "\n\nPayment Failed!";
    }

    getch();
}


// ======================================================
// VIEW ALL BOOKINGS
// ======================================================

void viewBookings()
{
    clrscr();

    cleanupExpiredBookings();

    ifstream file("hotel.dat");

    int bookingID;

    char guestName[50];
    char phone[20];
    char foodName[50];

    int roomNo;
    int days;
    int rate;

    int foodChoice;
    int foodRate;

    float subtotal;
    float gst;
    float total;

    long checkoutTime;

    int count = 0;

    cout << "====================================================\n";
    cout << "                    BAAV HOTEL\n";
    cout << "                  ALL BOOKINGS\n";
    cout << "====================================================\n";

    if (!file)
    {
        cout << "\nNo Active Booking Records Found!";

        pauseScreen();

        return;
    }

    while (file >> bookingID)
    {
        file.ignore();

        file.getline(
            guestName,
            50,
            '|'
        );

        file.getline(
            phone,
            20,
            '|'
        );

        file >> roomNo;
        file.ignore();

        file >> days;
        file.ignore();

        file >> rate;
        file.ignore();

        file >> foodChoice;
        file.ignore();

        file >> foodRate;
        file.ignore();

        file >> subtotal;
        file.ignore();

        file >> gst;
        file.ignore();

        file >> total;
        file.ignore();

        file >> checkoutTime;
        file.ignore();

        getFoodName(
            foodChoice,
            foodName
        );

        cout << "\n====================================================";

        cout << "\nBooking ID       : "
             << bookingID;

        cout << "\nGuest Name       : "
             << guestName;

        cout << "\nPhone Number     : "
             << phone;

        cout << "\nRoom Number      : "
             << roomNo;

        cout << "\nNumber of Days   : "
             << days;

        cout << "\nRoom Rate        : $"
             << rate;

        cout << "\nBreakfast        : "
             << foodName;

        cout << "\nBreakfast Rate   : $"
             << foodRate;

        cout << "\nSubtotal         : $"
             << subtotal;

        cout << "\nGST              : $"
             << gst;

        cout << "\nTotal Bill       : $"
             << total;

        cout << "\nCheckout Time    : ";

        displayDateTime(
            checkoutTime
        );

        cout << "====================================================";

        count++;
    }

    file.close();

    cout << "\n\nTotal Active Bookings : "
         << count;

    pauseScreen();
}


// ======================================================
// SEARCH BOOKING
// ======================================================

void searchBooking()
{
    clrscr();

    cleanupExpiredBookings();

    ifstream file("hotel.dat");

    int searchID;
    int bookingID;

    char guestName[50];
    char phone[20];
    char foodName[50];

    int roomNo;
    int days;
    int rate;

    int foodChoice;
    int foodRate;

    float subtotal;
    float gst;
    float total;

    long checkoutTime;

    int found = 0;

    cout << "====================================================\n";
    cout << "                    BAAV HOTEL\n";
    cout << "                 SEARCH BOOKING\n";
    cout << "====================================================\n";

    cout << "\nEnter Booking ID : ";

    cin >> searchID;

    if (!file)
    {
        cout << "\nNo Booking Database Found!";

        pauseScreen();

        return;
    }

    while (file >> bookingID)
    {
        file.ignore();

        file.getline(
            guestName,
            50,
            '|'
        );

        file.getline(
            phone,
            20,
            '|'
        );

        file >> roomNo;
        file.ignore();

        file >> days;
        file.ignore();

        file >> rate;
        file.ignore();

        file >> foodChoice;
        file.ignore();

        file >> foodRate;
        file.ignore();

        file >> subtotal;
        file.ignore();

        file >> gst;
        file.ignore();

        file >> total;
        file.ignore();

        file >> checkoutTime;
        file.ignore();

        if (bookingID == searchID)
        {
            getFoodName(
                foodChoice,
                foodName
            );

            cout << "\n====================================================";
            cout << "\n                 BOOKING FOUND";
            cout << "\n====================================================";

            cout << "\nBooking ID       : "
                 << bookingID;

            cout << "\nGuest Name       : "
                 << guestName;

            cout << "\nPhone Number     : "
                 << phone;

            cout << "\nRoom Number      : "
                 << roomNo;

            cout << "\nNumber of Days   : "
                 << days;

            cout << "\nRoom Rate        : $"
                 << rate;

            cout << "\nBreakfast        : "
                 << foodName;

            cout << "\nBreakfast Rate   : $"
                 << foodRate;

            cout << "\nSubtotal         : $"
                 << subtotal;

            cout << "\nGST              : $"
                 << gst;

            cout << "\nTotal Bill       : $"
                 << total;

            cout << "\nCheckout Time    : ";

            displayDateTime(
                checkoutTime
            );

            cout << "====================================================";

            found = 1;

            break;
        }
    }

    file.close();

    if (!found)
        cout << "\n\nBooking ID Not Found!";

    pauseScreen();
}


// ======================================================
// ADMIN CANCEL BOOKING
// ======================================================

void cancelBooking()
{
    clrscr();

    cleanupExpiredBookings();

    ifstream oldFile("hotel.dat");

    if (!oldFile)
    {
        cout << "\nNo Booking Records Found!";

        pauseScreen();

        return;
    }

    ofstream tempFile("temp.dat");

    int cancelID;
    int bookingID;

    char guestName[50];
    char phone[20];

    int roomNo;
    int days;
    int rate;

    int foodChoice;
    int foodRate;

    float subtotal;
    float gst;
    float total;

    long checkoutTime;

    int found = 0;

    cout << "====================================================\n";
    cout << "                    BAAV HOTEL\n";
    cout << "                 CANCEL BOOKING\n";
    cout << "====================================================\n";

    cout << "\nEnter Booking ID : ";

    cin >> cancelID;

    while (oldFile >> bookingID)
    {
        oldFile.ignore();

        oldFile.getline(
            guestName,
            50,
            '|'
        );

        oldFile.getline(
            phone,
            20,
            '|'
        );

        oldFile >> roomNo;
        oldFile.ignore();

        oldFile >> days;
        oldFile.ignore();

        oldFile >> rate;
        oldFile.ignore();

        oldFile >> foodChoice;
        oldFile.ignore();

        oldFile >> foodRate;
        oldFile.ignore();

        oldFile >> subtotal;
        oldFile.ignore();

        oldFile >> gst;
        oldFile.ignore();

        oldFile >> total;
        oldFile.ignore();

        oldFile >> checkoutTime;
        oldFile.ignore();

        if (bookingID == cancelID)
        {
            found = 1;

            cout << "\nBooking Cancelled!";
            cout << "\nGuest Name : "
                 << guestName;

            cout << "\nRoom No.   : "
                 << roomNo;
        }
        else
        {
            tempFile
                << bookingID << "|"
                << guestName << "|"
                << phone << "|"
                << roomNo << "|"
                << days << "|"
                << rate << "|"
                << foodChoice << "|"
                << foodRate << "|"
                << subtotal << "|"
                << gst << "|"
                << total << "|"
                << checkoutTime
                << "\n";
        }
    }

    oldFile.close();
    tempFile.close();

    if (!found)
    {
        remove("temp.dat");

        cout << "\nBooking ID Not Found!";

        pauseScreen();

        return;
    }

    remove("hotel.dat");

    rename(
        "temp.dat",
        "hotel.dat"
    );

    pauseScreen();
}


// ======================================================
// CHECK OUT
// ======================================================

void checkoutBooking()
{
    int id;

    clrscr();

    cout << "====================================================\n";
    cout << "                    BAAV HOTEL\n";
    cout << "                    CHECK-OUT\n";
    cout << "====================================================\n";

    cout << "\nEnter Booking ID : ";

    cin >> id;

    cout << "\nBooking ID : "
         << id;

    cout << "\n\nCheck-Out Successful!";

    cout << "\nRoom will become AVAILABLE.";

    cout << "\n\nNOTE:";
    cout << "\nAutomatic checkout is controlled by";
    cout << "\nthe booking checkout time.";

    pauseScreen();
}


// ======================================================
// REVENUE REPORT
// ======================================================

void revenueReport()
{
    ifstream file("hotel.dat");

    int bookingID;

    char guestName[50];
    char phone[20];

    int roomNo;
    int days;
    int rate;

    int foodChoice;
    int foodRate;

    float subtotal;
    float gst;
    float total;

    long checkoutTime;

    float totalRevenue = 0;

    int totalBookings = 0;

    clrscr();

    cout << "====================================================\n";
    cout << "                    BAAV HOTEL\n";
    cout << "                  REVENUE REPORT\n";
    cout << "====================================================\n";

    if (!file)
    {
        cout << "\nNo Revenue Records Found!";

        pauseScreen();

        return;
    }

    while (file >> bookingID)
    {
        file.ignore();

        file.getline(
            guestName,
            50,
            '|'
        );

        file.getline(
            phone,
            20,
            '|'
        );

        file >> roomNo;
        file.ignore();

        file >> days;
        file.ignore();

        file >> rate;
        file.ignore();

        file >> foodChoice;
        file.ignore();

        file >> foodRate;
        file.ignore();

        file >> subtotal;
        file.ignore();

        file >> gst;
        file.ignore();

        file >> total;
        file.ignore();

        file >> checkoutTime;
        file.ignore();

        totalRevenue =
            totalRevenue + total;

        totalBookings++;
    }

    file.close();

    cout << "\nTotal Active Bookings : "
         << totalBookings;

    cout << "\nTotal Revenue         : $"
         << totalRevenue;

    cout << "\n\n====================================================";

    pauseScreen();
}


// ======================================================
// PAUSE
// ======================================================

void pauseScreen()
{
    cout << "\n\nPress any key to continue...";

    getch();
}
