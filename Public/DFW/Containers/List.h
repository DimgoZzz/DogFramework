#pragma once
#include "DFW/DBase.h"
#include "DFW/Containers/Pair.h"

namespace DogFW::containers
{
	//Double Linked List
	template<class T,class A=Bool>
	class List
	{
	public: 
		using DataType = T;
		using AllocatorType = A;
#pragma region Iterator
	////////////////////////////////////
	//Forward declare
	private:class Node;
	public: class Iterator;
	public: class ReverseIterator;
	////////////////////////////////////
	//Node
	private:
		class Node
		{
			Node() nexpt {};
			//Node() noexcept : next(nullptr), prev(nullptr);
			//Node(T value, Node* nn, Node* pn) noexcept :data(value), next(nn), prev(pn) {};
			T data;
			Node* next{nullptr};
			Node* prev{nullptr};

			friend class List;
		};
	////////////////////////////////////
	//Iterator
	public:
		class Iterator
		{
		public:
			//Iterator() noexcept : currentNode_(nullptr) {};
			Iterator(Node* ptr)				nexpt : currentNode_(ptr) {}
			Iterator(const Iterator& other) nexpt : currentNode_(other.currentNode_) {}

			Iterator& operator=(Node* ptr)				nexpt { currentNode_ = ptr; return *this; }
			Iterator& operator=(const Iterator& other)	nexpt { currentNode_ = other.currentNode_; return *this; }
			
			~Iterator() nexpt {};

			//Prefix overload
			Iterator& operator++() nexpt
			{
				if (currentNode_)
				{
					currentNode_ = currentNode_->next;
				}
				return *this;
			}
			//Postfix overload
			Iterator& operator++(int) nexpt
			{
				Iterator temp = *this;
				++(*this);
				return *this;
			}
			//Prefix overload
			Iterator& operator--() nexpt
			{
				if (currentNode_)
				{
					currentNode_ = currentNode_->prev;
				}
				return *this;
			}
			//Postfix overload
			Iterator& operator--(int) nexpt
			{
				Iterator temp = *this;
				--(*this);
				return *this;
			}
			
			bool operator!=(const Iterator& other) const nexpt
			{
				return currentNode_ != other.currentNode_;
			}
			bool operator==(const Iterator& other) const nexpt
			{
				return currentNode_ == other.currentNode_;
			}
			
			T& operator*() nexpt
			{
				return (currentNode_->data);
			}
			T* operator->() nexpt
			{
				return &(currentNode_->data);
			}
		private:
			Node* getNodePtr() nexpt { return currentNode_; }

		private:
			Node* currentNode_;

			friend class List;
		};
	////////////////////////////////////
#pragma endregion Iterator
		
	public:
		List() nexpt{}
		~List() nexpt
		{
			clear();
		}

	public:
		//Iterators
		Iterator begin() nexpt
		{
			return Iterator(headPtr_);
		}
		Iterator end() nexpt
		{
			return Iterator(nullptr);
		}

		Bool isEmpty()	 nexpt	{ return size_ == 0;}
		UInt64 getSize() nexpt	{ return size_;		}
		//UInt64 getMaxSize() { return maxSize_;	}
		
		T getFrontElement()	nexpt		{ return headPtr_->data; }
		T getBackElement()	nexpt		{ return tailPtr_->data; }
		T& getFrontElementRef() nexpt	{ return headPtr_->data; }
		T& getBackElementRef()  nexpt	{ return tailPtr_->data; }

		void pushFront(const T& value) nexpt
		{
			Node* newNode = new Node;
			newNode->data = value;
			newNode->prev = nullptr;

			newNode->next = headPtr_;

			if (headPtr_ != nullptr)
			{
				headPtr_->prev = newNode;
			}
			
			headPtr_ = newNode;

			if (tailPtr_ == nullptr)
			{
				tailPtr_ = newNode;
			}

			++size_;
		};
		//void pushFront(T&& value);
		void pushBack(const T& value) nexpt
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

			newNode->prev = tailPtr_;
			tailPtr_->next = newNode;

			tailPtr_ = newNode;

			++size_;
		};
		//void pushBack(T&& value);

		/// <summary>Inserts new value after given iterator.</summary>
		/// <returns>Pair of Iterator to new element,and Bool indicating success</returns>
		Pair<Iterator, Bool> insertAfter(Iterator insIter, const T& value) nexpt
		{
			if (insIter.currentNode_ == nullptr)
			{
				return Pair(insIter, false);
			}

			Node* newNode = new Node();
			newNode->data = value;

			Node* prevNode = insIter.getNodePtr();
			Node* nextNode = prevNode->next;

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
		
		/// <summary>Inserts new value after given iterator.</summary>
		/// <returns>Pair of Iterator to new element,and Bool indicating success</returns>
		Pair<Iterator, Bool> insertBefore(Iterator insIter, const T& value) nexpt
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

		void erase(Iterator iter) nexpt
		{
			Node* nodeRef = iter.getNodePtr();
			if (nodeRef == nullptr) { return; };

			Node* next = nodeRef->next;
			Node* prev = nodeRef->prev;

			if (next != nullptr)
			{
				next->prev = prev;
			}
			else
			{
				tailPtr_ = prev;
			}
			if (prev != nullptr)
			{
				prev->next = next;
			}
			else
			{
				headPtr_ = next;
			}

			delete nodeRef;

			--size_;
		}
		//void erase(Iterator iterFirst, Iterator iterLast);

		void popBack() nexpt
		{
			erase(begin());
		}
		void popFront() nexpt
		{
			erase(end());
		}

		void clear() nexpt
		{
			Node* next = begin().getNodePtr();
			Node* curr;
			while (next != nullptr)
			{
				curr = next;
				next = curr->next;
				delete curr;
			}
			headPtr_ = nullptr;
			tailPtr_ = nullptr;
			size_ = 0;
		}

	private:
		Node* headPtr_ {nullptr};
		Node* tailPtr_ {nullptr};
		UInt64 size_{ 0 };
		//UInt64 maxSize_{ 0 };
	};
}