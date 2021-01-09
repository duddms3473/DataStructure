#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>

typedef int element;
typedef struct{
	element stack[100];
	int top;
}StackType;

void init(StackType *s){
	s->top = -1;
}

int is_full(StackType *s)
{
	if (s->top == 99)
		return 1;
	else return 0;
}
void push(StackType *s, element item){
	if (is_full(s)){
		std::cout << "스택 포화 에러\n" << std::endl;
		return;
	}
	else s->stack[++(s->top)] = item;
}
int is_empty(StackType *s){
	if (s->top == -1)
		return 1;
	else return 0;
}
element peek(StackType *s){
	if (is_empty(s)){
		std::cout << "스택 공백에러\n" << std::endl;
		exit(1);
	}
	else return s->stack[s->top];
}

element pop(StackType *s){
	if (is_empty(s)){
		std::cout << "스택 공백 에러\n" << std::endl;
		exit(1);
	}
	else return s->stack[(s->top)--];
}

int prec(char op){
	switch (op){
	case '(': case ')':return 0;
	case '+':case '-':return 1;
	case '*': case'/': return 2;
	}
	return -1;
}


void infix_to_postfix(char* infix, char *postfix){
	StackType s;
	init(&s);
	if (*infix == '-')
	{
		*postfix++ = *infix++;
	}
	else if (*infix == '+')
	{
		*infix++;
	}

	while (*infix != NULL){
		
		if (*infix == '('){
			push(&s, *infix);
			*infix++;
			if (*infix == '+')
				*infix++;
			else if (*infix == '-')
				*postfix++ == *infix++;
		}
		else if (*infix == ')'){
			while (peek(&s) != '('){
				*postfix++ = pop(&s);
				*postfix++ = ' ';
			}
			pop(&s);
			*infix++;
		}
		else if (*infix == '+' || *infix == '-' || *infix == '*' || *infix == '/'){
			*infix++;
			if (*infix == '+')
			{
				*infix--;
				while (!is_empty(&s) && (prec(*infix) <= prec(peek(&s)))){
					*postfix++ = pop(&s);
					*postfix++ = ' ';
				}
				push(&s, *infix);
				*infix++;
				*infix++;
				continue;
			}
			else if (*infix == '-')
			{
				*infix--;
				while (!is_empty(&s) && (prec(*infix) <= prec(peek(&s)))){
					*postfix++ = pop(&s);
					*postfix++ = ' ';
				}
				push(&s, *infix);
				*infix++;
				*postfix++ = *infix++;
				*postfix++ = *infix++;
				*postfix++ = ' ';
				continue;
			}
			else *infix--;
			
			while (!is_empty(&s) && (prec(*infix) <= prec(peek(&s)))){
				*postfix++ = pop(&s);
				*postfix++ = ' ';
			}
			push(&s, *infix);
			infix++;
		}
		else if (*infix >= '0'&&*infix <= '9'){
			do{
				*postfix++ = *infix++;
			} while ((*infix >= '0'&&*infix <= '9'));
			*postfix++ = ' ';
		}
		else
			infix++;
	}
	while (!is_empty(&s)){
		*postfix++ = pop(&s);
		*postfix++ = ' ';

	}
	postfix--;
	*postfix = NULL;

	return;
}

int main(void){
	std::string str;
	char in[100];
	
	while(!std::cin.eof())
	{
char out[100];
		getline(std::cin,str);

		strcpy(in,str.c_str());
		
		infix_to_postfix(in, out);
		std::cout << out << std::endl;
out[0]='\0';
	}
return 0;
}
