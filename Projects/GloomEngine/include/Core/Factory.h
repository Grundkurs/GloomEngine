#pragma once

#include <tuple>

namespace gloom
{

namespace FactoryDetail
{

template<class F, class Tuple, bool D, unsigned ...N>
struct ExpandNewImpl
{
template<class... Args>
static F* call(Tuple const& t, Args && ... args)
	{
	return ExpandNewImpl < F, Tuple, sizeof...(N) + 1 == std::tuple_size<Tuple>::value, N..., sizeof...(N) >::call(t, std::forward<Args>(args)...);
	}
};

template<class F, class Tuple, unsigned ...N>
struct ExpandNewImpl<F, Tuple, true, N...>
{
template<class... Args>
static F* call(Tuple const& t, Args && ... args)
	{
	(void) t; // Get rid of -Wunused-but-set-parameter
	return new F(std::forward<Args>(args)..., std::get<N>(t)...);
	}
};

template<class F, class Tuple, class ...Args>
F* ExpandNew(Tuple const& t, Args && ... args)
	{
	return ExpandNewImpl<F, Tuple, std::tuple_size<Tuple>::value == 0>::call(t, std::forward<Args>(args)...);
	}

}

template < class T,
		 class Impl,
		 class Ptr,
		 class TConsArgs = std::tuple<>,
		 class ...Args >
class FactoryImpl;

template<class T, class Ptr, class ...Args>
class Factory
{
public:
	template<class Impl, class ...ConsArgs>
	using Impl = FactoryImpl<T, Impl, Ptr, std::tuple<ConsArgs...>, Args...>;

	virtual Ptr create(Args && ... args) = 0;
};

template < class T,
		 class Impl,
		 class Ptr,
		 class TConsArgs,
		 class ...Args >
class FactoryImpl : public Factory<T, Ptr, Args...>
{
public:
	FactoryImpl(TConsArgs const& consArgs) :
		mConsArgs(consArgs) { }

	virtual Ptr create(Args && ... args)
		{
		Impl* impl = FactoryDetail::ExpandNew<Impl, TConsArgs, Args...>(mConsArgs, std::forward<Args>(args)...);
		return Ptr(impl);
		}

private:
	TConsArgs mConsArgs;
};

}
