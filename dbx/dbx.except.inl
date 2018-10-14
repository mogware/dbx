DBX_INLINE int dbx::error::code() const
{
	return code_;
}

DBX_INLINE std::string dbx::error::origin() const
{
	return runtime_error::what();
}

DBX_INLINE dbx::runtime_error::runtime_error(const char* const origin, const int& rc)
	: error(origin, rc)
{
}

DBX_INLINE dbx::corrupted_error::corrupted_error(const char* const origin, const int& rc)
	: error(origin, rc)
{
}

DBX_INLINE dbx::panic_error::panic_error(const char* const origin, const int& rc)
	: error(origin, rc)
{
}

DBX_INLINE dbx::version_mismatch_error::version_mismatch_error(const char* const origin, const int& rc)
	: error(origin, rc)
{
}

DBX_INLINE dbx::map_full_error::map_full_error(const char* const origin, const int& rc)
	: error(origin, rc)
{
}

DBX_INLINE dbx::bad_dbi_error::bad_dbi_error(const char* const origin, const int& rc)
	: error(origin, rc)
{
}
