#ifndef __DBX_MDBX_CUR__
#define __DBX_MDBX_CUR__

#include "dbx.noncopyable.h"
#include "dbx.cur.h"
#include "mdbx.h"

namespace dbx
{
	class mdbx_cur : public cur, public noncopyable
	{
		::MDBX_cursor* handle_;
	public:
		mdbx_cur(::MDBX_cursor* const handle);
		virtual ~mdbx_cur(void);
	public:
		std::shared_ptr<dbx::txn> txn(void) const;
		unsigned int dbi(void) const;
	public:
		bool get(std::shared_ptr<val>& key, std::shared_ptr<val>& data,
			const unsigned int& op);
		bool put(const std::shared_ptr<val>& key,
			std::shared_ptr<val>& data, const unsigned int& flags);
		bool del(const unsigned int& flags);
	public:
		virtual std::size_t count(void) const;
	public:
		void close(void);
	};
}

#endif



