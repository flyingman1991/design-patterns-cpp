/*
 * C++ Design Patterns: Factory Method
 * Author: Yunfei Li [github.com/flyingman1991]
 * 2022
 *
 * Source code is licensed under MIT License
 * (for more details see LICENSE)
 */

#include <iostream>
#include <string>

/*
 * Product
 * products implement the same interface so that the classes can refer
 * to the interface not the concrete product
 */
class Product
{
public:
    virtual ~Product() {}
    virtual std::string getName() = 0;
    // ...
};

/*
 * Concrete Product B
 * define product to be created
 */
class ConcreteProductA : public Product
{
public:
    ~ConcreteProductA() {}
    std::string getName()
    {
        return "type A";
    }
    // ...
};

/*
 * Concrete Product B
 * define product to be created
 */
class ConcreteProductB : public Product
{
public:
    ~ConcreteProductB() {}

    std::string getName()
    {
        return "type B";
    }
    // ...
};

/*
 * Creator
 * the interface of all concrete creators
 */
class Creator
{
public:
    virtual ~Creator() {}
    virtual Product* createProduct() = 0;
    virtual void removeProduct( Product *product ) = 0;
    // ...
};

/*
 * Concrete Creator
 * implements factory method that is responsible for creating
 * concrete product A.
 * Product and factory are corresponding.
 */
class ConcreteCreatorA : public Creator
{
public:
    ~ConcreteCreatorA() {}

    // only create product A
    Product* createProduct()
    {
        return new ConcreteProductA();
    }

    void removeProduct(Product *product)
    {
        delete product;
    }
    // ...
};

/*
 * Concrete Creator
 * implements factory method that is responsible for creating
 * concrete product B.
 * Product and factory are corresponding.
 */
class ConcreteCreatorB : public Creator
{
public:
    ~ConcreteCreatorB() {}

    // only create product B
    Product* createProduct()
    {
        return new ConcreteProductB();
    }

    void removeProduct(Product *product)
    {
        delete product;
    }
    // ...
};


int main()
{
    Creator *creator = new ConcreteCreatorA();
    Product *p1 = creator->createProduct();
    std::cout << "Product: " << p1->getName() << std::endl;
    creator->removeProduct(p1);
    delete creator;

    creator = new ConcreteCreatorB();
    Product *p2 = creator->createProduct();
    std::cout << "Product: " << p2->getName() << std::endl;
    creator->removeProduct(p2);
    delete creator;

    return 0;
}
