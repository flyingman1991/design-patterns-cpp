/*
 * C++ Design Patterns: Facade
 * Author: Jakub Vojvoda [github.com/JakubVojvoda]
 * 2016
 *
 * Source code is licensed under MIT License
 * (for more details see LICENSE)
 *
 */

#include <iostream>

/*
 * Subsystems
 * implement more complex subsystem functionality
 * and have no knowledge of the facade
 */
class SubsystemA
{
public:
    void subOperation()
    {
        std::cout << "Subsystem A method" << std::endl;
        // ...
    }
    // ...
};

class SubsystemB
{
public:
    void subOperation()
    {
        std::cout << "Subsystem B method" << std::endl;
        // ...
    }
    // ...
};

class SubsystemC
{
public:
    void subOperation()
    {
        std::cout << "Subsystem C method" << std::endl;
        // ...
    }
    // ...
};

/*
 * Facade
 * delegates client requests to appropriate subsystem object
 * and unified interface that is easier to use
 */
class Facade
{
public:
    Facade() : subsystemA(), subsystemB(), subsystemC() {}

    void operation_1()
    {
        subsystemA->subOperation();
        subsystemB->subOperation();
        // ...
    }

    void operation_2()
    {
        subsystemC->subOperation();
        // ...
    }
    // ...

private:
    SubsystemA *subsystemA;
    SubsystemB *subsystemB;
    SubsystemC *subsystemC;
    // ...
};


int main()
{
    Facade *facade = new Facade();

    facade->operation_1();
    facade->operation_2();
    delete facade;

    return 0;
}
