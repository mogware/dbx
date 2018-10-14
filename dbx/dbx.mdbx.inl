DBX_INLINE void dbx::mdbx::env_create(::MDBX_env** penv)
{
	const int rc = ::mdbx_env_create(penv);
	if (rc != MDBX_SUCCESS)
		error::raise("mdbx_env_create", rc);
}

DBX_INLINE void dbx::mdbx::env_open(::MDBX_env* env, const char* path,
	const unsigned int& flags, const mode_t& mode)
{
	const int rc = ::mdbx_env_open(env, path, flags, mode);
	if (rc != MDBX_SUCCESS)
		error::raise("mdbx_env_open", rc);
}

DBX_INLINE void dbx::mdbx::env_copy(::MDBX_env* env, const char* path,
	const unsigned int& flags)
{
	const int rc = ::mdbx_env_copy(env, path, flags);
	if (rc != MDBX_SUCCESS)
		error::raise("mdbx_env_copy", rc);
}

DBX_INLINE void dbx::mdbx::env_stat(::MDBX_env* env, ::MDBX_stat* stat,
	const size_t& bytes)
{
	const int rc = ::mdbx_env_stat(env, stat, bytes);
	if (rc != MDBX_SUCCESS)
		error::raise("mdbx_env_stat", rc);
}

DBX_INLINE void dbx::mdbx::env_info(::MDBX_env* env, ::MDBX_envinfo* stat,
	const size_t& bytes)
{
	const int rc = ::mdbx_env_info(env, stat, bytes);
	if (rc != MDBX_SUCCESS)
		error::raise("mdbx_env_info", rc);
}

DBX_INLINE void dbx::mdbx::env_sync(::MDBX_env* env, const bool& force)
{
	const int rc = ::mdbx_env_sync(env, force);
	if (rc != MDBX_SUCCESS)
		error::raise("mdbx_env_sync", rc);
}

DBX_INLINE void dbx::mdbx::env_close(::MDBX_env* env)
{
	::mdbx_env_close(env);
}

DBX_INLINE void dbx::mdbx::env_set_flags(::MDBX_env* env,
	const unsigned int& flags, const bool& onoff)
{
	const int rc = ::mdbx_env_set_flags(env, flags, onoff ? 1 : 0);
	if (rc != MDBX_SUCCESS)
		error::raise("mdbx_env_set_flags", rc);
}

DBX_INLINE void dbx::mdbx::env_get_flags(::MDBX_env* env, unsigned int* flags)
{
	const int rc = ::mdbx_env_get_flags(env, flags);
	if (rc != MDBX_SUCCESS)
		error::raise("mdbx_env_get_flags", rc);
}

DBX_INLINE void dbx::mdbx::env_get_path(::MDBX_env* env, const char** path)
{
	const int rc = ::mdbx_env_get_path(env, path);
	if (rc != MDBX_SUCCESS)
		error::raise("mdbx_env_get_path", rc);
}

DBX_INLINE void dbx::mdbx::env_get_fd(::MDBX_env* env, ::mdbx_filehandle_t* fd)
{
	const int rc = ::mdbx_env_get_fd(env, fd);
	if (rc != MDBX_SUCCESS)
		error::raise("mdbx_env_get_fd", rc);
}

DBX_INLINE void dbx::mdbx::env_set_mapsize(::MDBX_env* env,
	const std::size_t& size)
{
	const int rc = ::mdbx_env_set_mapsize(env, size);
	if (rc != MDBX_SUCCESS)
		error::raise("mdbx_env_set_mapsize", rc);
}

DBX_INLINE void dbx::mdbx::env_set_max_readers(::MDBX_env* env,
	const unsigned int& count)
{
	const int rc = ::mdbx_env_set_maxreaders(env, count);
	if (rc != MDBX_SUCCESS)
		error::raise("mdbx_env_set_maxreaders", rc);
}

DBX_INLINE void dbx::mdbx::env_get_max_readers(::MDBX_env* env,
	unsigned int* count)
{
	const int rc = ::mdbx_env_get_maxreaders(env, count);
	if (rc != MDBX_SUCCESS)
		error::raise("mdbx_env_get_maxreaders", rc);
}

DBX_INLINE void dbx::mdbx::env_set_max_dbs(::MDBX_env* env, ::MDBX_dbi count)
{
	const int rc = ::mdbx_env_set_maxdbs(env, count);
	if (rc != MDBX_SUCCESS)
		error::raise("mdbx_env_set_maxdbs", rc);
}

DBX_INLINE unsigned int dbx::mdbx::env_get_max_keysize(::MDBX_env* env)
{
	const int rc = ::mdbx_env_get_maxkeysize(env);
	return static_cast<unsigned int>(rc);
}

DBX_INLINE void dbx::mdbx::env_set_userctx(::MDBX_env* env, void* ctx)
{
	const int rc = ::mdbx_env_set_userctx(env, ctx);
	if (rc != MDBX_SUCCESS)
		error::raise("mdbx_env_set_userctx", rc);
}

DBX_INLINE void* dbx::mdbx::env_get_userctx(::MDBX_env* env)
{
	return ::mdbx_env_get_userctx(env);
}

DBX_INLINE void dbx::mdbx::txn_begin(::MDBX_env* const env,
	::MDBX_txn* const parent, const unsigned int& flags, ::MDBX_txn** txn)
{
	const int rc = ::mdbx_txn_begin(env, parent, flags, txn);
	if (rc != MDBX_SUCCESS)
		error::raise("mdbx_txn_begin", rc);
}

DBX_INLINE ::MDBX_env* dbx::mdbx::txn_env(::MDBX_txn* const txn)
{
	return ::mdbx_txn_env(txn);
}

DBX_INLINE void dbx::mdbx::txn_commit(::MDBX_txn* const txn)
{
	const int rc = ::mdbx_txn_commit(txn);
	if (rc != MDBX_SUCCESS)
		error::raise("mdbx_txn_commit", rc);
}

DBX_INLINE void dbx::mdbx::txn_abort(::MDBX_txn* const txn)
{
	::mdbx_txn_abort(txn);
}

DBX_INLINE void dbx::mdbx::txn_reset(::MDBX_txn* const txn)
{
	::mdbx_txn_reset(txn);
}

DBX_INLINE void dbx::mdbx::txn_renew(::MDBX_txn* const txn)
{
	const int rc = ::mdbx_txn_renew(txn);
	if (rc != MDBX_SUCCESS)
		error::raise("mdbx_txn_renew", rc);
}

DBX_INLINE void dbx::mdbx::dbi_open(::MDBX_txn* txn, const char* name,
	const unsigned int& flags, ::MDBX_dbi* dbi)
{
	const int rc = ::mdbx_dbi_open(txn, name, flags, dbi);
	if (rc != MDBX_SUCCESS)
		error::raise("mdbx_dbi_open", rc);
}

DBX_INLINE void dbx::mdbx::dbi_open_ex(::MDBX_txn *txn, const char *name,
	const unsigned int& flags, ::MDBX_dbi* dbi,
	::MDBX_cmp_func *keycmp, ::MDBX_cmp_func *datacmp)
{
	const int rc = ::mdbx_dbi_open_ex(txn, name, flags, dbi, keycmp, datacmp);
	if (rc != MDBX_SUCCESS)
		error::raise("mdbx_dbi_open_ex", rc);
}

DBX_INLINE void dbx::mdbx::dbi_stat(::MDBX_txn* txn,
	::MDBX_dbi dbi, ::MDBX_stat* stat, const std::size_t& bytes)
{
	const int rc = ::mdbx_dbi_stat(txn, dbi, stat, bytes);
	if (rc != MDBX_SUCCESS)
		error::raise("mdbx_stat", rc);
}

DBX_INLINE void dbx::mdbx::dbi_flags(::MDBX_txn* txn,
	::MDBX_dbi dbi, unsigned int* flags)
{
	const int rc = ::mdbx_dbi_flags(txn, dbi, flags);
	if (rc != MDBX_SUCCESS)
		error::raise("mdbx_dbi_flags", rc);
}

DBX_INLINE void dbx::mdbx::dbi_close(::MDBX_env* env, ::MDBX_dbi dbi)
{
	::mdbx_dbi_close(env, dbi);
}

DBX_INLINE void dbx::mdbx::dbi_drop(::MDBX_txn* txn,
	::MDBX_dbi dbi, const bool& del)
{
	const int rc = ::mdbx_drop(txn, dbi, del ? 1 : 0);
	if (rc != MDBX_SUCCESS)
		error::raise("mdbx_drop", rc);
}

DBX_INLINE bool dbx::mdbx::dbi_get(::MDBX_txn* txn, ::MDBX_dbi dbi,
	const ::MDBX_val* key, ::MDBX_val* data)
{
	const int rc = ::mdbx_get(txn, dbi, const_cast<::MDBX_val*>(key), data);
	if (rc != MDBX_SUCCESS && rc != MDBX_NOTFOUND)
		error::raise("mdbx_get", rc);
	return rc == MDBX_SUCCESS;
}

DBX_INLINE bool dbx::mdbx::dbi_put(::MDBX_txn* txn, ::MDBX_dbi dbi,
	const ::MDBX_val* key, ::MDBX_val* data, const unsigned int& flags)
{
	const int rc = ::mdbx_put(txn, dbi,
		const_cast<::MDBX_val*>(key), data, flags);
	if (rc != MDBX_SUCCESS && rc != MDBX_KEYEXIST)
		error::raise("mdbx_put", rc);
	return rc == MDBX_SUCCESS;
}

DBX_INLINE bool dbx::mdbx::dbi_del(::MDBX_txn* txn, ::MDBX_dbi dbi, const ::MDBX_val* key, const ::MDBX_val* data)
{
	const int rc = ::mdbx_del(txn, dbi,
		const_cast<MDBX_val*>(key), const_cast<MDBX_val*>(data));
	if (rc != MDBX_SUCCESS && rc != MDBX_NOTFOUND)
		error::raise("mdbx_del", rc);
	return rc == MDBX_SUCCESS;
}

DBX_INLINE void dbx::mdbx::cursor_open(::MDBX_txn* txn, ::MDBX_dbi dbi, ::MDBX_cursor** cursor)
{
	const int rc = ::mdbx_cursor_open(txn, dbi, cursor);
	if (rc != MDBX_SUCCESS)
		error::raise("mdbx_cursor_open", rc);
}

DBX_INLINE void dbx::mdbx::cursor_close(::MDBX_cursor* cursor)
{
	::mdbx_cursor_close(cursor);
}

DBX_INLINE void dbx::mdbx::cursor_renew(::MDBX_txn* txn, ::MDBX_cursor* cursor)
{
	const int rc = ::mdbx_cursor_renew(txn, cursor);
	if (rc != MDBX_SUCCESS)
		error::raise("mdbx_cursor_renew", rc);
}

DBX_INLINE::MDBX_txn* dbx::mdbx::cursor_txn(::MDBX_cursor* cursor)
{
	return ::mdbx_cursor_txn(cursor);
}

DBX_INLINE::MDBX_dbi dbx::mdbx::cursor_dbi(::MDBX_cursor* cursor)
{
	return ::mdbx_cursor_dbi(cursor);
}

DBX_INLINE bool dbx::mdbx::cursor_get(::MDBX_cursor* cursor, ::MDBX_val* key, ::MDBX_val* data, ::MDBX_cursor_op op)
{
	const int rc = ::mdbx_cursor_get(cursor, key, data, op);
	if (rc != MDBX_SUCCESS && rc != MDBX_NOTFOUND)
		error::raise("mdbx_cursor_get", rc);
	return rc == MDBX_SUCCESS;

}

DBX_INLINE bool dbx::mdbx::cursor_put(::MDBX_cursor* cursor, ::MDBX_val* key, ::MDBX_val* data, unsigned int flags)
{
	const int rc = ::mdbx_cursor_put(cursor, key, data, flags);
	if (rc != MDBX_SUCCESS)
	if (rc != MDBX_SUCCESS && rc != MDBX_KEYEXIST)
		error::raise("mdbx_cursor_put", rc);
	return rc == MDBX_SUCCESS;
}

DBX_INLINE bool dbx::mdbx::cursor_del(::MDBX_cursor* cursor, unsigned int flags)
{
	const int rc = ::mdbx_cursor_del(cursor, flags);
	if (rc != MDBX_SUCCESS && rc != MDBX_NOTFOUND)
		error::raise("mdbx_cursor_del", rc);
	return rc == MDBX_SUCCESS;
}

DBX_INLINE void dbx::mdbx::cursor_count(::MDBX_cursor* cursor, std::size_t& count)
{
	const int rc = ::mdbx_cursor_count(cursor, &count);
	if (rc != MDBX_SUCCESS)
		error::raise("mdbx_cursor_count", rc);
}
