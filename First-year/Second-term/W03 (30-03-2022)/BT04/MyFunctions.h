#ifndef MyFunctions_h
#define MyFunctions_h

int *CreateArray(int N);

void DeleteArray(int *&array);

void InputArray(int *&array, int &N);

void OutputArray(int *array, int N);

int SortAsc(const void *a, const void *b);

int SortDesc(const void *a, const void *b);


#endif /* MyFunctions_h */