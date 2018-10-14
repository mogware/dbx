#ifndef __DBX_MDBX_ENV__
#define __DBX_MDBX_ENV__

#include "dbx.noncopyable.h"
#include "dbx.env.h"
#include "mdbx.h"

namespace dbx
{
	class mdbx_env : public env, public noncopyable
	{
		::MDBX_env* handle_;
	public:
		mdbx_env(::MDBX_env* const handle);
		virtual ~mdbx_env(void);
	public:
		void open(const char* path, const unsigned int& flags,
			const unsigned int& mode);
		void copy(const char* path, const unsigned int& flags);
	public:
		void sync(const bool& force);
	public:
		std::shared_ptr<dbx::stat> stat(void) const;
		std::shared_ptr<dbx::info> info(void) const;
	public:
		void set_flags(const unsigned int& flags, const bool& onoff);
		unsigned int flags(void) const;
	public:
		std::string path(void) const;
	public:
		void set_mapsize(const std::size_t& size);
		void set_max_readers(const unsigned int& count);
		void set_max_dbs(const unsigned int& count);
	public:
		std::shared_ptr<txn> begin(const unsigned int& flags = 0);
	public:
		void close(void);
	};
}

#endif

