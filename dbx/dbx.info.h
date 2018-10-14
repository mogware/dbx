#ifndef __DBX_INFO__
#define __DBX_INFO__

#include <cstdint>

namespace dbx
{
	struct info
	{
		/* size of the data memory map */
		virtual std::uint64_t mapsize(void) = 0;
		/* id of the last used page */
		virtual std::uint64_t last_pgno(void) = 0;
		/* id of the last committed transaction */
		virtual std::uint64_t recent_txnid(void) = 0;
		/* max reader slots in the environment */
		virtual std::uint32_t maxreaders(void) = 0;
		/* max reader slots used in the environment */
		virtual std::uint32_t numreaders(void) = 0;
		virtual ~info(void) {}
	};
}

#endif


