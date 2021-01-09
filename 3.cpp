#include<iostream>

using namespace std;
struct ENode{
	int data = 0;
	ENode *link=0;
};
struct node{
	int data=0;
	node *next;
};
struct list{
	node *head;
	int length;
};
void listInit(list *a)
{
	a->head = (node *)calloc(1, sizeof(node));
	a->length = 0;
	return;
}
void listAdd(list *a, int d)
{
	node *b;
	b = (node*)calloc(1, sizeof(node));
	b->data = d;
	if (!a->head->next)
		a->head->next = b;
	else{
		b->next = a->head->next;
		a->head->next = b;
	}
	a->length++;
}
void printList(list *a)
{
	node *b;
	
	b = a->head->next;
	if (b!=NULL){

		cout << b->data;
		b = b->next;
	}
	while (b) {
		cout << ","<<b->data;
		b = b->next;
		if (!b) cout << "\n";
	}
	return;
}
void Equivalence()

{

	char c;
	int i, j, n;
	cin >> n;
	if (n < 0)
	{
		cout << "number is not correct. error." << endl;
		return;
	}

	ENode **first = new ENode*[n];
	bool *out = new bool[n];

	for (i = 0; i < n; i++)
	{
		first[i] = 0;
		out[i] = false;
	}

	while (!cin.eof())
	{
		cin >> i >>c>> j;
		if (i>n || j > n||i<0||j<0) {
			cout << "number is error." << endl;
			return;
		}

		ENode *x = new ENode;
		x->data = j;
		x->link = first[i];
		first[i] = x;

		ENode *y = new ENode;
		y->data = i;
		y->link = first[j];
		first[j] = y;

	}
	for (i = 0; i < n; i++)
	{
		list a;
		listInit(&a);

		if (out[i] == false)
		{
			listAdd(&a, i);
			out[i] = true;
			ENode *x = first[i];
			ENode *top = 0;
			while (1)
			{
				while (x)
				{
					j = x->data;
					if (out[j] == false)
					{
						listAdd(&a, j);
						out[j] = true;
						ENode *y = x->link;
						x->link = top;
						top = x;
						x = y;
					}
					else
						x = x->link;
				}

				if (!top)

					break;
				else
				{
					x = first[top->data];
					top = top->link;
				}
			}
		}
		printList(&a);

	}

	cout << endl;
}


int main(void)

{
	Equivalence();

	return 0;
}
