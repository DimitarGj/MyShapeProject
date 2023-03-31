/// Dimitar Gjorgievski, UIN 650730211
/// CS 251
/// Project 4 - Shape List
///
#pragma once

#include "shape.h"
#include <iostream>

using namespace std;

class ShapeNode
{
    public:
        Shape *value;
        ShapeNode *next;
};

class CanvasList
{
    private:
        int listSize;
        ShapeNode *listFront;

        //Helper function for push_back to traverse to the end of the list
        void AppendNode(ShapeNode *add, ShapeNode *list){
            if(list->next == NULL){
                list->next = add;
                return;
            }else{
                AppendNode(add, list->next);
            }
        }

    public:
        CanvasList();
        CanvasList(const CanvasList &);
        CanvasList operator=(const CanvasList &);
        
        virtual ~CanvasList();
        void clear();
        
        void insertAfter(int, Shape *);
        void push_front(Shape *);
        void push_back(Shape *);
        
        void removeAt(int);
        Shape* pop_front();
        Shape* pop_back();

        ShapeNode* front() const;
        bool isempty() const;
        int size() const;

        int find(int x, int y) const;
        Shape* shapeAt(int) const;
        
        void draw() const;
        void printAddresses() const;
};

//Defining default constructor of class CanvasList
CanvasList::CanvasList(){
    listSize = 0;
    listFront = NULL;   
}

//Defining copy constructor of class CanvasList
CanvasList::CanvasList(const CanvasList &c){
   ShapeNode* curr = c.listFront;
   ShapeNode* copy;
   listSize = c.listSize;
   if(listSize==0){
       listFront = NULL;
   }else{
        listFront = new ShapeNode;
        listFront->next = NULL;
        copy = listFront;
        while(curr!=NULL){
            copy->value = curr->value->copy();
            if(curr->next==NULL){
                copy->next = NULL;
                break;    
            }
            copy->next = new ShapeNode;
            copy = copy->next;
            curr = curr->next;
        }
    }
}

//Defining = operator of class CanvasList
CanvasList CanvasList::operator=(const CanvasList &c){
 this->clear();
   ShapeNode* curr = c.listFront;
   ShapeNode* copy;
   listSize = c.listSize;
   if(listSize==0){
       listFront = NULL;
   }else{
        listFront = new ShapeNode;
        listFront->next = NULL;
        copy = listFront;
        while(curr!=NULL){
            copy->value = curr->value->copy();
            if(curr->next==NULL){
                copy->next = NULL;
                break;    
            }
            copy->next = new ShapeNode;
            copy = copy->next;
            curr = curr->next;
        }
    }
    return *this;
}

//Defining the destructor of the class CanvasList
CanvasList::~CanvasList(){
    this->clear();
}

//Defining the clear function which deletes the linked list
void CanvasList::clear(){
    while(listFront!=NULL){
        ShapeNode *temp = listFront->next;
        delete listFront->value;
        delete listFront;
        listFront = temp;
    }
    listSize = 0;
}

//Defining the insertAfter function which adds a new shape to the linked list after node at index x
void CanvasList::insertAfter(int x, Shape *s){
    int i = 0;
    ShapeNode *new_node = new ShapeNode;
    ShapeNode *prev = NULL;
    ShapeNode *curr = listFront;
    while(curr!=NULL){
        if(i==x){
            listSize++;
            new_node->value = s;
            new_node->next = curr->next;
            prev = curr;
            prev->next = new_node;
            break;
        }
        prev = curr;
        curr = curr->next;
        i++;
    }
}

//Defining the push_front function which prepends a new shape to the linked list
void CanvasList::push_front(Shape *s){
    if(listSize==0){
        listSize++;
        listFront = new ShapeNode;
        listFront->next = NULL;
        listFront->value=s;
    }else{
        listSize++;
        ShapeNode *new_node = new ShapeNode;
        new_node->value = s;
        new_node->next = listFront;
        listFront = new_node;    
    }
}

//Defining the push_back function which appends a new shape to the linked list
void CanvasList::push_back(Shape *s){
    if(listSize==0){
        listSize++;
        listFront = new ShapeNode;
        listFront->next = NULL;
        listFront->value=s;
    }else{
        listSize++;
        ShapeNode* new_node = new ShapeNode;
        new_node->next = NULL;
        new_node->value = s;
        AppendNode(new_node, listFront);
    }
}

//Defining the removeAt function which removes the node at index x
void CanvasList::removeAt(int x){
    int i = 0;
    ShapeNode* curr = listFront;
    ShapeNode* prev = NULL;
    ShapeNode* del;
    
    if(listSize==0){
        return;
    }

    while (curr!=NULL)
    {   
        if(i==x){
            if(x==0){
                listSize--;
                del = listFront;
                listFront = listFront->next;
                delete del->value;
                delete del;  
                return;                             
             }else{
                listSize--;
                del = curr;
                curr = curr->next;
                prev->next = curr;
                delete del->value;
                delete del;                
            }
            break;
        }
        i++;
        prev = curr;
        curr = curr->next;
    }
     
}

//Defining the pop_front function which returns and removes the shape of the first node
Shape* CanvasList::pop_front(){
    if(listFront!=NULL){
       listSize--;
       Shape *popped = listFront->value;
       ShapeNode *old_list = listFront;
       listFront = listFront->next;
       delete old_list;
       return popped;
    }
    return NULL;
}

//Defining the pop_back function which returns and removes the shape of the last node
Shape* CanvasList::pop_back(){
    ShapeNode* Curr = listFront;
    if(listSize==1){
        listSize--;
        Shape* popped = Curr->value;
        delete Curr;
        listFront = NULL;
        return popped;
    }else if(listSize>1){
        while(Curr !=NULL){
            if(Curr->next->next==NULL){
                listSize--;
                Shape* popped = Curr->next->value;
                delete Curr->next;
                Curr->next = NULL;
                return popped;
            }
            Curr = Curr->next;
        }
    }
    return NULL;
}

//Defining the front function which returns the first node of the linked list
ShapeNode* CanvasList::front() const{
    if(listSize==0){
        return NULL;
    }else{
        return listFront;
    }
}

//Defining the isempty function which returns a true or false value depending on the size of the linked list
bool CanvasList::isempty() const{
    if(listSize!=0){
        return false;
    }else{
        return true;
    }

}

//Defining the size function which returns size of linked list
int CanvasList::size() const{
    return listSize;
}

//Defining the find function of class Canvaslist which returns index of node with x and y parameters
int CanvasList::find(int x, int y) const{
    int i=0;
    ShapeNode *head = listFront;
    while (head!=NULL)
    {
        if(head->value->getX()==x && head->value->getY()==y){
           return i;
        }
        i++;
        head = head->next;
    }
    return -1;

}

//Defining the shapeAt function of class Canvaslist which returns shape of node at x index of linked list
Shape* CanvasList::shapeAt(int x) const{
    int i = 0;
    ShapeNode *head = listFront;
    while(head!=NULL){
        if(i==x){
            return head->value;
            break;
        }
        head = head->next;
        i++;
    }
    return NULL;
}

//Defining the draw() function of class Canvaslist which prints out details of shapes in linked list
void CanvasList::draw() const{
    ShapeNode* new_node = listFront;
    while (new_node!=NULL)
    {
        new_node->value->printShape();
        new_node = new_node->next;
    }
}

//Defining the printAddresses() function of class Canvaslist which prints out the adress of the linked list
void CanvasList::printAddresses() const{
    ShapeNode *head = listFront;
    while (head!=NULL)
    {
        cout<<"Node Address: "<<head<<"    "<<"Shape Address: "<<head->value<<endl;
        head = head->next;
    }

}