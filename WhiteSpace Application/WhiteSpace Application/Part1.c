#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <stdarg.h>

char* capitalize(char*);

void main()
{
	/*
	The main limitation of my script is the length of the C-string array, because it's length has to be a constant, it cannot be updated based on what the user enters.
	Therefore there will always be a limit to what the user can enter into the program. 
	Also as there is not much error handling in C, I can't catch errors if the user enters too many characters for the C-string.

	There is a inbuilt library that automatically capitalizes letters instead of the switch statement I have used.

	If I was to obtain an uppercased verison of the origrinal string wihtout changing the original, I would store create a for loop to store the individual letters into a new C-string.
	e.g.
	char inputedString[x];
	char stringOriginal[x];

	gets(inputString);
	int stringLength = strlen(inputedString);

	for (int i = 0; i < stringlength; i++)
	{
		stringOriginal[i] = inputedString[i];
	}
	*/

	char _input[1000];
	printf("Please enter a string!\n\n");

	gets(_input);


	printf("\nYour string capitalized: %s\n\n", capitalize(_input));

	system("pause");
}

char* capitalize(char *_string)
{
	int string_Length = strlen(_string);

	printf("You entered: %s\n", _string);
	
	for (int i = 0; i < string_Length; i++)
	{
		switch (_string[i])
		{
		case 'a':
			_string[i] = 'A';
			break;
		case 'b':
			_string[i] = 'B';
			break;
		case 'c':
			_string[i] = 'C';
			break;
		case 'd':
			_string[i] = 'D';
			break;
		case 'e':
			_string[i] = 'E';
			break;
		case 'f':
			_string[i] = 'F';
			break;
		case 'g':
			_string[i] = 'G';
			break;
		case 'h':
			_string[i] = 'H';
			break;
		case 'i':
			_string[i] = 'I';
			break;
		case 'j':
			_string[i] = 'J';
			break;
		case 'k':
			_string[i] = 'K';
			break;
		case 'l':
			_string[i] = 'L';
			break;
		case 'm':
			_string[i] = 'M';
			break;
		case 'n':
			_string[i] = 'N';
			break;
		case 'o':
			_string[i] = 'O';
			break;
		case 'p':
			_string[i] = 'P';
			break;
		case 'q':
			_string[i] = 'Q';
			break;
		case 'r':
			_string[i] = 'R';
			break;
		case 's':
			_string[i] = 'S';
			break;
		case 't':
			_string[i] = 'T';
			break;
		case 'u':
			_string[i] = 'U';
			break;
		case 'v':
			_string[i] = 'V';
			break;
		case 'w':
			_string[i] = 'W';
			break;
		case 'x':
			_string[i] = 'Z';
			break;
		case 'y':
			_string[i] = 'Y';
			break;
		case 'z':
			_string[i] = 'Z';
			break;

		default:
			break;
		}
	}
	return _string;
}