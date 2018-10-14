#ifndef __DBX_ENV__
#define __DBX_ENV__

#include <memory>
#include <string>

namespace dbx
{
	struct stat;
	struct info;
	struct txn;
	struct env
	{
		static const unsigned int nosubdir;
		static const unsigned int nosync;
		static const unsigned int rdonly;
		static const unsigned int nometasync;
		static const unsigned int writemap;
		static const unsigned int mapasync;
		static const unsigned int notls;
		static const unsigned int exclusive;
		static const unsigned int nordahead;
		static const unsigned int nomeminit;
		static const unsigned int coalesce;
		static const unsigned int liforeclaim;
		static const unsigned int pageperturb;

		virtual void open(const char* path, const unsigned int& flags = 0,
			const unsigned int& mode = 0644) = 0;
		virtual void copy(const char* path, const unsigned int& flags = 0) = 0;
		virtual void sync(const bool& force = true) = 0;
		virtual std::shared_ptr<stat> stat(void) const = 0;
		virtual std::shared_ptr<info> info(void) const = 0;
		virtual void set_flags(const unsigned int& flags,
			const bool& onoff = true) = 0;
		virtual unsigned int flags(void) const = 0;
		virtual std::string path(void) const = 0;
		virtual void set_mapsize(const std::size_t& size) = 0;
		virtual void set_max_readers(const unsigned int& count) = 0;
		virtual void set_max_dbs(const unsigned int& count) = 0;
		virtual std::shared_ptr<txn> begin(const unsigned int& flags = 0) = 0;
		virtual void close(void) = 0;
		virtual ~env(void) {}
		
		static std::shared_ptr<env> create(const unsigned int& flags = 0);
	};
}

#endif

