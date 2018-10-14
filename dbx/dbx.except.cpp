#include "dbx.except.h"
#include "dbx.mdbx.h"

dbx::error::error(const char* const origin, const int& rc)
	: runtime_error(origin)
	, code_(rc)
{
}

const char* dbx::error::what() const
{
	static thread_local char buffer[1024];
	std::snprintf(buffer, sizeof(buffer),
		"%s: %s", origin().c_str(), ::mdbx_strerror(code()));
	return buffer;
}

void dbx::error::raise(const char* origin, const int& rc)
{
	switch (rc)
	{
	case MDBX_CORRUPTED:
		throw corrupted_error(origin, rc);
	case MDBX_PANIC:
		throw panic_error(origin, rc);
	case MDBX_VERSION_MISMATCH:
		throw version_mismatch_error(origin, rc);
	case MDBX_MAP_FULL:
		throw map_full_error(origin, rc);
#ifdef MDBX_BAD_DBI
	case MDBX_BAD_DBI:
		throw bad_dbi_error(origin, rc);
#endif
	default:
		throw dbx::runtime_error(origin, rc);
	}
}

#if !defined(__MDB_INLINE__)
#include "dbx.except.inl"
#endif