#ifndef EC_SYNTAX_H
#define EC_SYNTAX_H

#include "ec.h"
#endif // EC_SYNTAX_H


#ifdef EC_SYNTAX

#ifdef EC_CAPITALIZE
#define EC_SYNTAX EC_CAPITALIZE
#endif

#ifdef EC_CAMELCASE
#define EC_SYNTAX EC_CAMELCASE
#endif

#ifdef EC_LOWERCASE
#define EC_SYNTAX EC_LOWERCASE
#endif

#endif
