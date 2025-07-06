#include <iostream>

typedef struct DoublyNode {
    int value;
    DoublyNode* next;
    DoublyNode* prev;
} DoublyNode;

DoublyNode* head = NULL;
DoublyNode* tail = NULL;

void InitFromArray(int* arr, int n){
    DoublyNode* ptr;
    DoublyNode* NewNode;

    for(int i = 0; i < n ; i++){
        NewNode = new DoublyNode;
        NewNode->value = arr[i];
        NewNode->next = NULL;
        NewNode->prev = NULL;

        if(head == NULL){
            head = tail = NewNode;
            continue;
        }
        
        ptr = head;
        while (ptr->next != NULL){
            ptr = ptr->next;
        }
        tail = NewNode;
        ptr->next = tail;
        NewNode->prev = ptr;
        
    }

}
 // Khởi tạo danh sách từ mảng
void DisplayForward(){
    // In danh sách từ head đến tail
    if(head == NULL){
        std::cout<< " khong co node nao";
        return;
    }
    DoublyNode* ptr;
    ptr = head;
    while(ptr != NULL){
        std::cout<< ptr->value<<", ";
        ptr = ptr->next;
        if(ptr == NULL){
            std::cout<< " node rong ";
        }
    }

    
}
void DisplayBackward(){
    if(tail == NULL){
        std::cout<< " khong co node nao ";
        return;
    }
    DoublyNode* ptr;
    ptr = tail;
    while(ptr != NULL){
        std::cout<< ptr->value<<", ";
        ptr = ptr->prev;
        if(ptr == NULL){
            std::cout<< " node rong ";
        }
    }
}  // In danh sách từ tail về head

void InsertBegin(int val){
    DoublyNode* NewNode;
    NewNode = new DoublyNode;
    NewNode->value = val;
    NewNode->next = head;

    head->prev = NewNode;
    NewNode->next = head;
    head = NewNode;
}                   // Thêm vào đầu danh sách
void InsertEnd(int val){
    DoublyNode* NewNode;
    NewNode = new DoublyNode;
    NewNode->value = val;
    NewNode->next = NULL;
    
    NewNode->prev = tail;
    tail->next = NewNode;
    tail = NewNode;
}                    // Thêm vào cuối danh sách
void InsertBefore(int indexValue, int val){
    DoublyNode* NewNode;
    DoublyNode* ptr;
    DoublyNode* ptrsau;
    NewNode = new DoublyNode;
    NewNode->value = val;
    NewNode->next = NULL;
    NewNode->prev = NULL;

    if((head == NULL) && (tail == NULL)){
        head = tail = NewNode;
        return;
    }
    if(head->value == indexValue){
        NewNode->next = head;
        head->prev = NewNode;
        head = NewNode;
        return;
    }
    ptr = head;
    while (ptr->value != indexValue){
        if(ptr->next == NULL){
            std::cout << "Khong co gia tri " << indexValue << " trong danh sach, se chen vao cuoi."<<std::endl;
            ptr->next = NewNode;
            NewNode->prev = ptr;
            tail =NewNode;
            return;
        }
        ptrsau = ptr;
        ptr = ptr->next;
    }
    if(head->next->value == indexValue ){
        ptrsau->next = NewNode;
        NewNode->next = ptr;
        NewNode->prev = ptrsau;
        ptr->prev = NewNode;
        return;
    }
    ptrsau->next = NewNode;
    NewNode->next=ptr;
    NewNode->prev = ptrsau;
    ptr->prev = NewNode;

}  // Thêm val trước node có giá trị indexValue
void InsertAfter(int indexValue, int val){
    DoublyNode* NewNode;
    DoublyNode* ptr;
    DoublyNode* ptrsau;
    NewNode = new DoublyNode;
    NewNode->value = val;
    NewNode->next = NULL;
    NewNode->prev = NULL;

    if((head == NULL) && (tail == NULL)){
        head = tail = NewNode;
        return;
    }
    if(head->value == indexValue){
        head->next->prev = NewNode;
        NewNode->prev = head;
        NewNode->next = head->next;
        head->next = NewNode;
        // NewNode->next = head;
        // head->prev = NewNode;
        // head = NewNode;
        return;
    }
    ptr = head;
    while (ptr->value != indexValue){
        if(ptr->next == NULL){
            std::cout << "Khong co gia tri " << indexValue << " trong danh sach, se chen vao cuoi."<<std::endl;
            ptr->next = NewNode;
            NewNode->prev = ptr;
            tail = NewNode;
            return;
        }
        ptrsau = ptr;
        ptr = ptr->next;
    }
    ptrsau = ptr;
    ptr = ptr->next;

    if(tail->value == indexValue ){
        tail->next = NewNode;
        NewNode->prev = tail;
        tail = NewNode;
        return;
    }
    ptrsau->next = NewNode;
    NewNode->next=ptr;
    NewNode->prev = ptrsau;
    ptr->prev = NewNode;
}   // Thêm val sau node có giá trị indexValue


// ### 📌 Xóa phần tử

void DeleteBegin(){
    DoublyNode* ptr;
    ptr = head->next;
    ptr->prev = NULL;
    delete head;
    head = ptr;

}                    // Xóa node đầu tiên
void DeleteEnd(){
    DoublyNode* ptr;
    ptr = tail->prev;
    ptr->next = NULL;
    delete tail;
    tail = ptr;
}                      // Xóa node cuối cùng
void DeleteBefore(int indexValue){
    DoublyNode* ptr;
    DoublyNode* ptrsau;

    if((head == NULL) && (tail == NULL)){ // danh sach rong
        std::cout<< " danh sach rong khong co gi de xoa";
        return;
    }
    if(head->value == indexValue){ // xoa phan tu truoc gia tri dau tien
        std::cout<< " truoc no khong co phan tu nao";
        return;
    }
    if(head!= NULL && tail != NULL && head == tail){ // xoa khi danh sach co mot phan tu
        delete head;
        delete tail;
        head=tail= NULL;
        return;
    }
    ptr = head;
    while (ptr->value != indexValue){
        if(ptr->next == NULL){
            std::cout << "Khong co gia tri " << indexValue << " trong danh sach!"<<std::endl;
            return;
        }
        ptrsau = ptr;
        ptr = ptr->next;
    }
    if(head->next->value == indexValue ){ // xoa gia tri thu nhat (head)
        delete ptrsau;
        ptr->prev = NULL;
        head = ptr;
        return;
    }
    ptrsau->prev->next = ptr;
    ptr->prev = ptrsau->prev;
    delete ptrsau;
}     // Xóa node trước node có giá trị indexValue
void DeleteAfter(int indexValue){
    DoublyNode* ptr;
    DoublyNode* ptrsau;

    if((head == NULL) && (tail == NULL)){ // lhong co phan tu nao
        std::cout<< " danh sach rong khong co gi de xoa";
        return;
    }
    if(tail->value == indexValue){ // xoa sau gia tri cuoi cung
        std::cout<< " sau no khong co phan tu nao";
        return;
    }
    if(head!= NULL && tail != NULL && head == tail){ // chi co 1 phan tu
        delete head;
        delete tail;
        head=tail= NULL;
        return;
    }
    ptr = head;
    while (ptr->value != indexValue){
        if(ptr->next == NULL){
            std::cout << "Khong co gia tri " << indexValue << " trong danh sach!"<<std::endl;
            return;
        }
        ptrsau = ptr;
        ptr = ptr->next;
    }
    if(tail->prev->value == indexValue ){ // xoa phan tu thu 2 tu sau ve(hay la xoa tail)
        ptr->next = NULL;
        delete tail;
        tail = ptr;
        return;
    }
    ptrsau = ptr;
    ptr = ptr->next;
    ptrsau->next = ptr->next;
    ptr->next->prev = ptrsau;
    delete ptr;
}      // Xóa node sau node có giá trị indexValue



bool empty(){
    if((head == NULL) && (tail == NULL)){
        return true;
    }
    return false;
}               // Trả về true nếu danh sách rỗng
int size(){
    if(empty()){
        std::cout << " danh sach nay rong size = " << 0 <<std::endl;
        return 0;
    }
    DoublyNode* ptr;
    ptr = head;
    if(ptr->next == NULL){
        std::cout<< " danh sach co size = "<<1 <<std::endl;
        return 1;
    }
    int count = 1;
    while(ptr->next != NULL){
        ptr = ptr->next;
        count ++;
    }
    std::cout<< "danh sach co size = " << count<< std::endl;
    return count;
    // ptr = ptr->next;
}                 // Trả về số phần tử trong danh sách
bool search(int value){
    DoublyNode* ptr;
    ptr = head;
    while(ptr->value != value){
        ptr = ptr->next;
        if(ptr == NULL){
            std::cout<<" Khong co gia tri "<< value << " trong danh sach"<<std::endl;
            return false;
        }
    }
    return true;
    std::cout<< " co gia tri "<< value << " trong danh sach" <<std::endl;
    
}     // Trả về true nếu tìm thấy value trong danh sách

int main() {
    int array[5] = {5, 10, 15, 20, 25};
    InitFromArray(array, 5);
    std::cout << "Danh sách hiện tại: "<<std::endl;
    DisplayForward();
    std::cout<< std::endl;

    DisplayBackward();
    InsertBegin(7);
    InsertEnd(8);
    
    std::cout<< std::endl;
    DisplayForward();
    std::cout<< std::endl;

    DisplayBackward();
    std::cout<< std::endl;

    InsertBefore(9, 3);
    DisplayForward();
    std::cout<< std::endl;
    DisplayBackward();

    std::cout<< std::endl;

    InsertAfter(25, 3);
    DisplayForward();
    std::cout<< std::endl;
    DisplayBackward();

    std::cout<< std::endl<< "Xoa phan tu dau va cuoi"<< std::endl;

    DeleteBegin();
    DisplayForward();
    std::cout<< std::endl;
    DisplayBackward();
    std::cout<< std::endl;

    DeleteEnd();
    DisplayForward();
    std::cout<< std::endl;
    DisplayBackward();
    std::cout<< std::endl;

    std::cout<< std::endl<< "Xoa phan tu "<< std::endl;
    DeleteBefore(5);
    DisplayForward();
    std::cout<< std::endl;
    DisplayBackward();
    std::cout<< std::endl;



    return 0;
}