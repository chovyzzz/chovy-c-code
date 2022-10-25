typedef struct {
  int *values;
  int top;
  int maxTop;
} Stack;

/* function: creates a new stack array and initializes the stack data structure
   input: stack: pointer to the stack data structure
          size: maximum size of the stack
   output: a boolean indicating whether the creation succeeded or not
*/
bool CreateStack(Stack *stack, int size) ;
/* function: checks whether a stack is empty or not
   input: stack: pointer to the stack data structure
   output: a boolean indicating whether the stack is empty
*/
bool IsEmpty(Stack *stack);
/* function: checks whether a stack is full or not
   input: stack: pointer to the stack data structure
   output: a boolean indicating whether the stack is full
*/
bool IsFull(Stack *stack);
/* function: adds a new value at the top of the stack
   input: stack: pointer to the stack data structure
          x: the new value to be added
   output: a boolean indicating whether the push succeeded
*/
bool Push(Stack *stack, int x);
/* function: reads and removes the top value from the stack
   input: stack: pointer to the stack data structure
   output: the top value
*/
int Pop(Stack *stack);
/* function:calcute
   input: str 
   output: the result
*/
void EvalPostfix(char postfix[]);
