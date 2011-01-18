#include "minipascal_node.h"

#include <stdio.h>
#include <iostream>
#include "minipascal_visitor.h"

void minipascal::Node::accept(minipascal::Visitor* visitor)
{
        return visitor->visit(this);
}

void minipascal::Node::showError(std::string message)
{
        char buf[8];
        sprintf(buf, "%d", getLineNo());
        std::cout << "Error : " << message << " at LINE:" << buf << std::endl;
}

bool minipascal::Node::getFail() const
{
        return fail;
}

int minipascal::Node::getLineNo() const
{
        return lineno;
}

void minipascal::Node::setFail(bool fail)
{
        this->fail = fail;
}

void minipascal::Node::setLineNo(int lineno)
{
        this->lineno = lineno;
}
