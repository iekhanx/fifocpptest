// Program cpptest.cpp
// Date    12/05/2016 
//
//NOTE:
//     An effective use of FIFO using container class with
//     structure to fill in as requested.
//
//          PROGRAM DEMONSTRATE
//          ==================
//   1/ Structure based queue logic
//   2/ STL container queue class based logic
//----------------------------------------------------------

#define cls        "\033[2J\033[1;1H"   /* Clear the screen */
#include <iostream>
#include <iomanip>
#include <queue>
#include <fstream>
#include <sstream>
#include <cstring>
#include <pthread.h>
#include <time.h>

using namespace std;

struct fifo_queue    // Good old C structure based logic
{
 int data;
 struct fifo_queue *next;
}*head;

// custom function sleep for c++
// Container class 
class myfifo_queue
{
      private:
          std::queue<unsigned char*> _queue_;  // STL class queue logic
          pthread_mutex_t push_mutex;
          pthread_mutex_t pop_mutex;
          pthread_cond_t  cond;

      public:
         myfifo_queue() {   // custom constructor
          pthread_mutex_init (&push_mutex, NULL);
          pthread_mutex_init (&pop_mutex,  NULL);
          pthread_cond_init (&cond, NULL);
       }

  // void push (unsigned char * data)
  void push (int data)
  {
      unsigned char* test_data = new unsigned char [4096];
      pthread_mutex_lock (&push_mutex);

      // debugging 
      cout << "Received data " << data << endl;

      //do {
      //   _queue_.push(data);
      // } while (data);
     
      for (int i=0; i < data; i++) {
            _queue_.push(test_data); 
           cout << "Data added to Fifo Queue "<< i << endl;
        }

      cout << "Queue contains" << endl;

     while (!_queue_.empty()) {
            cout << " " << _queue_.front() << endl;
          _queue_.pop();
        }

       cout << "\n";

      pthread_cond_signal (&cond);
      pthread_mutex_unlock (&push_mutex);
  }

  //void pop (unsigned char** popped_data)
  void pop (int popped_data)
  {
      unsigned char* test_data = new unsigned char [1024];

       if(_queue_.empty())  {
          cout << "Queue is an empty currently. Exiting" << endl;
          exit(1); 
        }
	
	// debugging 	
	cout << "Received data " << popped_data << endl;

       pthread_mutex_lock (&pop_mutex);
    
       //while (_queue_.empty() == true) {
       //       pthread_cond_wait (&cond, &pop_mutex);
       //	*popped_data = _queue_.front();

       for (int i=0; i < popped_data; i++) {
               if (_queue_.empty() == true) {
                 pthread_cond_wait (&cond, &pop_mutex);
                 test_data = _queue_.front();
	         cout << "Popped " << test_data << endl;
                 _queue_.pop();
             }
     }
      pthread_mutex_unlock (&pop_mutex);
   }


  void enter_data()
  {
      fifo_queue *tmp;
      int val;
      tmp = head;

      if (tmp == NULL)
         cout << "\n\nList is an Empty" << endl;
         
      while (true ) {
       	cout << "Please enter data to create a fifo queue: ";
	cin >> val; 
        cout << "\n";
        if (val == 0 )
             break;
          else
              insertNode (val);
        }	   
  }


   void insertNode(int data)
   {
         fifo_queue * tmp;
         fifo_queue * addNode = new fifo_queue;
        
         addNode->data = data;
         addNode->next = NULL;

	tmp = head;

	if(tmp != NULL) {
           while ( tmp->next != NULL) {
               tmp = tmp->next;
            }
           tmp->next = addNode;
         }
        else {
                head = addNode;
        }
   }

   void display()
   {
	fifo_queue * tmp;
        tmp = head;

	if (tmp == NULL) {
           cout << "There is NO data in the fifo queue" << endl;
 	  return;
        }

	while (tmp != NULL) {
            cout << "Data : " << tmp->data << endl;
            tmp = tmp->next;
	}
       	cout << "Press Enter <R> to exit" << endl;
	cin.ignore().get();
   }

   int length() 
   {
       	fifo_queue *tmp;
       	int count = 0;

	tmp = head;
	while (tmp != NULL) {
	    tmp  = tmp->next;
	    count++;
	}
       return count;
    }	

   void insert_at_position()
   {
 	int pos = 0;
	fifo_queue * addNode = new fifo_queue;
	fifo_queue * tmp, *tmp1;

	cout << "Enter Data to add : ";
	cin >> addNode->data;
	
	addNode->next = NULL;

	do {
		cout << "Enter position to add: ";
		cin >> pos;
		
		if (pos > length() || pos < 0) {
			cout << "Invalid length !" << endl;
		}

	   } while (pos > length() || pos < 0);

	if (head == NULL) {
		head = addNode;
	}
	else {
		tmp = head;
		for (int i=1; i < pos -1; i++ ) {
			tmp = tmp->next;
		}
		tmp1 = tmp->next;
		tmp->next = addNode;
		addNode->next = tmp1;
	}
   }

   void del(void)
   {
           fifo_queue *tmp;
           tmp = head;
	   int count = 0;

	   if(tmp == NULL)
	   {
		   cout << "\n\nFifo Queue Empty\n";
		   return;
	   }
	   else
	   {
               cout << "FIFO Queue contains: " << head << endl;	
	 	while (tmp != NULL) {
		   tmp = tmp->next;
		   cout << count << " Data Deleted  " << tmp << endl;
	           delete (tmp);
                   count++;
		}
	   }
   }
   
};

// Consumer test for the class fifo_queue
void *consumer_thread (void *arguments)
{
	myfifo_queue *fq = static_cast<myfifo_queue*>(arguments);
	
	while (true) {
		//unsigned char *data = NULL;
                int data = 1024;		
		fq->pop (data);

		if (data != 0) {
		   // received from the other thread
		   // delete from memory
		   // process here with given parameters

		   //delete[] data;
		}
	}
      return 0;
}

int ShowChoices()
{
   int choice;
   string input = "";

   cout<<cls<<endl;     // clear the screen.
  while (true) {
   cout << "\n\n\nChoose your choice\n";
   cout << "==================\n";
   cout << "1) Insert - C structure\n";
   cout << "2) Insert at Position\n";
   cout << "3) Display\n";
   cout << "4) Delete\n";
   cout << "5) Push - STL Queue class\n";
   cout << "6) Pop  - STL Queue class\n";
   cout << "7) Exit\n";
   cout << endl;
   cout<<"Enter your  choice :- ";
   getline(cin, input);
   stringstream myStream(input);   // to number

   if (myStream >> choice)
      break;
   }
  return choice;
}

// program entry point
// ==================
int main()
{
   int choice;      // var for choices #

   // our class become an object.
   myfifo_queue fq;
   pthread_t consumer;

  do  
   {
       choice = ShowChoices();

    switch(choice)
    {
      	case 1 : fq.enter_data();
               break;
      	case 2 : fq.insert_at_position();
               break;
	case 3 : fq.display();
	       break;
      	case 4 : fq.del();
               break;
      	case 5 : 
	       // now create variable for consumer thread
	       pthread_create (&consumer, NULL, consumer_thread, &fq);

	      // while (true) 
	       {
		       //unsigned char* test_data = new unsigned char [4096];
		       int test_data = 4096;
		       fq.push (test_data);
	       }		

               break;
      	case 6 :
	       // now create variable for consumer thread
	       pthread_create (&consumer, NULL, consumer_thread, &fq);

	       //while (true) 
	       {
		       //unsigned char* test_data = new unsigned char [1024];
		       int test_data = 1024;
		       fq.pop (test_data);
	       }		

               break;
      	case 7 :  {cout << "Exiting " << choice << endl; }
               break;

     default:
              cout << "Invalid input or choice!" << endl;
	      //my_sleep(5);
    }
  }  while (choice != 7);

 return 0;
}
// -- Eof source code for cpptest.cpp --
