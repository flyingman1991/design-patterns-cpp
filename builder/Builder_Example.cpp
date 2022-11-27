/*
 * @Author: Harry
 * @Date: 2021-11-20 07:47:45
 * @LastEditTime: 2021-11-20 14:00:26
 * @LastEditors: Please set LastEditors
 * @Description: Another C++ example for builter pattern
 * @FilePath: \undefinedf:\DesignPattern\design-patterns-cpp\builder\Builder_Example.cpp
 */

#include <string>

class Computer
{
public:
    //The required parameters are injected via constructor
    Computer(std::string &cpu, std::string$ ram)
    {
    }

    //optional parameters are injected by setter#
    void setMouse(std::string mouse)
    {
        m_mouse = mouse;
    }

    void setKeyBoard(std::string keyBoard)
    {
        m_keyBoard = keyBoard;
    }

    void setDisplay(std::string display)
    {
        m_display = display;
    }

    //show that the computer has been built
    std::string describe()
    {
        std::cout << "My computer device :" << std::endl
                  << "CPU is " << m_cpu << std::endl
                  << "Ram is " << m_ram << std::endl
                  << "Mouse is " << m_mouse << std::endl
                  << "Keyboard is " << m_keyBoard << std::endl
                  << "Display is " << m_display << std::endl;
    }

private:
    std::string m_cpu;
    std::string m_ram;
    std::string m_mouse;
    std::string m_keyBoard;
    std::string m_display;
}

class ComputerBuilder
{
public:
    //define
    virtual void setMouse() = 0;
    virtual void setKeyboard() = 0;
    virtual void setDisplay() = 0;
    Computer getComputer() const
    {
        return m_Computer;
    }

protected:
    Computer m_Computer; //use protected member for derived class
}


class MacComputerBuilder : public ComputerBuilder
{
public:
    //The necessary properties use construction injection
    MacComputerBuilder( std::string cpu
                      , std::string ram)
        : m_Computer(cpu, ram)
    {}

    //implementation for interface
    void setMouse()
    {
        m_Computer.setMouse("Mac mouse");
    }

    void setKeyboard()
    {
        m_Computer.setKeyboard("Mac keyboard");
    }

    void setDisplay()
    {
        m_Computer.setKeyboard("Mac display");
    }
}


class WinComputerBuilder : public ComputerBuilder
{
public:
    //The necessary properties use construction injection
    WinComputerBuilder( std::string cpu
                      , std::string ram)
        : m_Computer(cpu, ram)
    {}

    //implementation for interface
    void setMouse()
    {
        m_Computer.setMouse("Windows mouse");
    }

    void setKeyboard()
    {
        m_Computer.setKeyboard("Windows keyboard");
    }

    void setDisplay()
    {
        m_Computer.setDisplay("Windows display");
    }
}

class Director
{
public:
    Director(Builder* pBuilder)
        : m_BuilderPtr(pBuilder)
    {}

    void setBuilder(Builder* pBuilder)
    {
        m_BuilderPtr = pBuilder;
    }

    // THere can be several make-up operation
    Computer makeComputer()
    {
        if (!m_BuilderPtr)
        {
            m_BuilderPtr->setMouse();
            m_BuilderPtr->setKeyboard();
            m_BuilderPtr->setDisplay();
            return m_BuilderPtr->getComputer();
        }
        else
        {
            return Computer();
        }
    }

private:
    Builder*    m_BuilderPtr;
}

int main()
{
    // main usage process
    ComputerBuilder* builder_1 = new MacComputerBuilder("I5_CPU", "samsung_123");
    Director* director = new Director(builder_1);
    Computer product_1 = director->makeComputer();
    product_1.describe();

    ComputerBuilder* builder_2 = new MacComputerBuilder("I7_CPU", "kingston_256");
    director->setBuilder(builder);
    Computer product_2 = director->makeComputer();
    product_2.describe();

    // the last but not least
    if (!builder_1)
    {
        delete builder_1;
        builder_1 = nullptr;
    }
    if (!builder_2)
    {
        delete builder_2;
        builder_2 = nullptr;
    }
    if (!director)
    {
        delete director;
        director = nullptr;
    }

    return 0;
}