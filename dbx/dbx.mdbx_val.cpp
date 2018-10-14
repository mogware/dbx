#include "dbx.mdbx_val.h"

#include <string>

dbx::mdbx_val::mdbx_val(const void* data, const std::size_t& size)
	: val_{ const_cast<void*>(data), size }
{
}

dbx::mdbx_val::~mdbx_val(void)
{
}

dbx::mdbx_val::operator MDBX_val*(void)
{
	return &val_;
}

dbx::mdbx_val::operator const MDBX_val*(void) const
{
	return &val_;
}

bool dbx::mdbx_val::empty(void) const
{
	return size() == 0;
}

std::size_t dbx::mdbx_val::size(void) const
{
	return val_.iov_len;
}

char* dbx::mdbx_val::data(void)
{
	return reinterpret_cast<char*>(val_.iov_base);
}

const char* dbx::mdbx_val::data(void) const
{
	return reinterpret_cast<char*>(val_.iov_base);
}

void dbx::mdbx_val::assign(const void* data, const std::size_t& size)
{
	val_.iov_len = size;
	val_.iov_base = const_cast<void*>(data);
}

std::shared_ptr<dbx::val> dbx::val::create(void)
{
	return std::make_shared<mdbx_val>(nullptr, 0);
}

std::shared_ptr<dbx::val> dbx::val::of(const void* data,
	const std::size_t& size)
{
	return std::make_shared<mdbx_val>(data, size);
}
