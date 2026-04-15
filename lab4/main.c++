#include <iostream>
#include <string>

#define maxcouriersize 5

using namespace std;

struct package {
    string packageid;
    string destinationcity;
    int dimensions[3];
    package* next;
};

struct courier {
    string couriername;
    string vehicletype;
};

package* top = nullptr; 

courier courierqueue[maxcouriersize];
int front = -1;
int rear = -1;

void pushpackage(string id, string city, int d[]) 
{
    package* newnode = new package();
    newnode->packageid = id;
    newnode->destinationcity = city;
    newnode->dimensions[0] = d[0];
    newnode->dimensions[1] = d[1];
    newnode->dimensions[2] = d[2];
    newnode->next = top;
    top = newnode;
}

void poppackage() 
{
    if (top != nullptr) {
        package* temp = top;
        top = top->next;
        delete temp;
    }
}

void enqueuecourier(string name, string vehicle) {
    if ((front == (rear + 1) % maxcouriersize))  
    {
        cout << "Kuyruk dolu!" << endl;
        return;
    }
    if (front == -1) front = 0;
    rear = (rear + 1) % maxcouriersize; 
    courierqueue[rear].couriername = name;
    courierqueue[rear].vehicletype = vehicle;
}

void dequeuecourier() {
    if (front == -1) return;
    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % maxcouriersize;
    }
}

void sendpackage() {
    if (top == nullptr || front == -1) {
        cout << "hata: Paket veya kurye yok!" << endl;
        return;
    }
    
    cout << ">>> Gonderiliyor: " << courierqueue[front].couriername 
         << " adli kurye [" << top->packageid << "] nolu paketi " 
         << top->destinationcity << " sehrine goturmek uzere aldi." << endl;
    
    poppackage();
    dequeuecourier();
}

void show() {
    cout << "\n--- Paketler  ---" << endl;
    package* temp = top;
    if (temp == nullptr) cout << "Paket yok.";
    while (temp != nullptr) 
    {
       
     cout << "[" << temp->packageid << " -> " << temp->destinationcity << "] ";
        temp = temp->next;
    }
    
    cout << "\n--- Kuryeler (Queue) ---" << endl;
    if (front == -1) {
        cout << "Kurye yok.";
    } 
    else {
        int i = front;
        while (true) {
            cout << courierqueue[i].couriername << " ";
            if (i == rear) break;
            i = (i + 1) % maxcouriersize;
        }
    }
    cout << "\n" << endl;
}

int main() {
    int olculer[] = {10, 10, 10};
    
    pushpackage("P1", "Duzce", olculer);
    pushpackage("P2", "Kocaeli", olculer);
    
    enqueuecourier("Kerem", "Motor");
    enqueuecourier("Emirhan", "Tuk-Tuk");
    
    show();
    sendpackage();
    show();
    
    return 0;
}