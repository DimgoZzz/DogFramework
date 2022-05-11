#pragma once

namespace DogFW
{
	class ClassNoCopy
	{
	public:
		ClassNoCopy() {};
		~ClassNoCopy() {};
	private:
		ClassNoCopy(ClassNoCopy const&) = delete;
		ClassNoCopy& operator=(ClassNoCopy const&) = delete;
		ClassNoCopy(ClassNoCopy&&) = delete;
		ClassNoCopy& operator=(ClassNoCopy&&) = delete;
	};
}