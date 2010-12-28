#ifndef MINIPACAL_LISTS_H
#define MINIPACAL_LISTS_H

#include <vector>

class ShareNStatement;
class ShareNExpression;
class ShareNVariableDeclaration;
class ShareNMethodDeclaration;

typedef std::vector<ShareNStatement> Stmt_list;
typedef std::vector<ShareNExpression> Exps_list;
typedef std::vector<ShareNVariableDeclaration> Decls_list;
typedef std::vector<ShareNMethodDeclaration> Mhd_list;
typedef std::vector<std::string*> Id_list;
typedef std::vector<int> Index_list;

#include "minipascal_nstatement.h"
#include "minipascal_nexpression.h"
#include "minipascal_nvariabledeclaration.h"
#include "minipascal_nmethoddeclaration.h"

#endif // MINIPACAL_LISTS_H