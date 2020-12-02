using namespace std;

template <class Type> class GenStack
{
  public:

    //constructors
    GenStack();
    GenStack(int s);

    //destructor
    ~GenStack();

    //helpers
    void push(Type p);
    Type peek(); //will return top element
    Type pop(); //will remove and return top element
    void resize(); //increases the size by creating new stack
    bool isEmpty(); //checks if stack is empty
    bool isFull(); //checks if stack is full

    //size of stack
    int size;

    //the top (most recent item & next to be returned)
    int top;

    //pointer to the stack
    Type *stack;

  private:
};

template <class Type>
GenStack<Type>::GenStack()
{
  stack = new Type[1];
  size = 1;
  top = -1;
}

template <class Type>
GenStack<Type>::GenStack(int s)
{
  stack = new Type[s];
  size = s;
  top = -1;
}

template <class Type>
GenStack<Type>::~GenStack()
{
  delete stack;
}

template <class Type>
void GenStack<Type>::push(Type p)
{
  if (!this->isFull())
  {
    stack[++top] = p;
  }
  else
  {
    this->resize();
    stack[++top] = p;
  }
}

template <class Type>
Type GenStack<Type>::peek()
{
  if (!this->isEmpty())
  {
    return stack[top];
  }
}

template <class Type>
Type GenStack<Type>::pop()
{
  if (!this->isEmpty())
  {
    return stack[top--];
  }
}

template <class Type>
void GenStack<Type>::resize()
{
  int biggerSize = size++;;
  Type* biggerStack = new Type[biggerSize];
  for (int i = 0; i < size; ++i)
  {
    biggerStack[i] = stack[i];
  }
  stack = biggerStack;
}

template <class Type>
bool GenStack<Type>::isEmpty()
{
  bool isEmpty;
  if (top == -1)
  {
    isEmpty = true;
  }
  else
  {
    isEmpty = false;
  }

  return isEmpty;
}

template <class Type>
bool GenStack<Type>::isFull()
{
  bool isFull;
  if (top == size - 1)
  {
    isFull = true;
  }
  else
  {
    isFull = false;
  }

  return isFull;
}
