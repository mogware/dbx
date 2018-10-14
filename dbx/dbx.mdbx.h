#ifndef __DBX_MDBX__
#define __DBX_MDBX__

#include <string>

#include "mdbx.h"
#include "dbx.config.h"
#include "dbx.except.h"

namespace dbx
{
	struct mdbx
	{
		static DBX_INLINE void env_create(::MDBX_env** penv);
		static DBX_INLINE void env_open(::MDBX_env* env, const char* path,
			const unsigned int& flags, const mode_t& mode);
		static DBX_INLINE void env_copy(::MDBX_env* env, const char* path,
			const unsigned int& flags);
		static DBX_INLINE void env_stat(::MDBX_env* env, ::MDBX_stat* stat,
			const size_t& bytes);
		static DBX_INLINE void env_info(::MDBX_env* env, ::MDBX_envinfo* info,
			const size_t& bytes);
		static DBX_INLINE void env_sync(::MDBX_env* env, const bool& force);
		static DBX_INLINE void env_close(::MDBX_env* env);
		static DBX_INLINE void env_set_flags(::MDBX_env* env,
			const unsigned int& flags, const bool& onoff = true);
		static DBX_INLINE void env_get_flags(::MDBX_env* env,
			unsigned int* flags);
		static DBX_INLINE void env_get_path(::MDBX_env* env,
			const char** path);
		static DBX_INLINE void env_get_fd(::MDBX_env* env,
			::mdbx_filehandle_t* fd);
		static DBX_INLINE void env_set_mapsize(::MDBX_env* env,
			const std::size_t& size);
		static DBX_INLINE void env_set_max_readers(::MDBX_env* env,
			const unsigned int& count);
		static DBX_INLINE void env_get_max_readers(::MDBX_env* env,
			unsigned int* count);
		static DBX_INLINE void env_set_max_dbs(::MDBX_env* env,
			::MDBX_dbi count);
		static DBX_INLINE unsigned int env_get_max_keysize(::MDBX_env* env);
		static DBX_INLINE void env_set_userctx(::MDBX_env* env, void* ctx);
		static DBX_INLINE void* env_get_userctx(::MDBX_env* env);

		static DBX_INLINE void txn_begin(::MDBX_env* env, ::MDBX_txn* parent,
			const unsigned int& flags, ::MDBX_txn** txn);
		static DBX_INLINE ::MDBX_env* txn_env(::MDBX_txn* txn);
		static DBX_INLINE void txn_commit(::MDBX_txn* txn);
		static DBX_INLINE void txn_abort(::MDBX_txn* txn);
		static DBX_INLINE void txn_reset(::MDBX_txn* txn);
		static DBX_INLINE void txn_renew(::MDBX_txn* txn);

		static DBX_INLINE void dbi_open(::MDBX_txn* txn, const char* name,
			const unsigned int& flags, ::MDBX_dbi* dbi);
		static DBX_INLINE void dbi_open_ex(::MDBX_txn *txn, const char *name,
			const unsigned int& flags, ::MDBX_dbi* dbi,
			::MDBX_cmp_func *keycmp, ::MDBX_cmp_func *datacmp);
		static DBX_INLINE void dbi_stat(::MDBX_txn* txn, ::MDBX_dbi dbi,
			::MDBX_stat* stat, const std::size_t& bytes);
		static DBX_INLINE void dbi_flags(::MDBX_txn* txn, ::MDBX_dbi dbi,
			unsigned int* flags);
		static DBX_INLINE void dbi_close(::MDBX_env* env, ::MDBX_dbi dbi);
		static DBX_INLINE void dbi_drop(::MDBX_txn* txn, ::MDBX_dbi dbi,
			const bool& del);
		static DBX_INLINE bool dbi_get(::MDBX_txn* txn, ::MDBX_dbi dbi,
			const ::MDBX_val* key, ::MDBX_val* data);
		static DBX_INLINE bool dbi_put(::MDBX_txn* txn, ::MDBX_dbi dbi,
			const ::MDBX_val* key, ::MDBX_val* data, const unsigned int& flags);
		static DBX_INLINE bool dbi_del(::MDBX_txn* txn, ::MDBX_dbi dbi,
			const ::MDBX_val* key, const ::MDBX_val* data = nullptr);

		static DBX_INLINE void cursor_open(::MDBX_txn* txn, ::MDBX_dbi dbi, ::MDBX_cursor** cursor);
		static DBX_INLINE void cursor_close(::MDBX_cursor* cursor);
		static DBX_INLINE void cursor_renew(::MDBX_txn* txn, ::MDBX_cursor* cursor);
		static DBX_INLINE ::MDBX_txn* cursor_txn(::MDBX_cursor* cursor);
		static DBX_INLINE ::MDBX_dbi cursor_dbi(::MDBX_cursor* cursor);
		static DBX_INLINE bool cursor_get(::MDBX_cursor* cursor, ::MDBX_val* key, ::MDBX_val* data, ::MDBX_cursor_op op);
		static DBX_INLINE bool cursor_put(::MDBX_cursor* cursor, ::MDBX_val* key, ::MDBX_val* data, unsigned int flags);
		static DBX_INLINE bool cursor_del(::MDBX_cursor* cursor, unsigned int flags);
		static DBX_INLINE void cursor_count(::MDBX_cursor* cursor, std::size_t& count);
	};
}

#if defined(__MDB_INLINE__)
#include "dbx.mdbx.inl"
#endif

#endif

