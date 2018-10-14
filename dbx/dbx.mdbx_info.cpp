#include "dbx.mdbx_info.h"

dbx::mdbx_info::mdbx_info(std::uint64_t mapsize, std::uint64_t pgno,
	std::uint64_t txnid, std::uint32_t maxreaders, std::uint32_t numreaders)
	: mapsize_(mapsize)
	, last_pgno_(pgno)
	, recent_txnid_(txnid)
	, maxreaders_(maxreaders)
	, numreaders_(numreaders)
{
}

std::uint64_t dbx::mdbx_info::mapsize(void)
{
	return mapsize_;
}

std::uint64_t dbx::mdbx_info::last_pgno(void)
{
	return last_pgno_;
}

std::uint64_t dbx::mdbx_info::recent_txnid(void)
{
	return recent_txnid_;
}

std::uint32_t dbx::mdbx_info::maxreaders(void)
{
	return maxreaders_;
}

std::uint32_t dbx::mdbx_info::numreaders(void)
{
	return numreaders_;
}
