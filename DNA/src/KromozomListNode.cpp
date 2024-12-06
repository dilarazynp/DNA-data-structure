#include "KromozomListNode.hpp"
KromozomListNode::KromozomListNode(Kromozom* data,KromozomListNode *next=NULL){
	this->data = data;
	this->next = next;
}