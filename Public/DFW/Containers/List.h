#pragma once
#include "DFW/DBasicTypes.h"
#include "DFW/Containers/Pair.h"

namespace DogFW::containers
{
	//Double Linked List
	template<class T,class A=Bool>
	class List
	{
#pragma region IteratorNodeClasses
	////////////////////////////////////
	//Forward declare
	private:class Node;
	public: class Iterator;
	public: 
		using ValueType = T;
		using AllocType = A;
	////////////////////////////////////
	//Node
	private:
		class Node
		{
			//Node() noexcept : next(nullptr), prev(nullptr);
			//Node(T value, Node* nn, Node* pn) noexcept :data(value), next(nn), prev(pn) {};
			T data;
			Node* next;
			Node* prev;

			friend class List;
		};
	////////////////////////////////////
	//Iterator
	public:
		class Iterator
		{
		public:
			//Iterator() noexcept : currentNode_(nullptr) {};
			Iterator(Node* ptr) noexcept			 : currentNode_(ptr) {}
			Iterator(const Iterator& other) noexcept : currentNode_(other.currentNode_) {}

			Iterator& operator=(Node* ptr)	noexcept			{ currentNode_ = ptr; return *this; }
			Iterator& operator=(const Iterator& other) noexcept { currentNode_ = other.currentNode_; return *this; }
			
			~Iterator() noexcept {}

			//Prefix overload
			Iterator& operator++()
			{
				if (currentNode_)
				{
					currentNode_ = currentNode_->next;
				}
				return *this;
			}
			//Postfix overload
			Iterator& operator++(int)
			{
				Iterator temp = *this;
				++(*this);
				return *this;
			}
			//Prefix overload
			Iterator& operator--()
			{
				if (currentNode_)
				{
					currentNode_ = currentNode_->prev;
				}
				return *this;
			}
			//Postfix overload
			Iterator& operator--(int)
			{
				Iterator temp = *this;
				--(*this);
				return *this;
			}

			bool operator!=(const Iterator& other)
			{
				return currentNode_ != other.currentNode_;
			}
			bool operator==(const Iterator& other)
			{
				return currentNode_ == other.currentNode_;
			}
			
			T& operator*()
			{
				return (currentNode_->data);
			}
		private:
			Node* getNodePtr() { return currentNode_; }

		private:
			Node* currentNode_;

			friend class List;
		};
	////////////////////////////////////
#pragma endregion IteratorNodeClasses
		
	public:
		List() noexcept {  }

	public:
		//Iterators
		Iterator begin()
		{
			return Iterator(headPtr_);
		}
		Iterator end()
		{
			return Iterator(nullptr);
		}

		//Info

		Bool isEmpty()		{ return size_ == 0;}
		UInt64 getSize()	{ return size_;		}
		//UInt64 getMaxSize() { return maxSize_;	}
		
		T getFrontElement()		{ return headPtr_->data; }
		T getBackElement()		{ return tailPtr_->data; }
		T& getFrontElementR()	{ return headPtr_->data; }
		T& getBackElementR()	{ return tailPtr_->data; }

		void pushFront(const T& value)
		{
			Node* newNode = new Node;
			newNode->data = value;

			newNode->next = headPtr_;
			newNode->prev = nullptr;

			if (headPtr_ != nullptr)
			{
				headPtr_->prev = newNode;
			}
			headPtr_ = newNode;

			++size_;
		};
		//void pushFront(T&& value);
		void pushBack(const T& value)
		{
			//If list is empty
			if (headPtr_ == nullptr)
			{
				pushFront(value);
				return;
			}
			
			Node* newNode = new Node;
			newNode->data = value;
			newNode->next = nullptr;

			//If only head exists 
			if (tailPtr_ == nullptr)
			{
				newNode->prev = headPtr_;
				headPtr_->next = newNode;
			}
			else
			{
				newNode->prev = tailPtr_;
				tailPtr_->next = newNode;
			}
			tailPtr_ = newNode;

			++size_;
		};
		//void pushBack(T&& value);

		/// <summary>
		/// Inserts new value after given iterator.
		/// </summary>
		/// <returns>Pair of Iterator to new element,and Bool indicating success</returns>
		Pair<Iterator, Bool> insertAfter(Iterator insIter, const T& value)
		{
			if (insIter.currentNode_ == nullptr)
			{
				return Pair(insIter, false);
			}

			Node* newNode = new Node();
			newNode->data = value;


			Node *prevNode = insIter.getNodePtr();
			Node *nextNode = prevNode->next;

			newNode->next = nextNode;
			newNode->prev = prevNode;

			prevNode->next = newNode;

			if (nextNode != nullptr)
			{
				nextNode->prev = newNode;	
			}
			else
			{
				tailPtr_ = newNode;
			}

			++size_;

			return Pair(Iterator(newNode), true);
		}
		Pair<Iterator, Bool> insertBefore(Iterator insIter, const T& value)
		{
			if (insIter.currentNode_ == nullptr)
			{
				return Pair(insIter, false);
			}

			Node* newNode = new Node();
			newNode->data = value;


			Node* nextNode = insIter.getNodePtr();
			Node* prevNode = nextNode->prev;

			newNode->next = nextNode;
			newNode->prev = prevNode;

			nextNode->prev = newNode;

			if (prevNode != nullptr)
			{
				prevNode->next = newNode;
			}
			else
			{
				headPtr_ = newNode;
			}

			++size_;

			return Pair(Iterator(newNode), true);
		}

		void erase(Iterator iter)
		{
			Node* nodeRef = iter.getNodePtr();
			Node* next = nodeRef->next;
			Node* prev = nodeRef->prev;

			if (next != nullptr)
			{
				next->prev = prev;
			}
			if (prev != nullptr)
			{
				prev->next = next;
			}

			delete nodeRef;

			--size_;
		}
		//void erase(Iterator iterFirst, Iterator iterLast);
		void popBack() 
		{
			if (tailPtr_ == nullptr) { return; }
			Node* nodeRef = tailPtr_;
			Node* next = nullptr;
			Node* prev = nodeRef->prev;

			if (prev != nullptr)
			{
				prev->next = next;
			}

			delete nodeRef;

			--size_;
		}
		void popFront();

	private:
		Node* headPtr_ {nullptr};
		Node* tailPtr_ {nullptr};
		UInt64 size_{ 0 };
		//UInt64 maxSize_{ 0 };
	};
}