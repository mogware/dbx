#ifndef __DBX_VAL__
#define __DBX_VAL__

#include <cstddef>
#include <memory>

namespace dbx
{
	struct val
	{
		virtual bool empty(void) const = 0;
		virtual std::size_t size(void) const = 0;
		virtual char* data(void) = 0;
		virtual const char* data(void) const = 0;
		virtual void assign(const void* data, const std::size_t& size) = 0;
		virtual ~val(void) {}

		static std::shared_ptr<val> create(void);
		static std::shared_ptr<val> of(const void* data,
			const std::size_t& size);
	};
}

#endif
