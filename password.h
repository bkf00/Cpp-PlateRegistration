#pragma once

#include <stdio.h>
#include <conio.h>
#include <string>


void read_pass(char* password)
{
	char ch;
	int i = 0;
	do
	{
		ch = _getch();
		password[i] = ch;
		if (ch != 27 && ch != 13)
			_putch('*');
		else
			break;
		i++;
	} while (i < 19);
	password[i] = '\0';
}

void decode_pass(char* password)
{
	for (int i = 0; password[i] != 0; i++)
		password[i] -= i;
}
