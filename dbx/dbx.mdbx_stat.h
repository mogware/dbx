#ifndef __DBX_MDBX_STAT__
#define __DBX_MDBX_STAT__

#include "dbx.stat.h"

namespace dbx
{
	class mdbx_stat : public stat
	{
		std::uint32_t psize_;
		std::uint32_t depth_;
		std::uint64_t branch_pages_;
		std::uint64_t leaf_pages_;
		std::uint64_t overflow_pages_;
		std::uint64_t entries_;
	public:
		mdbx_stat(std::uint32_t psize, std::uint32_t depth,
			std::uint64_t branch_pages, std::uint64_t leaf_pages,
			std::uint64_t overflow_pages, std::uint64_t entries);
	public:
		std::uint32_t psize(void);
		std::uint32_t depth(void);
		std::uint64_t branch_pages(void);
		std::uint64_t leaf_pages(void);
		std::uint64_t overflow_pages(void);
		std::uint64_t entries(void);
	};
}

#endif
