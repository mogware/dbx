#include "dbx.mdbx_stat.h"

dbx::mdbx_stat::mdbx_stat(std::uint32_t psize, std::uint32_t depth,
		std::uint64_t branch_pages, std::uint64_t leaf_pages,
		std::uint64_t overflow_pages, std::uint64_t entries)
	: psize_(psize)
	, depth_(depth)
	, branch_pages_(branch_pages)
	, leaf_pages_(leaf_pages)
	, overflow_pages_(overflow_pages)
	, entries_(entries)
{
}

std::uint32_t dbx::mdbx_stat::psize(void)
{
	return psize_;
}

std::uint32_t dbx::mdbx_stat::depth(void)
{
	return depth_;
}

std::uint64_t dbx::mdbx_stat::branch_pages(void)
{
	return branch_pages_;
}

std::uint64_t dbx::mdbx_stat::leaf_pages(void)
{
	return leaf_pages_;
}

std::uint64_t dbx::mdbx_stat::overflow_pages(void)
{
	return overflow_pages_;
}

std::uint64_t dbx::mdbx_stat::entries(void)
{
	return entries_;
}

