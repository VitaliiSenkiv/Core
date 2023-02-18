/** 
 * IsEqual type trait helps to determine, whether types are equal.
 * TIsEqual<A, B>::Value is true, if A and B are equal types and false if not
 */
#pragma region IsEqual

template<typename A, typename B>
struct TIsEqual
{
	static constexpr bool Value = false;
};

template<typename T>
struct TIsEqual<T, T>
{
	static constexpr bool Value = true;
};

#pragma endregion

/** 
 * EnableIf type trait contains Value, if type value is true, and doesn't in other case.
 * e.g. TEnableIf<TIsEqual<A, B>::Value>::Value will compile only, if A and B types are same
 */
#pragma region EnableIf

template<bool>
struct TEnableIf { };

template<>
struct TEnableIf<true> { enum { Value }; };

template<>
struct TEnableIf<false> { };

#pragma endregion

/**
 * IsChildOf type trait determines, whether one type is derived from another.
 * e.g. TIsChildOf<Base, Child>::IsChild equals to true if Child is Base or inherited from it, else IsChild = false
 */
#pragma region IsChildOf

template<typename Base, typename Child>
struct TIsChildOf
{
	/** Different sizes of types to compare sizes via sizeof in compile time*/
	using Yes = char[1];
	using No = char[2];

	/** Function to determine whether Child object is derived from Base*/
	static Yes& Check(const Base*);
	static No& Check(...);

	/** Returns pointer of child type */
	static Child* ChildTypePointer();

	static constexpr bool IsChild = (sizeof(Check(ChildTypePointer())) == sizeof(Yes));
};

#pragma endregion