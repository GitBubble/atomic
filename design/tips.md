good article for cache coherency:        
 https://fgiesen.wordpress.com/2014/07/07/cache-coherency/   
 https://mortoray.com/2010/11/18/cpu-memory-why-do-i-need-a-mutex/    

good article for explaine boost internal:
   https://www.boost.org/doc/libs/1_63_0/doc/html/interprocess/synchronization_mechanisms.html#interprocess.synchronization_mechanisms.synchronization_mechanisms_overview


spinlock wiki: (arthur : one should notice that this information is not regarded with hybrid spinlocks)   
 https://en.wikipedia.org/wiki/Spinlock    
 http://danglingpointers.com/post/spinlock-implementation/   (simple implementation, 16xx also did this with assembly code)
 https://stackoverflow.com/questions/11770571/how-do-mutexes-really-work   (this answer is not good ,bcz it ignore the mutex has 3 types of implementations in modern os, fastest path is use spinlock, middle path is use MCS spinlock, low path is simply use os scheduler to put the thread into sleep and wait for next round schedule) so , under the hood, spinlock and schedule is the key to implement the mutual exclusive semantics.   

the QNX neutrino implementations:   
https://www.osnews.com/story/29090/implementing-mutexes-in-the-qnx-neutrino-realtime-os/

it's interesting, the libstdc++ also adopt posix mutex type:
 https://github.com/gcc-mirror/gcc/blob/master/libgcc/gthr-posix.h   
 typedef pthread_mutex_t __gthread_mutex_t;  

linus torvald's kernel repo has a good article about mutex design:
https://github.com/torvalds/linux/blob/master/Documentation/locking/mutex-design.txt     

here is a guy implement a pub/sub zero-copy demo:
https://github.com/nickbjohnson4224/fastpub/blob/master/main.c    
