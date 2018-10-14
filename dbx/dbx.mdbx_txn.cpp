#include "dbx.mdbx_txn.h"
#include "dbx.mdbx_val.h"
#include "dbx.mdbx_cur.h"
#include "dbx.mdbx.h"

const unsigned int dbx::txn::reversekey = MDBX_REVERSEKEY;
const unsigned int dbx::txn::dupsort = MDBX_DUPSORT;
const unsigned int dbx::txn::integerkey = MDBX_INTEGERKEY;
const unsigned int dbx::txn::dupfixed = MDBX_DUPFIXED;
const unsigned int dbx::txn::integerdup = MDBX_INTEGERDUP;
const unsigned int dbx::txn::reversedup = MDBX_REVERSEDUP;
const unsigned int dbx::txn::create = MDBX_CREATE;

const unsigned int dbx::txn::trytxn = MDBX_TRYTXN;

const unsigned int dbx::txn::nooverwrite = MDBX_NOOVERWRITE;
const unsigned int dbx::txn::nodupdata = MDBX_NODUPDATA;
const unsigned int dbx::txn::current = MDBX_CURRENT;
const unsigned int dbx::txn::reserve = MDBX_RESERVE;
const unsigned int dbx::txn::append = MDBX_APPEND;
const unsigned int dbx::txn::appenddup = MDBX_APPENDDUP;
const unsigned int dbx::txn::multiple = MDBX_MULTIPLE;

dbx::mdbx_txn::mdbx_txn(::MDBX_txn* const handle)
	: handle_(handle)
{
}

dbx::mdbx_txn::~mdbx_txn(void)
{
	try { abort(); }
	catch (...) {}
}

void dbx::mdbx_txn::commit(void)
{
	if (handle_ != nullptr)
		mdbx::txn_commit(handle_);
	handle_ = nullptr;
}

void dbx::mdbx_txn::abort(void)
{
	if (handle_ != nullptr)
		mdbx::txn_abort(handle_);
	handle_ = nullptr;
}

void dbx::mdbx_txn::reset(void)
{
	mdbx::txn_reset(handle_);
}

void dbx::mdbx_txn::renew(void)
{
	mdbx::txn_renew(handle_);
}

unsigned int dbx::mdbx_txn::open(const char* name,
	const unsigned int& flags) const
{
	::MDBX_dbi handle;
	mdbx::dbi_open(handle_, name, flags, &handle);
	return handle;
}

void dbx::mdbx_txn::drop(const unsigned int& db, const bool& del)
{
	mdbx::dbi_drop(handle_, MDBX_dbi(db), del);
}

unsigned int dbx::mdbx_txn::flags(const unsigned int& db) const
{
	unsigned int result;
	mdbx::dbi_flags(handle_, MDBX_dbi(db), &result);
	return result;
}

std::uint64_t dbx::mdbx_txn::size(const unsigned int& db) const
{
	MDBX_stat result;
	mdbx::dbi_stat(handle_, MDBX_dbi(db), &result, sizeof(result));
	return result.ms_entries;
}

bool dbx::mdbx_txn::get(const unsigned int& db,
	const std::shared_ptr<val>& key, std::shared_ptr<val>& data)
{
	return mdbx::dbi_get(handle_, MDBX_dbi(db),
		*reinterpret_cast<const mdbx_val*>(key.get()),
		*reinterpret_cast<mdbx_val*>(data.get()));
}

bool dbx::mdbx_txn::put(const unsigned int& db,
	const std::shared_ptr<val>& key,
	std::shared_ptr<val>& data, const unsigned int& flags)
{
	return mdbx::dbi_put(handle_, MDBX_dbi(db),
		*reinterpret_cast<const mdbx_val*>(key.get()),
		*reinterpret_cast<mdbx_val*>(data.get()), flags);
}

bool dbx::mdbx_txn::del(const unsigned int& db,
	const std::shared_ptr<val>& key)
{
	return mdbx::dbi_del(handle_, MDBX_dbi(db),
		*reinterpret_cast<const mdbx_val*>(key.get()));
}

std::shared_ptr<dbx::cur> dbx::mdbx_txn::cursor(const unsigned int& db) const
{
	::MDBX_cursor* handle;
	mdbx::cursor_open(handle_, MDBX_dbi(db), &handle);
	return std::make_shared<mdbx_cur>(handle);
}