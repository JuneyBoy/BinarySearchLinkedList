# include <iostream>

using namespace std;

class Course{
    public:
        int capacity;
        Course* ptr_prev;
        Course* ptr_next;
        Course(int capacity){
            
            this -> capacity = capacity;
            ptr_prev = nullptr;
            ptr_next = nullptr;

        }
};

class DoublyLinkedList{
    private:
        int size;
        Course* head;
        Course* tail;
    public:
        DoublyLinkedList(){
            this->size = 0;
            this->head = nullptr;
            this->tail = nullptr;
        }
        void append(Course* course_ptr){
            if(this->head == nullptr){
                this->head = course_ptr;
                this->tail = course_ptr;
            }
            else{
                this->tail->ptr_next = course_ptr;
                course_ptr->ptr_prev = this->tail;
                this->tail = course_ptr;
            }
            ++size;
        }

        void addBefore(Course* new_course, Course* curr_course){
            if(this->head == curr_course){
                new_course->ptr_next = curr_course;
                curr_course->ptr_prev = new_course;
                this->head = new_course;
            }
            else{
                new_course->ptr_next = curr_course;
                curr_course->ptr_prev->ptr_next = new_course;
                new_course->ptr_prev = curr_course->ptr_prev;
                curr_course->ptr_prev = new_course;
            }
            ++size;
        }

        void printList(){
            Course* currCourse = this->head;
            while(currCourse != nullptr){
                cout << currCourse->capacity << " ";
                currCourse = currCourse->ptr_next;
            }
        }

        int getSize(){
            return size;
        }
};


int main(){
    
    DoublyLinkedList* list = new DoublyLinkedList();

    Course* course1 = new Course(10);

    Course* course2 = new Course(15);

    Course* course3 = new Course(20);

    list->append(course1);
    list->append(course2);
    list->addBefore(course3,course2);

    list->printList();
    cout << list->getSize();


    return 0;
}