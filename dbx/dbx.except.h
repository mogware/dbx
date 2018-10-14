#ifndef __DBX_EXCEPT__
#define __DBX_EXCEPT__

#include <stdexcept>
#include <string>

#include "dbx.config.h"

namespace dbx
{
	class error : public std::runtime_error
	{
	protected:
		const int code_;
	public:
		static void raise(const char* origin, const int& rc);
	public:
		error(const char* const origin, const int& rc);
	public:
		DBX_INLINE int code() const;
		DBX_INLINE std::string origin() const;
	public:
		const char* what() const;
	};

	class runtime_error : public error
	{
	public:
		DBX_INLINE runtime_error(const char* const origin, const int& rc);
	};

	class corrupted_error : public error
	{
	public:
		DBX_INLINE corrupted_error(const char* const origin, const int& rc);
	};

	class panic_error : public error
	{
	public:
		DBX_INLINE panic_error(const char* const origin, const int& rc);
	};
	
	class version_mismatch_error : public error
	{
	public:
		DBX_INLINE version_mismatch_error(const char* const origin, const int& rc);
	};

	class map_full_error : public error
	{
	public:
		DBX_INLINE map_full_error(const char* const origin, const int& rc);
	};

	class bad_dbi_error : public error
	{
	public:
		DBX_INLINE bad_dbi_error(const char* const origin, const int& rc);
	};
}

#endif