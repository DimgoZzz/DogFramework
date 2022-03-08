#pragma once

namespace DogFW::memory
{
	template<class T>
	class UniquePtr
	{
	public:
		UniquePtr() noexcept
		{

		};
		UniquePtr(T* ptr) noexcept : ptr_(ptr) 
		{

		};
		~UniquePtr()
		{
			delete ptr_; 
		};

	public:
		UniquePtr(const UniquePtr& in) = delete;
		UniquePtr& operator=(UniquePtr const& in) = delete;

	public:
		UniquePtr(UniquePtr&& in) noexcept
		{
			if (&in != this)
			{
				reset(in.release());
			}
		};

		UniquePtr& operator=(UniquePtr&& in) noexcept
		{
			if (&in != this)
			{
				reset(in.release());
			}
			return *this;
		}

	public:
		T* operator->() const noexcept
		{
			return this->ptr_;
		}
		T& operator*() const noexcept
		{
			return *(this->ptr_);
		}
		T* get() const noexcept
		{
			return ptr_;
		};

		operator bool() const noexcept
		{
			return ptr_ != nullptr;
		}

	public:

		T* release() noexcept
		{
			T* tmp = ptr_;
			ptr_ = nullptr;
			return tmp;
		};
		void reset(T* ptr = nullptr) noexcept
		{
			if (ptr_ != ptr)
			{
				delete ptr_;
				ptr_ = ptr;
			}
		}

	private:
		T* ptr_ {nullptr};
	};
}

