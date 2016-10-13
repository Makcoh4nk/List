#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <iostream>

using namespace std;

struct ListBrackets
{
	char s;
	ListBrackets *next;
};

void Add(ListBrackets **list, char s)
{
	ListBrackets *node = new ListBrackets;
	node->next = *list;
	node->s = s;
	*list = node;
}

bool isCorrect(char *s)
{
	ListBrackets *list = NULL;

	if (strlen(s) % 2 == 1)
		return false;
	else
	{
		for (int i = 0; i < strlen(s); ++i)
			if ((s[i] == '{') || (s[i] == '(') || (s[i] == '['))
				Add(&list, s[i]);
			else
			{
				if (list == NULL)
					return false;
				if ((s[i] == '}') && (list->s) != '{')
					return false;
				if ((s[i] == ')') && (list->s) != '(')
					return false;
				if ((s[i] == ']') && (list->s) != '[')
					return false;
				list = list->next;
			}

		if (list == NULL)
			return true;
		else
			return false;
	}
}

void Test(char *s)
{
	if (isCorrect(s) == true)
		cout << s << " - TRUE" << endl;
	else
		cout << s << " - FALSE" << endl;
}

void main()
{
	char s1[1] = "";
		Test(s1);
	char s2[2] = "(";
		Test(s2);
	char s3[3] = "[]";
		Test(s3);
	char s4[4] = "]{}";
		Test(s4);
	char s5[5] = "[]()";
		Test(s5);
	char s6[6] = "{[)]}";
		Test(s6);
	char s7[7] = "[{](})";
		Test(s7);
	char s8[8] = "()[{}]";
		Test(s8);
	char s9[9] = "[({})[]]"; 
		Test(s9);
	char s10[10] = ")({[]})(";
		Test(s10);
	_getch();
}