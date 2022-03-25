#ifndef MyFunctions_h
#define MyFunctions_h

struct ABook;

struct Books;

void InputABook(ABook& abook);

void InputBooks(Books& books);

///////////// C헧 2 /////////////

void OutputABook(ABook abook);

void OutputBooks(Books books);

///////////// C헧 3 /////////////

void Sort(Books& books);


///////////// C헧 4 /////////////

void Find(Books books);


///////////// C헧 5 /////////////

void Add(Books& books);


///////////// C헧 6 /////////////

void Remove(Books& books);

#endif /* MyFunctions_h */