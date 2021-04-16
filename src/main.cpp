#include <memory>
#include <string>
#include <vector>
#include <iostream>
#include <cstdlib> // for system()
#include <cstdint> // for uint32_t
#include <chrono>  // for currentYear() implementation
#include <ctime>   // for currentYear() implementation

//------------------- User includes ----------------------------

// A class that represents a form. A form has many fields
#include "Form.h"

// A class that represents a field. A field can have one or more validators
#include "Field.h"

// A class that represents a no-digit-characters validator.
// It validates that the field value contains no digits.
// Works only on std::string.
#include "NoDigitValidator.h"

// A class that represents an ID validator.
// ID validation is done using the control digit.
// Works only on the type 'uint32_t'.
#include "IDValidator.h"


//------------------- Function declarations ----------------------------

// Prints welcome message
void displayWelcomeMessage();

// Prints goodbye message
void displayGoodbyeMessage();

// Prints error message
void displayErrorMessage();

// Prints price
void displayPrice(int totalPeople, int roomNum);

// Utility function for clearing the terminal screen
void clearScreen();

// Utility function for getting current year from computer clock
int currentYear();


//------------------- consts --------------------------

const int MIN_AGE = 18;
const int MAX_AGE = 120;
const int ROOMS_NUM = 10;


//------------------- main ----------------------------

int main()
{
    // Creating the form fields
    auto nameField = std::make_unique<Field<std::string>>("What is your name?");
    auto idField = std::make_unique<Field<uint32_t>>("What is your ID?");

    // Creating the field validators
    auto nameValidator = std::make_unique<NoDigitValidator>();
    auto idValidator = std::make_unique<IDValidator>();

    // Adding the validators to the fields
    nameField->addValidator(nameValidator.get());
    idField->addValidator(idValidator.get());

    // Creating the form and adding the fields to it
    auto myForm = Form();
    myForm.addField(nameField.get());
    myForm.addField(idField.get());
    // Getting the information from the user
    clearScreen();
    displayWelcomeMessage();


    // Get the input only for empty or not valid fields
    myForm.fillForm();

    // Validation loop
    while (!myForm.validateForm())
    {
        // Displays all form fields with value (and error if not valid)
        clearScreen();
        displayErrorMessage();
        std::cout << myForm << '\n';
        myForm.fillForm();
    }
}
    /*
    clearScreen();
    displayGoodbyeMessage();
    std::cout << myForm << '\n';
    displayPrice(totalPeopleField.get()->getContent(), pairRoomsField.get()->getContent() + familyRoomsField.get()->getContent());
}
*/
void displayWelcomeMessage()
{
    std::cout << "+---------------------------------------------------+\n"
        "|                 Hello and welcome                 |\n"
        "|       Please fill the details of the order        |\n"
        "+---------------------------------------------------+\n";
}

void displayErrorMessage()
{
    std::cout << "+---------------------------------------------------+\n"
        "| There was an error in at least one of the fields! |\n"
        "|            Please correct the error(s)            |\n"
        "+---------------------------------------------------+\n";
}

void displayGoodbyeMessage()
{
    std::cout << "+---------------------------------------------------+\n"
        "|                    Thank you!                     |\n"
        "|           These are your order details:           |\n"
        "+---------------------------------------------------+\n";
}

void displayPrice(int totalPeople, int roomNum)
{
    const auto price = totalPeople * 100 + roomNum * 300;
    const auto priceStr = std::to_string(price);
    const auto spaces = std::string(23 - priceStr.size() / 2, ' ');
    std::cout << "+---------------------------------------------------+\n"
        "|                   The price is:                   |\n"
        "|" << spaces << priceStr << " NIS " << spaces << "|\n"
        "+---------------------------------------------------+\n";
}

void clearScreen()
{
    system("cls"); // Windows specific
}

int currentYear()
{
    using clock = std::chrono::system_clock;
    const auto now = clock::to_time_t(clock::now());
    auto calendarTime = std::tm{};
    localtime_s(&calendarTime, &now);
    return calendarTime.tm_year + 1900;
}
