#include <iostream>
#include <vector>
#include "Graph.hxx"
using namespace std;

class Node {
public:
    Node():_value(0){
    }
    Node(const int& value):_value(value){
    }
    
    bool operator==(Node* n){
        return _value == n->getValue();
    }
    
    int getValue(){
        return _value;
    }
private:
    int _value;
};

int main(){
    Graph<Node> g ;
    Node *n1 = new Node(0),*n2 = new Node(1),*n3 = new Node(2);
    g.addNode(n1);
    g.addNode(n2);
    g.addNode(n3);
    g.addConnexion(*n1,*n2);
    g.printConnexions();
}