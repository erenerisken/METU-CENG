#include "the3.h"

#define MAX_N 1005
#define LEFT_CHILD(x) (2*x)
#define RIGHT_CHILD(x) (2*x + 1)
#define PARENT(x) (x/2)

typedef std::pair<int,int> nodePair;

template <class T>
class MaxHeap
   {
      public:
         MaxHeap()
            {
               n = 0;
               elements.resize(MAX_N);
            }
         MaxHeap<T>& add(T el)
            {
               elements[++n] = el;
               percolateUp(n);
               return *this;
            }
         T pop()
            {
               T ret = elements[1];
               elements[1] = elements[n--];
               percolateDown(1);
               return ret;
            }
         bool empty()
            {
               //std::cout<<std::endl<<"N = "<<n<<std::endl;
               return n == 0;
            }
      private:
         void percolateUp(size_t ind)
            {
               while (ind > 1 && elements[PARENT(ind)] < elements[ind])
               {
                  std::swap(elements[PARENT(ind)], elements[ind]);
                  ind = PARENT(ind);
               }
            }
         void percolateDown(size_t ind)
            {
               if(n == 0)
                  return;
               while (LEFT_CHILD(ind) <= n)
               {
                  size_t child = LEFT_CHILD(ind);
                  if (RIGHT_CHILD(ind) <= n && elements[RIGHT_CHILD(ind)] > elements[LEFT_CHILD(ind)])
                  {
                     child = RIGHT_CHILD(ind);
                  }
                  if (elements[ind] > elements[child])
                  {
                     return;
                  }
                  std::swap(elements[ind], elements[child]);
                  ind = child;
               }
            }
         std::vector<T> elements;
         size_t n;
   };

// You  can define extra functions here



// INPUT :
//            n         : number of nodes in the graph
//            edgeList  : edges in the graph
//            scores    : importance scores
// return value : 
//                 number of disconnected components
int Important (int n, int**& edgeList, double*& scores)
{ 

   return -1; 
}

int main()
   {
      MaxHeap<int> h;
      h.add(3).add(2).add(5).add(7).add(14).add(1);
      while (!h.empty())
      {
         std::cout<<h.pop()<<" ";
      }
      
   }