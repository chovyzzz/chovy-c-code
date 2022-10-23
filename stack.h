typedef struct {
double *values;
int top; 
int maxTop; 
} Stack;
/*Creates an empty stack whose capacity is size
input: stack:pointer to a stack
	     size:the size of stack
output:true if queue creation is successful and false otherwise
*/


bool CreateStack(Stack *stack, int size);
bool IsEmpty(Stack *stack);
bool IsFull(Stack *stack);
bool Top(Stack *stack, double *x);
bool Push(Stack *stack, double x);
bool Pop(Stack *stack, double *x);
void DisplayStack(Stack *stack);
void DestroyStack(Stack *stack);
