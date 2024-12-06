#include "GenNode.hpp"

GenNode::GenNode(const char& data,GenNode *next=NULL,GenNode *prev=NULL){
	this->data = data;
	this->next = next;
	this->prev = prev;
}
