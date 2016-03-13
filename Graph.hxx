

#ifndef GRAPH_HXX
#define GRAPH_HXX
#define NOTEXIST -1

#include<vector>
#include<map>
#include<algorithm>

template<class N>



/*
class Graph{
/*
Node class should define the operand ==
Instances of Node sould be created with new Node...

Description of classes:
addNode():
    adds to the graph a blank node (default info in node class)
addNode(N* node):
    adds a specific node to the graph
addConnexion(N& node , N* connect):
    set a connexion from node to connect
nodeIndex(N* node):
    iterate through the vector of nodes and returns the index where was found or -1 if isn't in the graph
printConnexions():
    prints connexions of each node of the graph for the standard output
*/
/*
private:
    unsigned int _nNodes;
    std::vector<N*> _nodes ;
    std::vector<std::vector<N*> > _connexions;
    
    int nodeIndex(N* node){
        int i;
        for(i = 0 ; i < _nNodes;++i)
            if(*(_nodes[i]) == node)break;
        if(i == _nNodes){
            std::cout<<"Node isn't in the graph"<<std::endl;
            return NOTEXIST;
        }
        return i;
    }
public:
    Graph():_nNodes(0){
        
    }
    ~Graph(){
        for(int i = 0 ; i < _nNodes; ++i)
            delete _nodes[i];
    }
    void addNode(){
        N *node = new N() ;
        _nodes.push_back(node);
        _connexions.push_back(std::vector<N*>());
        _nNodes++;
    }
    void addNode(N* node){
        _nodes.push_back(node);
        _connexions.push_back(std::vector<N*>());
        _nNodes++;
    }
    void addConnexion(N& node , N& connect){
        int index = nodeIndex(&node);
        std::cout<<index<<std::endl;
        if(index != NOTEXIST){
            _connexions[index].push_back(&connect);
        }
    }
    void printConnexions(){
        for(int i = 0 ; i < _nNodes ; ++i){
            std::cout<<"Node id: "<<i<<" connects with:";
            for(int j = 0 ; j < _connexions[i].size() ; ++j){
                std::cout<<" "<<nodeIndex(_connexions[i][j]);
            }
            std::cout<<std::endl;
        }
    }
};*/
class Graph{
/*
    Compilation:
        flags :     -O2 -std=c++0x -funroll-loops -ftree-vectorizer-verbose=1 -o
        
    Node should have:   an empty constructor,
                        a method "double weightTo(Node* n)",
                        a method "string getInfo()" that returns some identifier of the node
*/
private:
    std::map<N*,std::vector< std::pair < N* , double > > > _nodes;   //maps a node into their connexions to other nodes. .first = connexion .second = cost of the connexion
public:
    Graph(){
        
    }
    ~Graph(){
        for(auto& element : _nodes){             //erase all nodes
            delete element.first;
        }
    }
    void addNode(N* node = new N() ){
        _nodes[node] = (std::vector< std::pair < N* , double > >());
    }
    void addConnexion(N* node , N* connect){
        double w = node->weightTo(connect);
        _nodes[node].push_back( std::make_pair(connect,w)  );
    }
    void addDoubleConnexion(N* node , N* connect){
        addConnexion(node,connect);
        addConnexion(connect,node);
    }
    void printConnexions(){
        for(auto& element : _nodes){
            std::cout<<"Node with info: "<< element.first->getInfo() <<" connects with:";
            for(auto& branch : element.second){
                std::cout<<" branch value "<<branch.second<<" connect to "<<branch.first->getInfo()<<" ;";
            }
            std::cout<<std::endl;
        }
    }
};


#endif