#include "dbx.mdbx_cur.h"
#include "dbx.mdbx_val.h"
#include "dbx.mdbx_txn.h"
#include "dbx.mdbx.h"

const unsigned int dbx::cur::first = MDBX_FIRST;
const unsigned int dbx::cur::first_dup = MDBX_FIRST_DUP;
const unsigned int dbx::cur::get_both = MDBX_GET_BOTH;
const unsigned int dbx::cur::get_both_range = MDBX_GET_BOTH_RANGE;
const unsigned int dbx::cur::get_current = MDBX_GET_CURRENT;
const unsigned int dbx::cur::get_multiple = MDBX_GET_MULTIPLE;
const unsigned int dbx::cur::last = MDBX_LAST;
const unsigned int dbx::cur::last_dup = MDBX_LAST_DUP;
const unsigned int dbx::cur::next = MDBX_NEXT;
const unsigned int dbx::cur::next_dup = MDBX_NEXT_DUP;
const unsigned int dbx::cur::next_multiple = MDBX_NEXT_MULTIPLE;
const unsigned int dbx::cur::next_nodup = MDBX_NEXT_NODUP;
const unsigned int dbx::cur::prev = MDBX_PREV;
const unsigned int dbx::cur::prev_dup = MDBX_PREV_DUP;
const unsigned int dbx::cur::prev_nodup = MDBX_PREV_NODUP;
const unsigned int dbx::cur::set = MDBX_SET;
const unsigned int dbx::cur::set_key = MDBX_SET_KEY;
const unsigned int dbx::cur::set_range = MDBX_SET_RANGE;
const unsigned int dbx::cur::prev_multiple = MDBX_PREV_MULTIPLE;


dbx::mdbx_cur::mdbx_cur(::MDBX_cursor* const handle)
	: handle_(handle)
{
}

dbx::mdbx_cur::~mdbx_cur(void)
{
	try { close(); }
	catch (...) {}
}

std::shared_ptr<dbx::txn> dbx::mdbx_cur::txn(void) const
{
	return std::make_shared<mdbx_txn>(mdbx::cursor_txn(handle_));
}

unsigned int dbx::mdbx_cur::dbi(void) const
{
	return mdbx::cursor_dbi(handle_);
}

bool dbx::mdbx_cur::get(std::shared_ptr<dbx::val>& key,
	std::shared_ptr<dbx::val>& data, const unsigned int& op)
{
	return mdbx::cursor_get(handle_, 
		*reinterpret_cast<mdbx_val*>(key.get()),
		*reinterpret_cast<mdbx_val*>(data.get()),
		MDBX_cursor_op(op));
}

bool dbx::mdbx_cur::put(const std::shared_ptr<dbx::val>& key,
	std::shared_ptr<dbx::val>& data, const unsigned int& flags)
{
	return mdbx::cursor_put(handle_,
		*reinterpret_cast<mdbx_val*>(key.get()),
		*reinterpret_cast<mdbx_val*>(data.get()), flags);
}

bool dbx::mdbx_cur::del(const unsigned int& flags)
{
	return mdbx::cursor_del(handle_, flags);
}

std::size_t dbx::mdbx_cur::count(void) const
{
	std::size_t size;
	mdbx::cursor_count(handle_, size);
	return size;
}

void dbx::mdbx_cur::close(void)
{
	if (handle_ != nullptr)
		mdbx::cursor_close(handle_);
	handle_ = nullptr;
}