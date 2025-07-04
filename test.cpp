#include <iostream>
#include <vector>



// Cho dinh dang node nhu sau:
typedef struct LinklistNode{
    int value;
    LinklistNode *next;
} LinklistNode;

LinklistNode *start = NULL;
// int array[5];
// Hoan thien cac function duoi day

void DisplayLinklist(){
    
    if(start == NULL){
        std::cout<< " Khong co Node nao trong array";
        return;    
    }
    LinklistNode *ptr = start;
    while (ptr != NULL){
        std::cout << ptr->value << ", ";
        if(ptr == NULL){
            std::cout<< "Node rong";
        }
        ptr = ptr->next;
    }
    
}
void InitLinklistWithVector(int *array, int size){
    LinklistNode *ptr;
    LinklistNode *NewNode;

    for (int i = 0; i < size; i++){
        NewNode = new LinklistNode; // 70x,80x,90x
        NewNode->value = array[i];
        NewNode->next = NULL;

        if (start == NULL)
        {
            start = NewNode;
            continue;
        }
        ptr = start;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = NewNode;
    }
}

void InsertEnd(int a)
{
    LinklistNode *Newnode;
    Newnode = new LinklistNode;
    Newnode->value = a;
    Newnode->next = NULL;
    if (start == NULL)
    {
        start = Newnode;
        return;
    }
    LinklistNode *ptrr;
    ptrr = start;
    while (ptrr->next != NULL)
    {
        ptrr = ptrr->next;
    }
    ptrr->next = Newnode;
}

void InsertBegin(int b){
    LinklistNode *Newnode1;
    Newnode1 = new LinklistNode;
    Newnode1->value = b;
    Newnode1->next = start;
    start = Newnode1;
}

void InsertIndex(int indexValue, int val)
{
    // Nút mới phải được chèn **trước** nút đầu tiên có giá trị bằng `indexValue`
    LinklistNode *NewNode2;
    LinklistNode *ptr;
    LinklistNode *prev;
    NewNode2 = new LinklistNode;
    // ptr = new LinklistNode;
    // prev = new LinklistNode;

    NewNode2->value = val;
    NewNode2->next = NULL;
    if (indexValue == 0){
        NewNode2->next = start;
        start = NewNode2; //                 0  1     2   3  4
        // vd indexvalue = 2 , chen 8 vao day 1, 2,[], 3, 4,  5
    }else{
        ptr = start;
        int count = 1;
        while (count <= indexValue)
        {
            prev = ptr;
            ptr = ptr->next;
            count++;
        }
        prev->next = NewNode2;
        NewNode2->next = ptr;
    }
}
void InsertBefore(int indexValue, int val)
{
    //                   3           100
    // vd 10,24,4,11,18,17,3,7,3
    // chen 3 vao giua 17 va 3
    LinklistNode *NewNode;
    LinklistNode *ptr;
    LinklistNode *prev;

    NewNode = new LinklistNode;
    // 2 dong duoi co the //
    // ptr = new LinklistNode;
    // prev = new LinklistNode;

    NewNode->value = val;
    NewNode->next = NULL;

    ptr = start;
    if(ptr->value == val){
        NewNode->next = ptr;
        start = NewNode;
        return;
    }

    while (ptr->value != indexValue){
        prev = ptr;
        ptr = ptr->next;
        if (ptr->next == NULL)
        {
            ptr->next = NewNode;
            return;
        }
    }
    prev->next = NewNode;
    NewNode->next = ptr;
}

void InsertAfter(int indexValue, int val){
    // vd 1,5,7,6,8,1,5,9,4;
    LinklistNode *NewNode;
    LinklistNode *ptr;
    LinklistNode *prev;

    NewNode = new LinklistNode;
    // ptr = new LinklistNode;
    // prev = new LinklistNode;

    NewNode->value = val;
    NewNode->next = NULL;

    ptr = start;
    while (ptr->value != indexValue){
        prev = ptr;
        ptr = ptr->next;
        if (ptr->next == NULL)
        {
            ptr->next = NewNode;
            return;
        }
    }
    prev = ptr;
    ptr = ptr->next;

    prev->next = NewNode;
    NewNode->next = ptr;
}
// Nút mới phải được chèn **sau** nút đầu tiên có giá trị bằng `indexValue`

void DeleteAfter(int indexValue)
{
    LinklistNode* before;
    LinklistNode *ptr;
    LinklistNode *prev;
    // vd 10,24,4,11,18,17,3,7,3

    ptr = start;
    if(start->value == indexValue){
        ptr = ptr->next;
        start->next= ptr->next;
        delete ptr;
        return;
    }
    if(ptr->next == NULL){
        std::cout<< "khong co node dang sau";
        return;
    }
    before = start;
    prev = start;
    while (ptr->value != indexValue){
        before = prev;
        prev = ptr;
        ptr = ptr->next;
        if(ptr == NULL){
            std::cout<<"Khong co gia tri nay trong node";
            return;
        }
        
    }
    before = prev;
    prev = ptr;
    ptr = ptr->next;

    prev->next = ptr->next;
    delete ptr;
}
// Tôi muốn xóa nút đứng **ngay sau** nút đầu tiên có giá trị bằng `indexValue`

void DeleteBefore(int indexValue)
{
    LinklistNode *before;
    LinklistNode *ptr;
    LinklistNode *prev;

    ptr = start;
    
    if (start->value == indexValue)
    {
        std::cout << "Khong co node";
        return;
    }
    if (start->next->value == indexValue)
    {
        ptr = ptr->next;

        delete start;
        start = ptr;
        return;
    }
    before = start;
    prev = start;
    // vd 10, 100, 24, 4, 11, 18, 17, 3, 7, 3, 9999
    while (ptr->value != indexValue){ // 24
        before = prev;
        prev = ptr;
        ptr = ptr->next;
        if(ptr == NULL){
            std::cout<<"Khong co gia tri nay trong node";
            return;
        }
    }
    delete prev;
    before->next = ptr;
}
// Tôi muốn xóa nút đứng **ngay trước** nút đầu tiên có giá trị bằng `indexValue

void DeleteEnd()
{
    LinklistNode *pointer;
    LinklistNode *prev;
    pointer = start;

    while (pointer->next != NULL)
    {
        prev = pointer;
        pointer = pointer->next;
    }
    delete pointer;
    prev->next = NULL;
}
void DeleteBegin()
{
    LinklistNode *ptr3;
    ptr3 = start->next;
    delete start;
    start = ptr3;
}

void PrintArrayWithAddresses(int *arr, int size)
{
    for (int i = 0; i < size; ++i)
    {
        std::cout << "arr[" << i << "] = " << arr[i] << ", Address: " << &arr[i] << std::endl;
    }
}

bool empty(){
    if(start == NULL){
        return true;
    }
    return false;
}

int main()
{
    // int link1[9] = {10, 24, 4, 11, 18, 17, 3, 7, 3};
    // InitLinklistWithVector(link1, 9);
    if(empty()){
        std::cout<< "linklist nay rong";
    }else{
        std::cout<< "linklist nay khong rong";
    }

    DisplayLinklist();
    std::cout << std::endl;

    // InsertEnd(8);
    // InsertBegin(23);
    // DisplayLinklist();
    // std::cout << std::endl;

    // DeleteEnd();
    // DisplayLinklist();
    // std::cout << std::endl;

    // DeleteBegin();
    // DisplayLinklist();
    // std::cout << std::endl;

    // InsertBefore(24, 100);
    // DisplayLinklist();
    // std::cout << std::endl;

    // InsertAfter(1, 9999);
    // DisplayLinklist();
    // std::cout << std::endl;

    // DeleteBefore(1000); // = 10 loi
    // DisplayLinklist();
    // std::cout << " Xoa trc " <<std::endl;

    // DeleteAfter(999);
    // DisplayLinklist();
    // std::cout<<std::endl;

    return 0;
}