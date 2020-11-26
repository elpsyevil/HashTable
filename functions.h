#define SIZE 20

typedef struct DataItem {
   int age;
   char* name; //key
}DataItem;

DataItem* hashArray[SIZE]; 
int hashFct(char);
DataItem* search(char *);
void insert(char *,int);
void display();
void delete(DataItem*);
