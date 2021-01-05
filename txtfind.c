#include <stdio.h>
#include <string.h>


// Max word length
#define WORD	30

// Max line length
#define LINE	256



/* This function reads a line from the standard input */
int getLine(char s[])
{
	int n = 0;
	int c;

	// Read character by character from the standard input until reach '\n' or EOF
    while (1)
	{
        c = getchar();

		if (c == '\n' || c == EOF)
			break;

		// Save the input character in 's' string
		s[n++] = c;
	}

	// Add end of string
	s[n] = '\0';

	// Return the characters count
	return n;
}


/* This function reads a word from the standard input */
int getWord(char w[])
{
	int n = 0;
	int c;

	// Read character by character from the standard input until reach ' ' or '\t' or '\n' or EOF
    while (1)
	{
        c = getchar();

		if (c == ' ' || c == '\t' || c == '\n' || c == EOF)
			break;
		
		// Save the input character in 'w' string
		w[n++] = c;
	}

	// Add end of string
	w[n] = '\0';

	// Return the characters count
	return n;
}


/* This function search for 'str2' inside 'str1' */
int substring(char * str1, char * str2)
{
	int i;
	int len1 = strlen(str1);
	int len2 = strlen(str2);

	// Loop on str1
	for (i = 0; i < len1; i++)
	{
		// For each pos check if includes str2
		if (strncmp(&str1[i], str2, len2) == 0)
			return 1;
	}

	// Match not found
	return 0;
}


/* This function checks if 't' is similar to 's' after discarding up to n characters from 's' */
int similar(char *s, char *t, int n)
{
	int i = 0;
	int j = 0;
	int discardCount = 0;


	// Loop on string 't'
	while (i < strlen(t)) 
	{
		// If current character in 't' equals character in 's' (GOOD)		
		if (t[i] == s[j])
		{
			// Move both strings to next index
			i++;
			j++;
		}
		else // If character in 't' is diff from character in 's' (BAD) 
		{
			// Move only 's' to next index => actually discard the character
			j++;

			// Increase the discard characters counter
			discardCount++;

			// If not similar after discarding N characters, return false
			if (discardCount > n)
				return 0;
		}
	}

	// If the 's' length is too big return false
	if (strlen(s) > (strlen(t) + n))
	{
		return 0;
	}

	// If we reach here then a similarity was found, return true
	return 1; 
}


/* This function prints all lines that include 'str' */
void print_lines(char *str)
{
	char line[LINE];

	// Iterate all lines in the rest of the file 
	while (getLine(line) != 0)
	{
		if (substring(line, str) == 1)
			printf("%s\n", line);
	}
}


/* This function prints all words that similar to 'str' */
void print_similar_words(char *str)
{
	char word[WORD];

	// Iterate all words in the rest of the file 
	while (getWord(word) != 0)
	{
		if (similar(word, str, 1) == 1)
			printf("%s\n", word);
	}
}


/* Main function */
int main()
{
	int		n;
	char	word1[WORD];
	char	word2[WORD];
	
	

	n = getWord(word1);
	if (n == 0)
	{
		printf("Invalid input word #1\n");
		return 0;
	}

	n = getWord(word2);
	if (n == 0)
	{
		printf("Invalid input word #2\n");
		return 0;
	}

	if (strcmp(word2, "a") == 0)
	{
		print_lines(word1);
	}
	else if (strcmp(word2, "b") == 0)
	{
		print_similar_words(word1);
	}
	else
	{
		printf("Invalid input word #2 %s\n", word2);
	}
}

