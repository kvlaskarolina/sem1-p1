// Karolina Kulas
/*#include <iostream>
typedef unsigned char BYTE;
typedef int OBJECT_TYPE;

const BYTE SIZE = 10;

struct NODE_STRUCT {
    OBJECT_TYPE* object;
    BYTE use;
    NODE_STRUCT* next;
};
*/
NODE_STRUCT* NewNode(void) {

}

void DeleteNode(NODE_STRUCT* ) {

}

void Clear(NODE_STRUCT** ) {
    
}

void AddFirst(NODE_STRUCT** , OBJECT_TYPE* ) {

}

void AddLast(NODE_STRUCT** , OBJECT_TYPE* ) {
   
}

void GetFirst(NODE_STRUCT* , NODE_STRUCT** , BYTE* ) {
    
}

void GetPrev(NODE_STRUCT*, NODE_STRUCT*, BYTE, NODE_STRUCT**, BYTE*) {

}

void GetNext(NODE_STRUCT*, NODE_STRUCT*, BYTE , NODE_STRUCT**, BYTE*) {

}

void GetLast(NODE_STRUCT* , NODE_STRUCT** , BYTE* ) {
   
}

void InsertPrev(NODE_STRUCT**, NODE_STRUCT*, BYTE, OBJECT_TYPE*) {

}

void InsertNext(NODE_STRUCT*, NODE_STRUCT*, BYTE, OBJECT_TYPE*) {

}

void RemoveFirst(NODE_STRUCT** ) {
}

void RemovePrev(NODE_STRUCT**, NODE_STRUCT*, BYTE) {

}

void RemoveCurrent(NODE_STRUCT** , NODE_STRUCT* , BYTE ) {
 
}

void RemoveNext(NODE_STRUCT*, NODE_STRUCT*, BYTE) {

}

void RemoveLast(NODE_STRUCT** ) {
}

void Find(NODE_STRUCT*, OBJECT_TYPE*,NODE_STRUCT**, BYTE*) {

}

void Compress(NODE_STRUCT*) {

}

void Reverse(NODE_STRUCT*) {

}