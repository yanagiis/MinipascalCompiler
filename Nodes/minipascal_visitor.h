#ifndef MINIPASCAL_VISITOR_H
#define MINIPASCAL_VISITOR_H

#include "minipascal_node.h"
#include "minipascal_nassignment.h"
#include "minipascal_nbinaryoperator.h"
#include "minipascal_nblock.h"
#include "minipascal_nboolean.h"
#include "minipascal_ncontrol.h"
#include "minipascal_ndouble.h"
#include "minipascal_nint.h"
#include "minipascal_nloop.h"
#include "minipascal_nmethodcall.h"
#include "minipascal_nmethoddeclaration.h"
#include "minipascal_nprogram.h"
#include "minipascal_nstatementexpression.h"
#include "minipascal_nstring.h"
#include "minipascal_nvariable.h"
#include "minipascal_nvariabledeclaration.h"
#include "minipascal_type.h"
namespace minipascal {
        class Visitor {
        public:
                virtual void visit(Node* node) = 0;
                virtual void visit(NAssignment* node) = 0;
                virtual void visit(NBinaryOperator* node) = 0;
                virtual void visit(NBlock* node) = 0;
                virtual void visit(NBoolean* node) = 0;
                virtual void visit(NControl* node) = 0;
                virtual void visit(NDouble* node) = 0;
                virtual void visit(NInt* node) = 0;
                virtual void visit(NLoop* node) = 0;
                virtual void visit(NMethodCall* node) = 0;
                virtual void visit(NMethodDeclaration* node) = 0;
                virtual void visit(NProgram* node) = 0;
                virtual void visit(NStatementExpression* node) = 0;
                virtual void visit(NString* node) = 0;
                virtual void visit(NVariable* node) = 0;
                virtual void visit(NVariableDeclaration* node) = 0;
                virtual void visit(minipascal::ArrayType* node) = 0;
                virtual void visit(minipascal::IntType* node) = 0;
                virtual void visit(minipascal::BooleanType* node) = 0;
                virtual void visit(minipascal::StringType* node) = 0;
        };
}


#endif // MINIPASCAL_VISITOR_H
