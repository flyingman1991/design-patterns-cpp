/*
 * C++ Design Patterns: Decorator
 * Author: Jakub Vojvoda [github.com/JakubVojvoda]
 * 2016
 *
 * Source code is licensed under MIT License
 * (for more details see LICENSE)
 *
 */

#include <iostream>

/*
 * Component
 * defines an interface for objects that can have responsibilities
 * added to them dynamically
 */
class Component
{
public:
    virtual ~Component() {}

    virtual void operation() = 0;
    // ...
};

/*
 * Concrete Component
 * defines an object to which additional responsibilities
 * can be attached
 */
class ConcreteComponent : public Component
{
public:
    ~ConcreteComponent() {}

    void operation()
    {
        std::cout << "Concrete Component operation" << std::endl;
    }
    // ...
};

/*
 * Decorator
 * maintains a reference to a Component object and defines an interface
 * that conforms to Component's interface
 */
class Decorator : public Component
{
public:
    ~Decorator() {}

    Decorator( Component *c ) : component( c ) {}

    virtual void operation()
    {
        component->operation();
    }
    // ...

private:
    Component *component;
};

/*
 * Concrete Decorators
 * add responsibilities to the component (can extend the state
 * of the component)
 */
class ConcreteDecoratorA : public Decorator
{
public:
    ConcreteDecoratorA( Component *c ) : Decorator( c ) {}

    void operation()
    {
        Decorator::operation(); // call basic functions
        std::cout << "Decorator A" << std::endl; // call additional functions
    }
    // ...
};

class ConcreteDecoratorB : public Decorator
{
public:
    ConcreteDecoratorB( Component *c ) : Decorator( c ) {}

    void operation()
    {
        Decorator::operation(); // call basic functions
        std::cout << "Decorator B" << std::endl; // call additional functions
    }
    // ...
};


int main()
{
    // component calls operation
    Component *cc = new ConcreteComponent();
    if (nullptr != cc)
    {
        cc->operation();
    }

    // decorator calls operation
    Component *db = new ConcreteDecoratorB( cc );
    if (nullptr != db)
    {
        db->operation();
    }

    delete db;
    delete cc;

    return 0;
}
