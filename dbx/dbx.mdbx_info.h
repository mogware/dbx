#ifndef __DBX_MDBX_INFO__
#define __DBX_MDBX_INFO__

#include "dbx.info.h"

namespace dbx
{
	class mdbx_info : public info
	{
		std::uint64_t mapsize_;
		std::uint64_t last_pgno_;
		std::uint64_t recent_txnid_;
		std::uint32_t maxreaders_;
		std::uint32_t numreaders_;
	public:
		mdbx_info(std::uint64_t mapsize, std::uint64_t pgno,
			std::uint64_t txnid, std::uint32_t maxreaders,
			std::uint32_t numreaders);
	public:
		std::uint64_t mapsize(void);
		std::uint64_t last_pgno(void);
		std::uint64_t recent_txnid(void);
		std::uint32_t maxreaders(void);
		std::uint32_t numreaders(void);
	};
}

#endif

