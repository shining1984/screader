#include <stdio.h>
#include <stdbool.h>
#include "Index.h"

bool printKindSpelling(CXCursor cursor) {
    enum CXCursorKind curKind = clang_getCursorKind(cursor);
    const char *curkindSpelling = clang_getCString(
                                  clang_getCursorKindSpelling(curKind));
    printf("The AST node kind spelling is:%s\n", curkindSpelling);
    return true;
}

bool printSpelling(CXCursor cursor) {
    const char *astSpelling = clang_getCString(clang_getCursorSpelling(cursor));
    printf("The AST node spelling is:%s\n", astSpelling);
    return true;
}

bool printLocation(CXCursor cursor) {
    CXSourceRange range = clang_getCursorExtent(cursor);
    CXSourceLocation startLocation = clang_getRangeStart(range);
    CXSourceLocation endLocation = clang_getRangeEnd(range);

    CXFile file;
    unsigned int line, column, offset;
    clang_getInstantiationLocation(startLocation, &file, &line, &column, &offset);
    printf("Start: Line: %u Column: %u Offset: %u\n", line, column, offset);
    clang_getInstantiationLocation(endLocation, &file, &line, &column, &offset);
    printf("End: Line: %u Column: %u Offset: %u\n", line, column, offset);

    return true;
}

enum CXChildVisitResult printVisitor(CXCursor cursor, CXCursor parent,
                                     CXClientData client_data) {
    printSpelling(cursor);
    printKindSpelling(cursor);
    printLocation(cursor);
    return CXChildVisit_Recurse;
}

int main(int argc, char *argv[]) {
    CXIndex Index = clang_createIndex(0,0);
    CXTranslationUnit TU = clang_parseTranslationUnit(Index, 0, argv, argc,
                                                      0, 0,
                                                      CXTranslationUnit_None);
    CXCursor C = clang_getTranslationUnitCursor(TU);
    printSpelling(C);
    printKindSpelling(C);
    printLocation(C);

    clang_visitChildren(C, printVisitor, NULL);

    clang_disposeTranslationUnit(TU);
    clang_disposeIndex(Index);
    return 0;
}
