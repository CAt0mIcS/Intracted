#pragma once

#include <memory>
#include <type_traits>

namespace Intracted
{
	template<typename T>
	using Scope = std::unique_ptr<T>;

	template<typename T, typename... Args>
	inline constexpr Scope<T> MakeScope(Args&&... val)
	{
		return std::make_unique<T>(std::forward<Args>(val)...);
	}

	template<typename T>
	using Ref = std::shared_ptr<T>;

	template<typename T, typename... Args>
	inline constexpr Ref<T> MakeRef(Args&&... val)
	{
		return std::make_shared<T>(std::forward<Args>(val)...);
	}
}  // namespace Intracted