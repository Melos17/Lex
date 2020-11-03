#include "tree.h"

#include <iostream>
#include <queue>

void AbstractTreeNode::insertSet(std::unordered_set<AbstractTreeLeaf*>& from, std::unordered_set<AbstractTreeLeaf*>& to) {
	for (auto val : from) {
		to.emplace(val);
	}
}


bool AbstractTreeNode::isNullable() {
	switch (mType) {
	case AbstractTreeNode::Symbols:
	case AbstractTreeNode::End:
		return false;
	case AbstractTreeNode::And: {
		return mLeft->isNullable() && mRight->isNullable();
	}
	case AbstractTreeNode::Or: {
		return mLeft->isNullable() || mRight->isNullable();
	}
	case AbstractTreeNode::Closure:
	case AbstractTreeNode::OneOrNone: {
		return true;
	}
	case AbstractTreeNode::ClosurePlus: {
		return mLeft->isNullable();
	}
	}
	return false;
}


std::unordered_set<AbstractTreeLeaf*> AbstractTreeNode::getFirstPos() {
	std::unordered_set<AbstractTreeLeaf*> set;
	switch (mType) {
	case AbstractTreeNode::Symbols:
	case AbstractTreeNode::End:
		set.emplace((AbstractTreeLeaf*)this);
		break;
	case AbstractTreeNode::And: {
		std::unordered_set<AbstractTreeLeaf*> set_left = mLeft->getFirstPos();
		insertSet(set_left, set);
		if (mLeft->isNullable()) {
			std::unordered_set<AbstractTreeLeaf*> set_right = mRight->getFirstPos();
			insertSet(set_right, set);
		}
		break;
	}
	case AbstractTreeNode::Or: {
		std::unordered_set<AbstractTreeLeaf*> set_left = mLeft->getFirstPos();
		insertSet(set_left, set);
		std::unordered_set<AbstractTreeLeaf*> set_right = mRight->getFirstPos();
		insertSet(set_right, set);
		break;
	}
	case AbstractTreeNode::Closure:
	case AbstractTreeNode::ClosurePlus:
	case AbstractTreeNode::OneOrNone: {
		std::unordered_set<AbstractTreeLeaf*> set_left = mLeft->getFirstPos();
		set.swap(set_left);
		break;
	}
	}
	return move(set);
}

std::unordered_set<AbstractTreeLeaf*> AbstractTreeNode::getLastPos() {
	std::unordered_set<AbstractTreeLeaf*> set;
	switch (mType) {
	case AbstractTreeNode::Symbols:
	case AbstractTreeNode::End:
		set.emplace((AbstractTreeLeaf*)this);
		break;
	case AbstractTreeNode::And: {
		std::unordered_set<AbstractTreeLeaf*> set_right = mRight->getLastPos();
		insertSet(set_right, set);
		if (mRight->isNullable()) {
			std::unordered_set<AbstractTreeLeaf*> set_left = mLeft->getLastPos();
			insertSet(set_left, set);
		}
		break;
	}
	case AbstractTreeNode::Or: {
		std::unordered_set<AbstractTreeLeaf*> set_left = mLeft->getLastPos();
		insertSet(set_left, set);
		std::unordered_set<AbstractTreeLeaf*> set_right = mRight->getLastPos();
		insertSet(set_right, set);
		break;
	}
	case AbstractTreeNode::Closure:
	case AbstractTreeNode::ClosurePlus:
	case AbstractTreeNode::OneOrNone: {
		std::unordered_set<AbstractTreeLeaf*> set_left = mLeft->getLastPos();
		insertSet(set_left, set);
		break;
	}
	}
	return move(set);
}

AbstractTreeNode* AbstractTreeNode::clone() const {
	AbstractTreeNode* left = mLeft == NULL ? NULL : mLeft->clone();
	AbstractTreeNode* right = mRight == NULL ? NULL : mRight->clone();
	AbstractTreeNode* node = new AbstractTreeNode(mType, left, right);
	return node;
}

void AbstractTreeNode::show() const {
	std::queue<const AbstractTreeNode*> nodes;
	std::queue<int> ids;
	int lastId = 1;
	nodes.push(this);
	ids.push(1);
	std::cout << "[ ";

	while (!nodes.empty()) {
		const AbstractTreeNode* node = nodes.front();
		nodes.pop();
		int id = ids.front();
		ids.pop();

		if (id > lastId) {
			lastId = lastId * 2 + 1;
			std::cout << ']' << std::endl << "[ ";
		}

		if (node->getLeftNode()) {
			nodes.push(node->getLeftNode());
			ids.push(id * 2);
		}
		if (node->getRightNode()) {
			nodes.push(node->getRightNode());
			ids.push(id * 2 + 1);
		}

		switch (node->getType()) {
		case Symbols:
			std::cout << id << "." << dynamic_cast<const AbstractTreeLeaf*>(node)->getSymbols().getContent() << " ";
			break;
		case And:
			std::cout << id << ".@ ";
			break;
		case Or:
			std::cout << id << ".| ";
			break;
		case Closure:
			std::cout << id << ".* ";
			break;
		case ClosurePlus:
			std::cout << id << ".+ ";
			break;
		case OneOrNone:
			std::cout << id << ".? ";
			break;
		case End:
			std::cout << id << ".# ";
			break;
		}
		// std::cout << "(" << node << ")";

	}
	std::cout << ']' << std::endl;
}
