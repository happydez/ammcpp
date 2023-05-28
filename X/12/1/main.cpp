#include <iostream>

using namespace std;

struct NodeList {
    double Value;
    NodeList* Next;
};

int main() {

    int n;
    cout << "node list size >> "; cin >> n;

    NodeList* mainNode = new NodeList();
    NodeList* headNode = mainNode;

    for (int i = 0; i < n; i++) {
        cout << "Input " << i + 1 << " value >> ";
        cin >> mainNode->Value;
        mainNode->Next = new NodeList();
        mainNode = mainNode->Next;
    }

    mainNode = headNode;

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (mainNode->Value >= 7.0) {
            cnt++;
        }
        mainNode = mainNode->Next;
    }

    cout << "answer: " << cnt << endl;

    return 0;
}