#include<iostream>
using namespace std;

int time1;
typedef enum colorName{
    WHITE,GRAY,BLACK
};
typedef pair<int,int> P;
typedef struct element{
    int fromnode;
    int tonode;
    struct element *next;
};
typedef struct list
{
    element *head;
    element *tail;
    int length;
    int d;
    int low;
    int nodeID;
    struct list *pi;
    struct list *next;
    colorName color;
};
void listInit(list *a)
{
    a->head=(element *)calloc(1,sizeof(element));
    a->tail=a->head->next;
    a->length=0;
}

void addArc(list *a, element *b){
    if(!a->tail){
        a->head->next=b;
        a->tail=b;
        ++a->length;
        return;
    }
    else{
        a->tail->next=b;
        a->tail=a->tail->next;
        ++a->length;
        return;
    }
}
void printList(list *a)
{
    element *b=a->head->next;
    while(b){
        cout<<b->tonode<<" -> ";
        b=b->next;
    }
    cout<<endl;
    return;
}
void printGraph(list *a,int numNode)
{
    int i;
    for(i=0;i<numNode;i++)
    {
        cout<<i<<":";
        printList(a+i);
    }
    return;
}
void DFS_Visit (list *a, list *u)
{
    element *v;
    time1=time1+1;
    u->d=time1;
    u->color=GRAY;
    v=u->head->next;
    while(v){
        if((a+v->tonode)->color==WHITE)
        {
            (a+v->tonode)->pi=u;
            DFS_Visit(a,a+v->tonode);
        }

        v=v->next;
    }
    
    return;
}

void DFS(list *a,int numNode)
{
    int i;
    for(i=0;i<numNode;i++)
    {
        (a+i)->color=WHITE;
        (a+i)->pi=NULL;
    }
    time1=0;
    for(i=0;i<numNode;i++){
        if((a+i)->color==WHITE){
        DFS_Visit(a,a+i);
        }
    }
        
 }

 void sibling_two(list *a,int numnode){
     int i,k;
     for(i=0;i<numnode;i++)
     {
         (a+i)->color=WHITE;

     }

     for(i=0;i<numnode;i++)
     {
         k=0;
         (a+i)->color=GRAY;
         element *b=(a+i)->head->next;
         while(b)
         {
             if((a+(b->tonode))->color==WHITE) k++;
             b=b->next;
         }
        
        (a+i)->low=k;
     }
 }
int main()
{
    string str;
    char c;
    int numnode,len,listnum,n,n1,i;
    list *V,*l;
    element *b;

    cin>>numnode;
    V=(list*)calloc(numnode,sizeof(list));
    for(i=0;i<numnode;i++)
    {
        listInit(V+i);
        (V+i)->nodeID=i;
        
    }


    while(!cin.eof())
    {
        cin>>listnum>>c;
        getline(cin,str);
        len=str.length();
        for(int i=0;i<len;i++){
            n=str[i]-'0';
            if((n>-1)&&(n<10))
            {
                b=(element*)calloc(1,sizeof(element));
                b->fromnode=listnum;
                b->tonode=n;
                addArc(V+listnum,b);
               
            }
        }
       str[0]=NULL;
    }

    DFS(V,numnode);
   
   for(i=0;i<numnode;i++)
   {
       cout<<i<<":"<<(V+i)->d<<endl;
   }
    return 0;
}