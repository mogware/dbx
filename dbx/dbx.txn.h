#ifndef __DBX_TXN__
#define __DBX_TXN__

#include <memory>
#include <cstdint>

namespace dbx
{
	struct val;
	struct dbi;
	struct cur;
	struct txn
	{
		static const unsigned int reversekey;
		static const unsigned int dupsort;
		static const unsigned int integerkey;
		static const unsigned int dupfixed;
		static const unsigned int integerdup;
		static const unsigned int reversedup;
		static const unsigned int create;

		static const unsigned int trytxn;

		static const unsigned int nooverwrite;
		static const unsigned int nodupdata;
		static const unsigned int current;
		static const unsigned int reserve;
		static const unsigned int append;
		static const unsigned int appenddup;
		static const unsigned int multiple;

		virtual void commit(void) = 0;
		virtual void abort(void) = 0;
		virtual void reset(void) = 0;
		virtual void renew(void) = 0;

		virtual unsigned int open(const char* name,
			const unsigned int& flags = 0) const = 0;
		virtual void drop(const unsigned int& db, const bool& del = false) = 0;
		virtual unsigned int flags(const unsigned int& db) const = 0;
		virtual std::uint64_t size(const unsigned int& db) const = 0;
		virtual bool get(const unsigned int& db,
			const std::shared_ptr<val>& key, std::shared_ptr<val>& data) = 0;
		virtual bool put(const unsigned int& db,
			const std::shared_ptr<val>& key, std::shared_ptr<val>& data,
			const unsigned int& flags = 0) = 0;
		virtual bool del(const unsigned int& db,
			const std::shared_ptr<val>& key) = 0;
		virtual std::shared_ptr<cur> cursor(const unsigned int& db) const = 0;
		virtual ~txn(void) {}
	};
}

#endif


