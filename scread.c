#include <stdio.h>
#include "Index.h"

enum CXChildVisitResult printVisitor(CXCursor cursor, CXCursor parent, CXClientData client_data) {

    const char *astName = clang_getCString(clang_getCursorSpelling(cursor));
    printf("The AST name is:%s\n", astName);

    return CXChildVisit_Recurse;
}


int main(int argc, char *argv[]) {
    CXIndex Index = clang_createIndex(0,0);
    CXTranslationUnit TU = clang_parseTranslationUnit(Index, 0, argv, argc,
                                                      0, 0,
                                                      CXTranslationUnit_None);
    CXCursor C = clang_getTranslationUnitCursor(TU);
    const char *astName = clang_getCString(clang_getCursorSpelling(C));
    printf("The AST name is:%s\n", astName);

    clang_visitChildren(C, printVisitor, NULL);

    clang_disposeTranslationUnit(TU);
    clang_disposeIndex(Index);
    return 0;
}
