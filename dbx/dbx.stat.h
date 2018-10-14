#ifndef __DBX_STAT__
#define __DBX_STAT__

#include <cstdint>

namespace dbx
{
	struct stat
	{
		/* size of a database page */
		virtual std::uint32_t psize(void) = 0;
		/* depth (height) of the B-tree */
		virtual std::uint32_t depth(void) = 0;
		/* number of internal (non-leaf) pages */
		virtual std::uint64_t branch_pages(void) = 0;
		/* number of leaf pages */
		virtual std::uint64_t leaf_pages(void) = 0;
		/* number of overflow pages */
		virtual std::uint64_t overflow_pages(void) = 0;
		/* number of data items */
		virtual std::uint64_t entries(void) = 0;
		virtual ~stat(void) {}
	};
}

#endif

