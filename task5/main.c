#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char SUBSTRING_SEPARATOR = ':';
const int MAX_STRING_LENGTH = 256;

int checkLogin(char login[], char string[])
{
	int i = 0;
	int loginLength = strlen(login);
	
	for (i; i < loginLength; i++)
	{
		if (string[i] == SUBSTRING_SEPARATOR)
		{
			break;
		}
		
		if (login[i] != string[i])
		{
			return 0;
		}
	}
	
	if (loginLength != i || string[i] != SUBSTRING_SEPARATOR)
	{
		return 0;
	}
	
	return 1;
}

int getSubstringStartIndex(char string[], char separator, int separatorIndex)
{
	int separatorCount = 0;
	int i = 0;
	
	for (i; i < strlen(string); i++)
	{
		if (separatorCount == separatorIndex)
		{
			break;
		}
		
		if (string[i] == separator)
		{
			separatorCount++;
		}
	}
	
	return i;
}

char *getUsername(char string[])
{
	char userinfoSeparator = ',';
	char *username = malloc(MAX_STRING_LENGTH * sizeof(char));
	
	int usernameStartIndex = getSubstringStartIndex(string, SUBSTRING_SEPARATOR, 4);
	int i = 0;
	int j = usernameStartIndex;
	
	for (i, j; j < strlen(string); i++, j++)
	{
		if (string[j] == userinfoSeparator || string[j] == SUBSTRING_SEPARATOR)
		{
			break;
		}
		
		username[i] = string[j];
	}
	
	username[i] = '\0';
	
	return username;
}

void printString(char *string)
{
	for (int i = 0; i < MAX_STRING_LENGTH; i++)
	{
		if (*(string + i) == '\0')
		{
			break;
		}
		
		printf("%c", *(string + i));
	}
	
	printf("\n");
}

int main(void)
{
	int maxLoginName = 32;
	char * filename = "/etc/passwd";
	FILE * passwordFile = fopen(filename, "r");
	char *username;
	int result = 0;
	
	char login[maxLoginName];
	printf("Enter your login: ");
	scanf("%32[^\n]", login);
	
	if (passwordFile)
	{
		char string[MAX_STRING_LENGTH];
		while ((fgets(string, MAX_STRING_LENGTH, passwordFile)) != NULL)
		{
			if (checkLogin(login, string))
			{
				username = getUsername(string);
				result = 1;
				break;
			}
		}
		
		fclose(passwordFile);
	}
	
	if (result)
	{
		printf("\nUsername: ");
		printString(username);
	}
	else
	{
		printf("Not found\n");
	}
	
	return 0;
}