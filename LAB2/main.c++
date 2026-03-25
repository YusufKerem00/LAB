#include <iostream>

using namespace std;

struct Node {

    string data;

    Node* next;

};


int main(){

Node* head = nullptr;
string input;




cout << "Kelime giriniz(UNDO: geri, EXIT:cikis):" << endl;

while (cin >> input && input!= "EXIT"){

    if(input =="UNDO"){
        if(head!=nullptr){
            if(head->next == nullptr){
                delete head;
                head = nullptr;
            }
        }
    }
}
     
}

