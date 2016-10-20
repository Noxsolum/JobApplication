#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

typedef int bool;
#define true 1
#define false 0


int init_access(char*);
int has_access(char*, int);

FILE *_fp;

char* user_details[50][25];
char* storage_string[50][25];

void main()
{
	/*
	There are a few limitations with this program; 
	Firstly with the way I have added the commentting of the file, the user has to use the specified '#' otherwise it will carry on as normal.
	The size of the array make a problem for when there are errors with the username length because of the way I have split the text up for analyzing.
	I've had to use a couple of extra arrays extra than what I would of liked to because of the way the strtok works.
	There isn't too much in the way of error handling but I think I got the basic errors fixed.
	Visual studio doesn't like fopen so I had to add _CRT_SECURE_NO_WARNINGS to make sure it works.

	If the requirement changed such that a much larger number of users or screens needed to be stored I would more than likely just need to change the sizes of the arrays.
	The way I have processed the data relys on spaces so having the amount of data changed doesn't matter too much. The only likely problem that could happen would be bad memory management with the amount of arrays I have.
	*/
	char _filePath[1000];
	
	printf("Please enter the file path of the text file.\nIf you wish to use the default file, leave empty and press 'Enter'.\nLines beginning with '# ' will be ignored!\n");

	gets(_filePath);
	init_access(_filePath);

	system("pause");
}

int init_access(char* file_path)
{
	int _index = 0;
	int _sA = 0;
	int stringLength = 0;
	bool ignored_lines[50];
	char *_checkString[50][25];
	char *_splitString;

	if (file_path[0] == NULL)
		_fp = fopen("..\\UserDetails.txt", "r");
	else
		_fp = fopen(file_path, "r");

	if (_fp == NULL)
	{
		perror("Cannot open file");
		return 0;
	}

	for (int i = 0; i < 50; i++)
	{
		fgets(storage_string[i], 25, _fp);
		if (strlen(storage_string[i]) != 0)
		{
			_sA++;
		}
	}

	fclose(_fp);

	if (file_path[0] == NULL)
		_fp = fopen("..\\UserDetails.txt", "r");
	else
		_fp = fopen(file_path, "r");

	if (_fp == NULL)
	{
		perror("Cannot open file");
		return 0;
	}

	for (int i = 0; i < _sA; i++)
	{
		ignored_lines[i] = true;
		fgets(_checkString[i], 25, _fp);
		_splitString = strtok(_checkString[i], " ");

		while (_splitString != NULL)
		{
			if (strcmp(_splitString, "#") == 0)
				ignored_lines[i] = false;

			stringLength = strlen(_splitString);

			if (stringLength > 5)
			{
				printf("A username has not been formatted correctly.\n");
				return 0;
			}
			_splitString = strtok(NULL, " ");
		}
	}

	fclose(_fp);

	for (int j = 0; j < _sA; j++)
	{
		if (ignored_lines[j] == true)
		{
			strncpy(user_details[_index], storage_string[j], 50);
			_index++;
		}
	}

	char user_name[6];
	int access_screen;
	printf("Please enter your username!\n");
	gets(user_name);
	printf("Please enter which screen you would like to access!\n");
	scanf("%d", &access_screen);

	has_access(user_name, access_screen);
}

int has_access(char* user_name, int screen)
{
	bool user_exists = false;
	bool can_access = false;
	bool valid_user = false;
	char *tempString;
	char *screenChar[1] = { screen + '0' };
	for (int i = 0; i < 50; i++)
	{
		user_exists = false;
		can_access = false;
		tempString = strtok(user_details[i], " ");
		while (tempString != NULL)
		{
			if (strcmp(tempString, user_name) == 0)
			{
				user_exists = true;
				valid_user = true;
				tempString = strtok(NULL, " ");
			}
			if (strcmp(tempString, screenChar) == 0)
			{
				can_access = true;
				tempString = strtok(NULL, " ");
			}
			else
				tempString = strtok(NULL, " ");
		}
		if (user_exists == true && can_access == true)
		{
			printf("\nAccess Granted to this screen: %d with this username: %s\n", screen, user_name);
			return 1;
		}
	}

	if (valid_user == true)
		printf("Access Denied to this screen: %d with this username: %s\n", screen, user_name);
	else
		printf("Invalid username: %s\n\n", user_name);

	return 0;
}