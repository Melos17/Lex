#ifndef TREE_H
#define TREE_H

#include <unordered_set>

#include "symbols.h"
#include "feature.h"

class AbstractTreeLeaf;

class AbstractTreeNode {
public:
	enum AbstractTreeType {
		Symbols, And, Or, Closure, ClosurePlus, OneOrNone, End
	};

	AbstractTreeNode(AbstractTreeType type) : mType(type) {
	}

	AbstractTreeNode(AbstractTreeType type, AbstractTreeNode* left, AbstractTreeNode* right) {
		mType = type;
		mLeft = left;
		mRight = right;
	}

	AbstractTreeNode(AbstractTreeType type, AbstractTreeNode* node) {
		mType = type;
		mLeft = node;
		mRight = NULL;
	}

	~AbstractTreeNode() {
		if (mLeft) delete mLeft;
		if (mRight) delete mRight;
	}


	void insertSet(std::unordered_set<AbstractTreeLeaf*>& from, std::unordered_set<AbstractTreeLeaf*>& to);
	bool isNullable();
	std::unordered_set<AbstractTreeLeaf*> getFirstPos();
	std::unordered_set<AbstractTreeLeaf*> getLastPos();

	AbstractTreeType getType() const { return mType; }
	AbstractTreeNode* getLeftNode() const { return mLeft; }
	AbstractTreeNode* getNode() const { return mLeft; }
	void setLeftNode(AbstractTreeNode* node) { mLeft = node; }
	AbstractTreeNode* getRightNode() const { return mRight; }
	void setRightNode(AbstractTreeNode* node) { mRight = node; }

	virtual void show() const;
	virtual AbstractTreeNode* clone() const;

private:
	AbstractTreeType mType;
	AbstractTreeNode* mLeft;
	AbstractTreeNode* mRight;
};


class AbstractTreeLeaf : public AbstractTreeNode {
public:
	AbstractTreeLeaf(SymbolCollection symbols) : AbstractTreeNode(AbstractTreeType::Symbols) {
		mSymbols = symbols;
	}

	SymbolCollection getSymbols() const { return this->mSymbols; }

	virtual AbstractTreeNode* clone() const {
		AbstractTreeNode* node = new AbstractTreeLeaf(mSymbols);
		return node;
	}

	virtual bool isEnd() const { return false; }

protected:
	AbstractTreeLeaf(AbstractTreeType type) : AbstractTreeNode(type) {
	}

private:
	SymbolCollection mSymbols;
};


class AbstractTreeEndLeaf : public AbstractTreeLeaf {
public:
	AbstractTreeEndLeaf() : AbstractTreeLeaf(AbstractTreeType::End) {
		mAcceptId = 0;
	}

	AbstractTreeEndLeaf(int acceptId) : AbstractTreeLeaf(AbstractTreeType::End) {
		mAcceptId = acceptId;
	}

	virtual AbstractTreeNode* clone() const {
		AbstractTreeNode* node = new AbstractTreeEndLeaf(mAcceptId);
		return node;
	}

	virtual bool isEnd() const { return true; }

	int getAcceptId() const { return mAcceptId; }

private:
	int mAcceptId;
};

#endif