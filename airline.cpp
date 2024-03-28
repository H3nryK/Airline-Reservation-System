#include <iostream>
#include <iomanip>

using namespace std;

// Constants
const int TOTAL_SEATS = 18;
const int BUSINESS_CLASS_CAPAITY = 9;

// Functions
void displayMenu();
void reserveSeat(int seatType, bool seats[]);
void displayBoardingPass(int seatNumber, int seatType);
bool isAllSeatsReserved(bool seats[]);

int main()
{
    // Initialize seats as unbooked
    bool seats[TOTAL_SEATS] = {false};

    int choice;
    do {
        displayMenu();
        cin>>choice;

        switch(choice){
        case 1:
            // Business class
            reserveSeat(1, seats);
            break;
        case 2:
            // Economy class
            reserveSeat(2, seats);
            break;
        case 3:
            cout<<" Exiting program. \n";
            break;
        default:
            cout<<" Invalid choice. Please try again. \n";
            break;
        }

        if (isAllSeatsReserved(seats)){
            cout<<" Sorry. All the seats are full. Please wait for the next flight that leaves in the next 3 hours.\n";
            break;
        }
    } while(choice != 3 && isAllSeatsReserved(seats));

    return 0;
}

void displayMenu()
{
    cout<<"\n************************************************************\n";
    cout<<"         Welcome to Airline Seat Reservation System\n";
    cout<<"************************************************************\n";
    cout<<" 1. Reserve a seat in Business class.\n";
    cout<<" 2. Reserve a seat in Economy class.\n";
    cout<<" 3. Exit.\n";
    cout<<"************************************************************\n";
    cout<<" Enter your choice: ";
}

void reserveSeat(int seatType, bool seats[])
{
    int seatNumber;
    if (seatType == 1){
        // Business Class
        cout << "\nReserving a seat in Business class...\n\n";
        for (int i = 0; i < BUSINESS_CLASS_CAPACITY; ++i){
            if (!seats[i]){
                seats[i] = true;
                seatNumber = i + 1;
                displayBoardingPass(seatNumber, seatType);
                break;
            }
        }
    } else if (seatType == 2){
        // Economy Class
        cout << "\nReserving a seat in Economy class...\n";
        for (int i = BUSINESS_CLASS_CAPACITY; i < TOTAL_SEATS; ++i){
            if (!seats[i]){
                seats[i] = true;
                seatNumber = i + 1;
                displayBoardingPass(seatNumber, seatType);
                break;
            }
        }
    }

    if (!isAllSeatsReserved(seats)){
        char choice;
        cout << "\nWould you like to reserve a seat in the other Class? (y/n) ";
        cin >> choice;
        if (choice == 'n'){
            cout << "\nExiting program.\n";
            return; // Exit the function if the user chooses not to reserve a seat in the other class
        }
    }

    // If the user chooses to reserve a seat in the other class, prompt them to select the seat type again
    int newSeatType;
    do {
        cout << "\nSelect the class to reserve a seat (1 for Business, 2 for Economy): ";
        cin >> newSeatType;
        if (newSeatType != 1 && newSeatType != 2) {
            cout << "Invalid choice. Please try again.\n";
        }
    } while (newSeatType != 1 && newSeatType != 2);

    reserveSeat(newSeatType, seats); // Recursive call to reserveSeat with the new seatType
}


void displayBoardingPass(int seatNumber, int seatType)
{
    cout<<"\n============================================================\n";
    cout<<"               Boarding Pass\n";
    cout<<"============================================================\n";
    cout<<setw(20)<<left<<" Seat Number: ";
    cout<<setw(10)<<right<<seatNumber<<endl;
    cout<<setw(20)<<left<<" Class: ";
    if (seatType == 1){
        cout<<setw(10)<<right<<" Business\n";
    } else {
        cout<<setw(10)<<right<<" Economy\n";
    }
}

bool isAllSeatsReserved(bool seats[]){
    for (int i=0; i<TOTAL_SEATS; ++i){
        if (!seats[i]){
            return false;
        }
    }
    return true;
}
