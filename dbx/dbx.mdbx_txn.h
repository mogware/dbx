#ifndef __DBX_MDBX_TXN__
#define __DBX_MDBX_TXN__

#include "dbx.noncopyable.h"
#include "dbx.txn.h"
#include "mdbx.h"

namespace dbx
{
	class mdbx_txn : public txn, public noncopyable
	{
		::MDBX_txn* handle_;
	public:
		mdbx_txn(::MDBX_txn* const handle);
		virtual ~mdbx_txn(void);
	public:
		void commit(void);
		void abort(void);
		void reset(void);
		void renew(void);
	public:
		unsigned int open(const char* name, const unsigned int& flags) const;
	public:
		void drop(const unsigned int& db, const bool& del);
		unsigned int flags(const unsigned int& db) const;
		std::uint64_t size(const unsigned int& db) const;
		bool get(const unsigned int& db,
			const std::shared_ptr<val>& key, std::shared_ptr<val>& data);
		bool put(const unsigned int& db,
			const std::shared_ptr<val>& key, std::shared_ptr<val>& data,
			const unsigned int& flags);
		bool del(const unsigned int& db,
			const std::shared_ptr<val>& key);
	public:
		std::shared_ptr<cur> cursor(const unsigned int& db) const;
	};
}

#endif


