#pragma once

#include "LeeEngine3/Core/Config.h"

#include <type_traits>

namespace lee{
namespace TypeTraits{

// --- IndexOf ---

template<typename T, unsigned S>
constexpr unsigned IndexOf(T t, T const* vs){
  return S == 0 ? -1
    : t == *vs ? 0
    : IndexOf<T, S == 0 ? 0 : S-1>(t, vs+1) == (unsigned) -1 ? -1
    : IndexOf<T, S == 0 ? 0 : S-1>(t, vs+1) + 1;
}

// --- Convertible ---

template<typename T>
struct Convertible{
  template<typename U>
  struct To{
    static constexpr bool value = std::is_convertible<U, T>::value;
  };
  template<typename U>
  struct From{
    static constexpr bool value = std::is_convertible<T, U>::value;
  };
};

// --- All ---

template<template <typename> class Pred, typename... Ts>
struct All{ };

template<template <typename> class Pred, typename Head, typename... Tail>
struct All<Pred, Head, Tail...>{
  static constexpr bool value = Pred<Head>::value && All<Pred, Tail...>::value;
};

template<template <typename> class Pred>
struct All<Pred>{
  static constexpr bool value = true;
};

}
}