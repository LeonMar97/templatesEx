Exercise 2: Templates
=============================
Written by: Ronen Heifetz,	id: 316481423
			Leon Markovich, id:

GENERAL INFORMATION
============================

This program is a terminal application used to fill a hotel reservation for a family vacation.
The basic idea behind this program is that there are fields the user needs to fill, and the program
validates each and every one individually, and ultimately validates the entire form.

DESIGN
===========================

------------------
Validator and Field
------------------
The core of this program are the classes Validator and Field. 
They are both template classes from which all the actual validators and fields inherit.

Fields hold the content the user has inserted with the correct validator to make sure the content is correct,
Validators hold the fields they need to validate.

Validator has a vector of the type of the field that it supposed to validate, or of type Field with the relevant instantiation
for form validation.

Field has a Validator member which is supposed to validate the information of the fields, though it is possible
to extend it to a vector of validators for several validations.

Using the functions addValidator() and attach() it is possible to glue the two of them together for the desired purpose.

------------------
BaseValidator and BaseField
------------------

Since Validator and Field are templated functions, they need a common base for each one of their instantiations. 
The BaseValidator and BaseField are simply for allowing polymorphism on all sorts of fields and validators.


------------------
Form
------------------

The controller of this entire program, it has a vector of fields for all the information the user needs to insert,
and it has a vector of validators to validate the entire form.

------------------
NoDigitValidator
------------------

A validator for checking there are no numbers in the name. Inherits from Validator<string>
------------------
IDValidator
------------------

A validator for checking the ID inserted is correct under Israeli terms. Inherits from Validator<uint_32>

------------------
RangeValidator
------------------

A template validator, inherits from Validator<T> where T is the type of the field it is supposed to validate.
It is checking if the content of the field is in range of pre-determined values.

------------------
NonNegativeValidator
------------------

A template validator, inherits from Validator<T> where T is the type of the field it is supposed to validate.
It is checking if the content of the field is non negative

------------------
NotGreaterThanValidator
------------------

A template validator, inherits from Validator<T> where T is the type of the field it is supposed to validate.
It is checking if the content of the field is non greater than a pre-determined value

------------------
SumValidator
------------------

Used for form validation, it is checking if two types have the sum of the third. (the types must be equal)
Since Validator class has a vector of types it needs to evaluate, the relevant types are inserted in the constructor
of this object. The validation depends on the order if insertion.

------------------
RoomValidator
------------------

Used for form validation, it is checking if the number of people that can enter in all rooms
the user required is not greater than the maximum number of people that can be in those rooms.
The validation depends on the order of insertion in constructor.

List of files
===========================

BaseField.h					BaseField.cpp
BaseValidator.h				BaseValidator.cpp
DateValidator.h				BaseValidator.cpp
Field.h						Field.cpp
Form.h						Form.cpp
IDValidator.h				IDValidator.cpp
NoDigitValidator.h			NoDigitValidator.cpp
NonNegativeValidator.h		NonNegativeValidator.cpp
NotGreaterThanValidator.h	NonGreaterThanValidator.cpp
RangeValidator.h			RangeValidator.cpp
SumValidator.cpp			SumValidator.cpp
Validator.h					Validator.cpp
macros.h

DATA STRUCTURES
==========================
NOTEWORTHY ALGORHTIMS
==========================
KNOWN BUGS
==========================
ELSE
==========================
