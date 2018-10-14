#ifndef __DBX_NONCOPYABLE__
#define __DBX_NONCOPYABLE__

namespace dbx
{
	class noncopyable
	{
	protected:
		constexpr noncopyable() = default;
		~noncopyable() = default;
	protected:
		noncopyable(const noncopyable&) = delete;
		noncopyable(noncopyable&&) = delete;
	protected:
		noncopyable & operator=(const noncopyable&) = delete;
		noncopyable& operator=(noncopyable&&) = delete;
	};
}

#endif

