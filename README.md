# Wrapper for the key-value storage engine MDBX 


## Usage

Example of writing a key/value pair to the storage engine

```c
std::shared_ptr<dbx::env> env = dbx::env::create();
env->set_mapsize(1UL * 1024UL * 1024UL * 1024UL); /* 1 GiB */
env->open("C:\\testdb", 0, 0664);
std::shared_ptr<dbx::txn> txn = env->begin();
unsigned int db = txn->open(nullptr);
std::shared_ptr<dbx::val> key = dbx::val::of("username", 9);
std::shared_ptr<dbx::val> val = dbx::val::of("jhacker", 8);
txn->put(db, key, val, 0);
txn->commit();
```

Example of reading all entries using a cursor

```c
std::shared_ptr<dbx::env> env = dbx::env::create();
env->open("C:\\testdb", 0, 0664);
std::shared_ptr<dbx::txn> txn = env->begin(dbx::env::rdonly);
unsigned int db = txn->open(nullptr);
std::shared_ptr<dbx::val> k = dbx::val::create();
std::shared_ptr<dbx::val> v = dbx::val::create();
std::shared_ptr<dbx::cur> cur = txn->cursor(db);
while (cur->get(k, v, dbx::cur::next)) {
	std::printf("key: '%s', value: '%s'\n", k->data(), v->data());
}
cur->close();
txn->abort();
```