#include "dbx.mdbx_env.h"
#include "dbx.mdbx_txn.h"
#include "dbx.mdbx_stat.h"
#include "dbx.mdbx_info.h"
#include "dbx.mdbx.h"

const unsigned int dbx::env::nosubdir = MDBX_NOSUBDIR;
const unsigned int dbx::env::nosync = MDBX_NOSYNC;
const unsigned int dbx::env::rdonly = MDBX_RDONLY;
const unsigned int dbx::env::nometasync = MDBX_NOMETASYNC;
const unsigned int dbx::env::writemap = MDBX_WRITEMAP;
const unsigned int dbx::env::mapasync = MDBX_MAPASYNC;
const unsigned int dbx::env::notls = MDBX_NOTLS;
const unsigned int dbx::env::exclusive = MDBX_EXCLUSIVE;
const unsigned int dbx::env::nordahead = MDBX_NORDAHEAD;
const unsigned int dbx::env::nomeminit = MDBX_NOMEMINIT;
const unsigned int dbx::env::coalesce = MDBX_COALESCE;
const unsigned int dbx::env::liforeclaim = MDBX_LIFORECLAIM;
const unsigned int dbx::env::pageperturb = MDBX_PAGEPERTURB;

dbx::mdbx_env::mdbx_env(::MDBX_env* const handle)
	: handle_(handle)
{
}

dbx::mdbx_env::~mdbx_env(void)
{
	try { close(); }
	catch (...) {}
}

void dbx::mdbx_env::open(const char* path, const unsigned int& flags,
	const unsigned int& mode)
{
	mdbx::env_open(handle_, path, flags, mode);
}

void dbx::mdbx_env::copy(const char* path, const unsigned int& flags)
{
	mdbx::env_copy(handle_, path, flags);
}

void dbx::mdbx_env::sync(const bool& force)
{
	mdbx::env_sync(handle_, force);
}

std::shared_ptr<dbx::stat> dbx::mdbx_env::stat(void) const
{
	::MDBX_stat stat;
	mdbx::env_stat(handle_, &stat, sizeof(stat));
	return std::make_shared<mdbx_stat>(stat.ms_psize, stat.ms_depth,
		stat.ms_branch_pages, stat.ms_leaf_pages, stat.ms_overflow_pages,
		stat.ms_entries);
}

std::shared_ptr<dbx::info> dbx::mdbx_env::info(void) const
{
	::MDBX_envinfo info;
	mdbx::env_info(handle_, &info, sizeof(info));
	return std::make_shared<mdbx_info>(info.mi_mapsize, info.mi_last_pgno,
		info.mi_recent_txnid, info.mi_maxreaders, info.mi_numreaders);
}

void dbx::mdbx_env::set_flags(const unsigned int& flags, const bool& onoff)
{
	mdbx::env_set_flags(handle_, flags, onoff);
}

unsigned int dbx::mdbx_env::flags(void) const
{
	unsigned int flags;
	mdbx::env_get_flags(handle_, &flags);
	return flags;
}

std::string dbx::mdbx_env::path(void) const
{
	const char* path;
	mdbx::env_get_path(handle_, &path);
	return path;
}

void dbx::mdbx_env::set_mapsize(const std::size_t& size)
{
	mdbx::env_set_mapsize(handle_, size);
}

void dbx::mdbx_env::set_max_readers(const unsigned int& count)
{
	mdbx::env_set_max_readers(handle_, count);
}

void dbx::mdbx_env::set_max_dbs(const unsigned int& count)
{
	mdbx::env_set_max_dbs(handle_, MDBX_dbi(count));
}

std::shared_ptr<dbx::txn> dbx::mdbx_env::begin(const unsigned int& flags)
{
	MDBX_txn* handle(nullptr);
	mdbx::txn_begin(handle_, nullptr, flags, &handle);
	return std::make_shared<mdbx_txn>(handle);
}

void dbx::mdbx_env::close(void)
{
	if (handle_ != nullptr)
		mdbx::env_close(handle_);
	handle_ = nullptr;
}

std::shared_ptr<dbx::env> dbx::env::create(const unsigned int& flags)
{
	MDBX_env* handle(nullptr);
	mdbx::env_create(&handle);
	if (flags) {
		try {
			mdbx::env_set_flags(handle, flags);
		}
		catch (const error&) {
			mdbx::env_close(handle);
			throw;
		}
	}
	return std::make_shared<mdbx_env>(handle);
}
