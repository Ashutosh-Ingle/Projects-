#include<iostream>
using namespace std;

//////////////////////////////////////////////////////
//Structure for singly linear and singly circular
template<class T>
struct NodeS                //S : Singly
{
    T data;
    struct NodeS *next;
};

//////////////////////////////////////////////////////////
//Structure for doubly linear and doubly circular
template<class T>
struct NodeD                //D : Doubly
{
    T data;
    struct NodeD *next;
    struct NodeD *prev;
};

//////////////////////////////////////////////////////////
//class of singly linear linked list
template<class T>
class SinglyLL
{
    public:
        struct NodeS<T> *first;
        int iCount;

    SinglyLL();
    
    void Display();
    int Count();

    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T, int);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);
};

template<class T>
SinglyLL <T>::SinglyLL()
{
    first = NULL;
    iCount = 0;
}

template<class T>
void SinglyLL<T>:: Display()
{
    cout<<"Elements of Singly Linear Linked list are : "<<"\n";

    NodeS<T> * temp = first;

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |-> ";
        temp = temp -> next;
    }
    cout<<"NULL"<<"\n";
}

template<class T>
int SinglyLL<T>::Count()
{
     return iCount;
}

template<class T>
void SinglyLL<T>::InsertFirst(T no)
{    
    NodeS<T> * newn = new NodeS<T>;

    newn->data = no;
    newn->next = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        newn->next = first;
        first = newn;
    }
    iCount++;
}

template<class T>
void SinglyLL<T>::InsertLast(T no)
{
    NodeS<T> * newn = new NodeS<T>;

    newn->data = no;
    newn->next = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        NodeS<T> *temp = first;

        while(temp->next != NULL)
        {
            temp= temp -> next;
        }
        temp->next = newn;
    }
    iCount++;
}

template<class T>
void SinglyLL<T>::DeleteFirst()
{
    if(first == NULL)
    {
        return;
    }
    else if(first -> next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        NodeS<T> *temp = first;

        first = first->next;
        delete temp;
    }
    iCount--;
}

template<class T>
void SinglyLL<T>::DeleteLast()
{
    if(first == NULL)
    {
        return;
    }
    else if(first -> next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        NodeS<T> *temp = first;

        while(temp ->next -> next!= NULL)
        {
            temp = temp -> next;
        }

        delete temp->next;
        temp->next = NULL;
    }
    iCount--;
}


template<class T>
void SinglyLL<T>::InsertAtPos(T no, int iPos)
{
     int iCount = Count();

    if((iPos < 1) || (iPos > iCount+1))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(no);
    }
    else if(iPos == iCount+1)
    {
        InsertLast(no);
    }
    else
    {
        NodeS<T> * temp = first;
        NodeS<T> * newn = new NodeS<T>;

        newn-> data = no;
        newn-> next = NULL;

        for(int iCnt = 1; iCnt < iPos -1; iCnt++)
        {
            temp = temp -> next;
        }

        newn->next = temp -> next;
        temp -> next = newn;
        
        iCount++;
    }
}

template<class T>
void SinglyLL<T>::DeleteAtPos(int iPos)
{
    int iCount = Count();

    if((iPos < 1) || (iPos > iCount))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        NodeS<T> * temp1 = first;
        NodeS<T> * temp2 = NULL;

        for(int iCnt = 1; iCnt < iPos -1; iCnt++)
        {
            temp1 = temp1 -> next;
        }

        temp2 = temp1->next->next;
        delete temp1->next;
        temp1->next = temp2;
        
        iCount--;
    }
}

/////////////////////////////////////////////////////////////////
//class of singly circular linked list
template<class T>
class SinglyCL
{
    public:
        struct NodeS<T> *first;
        struct NodeS<T> *last;
        int iCount;

    SinglyCL();
    
    void Display();
    int Count();

    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T, int);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);
};

template<class T>
SinglyCL <T>::SinglyCL()
{
    first = NULL;
    last = NULL;
    iCount = 0;
}

template<class T>
void SinglyCL<T>:: Display()
{
    NodeS<T> *temp = first;
    NodeS<T> *tempX = last;
    cout<<"Elements of Linked list are : "<<"\n";

    if(temp != NULL && tempX != NULL)
    {
        do
        {
        cout<<"|"<<temp->data<<"|->";
        temp = temp->next;
        }while(temp != tempX->next);
        cout<<"\n";
    }
    else
    {
        cout<<"Linkes list is empty";
    }
    cout<<"NULL"<<"\n";
}

template<class T>
int SinglyCL<T>::Count()
{
    return iCount;
}

template<class T>
void SinglyCL<T>::InsertFirst(T no)
{
    NodeS<T> *newn = NULL;
    newn = new NodeS<T>;

    newn-> data = no;
    newn->next = NULL;

    if((first == NULL) &&(last == NULL))
    {
       first = newn; 
       last = newn;
    }
    else
    {
        newn ->next = first;
        first = newn;
    }
    last->next = first;
    iCount++;
}

template<class T>
void SinglyCL<T>::InsertLast(T no)
{
    NodeS<T> * newn = NULL;
    newn = new NodeS<T>;

    newn-> data = no;
    newn->next = NULL;

    if((first == NULL) &&(last == NULL))
    {
       first = newn; 
       last = newn;
    }
    else
    {
       last -> next = newn;
       last = last -> next;  
    }
    last-> next = first;
    iCount++;
}

template<class T>
void SinglyCL<T>::InsertAtPos(T No, int iPos)
{
    if((ipos < 1) || (ipos > iCount+1))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(ipos == 1)
    {
        InsertFirst(No);
    }
    else if(ipos == iCount+1)
    {
        InsertLast(No);
    }
    else
    {
        NODES<T>* temp = first;

        for(int iCnt = 1; iCnt < ipos -1 ;iCnt++)
        {
            temp = temp->next;
        }
        NodeS<T>* newn = new NodeS<T>;
        newn -> data = No;
        newn -> next = NULL;

        newn->next = temp->next;
        temp->next = newn;
        iCount++;
    }
}

template<class T>
void SinglyCL<T>::DeleteFirst()
{
    if((first == NULL) && (last == NULL))
    {
        return;
    }
    else if(first == last)
    {
        delete first;
        first = NULL;
        last =NULL;
    }
    else
    {
        NodeS<T> * temp = first;

        first = first->next;
        delete temp;
        last -> next = first;
    }
    iCount--;
}

template<class T>
void SinglyCL<T>::DeleteLast()
{
    if((first == NULL) &&(last == NULL))
    {
        return;
    }
    else if(first == last)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        NodeS<T> * temp = first;

        while(temp->next != last)
        {
            temp = temp->next;
        }
        delete last;
        last = temp;
        last ->next = first;
    }
    iCount--;
}

template<class T>
void SinglyCL<T>::DeleteAtPos(int ipos)
{
    if((ipos < 1) || (ipos > iCount))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(ipos == 1)
    {
        DeleteFirst();
    }
    else if(ipos == iCount)
    {
        DeleteLast();
    }
    else
    {
        NodeS<T> * temp = first;
        NodeS<T> * tempX = NULL;

        for(int iCnt = 1; iCnt < ipos -1 ;iCnt++)
        {
            temp = temp->next;
        }

        tempX = temp->next;
        temp->next = temp->next->next;
        delete tempX;
        iCount--;
    }
}

///////////////////////////////////////////////////////////////
//class of doubly linear linked list 
template<class T>
class DoublyLL
{
    public:
        struct NodeD<T> *first;
        int iCount;

    DoublyLL();
    
    void Display();
    int Count();

    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T, int);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);
};

template<class T>
DoublyLL <T>::DoublyLL()
{ 
    first = NULL;
    iCount = 0;
}

template<class T>
void DoublyLL<T>:: Display()
{
    cout<<"Elements of Singly Linear Linked list are : "<<"\n";

    NodeD<T> * temp = first;

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |-> ";
        temp = temp -> next;
    }
    cout<<"NULL"<<"\n";
}

template<class T>
int DoublyLL<T>::Count()
{
    return iCount;
}

template<class T>
void DoublyLL<T>::InsertFirst(T no)
{
     NodeD<T> * newn = new NodeD<T>;
    newn ->data = no;
    newn -> next = NULL;
    newn -> prev = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        first -> prev = newn;
        newn -> next = first;
        first = newn;
    }
    iCount++;
}

template<class T>
void DoublyLL<T>::InsertLast(T no)
{
     NodeD<T> * newn = new NodeD<T>;
    newn->data = no;
    newn->next = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        NodeS<T> *temp = first;

        while(temp->next != NULL)
        {
            temp= temp -> next;
        }
        
        temp->next = newn;
        newn->prev = temp;
    }
    iCount++;
}

template<class T>
void DoublyLL<T>::DeleteFirst()
{
    if(first == NULL)
    {
        return;
    }
    else if(first -> next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        first = first -> next;
        delete first -> prev;
        first -> prev =NULL;
    }
}

template<class T>
void DoublyLL<T>::DeleteLast()
{
    if(first == NULL)
    {
        return;
    }
    else if(first -> next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        NodeD<T> * temp = first;

        while(temp ->next-> next != NULL)
        {
            temp = temp -> next;
        }
        delete temp -> next;
        temp -> next = NULL;
    }
}

template<class T>
void DoublyLL<T>::InsertAtPos(T no, int iPos)
{
    if(iPos < 1 || iPos > iCount + 1)
    {
        cout << "Invalid position\n";
        return;
    }

    NodeD<T> *newn = new NodeD<T>;
    newn->data = no;

    if(iPos == 1)
    {
        newn->next = first;
        newn->prev = NULL;

        if(first != NULL)
            first->prev = newn;
        
        first = newn;
    }
    else
    {
        NodeD<T> *temp = first;

        for(int i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        newn->prev = temp;
        
        if(temp->next != NULL)
            temp->next->prev = newn;

        temp->next = newn;
    }

    iCount++;
}

template<class T>
void DoublyLL<T>::DeleteAtPos(int iPos)
{
     if(iPos < 1 || iPos > iCount)
    {
        cout << "Invalid position\n";
        return;
    }

    if(iPos == 1)
    {
        NodeD<T> *temp = first;
        first = first->next;

        if(first != NULL)
            first->prev = NULL;

        delete temp;
    }
    else
    {
        NodeD<T> *temp = first;

        for(int i = 1; i < iPos; i++)
        {
            temp = temp->next;
        }

        temp->prev->next = temp->next;

        if(temp->next != NULL)
            temp->next->prev = temp->prev;

        delete temp;
    }

    iCount--;
}

///////////////////////////////////////////////////////////
//class of doubly circular linked list
template<class T>
class DoublyCL
{
    public:
        struct NodeD<T> *first;
        struct NodeD<T> *last;
        int iCount;

    DoublyCL();
    
    void Display();
    int Count();

    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T, int);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);
};
template<class T>
DoublyCL <T>::DoublyCL()
{
    first = NULL;
    last = NULL;
    iCount = 0;
}

template<class T>
void DoublyCL<T>:: Display()
{
    NodeD<T> * temp = first;
            cout<<"Elements of Linked List are : "<<"\n";

            for(int iCnt = 1; iCnt <= iCount; iCnt++)
            {
                cout<<"| "<<temp->data<<" |-> ";
                temp = temp -> next;
            }
            cout<<"NULL"<<"\n";
}

template<class T>
int DoublyCL<T>::Count()
{
    return iCount;
}

template<class T>
void DoublyCL<T>::InsertFirst(T no)
{
    NodeD<T> *newn = new NodeD<T>(no);

    if(first == NULL && last == NULL)
    {
        first = newn;
        last = newn;
    }
    else
    {
        newn->next = first;
        first -> prev = newn;
        first = newn;
    }

    last -> next = first;
    first -> prev = last;

    iCount++;
}

template<class T>
void DoublyCL<T>::InsertLast(T no)
{
    NodeD<T> * newn = new NodeD<T>(no);

    if(first == NULL && last == NULL)
    {
        first = newn;
        last = newn;
    }
    else
    {
        last->next = newn;
        newn->prev = last;
        last = last->next;
    }

    last -> next = first;
    first -> prev = last;

    iCount++;
}

template<class T>
void DoublyCL<T>::InsertAtPos(T no, int ipos)
{
    if((ipos < 1) || (ipos > iCount+1))
    {
        cout<<"Invalid position\n";
        return;
    }
    
    if(ipos == 1)
    {
        InsertFirst(no);
    }
    else if(ipos == iCount+1)
    {
        InsertLast(no);
    }
    else
    {
        NodeD<T> * temp = first;

        for(int icnt = 1; icnt < ipos -1; icnt++)
        {
            temp = temp->next;
        }
        NodeD<T> * newn = new NodeD<T>;
        newn ->next = temp->next;
        temp->next->prev = newn;

        temp->next = newn;
        newn->prev = temp;

        iCount++;
    }
}

template<class T>
void DoublyCL<T>::DeleteFirst()
{
     if(iCount == 0)
    {
        return;
    }
    else if(iCount == 1)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        first = first->next;
        delete last->next;

        first->prev = last;
        last->next = first;
    }
    iCount--;
}

template<class T>
void DoublyCL<T>::DeleteLast()
{
     if(iCount == 0)
    {
        return;
    }
    else if(iCount == 1)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        last = last -> prev;
        delete last->prev;

        first->prev = last;
        last->next = first;
    }
    iCount--;
}

template<class T>
void DoublyCL<T>::DeleteAtPos(int ipos)
{
    
    if((ipos < 1) || (ipos > iCount))
    {
        cout<<"Invalid position\n";
        return;
    }
    
    if(ipos == 1)
    {
        DeleteFirst();
    }
    else if(ipos == iCount)
    {
        DeleteLast();
    }
    else
    {
         NodeD<T> * temp = first;

        for(int icnt = 1; icnt < ipos -1; icnt++)
        {
            temp = temp->next;
        }

        temp ->next = temp->next->next;
        delete temp->next->prev;

        temp->next->prev = temp;
    }
}
///////////////////////////////////////////////////////////////
//Logic of 32 functions

int main()
{
    return 0;
}