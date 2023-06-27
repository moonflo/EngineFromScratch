#pragma once
#include "Interface.hpp"

namespace My {

/*
 * WHY WE CALL THIS RUNTIMEMODULE AND WHAT IS A RUNTIME CLASS:
 *
 * C++ is a statically typed language, which features type checking at compile
 * time. However,in C++ there is also run-time type information (RTTI), which
 * can be accessed through the typeid operator and the dynamic_cast operator.
 *
 * Classes in the C++ runtime have the following characteristics:
 * 1. Virtual Functions: A virtual function in C++ is a mechanism that allows
 * the actual type of an object to be determined at runtime. The virtual
 * function enables the subclass derived from the base class to override the
 * virtual function of the same name in the parent class and call the
 * appropriate subclass function at runtime.
 *
 * 2. Polymorphism: Polymorphism means that functions or operators with the same
 * name perform different operations in different situations. Polymorphism in
 * C++ is achieved through virtual functions.Because of virtual functions,
 * derived classes of the same parent class can have different execution
 * functions and effects for the same function, which allows C++ to not care
 * what specific functions are executed at compile time, but at run time
 * according to the called class. There are different implementations of the
 * same function.
 *
 * 3. RTTI: C++ provides the typeid operator to obtain the actual type
 * information of an object, and the dynamic_cast operator to perform safe type
 * conversions.
 */
Interface IRuntimeModule {
   public:
    virtual ~IRuntimeModule(){};

    virtual int Initialize() = 0;  // For initialize module
    virtual void Finalize() = 0;   // For clear module

    virtual void Tick() = 0;  // Tick
};
}  // namespace My