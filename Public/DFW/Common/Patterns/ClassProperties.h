#pragma once

namespace DogFW::inline patterns
{
	class NonCopyable
	{
	public:
		NonCopyable() {};
		~NonCopyable() {};
	private:
		NonCopyable(NonCopyable const&) = delete;
		NonCopyable(NonCopyable&&) = delete;
	};

	class NonMoveable
	{
	private:
		NonMoveable& operator=(NonCopyable const&) = delete;
		NonMoveable& operator=(NonCopyable&&) = delete;
	};

}