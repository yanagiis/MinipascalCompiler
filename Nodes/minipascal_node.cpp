#include "minipascal_node.h"

void minipascal::Node::accept(minipascal::Visitor* visitor)
{
        visitor->visit(this);
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
