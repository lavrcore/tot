// ok.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

//#include <iostream>
//using namespace std;
//
//void bubbleSort(int arr[], int n)
//{
//    int tmp;
//    for (int i = 0; i < n - 1; i++)
//    {
//        for (int j = 0; j < n - i - 1;j++)
//        {
//            if (arr[j] > arr[j + 1]) {
//                tmp = arr[j];
//                arr[j] = arr[j + 1];
//                arr[j + 1] = tmp;
//            }
//        }
//    }
//}
//void show(int arr[], int n)
//{
//    for (int i = 0; i < n; i++)
//    {
//        cout << arr[i] << " ";
//    }
//}
//int main()
//{
//    int n = 7;
//    int arr[] = { 4 ,2 ,1, 6  , 50 , 23 , 87 };
//    bubbleSort(arr, n);
//    show(arr, n);
//            
//}
#include <iostream>
#include <vector>
using namespace std;


template <typename T>
class Stack {
private:
    unique_ptr <T[]> arr;
    int top;
    int capacity;

public:
    Stack() {};
    Stack(int size) {
        capacity = size;
        top = -1;
        arr = make_unique <T[]>(size);
    }

    void push(T value) {
        if (top == capacity - 1) {
            cout << "Stack is full\n";
        }
        else {
            top++;
            arr[top] = value;
        }
    }

    void pop() {
        if (top == -1) {
            cout << "Stack is empty\n";
        }
        else {
            top--;
        }

    }

    void show() {
        if (top == -1) {
            cout << "Stack is empty.\n";
        }
        else {
            cout << "Stack contents: ";
            for (int i = 0; i <= top; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};    
template <typename T>

class Queue {
    unique_ptr <T[]> arr;
    int length = 0;
    int counter = -1;
public:

    Queue() {};

    Queue(int length) {
        this->length = length;
        arr = make_unique<T[]>(this->length);
    };

    Queue(int length, T arr[]) {
        this->length = length;
        int otherLength = sizeof(arr) / sizeof(arr[0]);
        cout << sizeof(arr);
        cout << otherLength;
        cout << otherLength - 2;
        cout << this->counter;
        this->counter = otherLength - 1;
        for (int i = 0; i < otherLength; i++) {
            this->arr[i] = arr[i];
        }
    }

    void push_back(T val) {
        if (this->counter == this->length - 1) {
            this->length++;
            this->counter++;
            unique_ptr  <T[]> tmp = make_unique <T[]>(length);
            for (int i = 0; i < this->length - 1; i++) {
                tmp[i] = this->arr[i];
            }
            tmp[this->counter] = val;
        }
        else {
            this->counter++;
            this->arr[this->counter] = val;
        }

    }

    T pop() {
        T deletedVal = this->arr[this->counter];
        this->length--;
        this->counter--;
        unique_ptr  <T[]> tmp = make_unique <T[]>(length);
        for (int i = 1; i < this->counter + 2; i++) {
            tmp[i - 1] = this->arr[i];
        }
        arr.swap(tmp);
        return deletedVal;
    }

    void show() {
        for (int i = 0; i < this->counter + 1; i++) {
            cout << this->arr[i] << " ";
        }
        cout << endl;
    }
};
       
template <typename T>
class LinkedList
{
    struct Node
    {
        T val;
        shared_ptr <Node> next;
        Node(T val) : val(val), next(nullptr) {}
    };
    shared_ptr <Node> head;

public:
    LinkedList() : head(nullptr) {}
    void add(T val)
    {
        shared_ptr <Node> newNode = make_shared <Node>(val);
        if (this->head == nullptr)
        {
            this->head = newNode;
        }
        else
        {
            shared_ptr <Node> cur = this->head;
            while (cur->next != nullptr)
            {
                cur = cur->next;

            }
            cur->next = newNode;
        }
    }
    void remove(T val)
    {
        shared_ptr <Node> cur = this->head;
        shared_ptr <Node> prev = nullptr;
        while (cur != nullptr && cur->val != val)
        {
            prev = cur;
            cur = cur->next;
        }
        if (cur == nullptr)
        {
            return;
        }
        else if (prev == nullptr)
        {
            this->head = this->head->next;
        }
        prev->next = cur->next;

    }
    void show()
    {
        shared_ptr <Node> current = this->head;
        while (current != nullptr)
        {
            cout << current->val << " ";
            current = current->next;
        }
        cout << endl;

    }

};
int main()
{
    LinkedList <int> ll;
    ll.add(111);
    ll.add(20);
    ll.add(1);
    ll.add(0);
    ll.show();
    ll.remove(1);
    ll.show();
    cout << endl;
    Stack <int> ss(4);
    ss.push(1);
    ss.push(2);
    ss.push(3);
    ss.push(6);
    ss.show();
    ss.pop();
    ss.show();
    Queue <int> q(5);
    q.push_back(1);
    q.push_back(2);
    q.push_back(3);
    q.push_back(4);
    q.push_back(9);
    q.pop();
    q.show();
}

