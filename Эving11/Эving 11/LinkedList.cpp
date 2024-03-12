#include "LinkedList.h"
#include <cassert>
#include <iostream>
#include <memory>
#include <ostream>
#include <sstream>
#include <string>
namespace LinkedList{

std::ostream & operator<<(std::ostream & os, const Node & node){
    os << node.getValue() << '\n';
    return os;
}


Node* LinkedList::insert(Node* pos, const std::string& value){
    if(pos == begin()){
        head = std::make_unique<Node>(value,std::move(head),nullptr);
    }else{
        auto prevNode = pos->prev;
        prevNode->next = std::make_unique<Node>(value,std::move(prevNode->next),prevNode);
        pos->prev = prevNode->getNext();
    }
 }


Node* LinkedList::remove(Node* pos){
    if(pos == begin()){
        head = std::move(pos->next);
        head->prev = nullptr;

        return begin();
    }else{
        auto nextNode = pos->getNext();
        pos->next->prev = pos->prev;
        pos->prev->next = std::move(pos->next);
        return nextNode;
    }

}   

void LinkedList::remove(const std::string& value){
    auto node = find(value);
    if(node != end()){
        remove(node);
    }
}

Node* LinkedList::find(const std::string& value){
	// node points to the first node
	auto node = begin();
	// traverse the list untill we reach the end, ord finds the value
	while (node != end() && node->value != value) {
		// make node point to the next node
		node = node->getNext();
	}
	// return the node with the given value,
	// or end() if the value wasn't found
	return node;
}

std::ostream& operator<<(std::ostream& os, const LinkedList& list){
	auto x = list.begin();
	os << "[" << *x;
	x = x->getNext();
	while (x != list.end()) {
		os << " " << *x;
		x = x->getNext();
	}
	os << "]";
	return os;
}



} //Namespace