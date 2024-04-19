/*Создать двунаправленный список, хранящий произвольные действительные числа.
 Обеспечить просмотр элементов списка, добавление новых элементов. 
 Удалить из списка все отрицательные элементы.
 */

#include <iostream>
using namespace std;

struct Node
{
    double value;
    Node* prev;
    Node* next;
    Node(double val) : value(val), prev(nullptr), next(nullptr) {}

};


class DList{
private:
    Node* head;
    Node* last;
public:
    DList(): head(nullptr), last(nullptr) {}
    void append (double vlaue){
        Node *newNode = new Node(vlaue);
        if(last == nullptr){
            head = last = newNode;
        } else{
            last-> next = newNode;
            newNode->prev = last;
            last = newNode;
        }
    }
    void print() {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void delete_negatives(){
        Node* current = head;
        while (current != nullptr)
        {
            Node* nextNode = current->next;
            if(current->value < 0){
                if(current->prev != nullptr){
                    current->prev->next = current->next;
                } else{
                    head = current->next;
                }
                if(current->next != nullptr){
                    current->next->prev = current->prev;
                } else{
                    last = current->prev;
                }
                delete current;
            }
            current =nextNode;
        }
        
    }

};



int main(){
    DList list;
    list.append(1.0);
    list.append(2.23);
    list.append(-213.2);
    list.append(-21.0);
    list.append(100.101);
    list.append(-11.11);
    list.append(14.1);
    list.append(-21.4832084);

    cout << "до удаления отрицательных чисел" ;
    list.print();
    cout << "после удаления отрицательных чисел" ;
    list.delete_negatives();
    list.print();
}