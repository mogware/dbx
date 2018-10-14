#ifndef __DBX_MDBX_VAL__
#define __DBX_MDBX_VAL__

#include "dbx.noncopyable.h"
#include "dbx.val.h"
#include "mdbx.h"

namespace dbx
{
	class mdbx_val : public val, public noncopyable
	{
		::MDBX_val val_;
	public:
		mdbx_val(const void* data, const std::size_t& size);
		virtual ~mdbx_val(void);
	public:
		operator MDBX_val*(void);
		operator const MDBX_val*(void) const;
	public:
		bool empty(void) const;
		std::size_t size(void) const;
	public:
		char* data(void);
		const char* data(void) const;
	public:
		void assign(const void* data, const std::size_t& size);
	};
}

#endif


