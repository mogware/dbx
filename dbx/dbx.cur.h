#ifndef __DBX_CUR__
#define __DBX_CUR__

#include <cstdint>
#include <memory>

namespace dbx
{
	struct val;
	struct txn;
	struct cur
	{
		static const unsigned int first;
		static const unsigned int first_dup;
		static const unsigned int get_both;
		static const unsigned int get_both_range;
		static const unsigned int get_current;
		static const unsigned int get_multiple;
		static const unsigned int last;
		static const unsigned int last_dup;
		static const unsigned int next;
		static const unsigned int next_dup;
		static const unsigned int next_multiple;
		static const unsigned int next_nodup;
		static const unsigned int prev;
		static const unsigned int prev_dup;
		static const unsigned int prev_nodup;
		static const unsigned int set;
		static const unsigned int set_key;
		static const unsigned int set_range;
		static const unsigned int prev_multiple;

		virtual std::shared_ptr<txn> txn(void) const = 0;
		virtual unsigned int dbi(void) const = 0;
		virtual bool get(std::shared_ptr<val>& key,
			std::shared_ptr<val>& data, const unsigned int& op) = 0;
		virtual bool put(const std::shared_ptr<val>& key,
			std::shared_ptr<val>& data, const unsigned int& flags = 0) = 0;
		virtual bool del(const unsigned int& flags = 0) = 0;
		virtual std::size_t count(void) const = 0;
		virtual void close(void) = 0;
		virtual ~cur(void) {}
	};
}

#endif
