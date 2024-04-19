/*
Составить однонаправленный список, хранящий информацию о многочлене n-го порядка. 
Элемент списка хранит коэффициент очередного слагаемого и показатель степени этого слагаемого. 
Если коэффициент равен нулю, то соответствующего элемента в списке быть не должно. 
Составить подпрограммы 1) проверки двух многочленов на равенство, заданных в виде списков, 
2) сложения двух многочленов, заданных в виде списков, и представления результата в виде списка.*/


#include <iostream>
// #include <utility>
using namespace std;


typedef pair<int, int> Term;

struct Node
{
    Term term;
    Node* next;
    Node(const Term& _term) : term(_term), next(nullptr) {}
    
};

class P{
private: 
    Node *head;
public: 
    P() : head(nullptr){}
    void add(const Term &term){
        if(term.first == 0){
            return;
        }
        Node* newNode = new Node(term);
        if(head == nullptr || head->term.second < term.second){
            newNode ->next = head;
            head = newNode;
        }else{
            Node* current  = head;
            while(current->next != nullptr && current->next->term.second > term.second){
                current = current->next;
            }
            newNode->next = current ->next;
            current->next = newNode;
        }
    }   
    void print(){
        Node* current = head;
        while (current!=nullptr)
        {
            cout << current ->term.first << "x^" << current ->term.second << " ";
            current = current ->next;
        }
        cout << endl;  
    }

    bool operator==(P other){
        Node* current1 = head;
        Node* current2 = other.head;
        while (current1 != nullptr && current2 != nullptr)
        {
            if(current1->term != current2->term) return false;
            current1 = current1->next;
            current2 = current2->next;
        }
        return current1 == nullptr && current2 == nullptr;  
    }


    P operator+(const P& other) const {
        P result;
        Node* current1 = head;
        Node* current2 = other.head;
        while (current1 != nullptr && current2 != nullptr) {
            if (current1->term.second > current2->term.second) {
                result.add(current1->term);
                current1 = current1->next;
            } else if (current1->term.second < current2->term.second) {
                result.add(current2->term);
                current2 = current2->next;
            } else {
                int sum = current1->term.first + current2->term.first;
                if (sum != 0) {
                    result.add({sum, current1->term.second});
                }
                current1 = current1->next;
                current2 = current2->next;
            }
        }
        while (current1 != nullptr) {
            result.add(current1->term);
            current1 = current1->next;
        }
        while (current2 != nullptr) {
            result.add(current2->term);
            current2 = current2->next;
        }
        return result;
    }


};



int main(){
    P listo;
    listo.add({3,2});
    listo.add({2,1});
    listo.add({1,0});
    P listt;
    listt.add({1,2});
    listt.add({-2,1});
    listt.add({3,0});
    
    listo.print();
    listt.print();

    if(listo == listt){
        cout << "многочлены равны" << endl;
    } else{
        cout << "многочлены не равны" << endl;
    }
    cout << "сумма многочленов" << endl;
    P sum_list = listo + listt;
    sum_list.print();
}