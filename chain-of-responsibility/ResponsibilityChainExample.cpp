/*
 * @Author: yunfei li
 * @Date: 2021-11-27 09:58:59
 * @LastEditTime: 2021-11-27 10:17:35
 * @LastEditors: Please set LastEditors
 * @Description: eference link(http://c.biancheng.net/view/1383.html)
 * @FilePath: \undefinedf:\DesignPattern\design-patterns-cpp\chain-of-responsibility\ResponsibilityChainExample.cpp
 */
#include <iostream>

class Leader
{
public:
    void setSuccessor(Leader* leader)
    {
        m_pLeader = leader; // Maybe shallow copy is OK
    }

    Leader* getSuccessor()
    {
        return m_pLeader;
    }

    virtual void handlerRequest(int leaveDays); // Don't provide default implementation

private:
    Leader*    m_pLeader;
};

// Concreate Leader can not see m_pLeader,
// however it can operate it via setter/getter
class ClassAdviser : public Leader
{
public:
    void handlerRequest(int leaveDays) override
    {
        if (LeaveDays <= 2)
        {
            std::cout << "班主任批准您请假" + LeaveDays + "天。" << std::endl;
        }
        else
        {
            // in this case, request to next handler if not met conditions
            if (nullptr != getNext())
            {
                getNext().handleRequest(LeaveDays);
            }
            else
            {
                std::cout << "请假天数太多，没有人批准该假条！" << std::endl;
            }
        }
    }
};

class DepartmentHead  : public Leader
{
public:
    void handlerRequest(int leaveDays) override
    {
        if (LeaveDays <= 7)
        {
            std::cout << "系主任批准您请假" + LeaveDays + "天。" << std::endl;
        }
        else
        {
            if (nullptr != getNext())
            {
                getNext().handleRequest(LeaveDays);
            }
            else
            {
                std::cout << "请假天数太多，没有人批准该假条！" << std::endl;
            }
        }
    }
};

class Dean : public Leader
{
public:
    void handlerRequest(int leaveDays) override
    {
        if (LeaveDays <= 14)
        {
            std::cout << "院长批准您请假" + LeaveDays + "天。" << std::endl;
        }
        else
        {
            if (nullptr != getNext())
            {
                getNext().handleRequest(LeaveDays);
            }
            else
            {
                std::cout << "请假天数太多，没有人批准该假条！" << std::endl;
            }
        }
    }
};

class DeanOfStudies  : public Leader
{
public:
    void handlerRequest(int leaveDays) override
    {
        if (LeaveDays <= 14)
        {
            std::cout << "教务处长批准您请假" + LeaveDays + "天。" << std::endl;
        }
        else
        {
            if (nullptr != getNext())
            {
                getNext().handleRequest(LeaveDays);
            }
            else
            {
                std::cout << "请假天数太多，没有人批准该假条！" << std::endl;
            }
        }
    }
};


// this equals implementation of client class
int main()
{
    //组装责任链
    Leader* teacher1 = new ClassAdviser();
    Leader* teacher2 = new DepartmentHead();
    Leader* teacher3 = new Dean();
    //Leader teacher4=new DeanOfStudies(); // you can extend chains easily
    teacher1.setNext(teacher2);
    teacher2.setNext(teacher3);
    //teacher3.setNext(teacher4);

    //提交请求
    teacher1.handleRequest(8);
    return 0;
}

// result : 院长批准您请假8天