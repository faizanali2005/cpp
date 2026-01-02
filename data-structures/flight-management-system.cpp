#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

/* =======================
   FLIGHT STRUCT
======================= */
struct Flight {
    int id;
    string origin;
    string destination;
    string departure;
    string arrival;
};

/* =======================
   AVL TREE NODE
======================= */
struct Node {
    Flight data;
    Node* left;
    Node* right;
    int height;

    Node(Flight f) {
        data = f;
        left = right = nullptr;
        height = 1;
    }
};

/* =======================
   AVL TREE CLASS
======================= */
class AVL {
public:
    Node* root;

    AVL() {
        root = nullptr;
    }

    int height(Node* n) {
        return n ? n->height : 0;
    }

    int balance(Node* n) {
        return n ? height(n->left) - height(n->right) : 0;
    }

    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;

        return x;
    }

    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;

        return y;
    }

    Node* insert(Node* node, Flight f) {
        if (!node)
            return new Node(f);

        if (f.id < node->data.id)
            node->left = insert(node->left, f);
        else if (f.id > node->data.id)
            node->right = insert(node->right, f);
        else
            return node;

        node->height = 1 + max(height(node->left), height(node->right));
        int b = balance(node);

        // AVL Cases
        if (b > 1 && f.id < node->left->data.id)
            return rightRotate(node);

        if (b < -1 && f.id > node->right->data.id)
            return leftRotate(node);

        if (b > 1 && f.id > node->left->data.id) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        if (b < -1 && f.id < node->right->data.id) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    void inorder(Node* node) {
        if (!node) return;
        inorder(node->left);
        printFlight(node->data);
        inorder(node->right);
    }

    Node* search(Node* node, int id) {
        if (!node || node->data.id == id)
            return node;
        if (id < node->data.id)
            return search(node->left, id);
        return search(node->right, id);
    }

    void printFlight(Flight f) {
        cout << "ID: " << f.id
             << " | " << f.origin << " -> " << f.destination
             << " | Dep: " << f.departure
             << " | Arr: " << f.arrival << endl;
    }
};

/* =======================
   FILE HANDLING
======================= */
void saveToCSV(Flight f) {
    ofstream file("flights.csv", ios::app);
    file << f.id << ","
         << f.origin << ","
         << f.destination << ","
         << f.departure << ","
         << f.arrival << endl;
    file.close();
}

void loadFromCSV(AVL& tree) {
    ifstream file("flights.csv");
    if (!file.is_open()) return;

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string temp;
        Flight f;

        getline(ss, temp, ','); f.id = stoi(temp);
        getline(ss, f.origin, ',');
        getline(ss, f.destination, ',');
        getline(ss, f.departure, ',');
        getline(ss, f.arrival, ',');

        tree.root = tree.insert(tree.root, f);
    }
    file.close();
}

/* =======================
   MENU
======================= */
int main() {
    AVL tree;
    loadFromCSV(tree);

    int choice;
    do {
        cout << "\n===== FLIGHT MANAGEMENT (AVL + CSV) =====\n";
        cout << "1. Add Flight\n";
        cout << "2. Display All Flights\n";
        cout << "3. Search Flight by ID\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            Flight f;
            cout << "Enter ID: ";
            cin >> f.id;
            cin.ignore();
            cout << "Origin: ";
            getline(cin, f.origin);
            cout << "Destination: ";
            getline(cin, f.destination);
            cout << "Departure Time: ";
            getline(cin, f.departure);
            cout << "Arrival Time: ";
            getline(cin, f.arrival);

            tree.root = tree.insert(tree.root, f);
            saveToCSV(f);
            cout << "Flight Added Successfully!\n";
        }
        else if (choice == 2) {
            cout << "\n--- ALL FLIGHTS ---\n";
            tree.inorder(tree.root);
        }
        else if (choice == 3) {
            int id;
            cout << "Enter Flight ID: ";
            cin >> id;
            Node* res = tree.search(tree.root, id);
            if (res)
                tree.printFlight(res->data);
            else
                cout << "Flight Not Found!\n";
        }

    } while (choice != 4);

    return 0;
}

