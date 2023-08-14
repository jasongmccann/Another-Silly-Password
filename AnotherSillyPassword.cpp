/*
Another Silly Password
Version 1.0
Created By Jason McCann
2021
*/

// Start Program
// Directives
#include <iostream>
#include <string>
#include <cstdlib>
#include <conio.h>
#include <random>
// Namespace
using namespace std;

// Password generating algorithm function for passwords with letters, numbers, and special characters. 
std::string random_string_letNumSpec(std::size_t length)
{
    const std::string CHARACTERS = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz!@#$%%^&*?";

    std::random_device random_device;
    std::mt19937 generator(random_device());
    std::uniform_int_distribution<> distribution(0, CHARACTERS.size() - 1);

    std::string random_string;

    for (std::size_t i = 0; i < length; ++i)
    {
        random_string += CHARACTERS[distribution(generator)];
    }

    return random_string;
}

// Password Generating algorithm function for passwords with letters and numbers only.
std::string random_string_letNum(std::size_t length)
{
    const std::string CHARACTERS = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

    std::random_device random_device;
    std::mt19937 generator(random_device());
    std::uniform_int_distribution<> distribution(0, CHARACTERS.size() - 1);

    std::string random_string;

    for (std::size_t i = 0; i < length; ++i)
    {
        random_string += CHARACTERS[distribution(generator)];
    }

    return random_string;
}

// Password generating algorithm function for passwords with letters only.
std::string random_string_let(std::size_t length)
{
    const std::string CHARACTERS = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

    std::random_device random_device;
    std::mt19937 generator(random_device());
    std::uniform_int_distribution<> distribution(0, CHARACTERS.size() - 1);

    std::string random_string;

    for (std::size_t i = 0; i < length; ++i)
    {
        random_string += CHARACTERS[distribution(generator)];
    }

    return random_string;
}


// Main Executable
int main()
{
    cout << "--------------------------------------------------------------------------------" << endl;
    cout << "                     Another Silly Password (Version 1.0)                      " << endl;
    cout << "                            Created By Jason McCann                             " << endl;
    cout << "                                     2021                                       " << endl;
    cout << "--------------------------------------------------------------------------------" << endl;
    // Program welcome message.
    cout << "  Thank you for using Another Silly Password, a simple command line password \n  creation tool that runs locally on your computer and will take away the \n  struggles of having to create a strong password on your own.\n\n  Press any key to continue. " << endl;
    // Will not continue until a random key is pressed.
    _getch();
    // Boolean to keep password generator do-while loop active.
    bool active = true;
    // Password Generator Do-While Loop.
    do
    {
        // Password type choices menu.
        cout << "--------------------------------------------------------------------------------" << endl;
        cout << "  Please choose the corresponding number to the type of password you want to\n  generate.\n" << endl;
        cout << "   1. Password with letters, numbers and special characters" << endl << "   2. Password with letters and numbers" << endl << "   3. Password with letters only" << endl << "   4. Exit the program\n" << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
        cout << "  Your Choice: ";
        // Defining choice integer for use in switch .
        int choice;
        // Defining minimum character integer to be used in creating password.
        int minChar;
        // Defining password string that will be displayed to the user when password is finished being created.
        string pass;
        // Defining the final password string that will be displayed to the user when the original password is done being randomized again.
        string finalPass;
        // Collect password choice from user.
        cin >> choice;
        // Fail-Safe mechanism for improper input, prevents program from looping bug.
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
        }
        cout << "" << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
        // Switch of fuctions that correspond to those described in the menu of choices.
        switch (choice)
        {
            // Case to create a password with letters, number, and special characters.
        case 1:
            // Choice title and prompt to define how long of a password the user wants to make.
            cout << "             Password with letters, numbers, and special characters             " << endl;
            cout << "--------------------------------------------------------------------------------" << endl;
            cout << "              How many characters do you need your password to be?\n              (Between 8-50 Characters): ";
            // Fail-Safe mechanism for improper input, prevents program from looping bug
            while (!(cin >> minChar))
            {
                // Error message for if a non integer is entered.
                cout << "" << endl;
                cout << "--------------------------------------------------------------------------------" << endl;
                cout << "                   Error: Please enter a number ammount 8-50!                   " << endl;
                cout << "--------------------------------------------------------------------------------" << endl;
                // Prompt to define how long of a password the user wants to make.
                cout << "              How many characters do you need your password to be: ";
                // Clears input so new input can be recieved.
                cin.clear();
                cin.ignore(1000, '\n');
            }
            // Checks if password size defined by user is less than 8 characters.
            if (minChar > 7)
            {
                // Checks if password size defined by user is greater than 50 characters.
                if (minChar < 51)
                {
                    // Creating the custom sized password using the getRandomPassFull() function created above. (Old Version)
                    /*
                    for (int i = 0; i < minChar; i++)
                    {
                        pass += getRandomPassFull();
                    }
                    */
                    // Calling the password generating algorithm
                    pass = random_string_letNumSpec(minChar);
                    // Display the password that was just created.
                    cout << "" << endl;
                    cout << "--------------------------------------------------------------------------------" << endl;
                    cout << "   Here is your password: " << pass << endl;
                    cout << "" << endl;
                    cout << "--------------------------------------------------------------------------------" << endl;
                    // Sets active boolean to false, thus killing the Do-While loop.
                    active = false;
                    // Ends switch.
                    break;
                }
                // If the requested size for the password is beyond 50 characters, display error and take user back to the selection menu.
                else
                {
                    // Error message for password character requests over 50.
                    cout << "" << endl;
                    cout << "                   Your request is invalid! Please try again.                    " << endl;
                    // Ends switch.
                    break;
                }// Reset Do-While Loop
            }
            // If the requested size for the password is below 8 characters, display error and take user back to the selection menu.
            else
            {
                // Error message for password character requests under 8.
                cout << "" << endl;
                cout << "                   Your request is invalid! Please try again.                    " << endl;
                // Ends switch.
                break;
            }// Reset Do-While Loop

        // Case to create a password with letters and numbers.
        case 2:
            // Choice title and prompt to define how long of a password the user wants to make.
            cout << "                       Password with letters and numbers                        " << endl;
            cout << "--------------------------------------------------------------------------------" << endl;
            cout << "              How many characters do you need your password to be?\n              (Between 8-50 Characters): ";
            // Fail-Safe mechanism for improper input, prevents program from looping bug
            while (!(cin >> minChar))
            {
                // Error message for if a non integer is entered.
                cout << "" << endl;
                cout << "--------------------------------------------------------------------------------" << endl;
                cout << "                   Error: Please enter a number ammount 8-50!                   " << endl;
                cout << "--------------------------------------------------------------------------------" << endl;
                // Prompt to define how long of a password the user wants to make.
                cout << "              How many characters do you need your password to be: ";
                // Clears input so new input can be recieved.
                cin.clear();
                cin.ignore(1000, '\n');
            }
            // Checks if password size defined by user is less than 8 characters.
            if (minChar > 7)
            {
                // Checks if password size defined by user is greater than 50 characters.
                if (minChar < 51)
                {
                    // Calling the password generating algorithm
                    pass = random_string_letNum(minChar);
                    // Display the password that was just created.
                    cout << "" << endl;
                    cout << "--------------------------------------------------------------------------------" << endl;
                    cout << "   Here is your password: " << pass << endl;
                    cout << "" << endl;
                    cout << "--------------------------------------------------------------------------------" << endl;
                    // Sets active boolean to false, thus killing the Do-While loop.
                    active = false;
                    // Ends switch.
                    break;
                }
                // If the requested size for the password is beyond 50 characters, display error and take user back to the selection menu.
                else
                {
                    // Error message for password character requests over 50.
                    cout << "" << endl;
                    cout << "                   Your request is invalid! Please try again.                    " << endl;
                    // Ends switch.
                    break;
                }// Reset Do-While Loop
            }
            // If the requested size for the password is below 8 characters, display error and take user back to the selection menu.
            else
            {
                // Error message for password character requests under 8.
                cout << "" << endl;
                cout << "                   Your request is invalid! Please try again.                    " << endl;
                // Ends switch.
                break;
            }// Reset Do-While Loop

        // Case to create a password with letters only.
        case 3:
            // Choice title and prompt to define how long of a password the user wants to make.
            cout << "                         Passwords with letters only                            " << endl;
            cout << "--------------------------------------------------------------------------------" << endl;
            cout << "              How many characters do you need your password to be?\n              (Between 8-50 Characters): ";
            // Fail-Safe mechanism for improper input, prevents program from looping bug
            while (!(cin >> minChar))
            {
                // Error message for if a non integer is entered.
                cout << "" << endl;
                cout << "--------------------------------------------------------------------------------" << endl;
                cout << "                   Error: Please enter a number ammount 8-50!                   " << endl;
                cout << "--------------------------------------------------------------------------------" << endl;
                // Prompt to define how long of a password the user wants to make.
                cout << "              How many characters do you need your password to be: ";
                // Clears input so new input can be recieved.
                cin.clear();
                cin.ignore(1000, '\n');
            }
            // Checks if password size defined by user is less than 8 characters.
            if (minChar > 7)
            {
                // Checks if password size defined by user is greater than 50 characters.
                if (minChar < 51)
                {
                    // Calling the password generating algorithm
                    pass = random_string_let(minChar);
                    // Display the password that was just created.
                    cout << "" << endl;
                    cout << "--------------------------------------------------------------------------------" << endl;
                    cout << "   Here is your password: " << pass << endl;
                    cout << "" << endl;
                    cout << "--------------------------------------------------------------------------------" << endl;
                    // Sets active boolean to false, thus killing the Do-While loop.
                    active = false;
                    // Ends switch.
                    break;
                }
                // If the requested size for the password is beyond 50 characters, display error and take user back to the selection menu.
                else
                {
                    // Error message for password character requests over 50.
                    cout << "" << endl;
                    cout << "                   Your request is invalid! Please try again.                    " << endl;
                    // Ends switch.
                    break;
                }// Reset Do-While Loop
            }
            // If the requested size for the password is below 8 characters, display error and take user back to the selection menu.
            else
            {
                // Error message for password character requests under 8.
                cout << "" << endl;
                cout << "                   Your request is invalid! Please try again.                    " << endl;
                // Ends switch.
                break;
            }// Reset Do-While Loop

        // Case to quit the program.   
        case 4:
            // Sets active boolean to false, thus killing the Do-While loop.
            active = false;
            // Ends switch.
            break;

            // Error for when a case is not properly defined.
        default:
            // Invalid option error message.
            cout << "                    The option you have selected is invalid!                     " << endl;
            // Ends switch.
            break;
        }// Reset Do-While Loop
    } while (active == true);// Do-While loop will remain active so long as the active boolean is set to true.

    // Exit message.
    cout << " " << endl;
    cout << "             Thank you for using Another Silly Password. GOOD BYE!" << endl;
    cout << " " << endl;
    // Press any key to exit, prevents program from closing on its own.
    cout << "                  Please press any key to exit the program.        " << endl;
    cout << "" << endl;
    // Will not continue until a random key is pressed.
    _getch();

    // Exit Program.
    return 0;
}//End of program.