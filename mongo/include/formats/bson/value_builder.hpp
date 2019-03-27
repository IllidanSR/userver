#pragma once

/// @file formats/bson/value_builder.hpp
/// @brief @copybrief formats::bson::ValueBuilder

#include <chrono>
#include <cstddef>
#include <cstdint>
#include <string>

#include <formats/bson/iterator.hpp>
#include <formats/bson/types.hpp>
#include <formats/bson/value.hpp>
#include <formats/common/type.hpp>

namespace formats::bson {

/// BSON value builder
class ValueBuilder {
 public:
  using iterator = Iterator<ValueBuilder>;
  using Type = formats::common::Type;

  /// Constructs a `null` value (may be used as either document or array)
  ValueBuilder();

  /// Constructs a value with the predefined type
  explicit ValueBuilder(Type);

  /// @cond
  /// Constructor from implementation, internal use only
  explicit ValueBuilder(impl::ValueImplPtr);
  /// @endcond

  ValueBuilder(const ValueBuilder& other);
  ValueBuilder(ValueBuilder&& other);
  ValueBuilder& operator=(const ValueBuilder& other);
  ValueBuilder& operator=(ValueBuilder&& other);

  /// @{
  /// Efficiently constructs a copy of an existing value
  ValueBuilder(const Value&);
  ValueBuilder(Value&&);
  /// @}

  /// @name Concrete type constructors
  /// @{
  /* implicit */ ValueBuilder(std::nullptr_t);
  /* implicit */ ValueBuilder(bool);
  /* implicit */ ValueBuilder(int32_t);
  /* implicit */ ValueBuilder(uint32_t);
  /* implicit */ ValueBuilder(int64_t);
  /* implicit */ ValueBuilder(uint64_t);
  /* implicit */ ValueBuilder(double);
  /* implicit */ ValueBuilder(const char*);
  /* implicit */ ValueBuilder(std::string);
  /* implicit */ ValueBuilder(const std::chrono::system_clock::time_point&);
  /* implicit */ ValueBuilder(const Oid&);
  /* implicit */ ValueBuilder(Binary);
  /* implicit */ ValueBuilder(const Decimal128&);
  /* implicit */ ValueBuilder(MinKey);
  /* implicit */ ValueBuilder(MaxKey);
#ifdef _LIBCPP_VERSION
  /* implicit */ ValueBuilder(long);
  /* implicit */ ValueBuilder(unsigned long);
#else
  /* implicit */ ValueBuilder(long long);
  /* implicit */ ValueBuilder(unsigned long long);
#endif
  /// @}

  /// @brief Retrieves or creates document field by name
  /// @throws TypeMismatchException if value is not a document or `null`
  ValueBuilder operator[](const std::string& name);

  /// @brief Retrieves array element by index
  /// @throws TypeMismatchException if value is not an array or `null`
  /// @throws OutOfBoundsException if index is invalid for the array
  ValueBuilder operator[](uint32_t index);

  /// @brief Returns an iterator to the first array element/document field
  /// @throws TypeMismatchException if value is not a document, array or `null`
  iterator begin();

  /// @brief Returns an iterator following the last array element/document field
  /// @throws TypeMismatchException if value is not a document, array or `null`
  iterator end();

  /// @brief Returns the number of elements in a document/array
  /// @throws TypeMismatchException if value is not a document, array or `null`
  /// @note Returns 0 for `null`.
  uint32_t GetSize() const;

  /// @brief Creates or resizes the array
  /// @param size new size
  /// @throws TypeMismatchException if value is not an array or `null`
  void Resize(uint32_t size);

  /// @brief Appends an element to the array, possibly creating one
  /// @param elem element to append
  /// @throws TypeMismatchException if value is not an array or `null`
  void PushBack(ValueBuilder&& elem);

  /// @brief Retrieves a compiled value from the builder.
  /// After calling this method the builder is in unspecified state.
  Value ExtractValue();

 private:
  void Assign(const impl::ValueImplPtr&);
  void Assign(impl::ValueImplPtr&&);

  impl::ValueImplPtr impl_;
};

}  // namespace formats::bson
